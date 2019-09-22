

boolean DEBUG = false;

int MOTOR_DIR_PINS[2] = {5, 6};
int MOTOR_SPEED_PIN = 8;
int MOTOR_SPEED = 255;
int MOTOR_ENABLE_PIN = A6;

int ENDSTOPS_PINS[2] = { 9, 10 };

int TARGET_PIN = 12;

boolean headed_to_motor = true;

/* FUNCTIONS */

void roll(boolean toMotor = true) {

  if (DEBUG == true) {
    Serial.print("rolling to motor? ");
    Serial.println(toMotor);
  }

  boolean hit_endpoint = false;
  int timeout = millis() + 30*1000;

  // Move while we want to
  while (hit_endpoint == false && millis() < timeout) {
    timeout--;

    if (DEBUG == true) {
      Serial.println("ROLL");
    }
    
    //hit_endpoint = digitalRead(ENDSTOPS_PINS[0]) == HIGH || digitalRead(ENDSTOPS_PINS[1]) == HIGH; // messy
    hit_endpoint = (digitalRead(ENDSTOPS_PINS[1]) == HIGH && toMotor == true) || (digitalRead(ENDSTOPS_PINS[0]) == HIGH && toMotor == false);
    
    if (DEBUG == true) {
      if (hit_endpoint)
        Serial.print("HIT ");
        Serial.print((digitalRead(ENDSTOPS_PINS[0])==HIGH ? "yes " : "no "));
        Serial.print((digitalRead(ENDSTOPS_PINS[1])==HIGH ? "yes " : "no "));
        Serial.println("");
    }
    
    delay(200);

    // move
    if (toMotor) {
      // TODO: guessing direction. Could be other way.
      digitalWrite(MOTOR_DIR_PINS[0], HIGH);
      digitalWrite(MOTOR_DIR_PINS[1], LOW);
    }
    else {
      digitalWrite(MOTOR_DIR_PINS[0], LOW);
      digitalWrite(MOTOR_DIR_PINS[1], HIGH);
    }
    // Finished step, continue while loop
  } // end while running

  digitalWrite(MOTOR_DIR_PINS[0], LOW);
  digitalWrite(MOTOR_DIR_PINS[1], LOW);
  
  
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

  for (int i=0; i<2; i++)
    pinMode(ENDSTOPS_PINS[i], INPUT);

  for (int i=0; i<2; i++)
    pinMode(MOTOR_DIR_PINS[i], OUTPUT);
  pinMode(MOTOR_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_ENABLE_PIN, OUTPUT);
  digitalWrite(MOTOR_ENABLE_PIN, HIGH);
    
  pinMode(TARGET_PIN, INPUT);

  if (DEBUG == true) {
     Serial.begin(9600);
  }
  
  analogWrite(MOTOR_SPEED_PIN, MOTOR_SPEED);

  // Home the loom frame
  roll(true);
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
  
  
}
