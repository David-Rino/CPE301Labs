/****************************************
 * Name: Rino David & Nolan Visitacion
 * Assignment: Lab 2 Assignment
 * Date: 2 - 9 - 23
 ****************************************/

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("Hello from the Serial Monitor");

  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int buttonFirst = digitalRead(3);
  int buttonSecond = digitalRead(4);

    // DECODER BLOCK
  if(buttonSecond == LOW && buttonFirst == LOW){      // First starts on the right
    // write 0001 to the LED 
    digitalWrite(6, HIGH);
    Serial.println("Joe Okaasan said 0 has been lit");
    delay(1000);
    digitalWrite(8, LOW);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
    
  }else if(buttonSecond == LOW && buttonFirst == HIGH){
    // write 0010 to the LED 
    digitalWrite(8, HIGH);
    Serial.println("Joe Otoosan said 1 has been lit");
    delay(1000);
    digitalWrite(6, LOW);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
    
  }else if(buttonSecond == HIGH && buttonFirst == LOW){
    // write 0100 to the LED 
    digitalWrite(10, HIGH);
    Serial.println("Joe Neesan said 2 has been lit");
    delay(1000);
    digitalWrite(6, LOW);
    digitalWrite(8,LOW);
    digitalWrite(12,LOW);
    
  }else if(buttonSecond == HIGH && buttonFirst == HIGH){
    // write 1000 to the LED 
    digitalWrite(12, HIGH);
    Serial.println("Joe Niisan said 3 has been lit");
    delay(1000);
    digitalWrite(6, LOW);
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    
  } // end DECODER BLOCK
  
}
