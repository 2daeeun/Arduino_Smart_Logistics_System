#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "HX711.h"

Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver();
HX711 scale;

#define MG996R_SERVO_MIN 150 // MG996R 서보 모터의 최소 펄스 길이 (0도)
#define MG996R_SERVO_MAX 600 // MG996R 서보 모터의 최대 펄스 길이 (180도)
#define SG90_SERVO_MIN 120   // SG90 서보 모터의 최소 펄스 길이 (0도)
#define SG90_SERVO_MAX 500   // SG90 서보 모터의 최대 펄스 길이 (180도)
#define DOUT 3 // HX711의 DT 핀
#define CLK 2 // HX711의 SCK 핀
#define REPETITIONS 3 // 반복 횟수 (모터의 개수)

// 각도를 MG996R 서보의 펄스 길이로 변환하는 함수
int angleToPulseMG996R(int angle) {
  return map(angle, 0, 180, MG996R_SERVO_MIN, MG996R_SERVO_MAX);
}

// 각도를 SG90 서보의 펄스 길이로 변환하는 함수
int angleToPulseSG90(int angle) {
  return map(angle, 0, 180, SG90_SERVO_MIN, SG90_SERVO_MAX);
}

void setup() {
  Serial.begin(9600);

  // PCA9685 초기화
  pca9685.begin();
  pca9685.setPWMFreq(50);

  // HX711 초기화
  scale.begin(DOUT, CLK);
  scale.set_scale();    // 기본 설정
  scale.tare();         // 로드셀 초기화 (tare로 영점 설정)
  
  delay(100); // 안정화 대기
}

void loop() {
  // 로드셀 데이터 읽기
  // float weight = scale.get_units(5); // 평균 5번 측정
  // weight = abs((weight / 1000)); // weight 값 보정
  
  // // 시리얼 모니터에 무게 출력
  // Serial.print("Weight: ");
  // Serial.print(weight);
  // Serial.println(" g");

  // 임시 모터 초기화 
  pca9685.setPWM(7, 0, angleToPulseMG996R(30));      delay(1000);
  pca9685.setPWM(1, 0, angleToPulseMG996R(30));      delay(1000);
  pca9685.setPWM(2, 0, angleToPulseMG996R(0));      delay(1000);
  pca9685.setPWM(3, 0, angleToPulseMG996R(0));      delay(1000);
  pca9685.setPWM(4, 0, angleToPulseSG90(45));       delay(1000);
  pca9685.setPWM(5, 0, angleToPulseSG90(0));       delay(1000);

  // 임시 무게 설정
  float weight = 3;
  Serial.println(weight);
  delay(5000);

  // 무게가 특정 값 이상일 때 모터 제어
  if (weight >= 2 && weight <= 3) {

    // 1번째 물품 분류기
    pca9685.setPWM(7, 0, angleToPulseMG996R(30));     delay(500);
    pca9685.setPWM(7, 0, angleToPulseMG996R(5));      delay(5000);

    // 로봇팔 (1단계)
    pca9685.setPWM(4, 0, angleToPulseSG90(65));       delay(1000);
    pca9685.setPWM(2, 0, angleToPulseMG996R(0));      delay(1000);
    pca9685.setPWM(2, 0, angleToPulseMG996R(90));     delay(1000);
    pca9685.setPWM(3, 0, angleToPulseMG996R(90));     delay(1000);
    pca9685.setPWM(5, 0, angleToPulseSG90(0));        delay(1000);
    pca9685.setPWM(5, 0, angleToPulseSG90(60));       delay(1000);

    delay(3000);

    // 로봇팔 (2단계)
    pca9685.setPWM(3, 0, angleToPulseSG90(60));       delay(1000);
    pca9685.setPWM(2, 0, angleToPulseMG996R(0));      delay(1000);
    pca9685.setPWM(3, 0, angleToPulseMG996R(83));     delay(1000);
    pca9685.setPWM(4, 0, angleToPulseSG90(80));       delay(1000);
    pca9685.setPWM(5, 0, angleToPulseSG90(0));        delay(1000);
    pca9685.setPWM(3, 0, angleToPulseSG90(60));        delay(2000);
    pca9685.setPWM(4, 0, 0); // 4번 모터 연결 끊기
    pca9685.setPWM(5, 0, 0); // 5번 모터 연결 끊기

    // 1번 물품 분류기 닫기
    pca9685.setPWM(1, 0, angleToPulseMG996R(30));     delay(500);
    pca9685.setPWM(7, 0, angleToPulseMG996R(30));     delay(500);
  }
  
  if(weight >= 5 && weight <= 6){
    // 1번째 물품 분류기 열기
        pca9685.setPWM(7, 0, angleToPulseMG996R(90));     delay(500);

    // 2번째 물품 분류기
    pca9685.setPWM(1, 0, angleToPulseMG996R(30));     delay(500);
    pca9685.setPWM(1, 0, angleToPulseMG996R(5));      delay(5000);

    // 로봇팔 (1단계)
    pca9685.setPWM(4, 0, angleToPulseSG90(65));       delay(1000);
    pca9685.setPWM(2, 0, angleToPulseMG996R(0));      delay(1000);
    pca9685.setPWM(2, 0, angleToPulseMG996R(90));     delay(1000);
    pca9685.setPWM(3, 0, angleToPulseMG996R(90));     delay(1000);
    pca9685.setPWM(5, 0, angleToPulseSG90(0));        delay(1000);
    pca9685.setPWM(5, 0, angleToPulseSG90(60));       delay(1000);

    delay(3000);

    // 로봇팔 (2단계)
    pca9685.setPWM(3, 0, angleToPulseSG90(60));       delay(1000);
    pca9685.setPWM(2, 0, angleToPulseMG996R(0));      delay(1000);
    pca9685.setPWM(3, 0, angleToPulseMG996R(83));     delay(1000);
    pca9685.setPWM(4, 0, angleToPulseSG90(80));       delay(1000);
    pca9685.setPWM(5, 0, angleToPulseSG90(0));        delay(1000);
    pca9685.setPWM(3, 0, angleToPulseSG90(60));        delay(2000);
    pca9685.setPWM(4, 0, 0); // 4번 모터 연결 끊기
    pca9685.setPWM(5, 0, 0); // 5번 모터 연결 끊기

    // 2번 물품 분류기 되돌아오기
    pca9685.setPWM(1, 0, angleToPulseMG996R(30));     delay(500);
    pca9685.setPWM(7, 0, angleToPulseMG996R(30));     delay(500);
  }
  delay(500); // 무게를 주기적으로 확인 (500ms)
}
