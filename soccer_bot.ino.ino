//Motor pin declare
int r_motor1 = 7;
int r_motor2 = 8;
int l_motor1 = 3;              //backward wheels
int l_motor2 = 4;

int value = 255;   // value set to maximum
char temp = 'g';   //temp value to kill commands
int val = 200;

void setup() {
  //setting motor output
  pinMode(r_motor1, OUTPUT);
  pinMode(r_motor2, OUTPUT);
  pinMode(l_motor1, OUTPUT);
  pinMode(l_motor2, OUTPUT);
  // Begins serial communication
  Serial.begin(9600);
}


void loop() {

  if (temp == 'n') {
    analogWrite(r_motor1, value);
    analogWrite(r_motor2, 0);
    analogWrite(l_motor1, val);
    analogWrite(l_motor2, 0);
  }
  if (Serial.available() > 0) {
    temp = Serial.read();
  }
    if (temp == 'g') {
      analogWrite(r_motor1, 0);
      analogWrite(r_motor2, 0);
      analogWrite(l_motor1, 0);
      analogWrite(l_motor2, 0);
    }
    if (temp == 'f') {   // Forward
      analogWrite(r_motor1, value);
      analogWrite(r_motor2, 0);
      analogWrite(l_motor1, val);
      analogWrite(l_motor2, 0);
    }
    if (temp == 'b') {  // Back
      analogWrite(r_motor1, 0);
      analogWrite(r_motor2, value);
      analogWrite(l_motor1, 0);
      analogWrite(l_motor2, val);
    }

    if (temp == 'r') {
      analogWrite(r_motor1, 0);
      analogWrite(r_motor2, value);
      analogWrite(l_motor1, val);
      analogWrite(l_motor2, 0);
    }

    if (temp == 'l') {
      analogWrite(r_motor1, value);
      analogWrite(r_motor2, 0);
      analogWrite(l_motor1, 0);
      analogWrite(l_motor2, val);
    }
}
