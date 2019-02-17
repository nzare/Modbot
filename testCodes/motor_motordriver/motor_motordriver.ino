const int pwm  = 23;  
const int in_1 = 7 ;
const int in_2 = 20;
void setup()
{
pinMode(pwm,OUTPUT) ;   
pinMode(in_1,OUTPUT) ;  
pinMode(in_2,OUTPUT) ;
}

void loop()
{
//For Clock wise motion , in_1 = High , in_2 = Low

//digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,LOW) ;
analogWrite(pwm,100) ;

delay(300) ;     

//For brake
/*digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,HIGH) ;
delay(1000) ;

//For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
digitalWrite(in_1,LOW) ;
digitalWrite(in_2,HIGH) ;
delay(3000) ;

//For brake
digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,HIGH) ;
delay(1000) ; */
 }

                  
