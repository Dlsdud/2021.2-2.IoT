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
int state = 0;      //state라는 정수형 변수 정의

void blink_LED() {  //blink_LED() 함수 정의

  if(state==0){   //state가 0일 경우
    digitalWrite(RED_PIN, LOW);   //RED_PIN을 끔
    digitalWrite(BLUE_PIN, HIGH); //BLUE_PIN을 킴
    delay(1000);      // delay 1초
    state = 1;        // state를 1로
  } else if(state==1) { //state가 1일 경우
    digitalWrite(BLUE_PIN, LOW); //BLUE_PIN을 끔
    digitalWrite(RED_PIN, HIGH); //RED_PIN을 킴
    delay(1000);      // delay 1초
    state= 0;         // state를 0으로
  }
}

void setup() {  //사용할 함수들을 선언하는 곳(설정)
  pinMode(BLUE_PIN, OUTPUT);   //BLUE_PIN의 상태를 출력(output)으로 설정
  pinMode(RED_PIN, OUTPUT);    //RED_PIN의 상태를 출력(output)으로 설정
  Serial.begin(115200); //Serial통신을 시작하겠다는 뜻(1초에 115200비트를 보냄)
}



void loop() { //선언한 변수들을 어떻게 사용할 것인지 정해놓는 곳
  blink_LED();  //blink_LED함수 선언
}
