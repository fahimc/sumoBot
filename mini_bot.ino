#include <NewPing.h>
#include <AFMotor.h>

#define TRIG_PIN A3 // Pin A4 on the Motor Drive Shield soldered to the ultrasonic sensor
#define ECHO_PIN A2 // Pin A5 on the Motor Drive Shield soldered to the ultrasonic sensor
#define MAX_DISTANCE 200 // sets maximum useable sensor measuring distance to 200cm

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); // sets up sensor library to use the correct pins to measure distance.
AF_DCMotor leftWheel(3);
AF_DCMotor rightWheel(4);

void setup()
{
  Serial.begin(9600);
  leftWheel.setSpeed(200);
  rightWheel.setSpeed(200);
}


void loop()
{
  if(isObject()){
     moveForward();    
  }else{
    stopMoving();
  }

  delay(70);
  
}


int getDistance() { // read the ultrasonic sensor distance
  delay(70);
  unsigned int uS = sonar.ping();
  int cm = uS/US_ROUNDTRIP_CM;
  return cm;
}

boolean isObject(){
  int value = getDistance();
  Serial.println(value);
  if(value < 10)
  {
    return true;
  }
  return false;
}

void moveForward(){
  leftWheel.run(FORWARD);
  rightWheel.run(FORWARD);
}
void moveBackward(){
  leftWheel.run(BACKWARD);
  rightWheel.run(BACKWARD);
}
void moveForwardLeft(){
  rightWheel.run(RELEASE);
  leftWheel.run(FORWARD);
}
void moveForwardRight(){
  leftWheel.run(RELEASE);
  rightWheel.run(FORWARD);
}
void moveBackwardLeft(){
  rightWheel.run(RELEASE);
  leftWheel.run(BACKWARD);
}
void moveBackwardRight(){
  leftWheel.run(RELEASE);
  rightWheel.run(BACKWARD);
}
void stopMoving(){
  leftWheel.run(RELEASE);
  rightWheel.run(RELEASE);
}



