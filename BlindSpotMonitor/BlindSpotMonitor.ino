
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


void setup() 
  Serial.begin (9600);
  pinMode(trigPin,  OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampRed, OUTPUT);
  pinMode(LEDlampWhite,  OUTPUT);
  pinMode(LEDlampBlue, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
}
void  loop() 
  long durationindigit, distanceincm;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit/5) / 29.1;
 
  if (distanceincm < 50) 
      digitalWrite(LEDlampBlue, HIGH);
}
  else       digitalWrite(LEDlampBlue,  LOW);
  }
  
  if (distance < 20) {
    digitalWrite(LEDlampWhite,  HIGH);
}
  else {
    digitalWrite(LEDlampWhite,LOW);
  }
  if (distance  < 5) {
   digitalWrite(LEDlampRed, HIGH);
    sound = 1000;
}
  else  {
    digitalWrite(LEDlampRed,LOW);
  }
 
  if (distanceincm > 5 ||  distanceinsm <= 0){
    Serial.println("Outside the permissible range of distances");
    noTone(soundbuzzer);
  }
  else {
    Serial.print(distance);
    Serial.println("  cm");
    tone(buzzer, sound);
  }
  
  delay(300);
}
