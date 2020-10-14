#include <Servo.h>

Servo myservo;

int sound_sensor = A0; 
int led1 = 13;
int solenoid = 11;
int relay = 9;
int flame = 2;
int pos = 0;
int flame_sensor = A2; // variable to store the value coming from the sensor
int buttonPin = 12;
int buttonIgniter = 0;

const int max_SoundThresh = 481;
const int min_SoundThresh = 503;
const int FlameThresh = 1050;

                                 
void setup()
{
  Serial.begin(115200);
 
  
  pinMode(led1, OUTPUT);
  pinMode(solenoid, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(flame, INPUT);
  pinMode(flame_sensor, INPUT);
  pinMode(sound_sensor, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  myservo.attach(10); //need to check this one again if it's possible to write it in a different way
}



void loop()
{
    int analogSoundVal = analogRead(sound_sensor);
    analogRead(sound_sensor);
    
    if (analogSoundVal >= max_SoundThresh) {
      if (analogSoundVal <= min_SoundThresh) {

        delay(500);
  
        digitalWrite(led1, HIGH);

        for (pos = 92; pos <= 130; pos+=1) { //92 degrees is the home position of the servo (for me atleast)
        myservo.write(pos);
        delay(10);
        }

        delay(700);

        for (int i=0; i<=35; i++) { //time period where the relay is closed/in-contact
          digitalWrite(relay, HIGH);
          delay(10);
        }

        digitalWrite(relay, LOW);

        int analogFlameVal = analogRead(flame_sensor);
        analogRead(flame_sensor);

        delay(1500);
    
        for (pos = 130; pos >= 92; pos-=1) { //turn servo motor back //closing butane valve
        myservo.write(pos);
        delay(10);
        }
        digitalWrite(led1, LOW);
        delay(1000);
        }
        
        // separate activation method ----------------------------------------------------------------------------------------
        
        int buttonValue = digitalRead(buttonPin);
        if (buttonValue == LOW) {
          FireButton(buttonIgniter);
        }
        
    }



  digitalRead(buttonPin);

  }

  void FireButton(int buttonIgniter) {
    int buttonValue = digitalRead(buttonPin);
    for (pos = 92; pos <= 10; pos +=1) {
      myservo.write(pos);
      delay(10);
    }
    delay(100);
    for (int i=0; i<=49; i++) {
      digitalWrite(relay, HIGH);
      delay(5);
    }
    digitalWrite(relay, LOW);
    for (buttonValue = 0; buttonValue == 0; digitalRead(buttonPin)) {
      digitalRead(buttonPin);
      int buttonValue = digitalRead(buttonPin);
      Serial.println(digitalRead(buttonValue));
      if (buttonValue == 1) {
        break;
      }
    }
    for (pos = 130; pos >=92; pos-=1) {
      myservo.write(pos);
      delay(10);
    }
  }
  

  