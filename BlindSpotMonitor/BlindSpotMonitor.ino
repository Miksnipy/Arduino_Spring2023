
//progrmer: Roman Cleary
//Date: 3.22.23
//program: blind spot monitor

int trigPin = 7;
int echoPin = 6;
int LEDlampBlue =11;
int LEDlampWhite = 9;
int LEDlampRed = 10; 
int soundbuzzer = 3;
int sound  = 500;


void setup()  {
  Serial.begin (9600);
  pinMode(trigPin,  OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampBlue, OUTPUT);
  pinMode(LEDlampWhite,  OUTPUT);
  pinMode(LEDlampRed, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
}
void  loop()  { 
  long durationindigit, distanceinft;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceinft = (durationindigit/5) / 29.1;

 if (distanceinft >10){
  Serial.println("We have not detected any car in your blind spot- Change Lanes when needed."); 
 }


 if (distanceinft <= 10 && distanceinft >=7){
  digitalWrite(LEDlampBlue, HIGH);
  Serial.println("there is another car within");
  Serial.print(distanceinft);
  Serial.println(" feet from your Blind spot \nGetting close - change lanes with caution");
 }
 else {
  digitalWrite(LEDlampBlue, LOW);
 }


  
  delay(1000);
}
