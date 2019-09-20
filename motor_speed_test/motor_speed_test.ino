// Check what we want to send through PWM as speed

int SPEED_PIN = 8;
int DIR_PINS[2] = {5, 6};
int ENABLE_PIN = A6;

void setup() {
  pinMode(SPEED_PIN, OUTPUT);
  Serial.begin(9600);

  // motor enable
  pinMode(ENABLE_PIN, OUTPUT);
  digitalWrite(ENABLE_PIN, HIGH);
}

void loop() {
  // Write high & low into pins. Direction arbitrary
  digitalWrite(DIR_PINS[0], HIGH);
  digitalWrite(DIR_PINS[1], LOW);


  analogWrite(SPEED_PIN, 255);
  return;
  for (int speed=0; speed<=255; speed+=5) {
    Serial.print("Speed: ");
    Serial.println(speed);

    analogWrite(SPEED_PIN, speed);
    delay(500);
  }
}
