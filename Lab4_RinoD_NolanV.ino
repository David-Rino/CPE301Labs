// CPE 301 Lab 4
//Written By Rino D. & Nolan V.

//Port Definitions
volatile unsigned char* port_b = (unsigned char*) 0x25;
volatile unsigned char* ddr_b = (unsigned char*) 0x24;
volatile unsigned char* pin_b = (unsigned char*) 0x23;

volatile unsigned char *myTCCR1A = (unsigned char *) 0x80;
volatile unsigned char *myTCCR1B = (unsigned char *) 0x81;
volatile unsigned char *myTCCR1C = (unsigned char *) 0x82;
volatile unsigned char *myTIMSK1 = (unsigned char *) 0x6F;
volatile unsigned int  *myTCNT1  = (unsigned  int *) 0x84;
volatile unsigned char *myTIFR1 =  (unsigned char *) 0x36;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setPinOutput('b', 6);
  *myTCCR1A = 0;
  *myTCCR1B = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
    unsigned char in_char = Serial.read();

    switch(in_char) {
      case '1': 
      //Note A 440 Hz
        writePin('b', 6, 1);
        my_delay(440);
        writePin('b', 6, 0);
        my_delay(440);
        break;
      case '2': 
      //Note B 494 Hz
        writePin('b', 6, 1);
        my_delay(494);
        writePin('b', 6, 0);
        my_delay(494);
        break;
      case '3': 
      //Note C 523 Hz
        writePin('b', 6, 1);
        my_delay(523);
        writePin('b', 6, 0);
        my_delay(523);
        break;
      case '4': 
      //Note D 587 Hz
        writePin('b', 6, 1);
        my_delay(587);
        writePin('b', 6, 0);
        my_delay(587);
        break;
      case '5': 
      //Note E 659 Hz
        writePin('b', 6, 1);
        my_delay(659);
        writePin('b', 6, 0);
        my_delay(659);
        break;
      case '6': 
      //Note F 698 Hz
        writePin('b', 6, 1);
        my_delay(698);
        writePin('b', 6, 0);
        my_delay(698);
        break;
      case '7': 
      //Note G 784 Hz
        writePin('b', 6, 1);
        my_delay(784);
        writePin('b', 6, 0);
        my_delay(784);
        break;
    }

  
}

void setPinOutput(char pin, unsigned char pin_num) {
  if(pin == 'b') {
    *ddr_b |= 0x01 << pin_num;
  }
}

void setPinInput(char pin, unsigned char pin_num) {
  if(pin == 'b') {
    *ddr_b &= 0x01 << pin_num;
  }
}

void writePin(char pin, unsigned char pin_num, unsigned char state) {
  if(pin == 'b') {
    if(state == 0) {
      *port_b &= ~(0x01 << pin_num);
    } else {
      *port_b |= 0x01 << pin_num;
    }
  }
}

void my_delay(unsigned int freq)
{
  // calc period
  double period = 1.0/double(freq);
  // 50% duty cycle
  double half_period = period/ 2.0f;
  // clock period def
  double clk_period = 0.0000000625;
  // calc ticks
  unsigned int ticks = half_period / clk_period;


  // stop the timer
  *myTCCR1B &= 0xF8;
  // set the counts
  *myTCNT1 = (unsigned int) (65536 - ticks);
  // start the timer
  * myTCCR1B |= 0b00000001;
  // wait for overflow
  while((*myTIFR1 & 0x01)==0); // 0b 0000 0000
  // stop the timer
  *myTCCR1B &= 0xF8;   // 0b 0000 0000
  // reset TOV           
  *myTIFR1 |= 0x01;
}