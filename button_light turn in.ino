
//Completed Lab with Rino David & Nolan Visitacion 
//CPE 301 Lab 1
//2 - 2 - 23

// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(9600); // sets up the serial port, 9600 is the baud rate. The speed at which a signal can travel
  Serial.println("Hello from the Serial monitor!");
  pinMode(4, OUTPUT); // Output is the macro
  pinMode(2, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  char input = digitalRead(2);
  if(input == HIGH){
    digitalWrite(4,HIGH);
    Serial.println("Button has been pressed");
    delay(1000);
  }else{
    digitalWrite(4,LOW);
  }

  char serialInput = Serial.read(); //asking for input

  if(serialInput == 'a'){ 
    
   
    digitalWrite(4,HIGH);
    delay(1000);
    digitalWrite(4,LOW);
  
  }else if(serialInput == 'b'){
    Serial.println(serialInput);
  }
  
}
