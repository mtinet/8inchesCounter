// 1개의 SN74HC595N 시프트 레지스터와 1개의 7segment를 이용해 1~9까지 반복적으로 보여주는 예제  

// 핀 설정  
int dataPin = 4;
int latchPin = 5;
int clockPin = 6;

// 1~9까지의 숫자 표현  
byte dec_digits[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111100, 0b00000111, 0b01111111, 0b01100111 };

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for (int numberToDisplay = 0; numberToDisplay < 10; numberToDisplay++) {
    // take the latchPin low so
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW); // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[numberToDisplay]);
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH); // pause before next value:
    delay(1000);
  }
}
