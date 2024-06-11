#include<Servo.h> //Servo 라이브러리를 추가
Servo servo;      //Servo 클래스로 servo객체 생성
int value = 0;    // 각도를 조절할 변수 value

void setup() {
  servo.attach(7);  // 핀 연결
  // Serial.begin(9600); // 시리얼 모니터 사용
}

void loop() {
    value = 0;
    servo.write(value); //value값의 각도로 회전. ex) value가 90이라면 90도 회전
    delay(500);

    value = 45;
    servo.write(value);
    delay(500);

    value = 90;
    servo.write(value);
    delay(500);

    value = 135;
    servo.write(value);
    delay(500);

    value = 179;
    servo.write(value);
    delay(500);
}