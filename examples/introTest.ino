// 1개의 SN74HC595N 시프트 레지스터와 1개의 7segment를 이용해 intro를 반복적으로 보여주는 예제  

int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
int outputEnablePin = 3;
 
byte leds = 0;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT); 
  pinMode(clockPin, OUTPUT);
  pinMode(outputEnablePin, OUTPUT); 
}
 
void loop() 
{
  setBrightness(255);
  leds = 0;
  updateShiftRegister();
  delay(500);
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister();
    delay(100);
  } 

}
 
void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}
 
void setBrightness(byte brightness) // 0 to 255
{
  analogWrite(outputEnablePin, 255-brightness);
}
