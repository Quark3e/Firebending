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
        Serial.println(analogSoundVal);
        delay(500);
        digitalWrite(led1, HIGH);
        for (pos = 92; pos <= 130; pos+=1) {
            myservo.write(pos);
            delay(10);
        }

        delay(700);

        for (int i=0; i<=35; i++) {
            digitalWrite(relay, HIGH);
            delay(10);
        }

        digitalWrite(relay, LOW);

        int analogSoundVal = analogRead(sound_sensor);
        analogRead(sound_sensor);
        Serial.println(analogSoundVal);

        for ( 0; analogSoundVal < max_SoundThresh; analogRead(sound_sensor)) {
            
            int analogSoundVal = analogRead(sound_sensor);
            analogRead(sound_sensor);
            
            int buttonValue = digitalRead(buttonPin);
            if (analogSoundVal >= max_SoundThresh) {
              Serial.println(analogSoundVal);
            }
            if (analogSoundVal >= max_SoundThresh) {
                break;
            }
        }
        delay(700);
        for (int i=0; i<=35; i++) {
            digitalWrite(relay, HIGH);
            delay(10);
        }
        digitalWrite(relay, LOW);

        delay(4000);
        for (pos = 130; pos >= 92; pos-=1) {
            myservo.write(pos);
            delay(10);
        }
        digitalWrite(led1, LOW);

    }

}

