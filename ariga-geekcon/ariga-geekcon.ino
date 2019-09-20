#include <Servo.h> // TODO: replace

boolean DEBUG = false;

int MOTOR_PIN = A2; // TODO
int ENDSTOPS_PINS[2] = { 3, 4 };
int TARGET_PIN = 2;
boolean headed_to_motor = true;
Servo motor; // TODO: replace
int currServoAngle = 90; // TODO


void roll(boolean toMotor = true) {

  if (DEBUG == true) {
    Serial.print("rolling to motor? ");
    Serial.println(toMotor);
  }

  boolean hit_endpoint = false;
  int timeout = 1000;

  currServoAngle = 90;
  motor.write(currServoAngle);

  while (hit_endpoint == false && timeout > 0 && currServoAngle>=0 && currServoAngle<180) {
    timeout--;
    if (DEBUG == true) {
      Serial.println("ROLL");
    }
    hit_endpoint = digitalRead(ENDSTOPS_PINS[0]) == HIGH || digitalRead(ENDSTOPS_PINS[1]) == HIGH; // messy
    if (DEBUG == true) {
      if (hit_endpoint)
        Serial.print("HIT ");
        Serial.print((digitalRead(ENDSTOPS_PINS[0])==HIGH ? "yes " : "no "));
        Serial.print((digitalRead(ENDSTOPS_PINS[1])==HIGH ? "yes " : "no "));
        Serial.println("");
        delay(200);
    }

    if (toMotor)
      currServoAngle++;
    else
      currServoAngle--;
    motor.write(currServoAngle); 
    delay(30); // FOR DEBUG
  }
  
  if (DEBUG == true) {
    Serial.print("finished rolling. hit endpoint?");
    Serial.print((hit_endpoint) ? "yes" : "no");
    Serial.print(" timeout");
    Serial.print(timeout);
    Serial.println("");
  }


}

boolean was_target_hit() {
  if (DEBUG == true) {
    Serial.print("was_target_hit output: ");
    Serial.println((digitalRead(TARGET_PIN)==HIGH) ? "true" : "false");
  }

  //return digitalRead(TARGET_PIN);
  if (digitalRead(TARGET_PIN) == HIGH)
    return true;
  else
    return false;
}

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  for (int i=0; i<2; i++) 
    pinMode(ENDSTOPS_PINS[i], INPUT);
  pinMode(TARGET_PIN, INPUT);

  if (DEBUG == true) {
     Serial.begin(9600);
  }

  motor.attach(MOTOR_PIN); // TODO: replace
  motor.write(0);
  delay(200);
  motor.write(90);
  delay(200);
}

void loop() {

  if (was_target_hit() == false) {
    
    return;
  }

  // TARGET WAS HIT
  if (DEBUG == true) {
    Serial.print("hit. was headed to motor? ");
    Serial.println(headed_to_motor);
  }

  headed_to_motor = !headed_to_motor;
  roll(headed_to_motor);

  //delay(500);
  

  
  
}
