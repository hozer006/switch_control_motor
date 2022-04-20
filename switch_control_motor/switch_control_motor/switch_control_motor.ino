/*

 How To per pin
 
- Joystick 
    GND -> GND
    +5V -> 5V (ต่อ 3V ไฟจะไม่พอ)
    VRX -> A0
    VRY -> A1
    SW  ->  7

- Step Motor
    IN1 ->  8
    IN2 ->  9
    IN3 ->  10
    IN4 ->  11

- LED
    - LED 1 - 4 -> Resistor -> LED 1 - 4
    + LED1 -> 2
    + LED2 -> 3
    + LED3 -> 4
    + LED4 -> 4 
    
*/

//Joystick 
int X = A0;
int XValue = 0;
int Y = A1;
int YValue = 0;
int SW = 7;
int SWValue = 0;

//Stepper Motor
int motorPin1 = 8; // Blue
int motorPin2 = 9; // Pink
int motorPin3 = 10; // Yellow
int motorPin4 = 11; // Orange
int motorSpeed;

//LED
int LEDPin1 = 2;
int LEDPin2 = 3;
int LEDPin3 = 4;
int LEDPin4 = 5;


void setup() {
  
  //motor OUTPUT Electricity 
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  //LED OUTPUT Electricity 
  pinMode(LEDPin1, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
  pinMode(LEDPin3, OUTPUT);
  pinMode(LEDPin4, OUTPUT);

  //Joystick SW INPUT Digital 1
  pinMode(SW, INPUT_PULLUP);

  //Set LED Electricity = 0
  digitalWrite(LEDPin1, LOW);
  digitalWrite(LEDPin2, LOW);
  digitalWrite(LEDPin3, LOW);
  digitalWrite(LEDPin4, LOW);

  Serial.begin(9600);
  // --------------- //

}

void loop() {

  //Set Joystick Readanalog range 0 - 1023
  XValue = analogRead(X);
  YValue = analogRead(Y);
  SWValue = analogRead(SWValue);


  //Motor ซ้าย--ขวา
  Serial.println(XValue);
  Serial.println(YValue);
  if (YValue >= 1000 and (XValue > 450 and  XValue < 700)) {
    motorSpeed = 0;
    while (true) {
      counterclockwise();
      motorSpeed++;
      if (motorSpeed == 102) {
        break;
      }
    }

  } else if (YValue <= 50 and (XValue > 450 and  XValue < 700)) {
     while (true) {
      clockwise();
      if (analogRead(X) < 50 and analogRead(Y) >1000) {
        break;
      }
    }
  }

  // MOtor ขี้น-ลง
  if (XValue >= 1000 and (YValue > 450 and  YValue < 600)) {
    digitalWrite(LEDPin1, HIGH);
    digitalWrite(LEDPin2, LOW);
    
  } else if (XValue  <= 50 and (YValue > 450 and  YValue < 600)) {
while (true) {
      counterclockwise();
      if (analogRead(X) < 50 and analogRead(Y) >1000) {
        break;
      }
    }
    
  }

//Motor เอียงซ้าย -- ขวา
if (analogRead(X) < 50 and analogRead(Y) < 50) {
    motorSpeed = 0;
    while (true) {
      clockwise();
      motorSpeed++;
      if (motorSpeed == 102) {
        break;
      }
    }
  } else if (analogRead(X) > 1000 and analogRead(Y) > 1000) {
     digitalWrite(LEDPin1, LOW);
     digitalWrite(LEDPin2, LOW);
  }else if(digitalRead(SW) == 0){
    digitalWrite(LEDPin2, HIGH);
    digitalWrite(LEDPin1, LOW);
  }
}


//function step motor
void counterclockwise() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW) ;
  digitalWrite(motorPin3, LOW) ;
  digitalWrite(motorPin4, HIGH) ;
  delay(10);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW) ;
  digitalWrite(motorPin3, HIGH) ;
  digitalWrite(motorPin4, LOW) ;
  delay(10);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH) ;
  digitalWrite(motorPin3, LOW) ;
  digitalWrite(motorPin4, LOW) ;
  delay(10);

  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW) ;
  digitalWrite(motorPin3, LOW) ;
  digitalWrite(motorPin4, LOW) ;
  delay (10);
}

void clockwise() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW) ;
  digitalWrite(motorPin3, LOW) ;
  digitalWrite(motorPin4, LOW) ;
  delay(10);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH) ;
  digitalWrite(motorPin3, LOW) ;
  digitalWrite(motorPin4, LOW) ;
  delay(10);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW) ;
  digitalWrite(motorPin3, HIGH) ;
  digitalWrite(motorPin4, LOW) ;
  delay(10);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW) ;
  digitalWrite(motorPin3, LOW) ;
  digitalWrite(motorPin4, HIGH) ;
  delay (10);
}
