#define outputA1 2
#define outputB1 7
#define outputA2 2
#define outputB2 7
const int pwm1 = 11;
const int enable_pin1 = 3 ;
const int in_1 = 8;
const int pwm2 = 11;
const int enable_pin2 = 3 ;
const int in_2 = 8;
int ppr;
int counter1=0;
int counter2=0;
int aState1;
int aLastState1;
int aState2;
int aLastState2;
float angle;
void setup() {
  pinMode(pwm1, OUTPUT) ;
  pinMode(enable_pin1, OUTPUT) ;
  pinMode(in_1, OUTPUT) ;

  pinMode (outputA1, INPUT);
  pinMode (outputB1, INPUT);
  pinMode(pwm2, OUTPUT) ;
  pinMode(enable_pin2, OUTPUT) ;
  pinMode(in_2, OUTPUT) ;

  pinMode (outputA2, INPUT);
  pinMode (outputB2, INPUT);

  Serial.begin (115200);
  // Reads the initial state of the outputA
  aLastState1 = digitalRead(outputA1);
  aLastState1 = digitalRead(outputA2);
}

int counter(int aState,int aLastState,int outputA,int outputB,int count){
  
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
  // If the previous and the current state of the outputA are different, that means a Pulse has occured
  if (aState != aLastState) {
    // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
    if (digitalRead(outputB) != aState) {
      count ++;
    } else {
      count --;
    }
  }
  aLastState = aState; // Updates the previous state of the outputA with the current state
  return count;
}
void loop() {
  analogWrite(pwm1, 100) ;
  digitalWrite(in_1, LOW) ;
  digitalWrite(enable_pin1, HIGH) ;
  analogWrite(pwm2, 100) ;
  digitalWrite(in_2, LOW) ;
  digitalWrite(enable_pin2, HIGH) ;
  Serial.println("Encoder 1: ");
  Serial.print(counter(aState1,aLastState1,outputA1, outputB1,counter1));
  Serial.print("  Encoder 2: ");
  Serial.print(counter(aState2,aLastState2,outputA2, outputB2,counter2));
  
}
