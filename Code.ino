#define RCPin_Thrust 3
#define RCPin_Button 2
#define LEDSW 4

int ena = 5;
int motor1pin1 = 6;
int motor1pin2 = 7;
int brake1 = 9;
int brake2 = 10;
int head = 11;
int head2 = A2;

int RCValue_Thrust;
int RCValue_Button;
int RCValue_Light;
int speed = 0;

void setup() {
  Serial.begin(9600);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(RCPin_Thrust, INPUT);
  pinMode(RCPin_Button, INPUT);
  pinMode(LEDSW, INPUT);
  pinMode(ena, OUTPUT);

  pinMode(brake1, OUTPUT);
  pinMode(brake2, OUTPUT);
  pinMode(head, OUTPUT);

}
void loop() {
  RCValue_Thrust = pulseIn(RCPin_Thrust, HIGH);
  RCValue_Button = pulseIn(RCPin_Button, HIGH);
  RCValue_Light = pulseIn(LEDSW, HIGH);
  Serial.println(RCValue_Button);
  Serial.println(RCValue_Thrust);
  Serial.println(RCValue_Light);
  if (RCValue_Thrust >= 1110 && RCValue_Button < 1000) { // Forward
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    speed = map(RCValue_Thrust, 1100, 1918, 0, 255);
    analogWrite(ena, speed);
    Serial.println(speed);
} else if (RCValue_Thrust >= 1110 && RCValue_Button > 2000 ) { // Reverse
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    speed = map(RCValue_Thrust, 1918, 1100, 255, 0); 
    analogWrite(ena, speed); 
    Serial.println(speed);
} else {
    analogWrite(ena, 0); // No movement
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    Serial.println(speed);
}

if (RCValue_Light < 2000){
  digitalWrite(brake1, HIGH);
  digitalWrite(brake2, HIGH);
  digitalWrite(head, HIGH);
  analogWrite(head2, 255);
}
else if (RCValue_Light > 1500) {
  digitalWrite(brake1, LOW);
  digitalWrite(brake2, LOW);
  digitalWrite(head, LOW);
  analogWrite(head2, 0);
  }
}