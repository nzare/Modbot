 #define outputA1 3
 #define outputB1 4
 #define outputA2 7
 #define outputB2 8
const int pwm1 = 22;  
const int pwm2 = 16;
const int in_1 = 23;
const int in_2 = 17;
int count1=0;
int count2=0;
 int aState;
 int aLastState;  
 int angle1=360;
 int angle2=360;
 int req_ticks1=(angle1*1605)/360;
 int req_ticks2=(angle2*1605)/360;
 int counter=0;
 int speed1=300;
 int speed2=300;
 int count(int outputA,int outputB){
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
   return counter;
  }
 void setup() { 
pinMode(pwm1,OUTPUT) ;     
pinMode(pwm2,OUTPUT) ;
pinMode(in_1,OUTPUT);
pinMode(in_2,OUTPUT);
pinMode (outputA1,INPUT);
pinMode (outputB1,INPUT);
pinMode (outputA2,INPUT);
pinMode (outputB2,INPUT);  
   Serial.begin (115200);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA1);   
      aLastState = digitalRead(outputA2);   
 } 
 void loop() { 
  //digitalWrite(enable_pin,HIGH) ;
digitalWrite(in_1,LOW) ;
digitalWrite(in_2,LOW) ;
analogWrite(pwm1,speed1) ;
analogWrite(pwm2,speed2) ;
count(outputA1,outputB1);
count(outputA2,outputB2);
/*  int c1=count(outputA1,outputB1);
   int c2=count(outputA2,outputB2);
   if(c1>req_ticks1 && req_ticks1>0){
   Serial.print("stop1");
    analogWrite(pwm1,0) ;
    c1=0;
     delay(2000);
    
    }
     if(c2>req_ticks2 && req_ticks2>0){
   Serial.print("stop2");
    analogWrite(pwm2,0) ;
    c2=0;
     delay(2000);
    
    }
    if(c1<req_ticks1 && req_ticks1<0){
   Serial.print("stop2");
    analogWrite(pwm1,0) ;
    c1=0;
     delay(2000);
    
    }
    if(c2<req_ticks2 && req_ticks2<0){
   Serial.print("stop2");
    analogWrite(pwm2,0) ;
    c2=0;
     delay(2000);
    
    } */
 }
