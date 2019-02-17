// set the pin that will control the valve
int ValvePin = 8;

void setup() {
   // set the digital pin as output:
 pinMode(ValvePin, OUTPUT);    
 
 // start the pin on LOW
 digitalWrite(ValvePin, LOW);  
}

void loop(){

digitalWrite(ValvePin, LOW);

delay(5000);

digitalWrite(ValvePin, HIGH);


delay(5000);
}
