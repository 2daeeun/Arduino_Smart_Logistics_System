#include <SPI.h>
#include <MFRC522.h>
#include <ESP8266WiFi.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

// RFID 설정
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

// WiFi 설정
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// MySQL 설정
IPAddress server_addr(192, 168, 1, 100); // MySQL 서버 IP 주소
char user[] = "your_username"; // MySQL 사용자 이름
char password_db[] = "your_password"; // MySQL 비밀번호
char database[] = "your_database"; // 데이터베이스 이름

WiFiClient client;
MySQL_Connection conn((Client *)&client);

void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
  connectWiFi();
  connectMySQL();
}

void loop() {
  // RFID 카드가 인식되었는지 확인
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    delay(50);
    return;
  }

  // RFID UID 읽기
  String rfidUID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    rfidUID += String(mfrc522.uid.uidByte[i], HEX);
  }
  
  Serial.print("RFID UID: ");
  Serial.println(rfidUID);

  // 물품 정보 입력 (예시)
  String itemName = "Example Item";
  String sender = "Sender Name";
  String receiver = "Receiver Name";
  String deliveryArea = "Delivery Area";

  // MySQL 데이터베이스에 RFID UID 저장
  saveToDatabase(rfidUID, itemName, sender, receiver, deliveryArea);

  // 일정 시간 대기 (중복 인식 방지)
  delay(2000);
}

void connectWiFi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
}

void connectMySQL() {
  Serial.print("Connecting to database...");
  while (!conn.connect(server_addr, 3306, user, password_db, database)) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connected to database");
}

void saveToDatabase(String rfidUID, String itemName, String sender, String receiver, String deliveryArea) {
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  char query[512];
  sprintf(query, "INSERT INTO rfid_data (uid, item_name, sender, receiver, delivery_area) VALUES ('%s', '%s', '%s', '%s', '%s')", 
          rfidUID.c_str(), itemName.c_str(), sender.c_str(), receiver.c_str(), deliveryArea.c_str());

  cur_mem->execute(query);
  delete cur_mem;
}

