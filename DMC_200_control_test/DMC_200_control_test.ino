#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);   //RX, TX

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.flush();

  Serial.println("Start");
  PORTB = 0x00;
  DDRB = 0xFF;



  Serial.println("Setting");

  // 공장 초기화
  sbi(PORTB,PB5);
  _delay_ms(10);
  mySerial.write(0xFF);
  mySerial.write(0xFE);
  mySerial.write(0xFF);
  mySerial.write(0x02);
  mySerial.write(0xF1);
  mySerial.write(0x0D);
  mySerial.flush();
  cbi(PORTB,PB5);
  _delay_ms(10);


  // 분해능 설정
//  sbi(PORTB,PB5);
//  _delay_ms(10);
//  mySerial.write(0xFF);
//  mySerial.write(0xFE);
//  mySerial.write(byte(0x00));
//  mySerial.write(0x04);
//  mySerial.write(0xE4);
//  mySerial.write(0x0A);
//  mySerial.write(byte(0x00));
//  mySerial.write(0x0D);
//  mySerial.flush();
//  cbi(PORTB,PB5);
//  _delay_ms(10);


  // 감속비 설정
//  sbi(PORTB,PB5);
//  _delay_ms(10);
//  mySerial.write(0xFF);
//  mySerial.write(0xFE);
//  mySerial.write(byte(0x00));
//  mySerial.write(0x04);
//  mySerial.write(0x8C);
//  mySerial.write(0x0B);
//  mySerial.write(byte(0x00));
//  mySerial.write(0x64);
//  mySerial.flush();
//  cbi(PORTB,PB5);
//  _delay_ms(10);
  
  // 위치 제어 모드 설정
  sbi(PORTB,PB5);
  _delay_ms(10);
  mySerial.write(0xFF);
  mySerial.write(0xFE);
  mySerial.write(byte(0x00));
  mySerial.write(0x03);
  mySerial.write(0xEE);
  mySerial.write(0x0D);
  mySerial.write(byte(0x01));
  mySerial.flush();
  cbi(PORTB,PB5);
  _delay_ms(10);

  // 제어 방향 설정
//  sbi(PORTB,PB5);
//  _delay_ms(10);
//  mySerial.write(0xFF);
//  mySerial.write(0xFE);
//  mySerial.write(byte(0x00));
//  mySerial.write(0x03);
//  mySerial.write(0xEC);
//  mySerial.write(0x0F);
//  mySerial.write(byte(0x01));
//  mySerial.flush();
//  cbi(PORTB,PB5);
//  _delay_ms(1000);

  // 위치 제어기 설정
//  sbi(PORTB,PB5);
//  _delay_ms(10);
//  mySerial.write(0xFF);
//  mySerial.write(0xFE);
//  mySerial.write(byte(0x00));
//  mySerial.write(0x06);
//  mySerial.write(0xAB);
//  mySerial.write(0x04);
//  mySerial.write(0xFE);
//  mySerial.write(0xFE);
//  mySerial.write(0xFE);
//  mySerial.write(0x50);
//  mySerial.flush();
//  cbi(PORTB,PB5);
//  _delay_ms(10);

//  // 제어 On
  sbi(PORTB,PB5);
  _delay_ms(10);
  mySerial.write(0xFF);
  mySerial.write(0xFE);
  mySerial.write(byte(0x00));
  mySerial.write(0x03);
  mySerial.write(0xF0);
  mySerial.write(0x0C);
  mySerial.write(byte(0x00));
  mySerial.flush();
  cbi(PORTB,PB5);
  _delay_ms(10);


  // 위치 속도 제어
  sbi(PORTB,PB5);
  _delay_ms(10);
  mySerial.write(0xFF);
  mySerial.write(0xFE);
  mySerial.write(byte(0x00));
  mySerial.write(0x07);
  mySerial.write(0x76);
  mySerial.write(byte(0x01));
  mySerial.write(byte(0x00));
  mySerial.write(0x46);
  mySerial.write(0x50);
  mySerial.write(0x03);
  mySerial.write(0xE8);
  mySerial.flush();
  cbi(PORTB,PB5);
  _delay_ms(1000);

  Serial.println("End");
}

void loop() {
  // put your main code here, to run repeatedly:

}
