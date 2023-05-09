// CPE 301 - REGISTER-LEVEL PART 5
// Written By Rino D. & Nolan V.


//Port Definitions 
volatile unsigned char* port_k = (unsigned char*) 0x108;
volatile unsigned char* ddr_k = (unsigned char*) 0x107;
volatile unsigned char* pin_k = (unsigned char*) 0x106;

volatile unsigned char* port_e = (unsigned char*) 0x2E;
volatile unsigned char* ddr_e = (unsigned char*) 0x2D;
volatile unsigned char* pin_e = (unsigned char*) 0x2C;

volatile unsigned char* port_d = (unsigned char*) 0x2B;
volatile unsigned char* ddr_d = (unsigned char*) 0x2A;
volatile unsigned char* pin_d = (unsigned char*) 0x29;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  setPinInput('k', 2);
  setPinOutput('d', 0);
  setPinOutput('e', 3);

}

void loop() {
  // put your main code here, to run repeatedly:

  //if pin k2 is high
  if(*pin_k & 0x4) {
    Serial.println("PIN K 2 Is High");
    writePin('d', 0, 1);
    writePin('e', 3, 0);
  } else {
    Serial.println("PIN K 2 Is Low");
    writePin('d', 0, 0);
    writePin('e', 3, 1);   
  }
}

void setPinOutput(char pin, unsigned char pin_num) {
  if(pin == 'k') {
    *ddr_k |= 0x01 << pin_num;
  } else if (pin == 'e') {
    *ddr_e |= 0x01 << pin_num;
  } else if (pin == 'd') {
    *ddr_d |= 0x01 << pin_num;
  }
}

void setPinInput(char pin, unsigned char pin_num) {
  if(pin == 'k') {
    *ddr_k &= 0x01 << pin_num;
  } else if (pin == 'e') {
    *ddr_e &= 0x01 << pin_num;
  } else if (pin == 'd') {
    *ddr_d &= 0x01 << pin_num;
  }
}

void writePin(char pin, unsigned char pin_num, unsigned char state) {
  if(pin == 'k') {
    if(state == 0) {
      *port_k &= ~(0x01 << pin_num);
    } else {
      *port_k |= 0x01 << pin_num;
    }
  } else if (pin == 'e') {
    if(state == 0) {
      *port_e &= ~(0x01 << pin_num);
    } else {
      *port_e |= 0x01 << pin_num;
    }
  } else if (pin == 'd') {
    if(state == 0) {
      *port_d &= ~(0x01 << pin_num);
    } else {
      *port_d |= 0x01 << pin_num;
    }
  }
}


