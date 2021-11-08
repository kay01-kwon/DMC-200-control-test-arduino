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

  // 16. 공장 초기화
//  sbi(PORTB,PB5);
//  mySerial.write(0xFF);
//  mySerial.write(0xFE);
//  mySerial.write(0xFF);
//  mySerial.write(0x02);
//  mySerial.write(0xF1);
//  mySerial.write(0x0D);
//  mySerial.flush();
//  cbi(PORTB,PB5);
//  _delay_ms(10);

  // 15. 위치 초기화
  sbi(PORTB,PB5);
  mySerial.write(0xFF);
  mySerial.write(0xFE);
  mySerial.write((byte)0x00);
  mySerial.write(0x02);
  mySerial.write(0xEE);
  mySerial.write(0x0F);
  mySerial.flush();
  cbi(PORTB,PB5);
  _delay_ms(10);


  sbi(PORTB,PB5);
  mySerial.write(0xFF);
  mySerial.write(0xFE);
  mySerial.write(byte(0x00));
  mySerial.write(0x02);
  mySerial.write(0x5B);
  mySerial.write(0xA2);
  mySerial.flush();
  cbi(PORTB,PB5);
  _delay_ms(10);
  
    while(mySerial.available())
  {
    byte c = mySerial.read();
    Serial.print(c,HEX);
    Serial.print(" ");
  }
  Serial.println();
  mySerial.flush();
  
  // 10. 분해능 설정
  sbi(PORTB,PB5);
  mySerial.write(0xFF);
  mySerial.write(0xFE);
  mySerial.write(byte(0x00));
  mySerial.write(0x04);
  mySerial.write(0xE1);
  mySerial.write(0x0A);
  mySerial.write(byte(0x00));
  mySerial.write(0x10);
  mySerial.flush();
  cbi(PORTB,PB5);
  _delay_ms(10);

//  // 11. 감속비 설정
  sbi(PORTB,PB5);
  mySerial.write(0xFF);
  mySerial.write(0xFE);
  mySerial.write(byte(0x00));
  mySerial.write(0x04);
  mySerial.write(0x31);
  mySerial.write(0x0B);
  mySerial.write(byte(0x00));
  mySerial.write(0xBF);
  mySerial.flush();
  cbi(PORTB,PB5);
  _delay_ms(10);

//  // 13.위치 제어 모드 설정
//  sbi(PORTB,PB5);
//  mySerial.write(0xFF);
//  mySerial.write(0xFE);
//  mySerial.write(byte(0x00));
//  mySerial.write(0x03);
//  mySerial.write(0xEF);
//  mySerial.write(0x0D);
//  mySerial.write(byte(0x00));
//  mySerial.flush();
//  cbi(PORTB,PB5);
//  _delay_ms(10);

//  // 4. 위치 제어기 설정
//  sbi(PORTB,PB5);
//  mySerial.write(0xFF);
//  mySerial.write(0xFE);
//  mySerial.write(byte(0x00));
//  mySerial.write(0x06);
//  mySerial.write(0xab);
//  mySerial.write(0x04);
//  mySerial.write(0xFE);
//  mySerial.write(0xFE);
//  mySerial.write(0xFE);
//  mySerial.write(0x50);
//  mySerial.flush();
//  cbi(PORTB,PB5);
//  _delay_ms(10);

  // 5. 속도 제어기 설정
  sbi(PORTB,PB5);
  mySerial.write(0xFF);
  mySerial.write(0xFE);
  mySerial.write(byte(0x00));
  mySerial.write(0x06);
  mySerial.write(0xaa);
  mySerial.write(0x05);
  mySerial.write(0xFE);
  mySerial.write(0xFE);
  mySerial.write(0xFE);
  mySerial.write(0x50);
  mySerial.flush();
  cbi(PORTB,PB5);
  _delay_ms(10);



// 12. 제어 On
  sbi(PORTB,PB5);
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

//  // 1. 위치 속도 제어
//  byte notchecksum = ~lowByte(byte(0x00) + 0x07 + 0x01 + byte(0x01) + byte(0x46) + byte(0x50) + 0x03 + 0xE8);
//  Serial.println(notchecksum,HEX);
//  sbi(PORTB,PB5);
//  mySerial.write((byte)0xFF);
//  mySerial.write((byte)0xFE);
//  mySerial.write((byte)0x00);
//  mySerial.write((byte)0x07);
//  mySerial.write(notchecksum);
//  mySerial.write((byte)0x01);
//  mySerial.write((byte)0x01);
//  mySerial.write((byte)0x46);
//  mySerial.write((byte)0x50);
//  mySerial.write((byte)0x03);
//  mySerial.write((byte)0xE8);
//  mySerial.flush();
//  cbi(PORTB,PB5);
//  _delay_ms(10);

//  byte notchecksum = ~lowByte(byte(0x00) + 0x07 + 0x01 + byte(0x00) + byte(0xff) + byte(0xfd) + 0x03 + 0xE8);
//  Serial.println(notchecksum,HEX);
//  sbi(PORTB,PB5);
//  mySerial.write((byte)0xFF);
//  mySerial.write((byte)0xFE);
//  mySerial.write((byte)0x00);
//  mySerial.write((byte)0x07);
//  mySerial.write(notchecksum);
//  mySerial.write((byte)0x01);
//  mySerial.write((byte)0x00);
//  mySerial.write((byte)0xff);
//  mySerial.write((byte)0xfd);
//  mySerial.write((byte)0x03);
//  mySerial.write((byte)0xE8);
//  mySerial.flush();
//  cbi(PORTB,PB5);

  byte notchecksum = ~lowByte(byte(0x00) + 0x06 + 0x03 + byte(0x00) + byte(0x00) + byte(0x64) + 0x14);
  Serial.println(notchecksum,HEX);
  sbi(PORTB,PB5);
  mySerial.write((byte)0xFF);
  mySerial.write((byte)0xFE);
  mySerial.write((byte)0x00);
  mySerial.write((byte)0x06);
  mySerial.write(notchecksum);
  mySerial.write((byte)0x03);
  mySerial.write((byte)0x00);
  mySerial.write((byte)0x00);
  mySerial.write((byte)0x64);
  mySerial.write((byte)0x14);
  mySerial.flush();
  cbi(PORTB,PB5);
  _delay_ms(10);

  
  sbi(PORTB,PB5);
  mySerial.write(0xFF);
  mySerial.write(0xFE);
  mySerial.write(byte(0x00));
  mySerial.write(0x02);
  mySerial.write(0x5B);
  mySerial.write(0xA2);
  mySerial.flush();
  cbi(PORTB,PB5);
  _delay_ms(10);
  
    while(mySerial.available())
  {
    byte c = mySerial.read();
    Serial.print(c,HEX);
    Serial.print(" ");
  }
  Serial.println();
  mySerial.flush();

  Serial.println("End");

}

void loop() {
//  // put your main code here, to run repeatedly:
  sbi(PORTB,PB5);
  mySerial.write(0xFF);
  mySerial.write(0xFE);
  mySerial.write(byte(0x00));
  mySerial.write(0x02);
  mySerial.write(0x5B);
  mySerial.write(0xA2);
  mySerial.flush();
  cbi(PORTB,PB5);
  _delay_ms(10);
  
    while(mySerial.available())
  {
    byte c = mySerial.read();
    Serial.print(c,HEX);
    Serial.print(" ");
  }
  Serial.println();
  mySerial.flush();
}
