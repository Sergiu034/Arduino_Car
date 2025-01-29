int mr1 = 8;   // Motor right 1
int mr2 = 9;   // Motor right 2
int ml1 = 10;  // Motor left 1
int ml2 = 11;  // Motor left 2
int sr = 6;    // Sensor right
int sl = 7;    // Sensor left
int svr = 0;   // Sensor value for right
int svl = 0;   // Sensor value for left
int led = 13;
int enr = 3;
int enl = 5;

int vspeed = 100; // Speed for forward/backward
int tspeed = 255; // Speed for turning
int tdelay = 20;  // Delay for turning

void setup() {
  pinMode(mr1, OUTPUT);
  pinMode(mr2, OUTPUT);
  pinMode(ml1, OUTPUT);
  pinMode(ml2, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(sr, INPUT);
  pinMode(sl, INPUT);

  Serial.begin(9600);
  delay(5000); // Startup delay
}

void loop() {
  // Read sensor values
  svr = digitalRead(sr); // Right sensor
  svl = digitalRead(sl); // Left sensor

  // Debugging: Print sensor values
  Serial.print("svr: ");
  Serial.print(svr);
  Serial.print(" | svl: ");
  Serial.println(svl);

  // Adjust movement based on sensor readings
  if (svl == LOW && svr == LOW) {
    forward();  // Both sensors detect the line
  } else if (svl == HIGH && svr == LOW) {
    right();    // Left sensor off the line, turn right
  } else if (svl == LOW && svr == HIGH) {
    left();     // Right sensor off the line, turn left
  } else if (svl == HIGH && svr == HIGH) {
    stop();     // Both sensors off the line, stop
  }
}

void forward() {
  Serial.println("Moving Forward");
  digitalWrite(mr1, HIGH);
  digitalWrite(mr2, LOW);
  digitalWrite(ml1, HIGH);
  digitalWrite(ml2, LOW);
  analogWrite(enr, vspeed);
  analogWrite(enl, vspeed);
}

void backward() {
  Serial.println("Moving Backward");
  digitalWrite(mr1, LOW);
  digitalWrite(mr2, HIGH);
  digitalWrite(ml1, LOW);
  digitalWrite(ml2, HIGH);
  analogWrite(enr, vspeed);
  analogWrite(enl, vspeed);
}

void right() {
  Serial.println("Turning Right");
  digitalWrite(mr1, LOW);  // Stop the right motor
  digitalWrite(mr2, HIGH); // Reverse the right motor
  digitalWrite(ml1, HIGH); // Move the left motor forward
  digitalWrite(ml2, LOW);  // Stop reversing the left motor
  analogWrite(enr, tspeed);
  analogWrite(enl, tspeed);
  delay(tdelay);
}

void left() {
  Serial.println("Turning Left");
  digitalWrite(mr1, HIGH); // Move the right motor forward
  digitalWrite(mr2, LOW);  // Stop reversing the right motor
  digitalWrite(ml1, LOW);  // Stop the left motor
  digitalWrite(ml2, HIGH); // Reverse the left motor
  analogWrite(enr, tspeed);
  analogWrite(enl, tspeed);
  delay(tdelay);
}

void stop() {
  Serial.println("Stopping");
  digitalWrite(mr1, LOW); // Stop right motor
  digitalWrite(mr2, LOW); // Stop right motor
  digitalWrite(ml1, LOW); // Stop left motor
  digitalWrite(ml2, LOW); // Stop left motor
  analogWrite(enr, 0);    // Ensure no PWM signal
  analogWrite(enl, 0);    // Ensure no PWM signal
}
