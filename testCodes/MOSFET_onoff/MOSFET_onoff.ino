#define s 10

void setup() {
  // put your setup code here, to run once:
pinMode(s,OUTPUT);
}
int s1; //...based on some condition(s)
void loop() {
  if(s1==0){
  digitalWrite(s,LOW);
    }
if(s1==1){
  digitalWrite(s,HIGH);
  }
  else
  {
    Serial.println("Exception..");
   }
}
