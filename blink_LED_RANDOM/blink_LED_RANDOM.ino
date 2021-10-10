/*
  ESP8266 Blink by Simon Peter
  Blink the blue LED on the ESP-01 module
  This example code is in the public domain

  The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)

  Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/

// #define PIN_NO 16 //D0

#define BLUE_PIN D1 //5 D1 LED 정의
#define RED_PIN D2  //4 D2 LED 정의

void setup() {  //사용할 함수들을 선언하는 곳(설정)
  pinMode(BLUE_PIN, OUTPUT);   //BLUE_PIN의 상태를 출력(output)으로 설정
  pinMode(RED_PIN, OUTPUT);    //RED_PIN의 상태를 출력(output)으로 설정
  Serial.begin(115200); //Serial통신을 시작하겠다는 뜻(1초에 115200비트를 보냄)
}

void blink_LED(int pinNo, int delayTime) {  //blink_LED함수 선언
  digitalWrite(pinNo, LOW); //pinNo의 LED를 LOW로
  delay(delayTime);         //delay를 입력받은(delayTIme)동안 진행
  digitalWrite(pinNo, HIGH);//pinNo의 LED를 HIGH로
  delay(delayTime);         //delay를 입력받은(delayTIme)동안 진행
}

void loop() { //선언한 변수들을 어떻게 사용할 것인지 정해놓는 곳
  int random_PIN = random(4, 6);  //4와 5를 랜덤으로 가져와 random_PIN이라는 정수형 변수에 저장
  Serial.println(random_PIN);   //시리얼모니터에 random_PIN값 출력  
  blink_LED(random_PIN, 1000);  //blink_LED함수 선언(random_PIN의 번호를 사용하며 딜레이를 1초 준다)
}
