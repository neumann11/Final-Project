#include <IRremote.h>

const int rec = 2; 
const int led = 8;   
IRrecv irrecv(rec);
decode_results results;

bool ledState = false; 

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);  
  Serial.begin(9600);
  irrecv.enableIRIn();  
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 4294967295) {  
      toggleLED();
      delay(250);  
    }
    irrecv.resume(); 
  }
}

void toggleLED() {
  ledState = !ledState; 
  if (ledState) {
    digitalWrite(led, HIGH); 
    Serial.println("LED ON");     
  } 
  else {
    digitalWrite(led, LOW);   
    Serial.println("LED OFF");    
  }

}

