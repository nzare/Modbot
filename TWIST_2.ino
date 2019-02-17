#define outputA1 23
#define outputB1 22
#define outputA2 21
#define outputB2 20
#define outputA3 19
#define outputB3 18
#define outputA4 15
#define outputB4 14


const int pwm1 = 3;
const int enable_pin1 = 0 ;
const int in_1 = 2;
const int pwm2 = 4;
const int enable_pin2 = 5 ;
const int in_2 = 1;
const int pwm3 = 9;
const int enable_pin3 = 11 ;
const int in_3 = 6;
const int pwm4 = 10;
const int enable_pin4 = 12 ;
const int in_4 = 7;

int counter1=0;
int counter2=0;
int counter3=0;
int counter4=0;

void count1(){
  counter1++;
  Serial.println("Ëncoder1: ");
  Serial.println(counter1);
  
}

void Twist(int angle, int rspeed){
  int max_count = angle*50;
  while(counter1 < max_count){
    analogWrite(pwm1, rspeed) ;
    digitalWrite(in_1, LOW) ;
    digitalWrite(enable_pin1, HIGH) ;
    analogWrite(pwm2, rspeed) ;
    digitalWrite(in_2, LOW) ;
    digitalWrite(enable_pin2, HIGH) ;
    analogWrite(pwm3, rspeed) ;
    digitalWrite(in_3, LOW) ;
    digitalWrite(enable_pin3, HIGH) ;
    analogWrite(pwm4, rspeed) ;
    digitalWrite(in_4, LOW) ;
    digitalWrite(enable_pin4, HIGH) ;
  }
  analogWrite(pwm1, LOW) ;
  digitalWrite(in_1, LOW) ;
  digitalWrite(enable_pin1, LOW) ;
  analogWrite(pwm2, LOW) ;
  digitalWrite(in_2, LOW) ;
  digitalWrite(enable_pin2, LOW) ;
  analogWrite(pwm3, LOW) ;
  digitalWrite(in_3, LOW) ;
  digitalWrite(enable_pin3, LOW) ;
  analogWrite(pwm4, LOW) ;
  digitalWrite(in_4, LOW) ;
  digitalWrite(enable_pin4, LOW) ;
  delay(2000);
  counter1 =0;
}

void setup() {
  // put your setup code here, to run once:
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

  pinMode(pwm3, OUTPUT) ;
  pinMode(enable_pin3, OUTPUT) ;
  pinMode(in_3, OUTPUT) ;

  pinMode (outputA3, INPUT);
  pinMode (outputB3, INPUT);
  pinMode(pwm4, OUTPUT) ;
  pinMode(enable_pin4, OUTPUT) ;
  pinMode(in_4, OUTPUT) ;

  pinMode (outputA4, INPUT);
  pinMode (outputB4, INPUT);

  attachInterrupt(digitalPinToInterrupt(outputA1), count1, CHANGE);
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Twist(45, 100);
  
}
