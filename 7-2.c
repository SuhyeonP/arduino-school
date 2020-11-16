#include <Servo.h> 			 // 서보모터 라이브러리 불러오기
Servo motor1; 			// 서보모터 이름 설정 
int servoMotorPin = 9;			// 서보 모터 신호핀 설정 
int potentioMeterPin = 0;		 // 포텐쇼미터 핀 설정 // 모터 각도 변수 설정
int motorAngle; int motorAngleOld;void setup() {
   motor1.attach(servoMotorPin,600,2400);	 // 서보모터 설정. 0.6ms 부터 2.4ms 범위로 설정
   Serial.begin(9600);			 // 시리얼 통신 설정  
}  
void loop(){
int potentioMeter = analogRead(potentioMeterPin);	 // 포텐쇼미터 값을 읽어옴 
motorAngle = map(potentioMeter,0,1023,0,180);		 // 포텐쇼미터 값을 모터 각도로 변환 
motor1.write(motorAngle);			 // 모터에 각도값을 전달
}
   // 이전각도와 현재 각도가 같지 않으면 시리얼 모니터에 각도를 출력한다.   
if(motorAngle != motorAngleOld){ 
Serial.print("Servo Motor Angle is: "); 
Serial.println(motorAngle);
}   // 현재의 모터 각도를 저장한다.
motorAngleOld = motorAngle;
delay(20);
}