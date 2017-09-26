//nRF24L01 - MSP430 Launchpad
//3 CE   - P2.0:
//4 CSN  - P2.1:
//5 SCK  - P1.5:
//6 MOSi - P1.7:
//7 MISO - P1.6:
//8 IRQ  - P2.2:
//
//
// 	                               +-\/-+
// 	                        VCC   1|    |20  GND
// 	                 RELAY1 P1.0  2|    |19  XIN
// 	         ESP8266 UART   P1.1  3|    |18  XOUT
// 	         ESP8266 UART   P1.2  4|    |17  TEST
// 	                 BUTTON P1.3  5|    |16  RST#
// 	                 RELAY2 P1.4  6|    |15  P1.7 MOSI  6
// 	                 5  SCK P1.5  7|    |14  P1.6 MISO  7
// 	                 3   CE P2.0  8|    |13  P2.5 RELAY3
// 	   	 	 4  CSN P2.1  9|    |12  P2.4 RELAY4
//		         8  IRQ P2.2 10|    |11  P2.3 BUZZER
// 			               +----+
//
//

#include "Energia.h"


void setup();
void loop();
void dump_radio_status_to_serialport(uint8_t status);
void ps_out();


#include "Enrf24.h"
#include "nRF24L01.h"
#include <string.h>
#include <SPI.h>

#define relay1 P1_0
#define relay2 P1_4
#define relay3 P2_5
#define relay4 P2_4
#define buzzer P2_3

Enrf24 radio(P2_0, P2_1, P2_2);
const uint8_t rxaddr[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0x01 };

const char *str_sens1 = "SENS1";
const char *str_sens2 = "SENS2";
const char *str_sens3 = "SENS3";
const char *str_sens4 = "SENS4";
const char *str_sens5 = "SENS5";


void dump_radio_status_to_serialport(uint8_t);

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);


  pinMode(PUSH2, INPUT_PULLUP); //Enable internal pullup
  attachInterrupt(PUSH2, ps_out, RISING);
  Serial.begin(9600);

  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);

  radio.begin();  // Defaults 1Mbps, channel 0, max TX power
  radio.setChannel (95);
  //radio.setSpeed(speed);
  dump_radio_status_to_serialport(radio.radioState());

  radio.setRXaddress((void*)rxaddr);

  radio.enableRX();  // Start listening

}

void ps_out(){
	digitalWrite(relay1, HIGH);
	digitalWrite(relay2, HIGH);
	digitalWrite(relay3, HIGH);
	digitalWrite(relay4, HIGH);
}

void loop() {
  char inbuf[33];
  
  dump_radio_status_to_serialport(radio.radioState());  // Should show Receive Mode

  while (!radio.available(true))
    ;
  if (radio.read(inbuf)) {
    Serial.print("RXIN<");
    Serial.print(inbuf);
    Serial.println(">");

    if (strcmp(inbuf, str_sens1) == 0){
      digitalWrite(relay1, LOW);
    }

    if (strcmp(inbuf, str_sens2) == 0){
      digitalWrite(relay2, LOW);
    }

    if (strcmp(inbuf, str_sens3) == 0){
      digitalWrite(relay3, LOW);
    }

    if (strcmp(inbuf, str_sens4) == 0){
      digitalWrite(relay4, LOW);
    }
  }
}

void dump_radio_status_to_serialport(uint8_t status)
{
  Serial.print("STATE<");
  switch (status) {
    case ENRF24_STATE_NOTPRESENT:
      Serial.println("NO TRX>");
      break;

    case ENRF24_STATE_DEEPSLEEP:
      Serial.println("LP>");
      break;

    case ENRF24_STATE_IDLE:
      Serial.println("IDLE>");
      break;

    case ENRF24_STATE_PTX:
      Serial.println("TX>");
      break;

    case ENRF24_STATE_PRX:
      Serial.println("RX>");
      break;

    default:
      Serial.println("UN>");
  }
}


