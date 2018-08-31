#include <hcsr04.h>

#include <DWRobot2WheelDC.h>
#include <DWRobotDCMotorL298N.h>

#define PIN_MOTOR_LEFT_BACKWARD  D3
#define PIN_MOTOR_LEFT_FORWARD   D2
#define PIN_MOTOR_LEFT_SPEED     D1
#define PIN_MOTOR_RIGHT_BACKWARD D4
#define PIN_MOTOR_RIGHT_FORWARD  D6
#define PIN_MOTOR_RIGHT_SPEED    D7

#define PIN_DIST_SENSOR_TRIGGER  D0
#define PIN_DIST_SENSOR_ECHOBACK D8

#define STATE_INITIAL          0
#define STATE_DO_FORWARD       1
#define STATE_DOING_FORWARD    2
#define STATE_DO_TURN          3
#define STATE_DOING_TURN       4
#define STATE_WAITING          5

int mode = STATE_INITIAL;

DWRobotDCMotorL298N motorLeft(PIN_MOTOR_LEFT_BACKWARD, PIN_MOTOR_LEFT_FORWARD, PIN_MOTOR_LEFT_SPEED);
DWRobotDCMotorL298N motorRight(PIN_MOTOR_RIGHT_BACKWARD, PIN_MOTOR_RIGHT_FORWARD, PIN_MOTOR_RIGHT_SPEED);
DWRobot2WheelDC robot(&motorLeft, &motorRight);

HCSR04 fwdDistance(PIN_DIST_SENSOR_TRIGGER, PIN_DIST_SENSOR_ECHOBACK, 20, 4000);

void setup() {
  Serial.begin(115200);
  robot.setup();
  delay(1000);
}

void loop() {
//  delay(200);
//  return;
  
  Serial.print("Mode:");
  Serial.println(mode);
  
  robot.loop();

  int fwdDistanceReading = fwdDistance.distanceInMillimeters();
  if (fwdDistanceReading == -1) {
    fwdDistanceReading = 4000;
  }
  Serial.print("Front distance:");
  Serial.println(fwdDistanceReading);

  if (mode == STATE_INITIAL) {
    mode = STATE_DO_FORWARD;
    Serial.println("STATE_INITIAL -> STATE_DO_FORWARD");
    
  } else if (mode == STATE_DO_FORWARD) {
    robot.forwardSpeed(1023);
    delay(200);
    robot.forwardSpeed(500);
    robot.forMilliseconds(10000);
    mode = STATE_DOING_FORWARD;
    Serial.println("STATE_DO_FORWARD -> STATE_DOING_FORWARD");
    
  } else if (mode == STATE_DOING_FORWARD) {
    if (robot.moveJustFinished()) {
      mode = STATE_DO_TURN;
      Serial.println("STATE_DOING_FORWARD -> STATE_DO_TURN");
    }
    if (fwdDistanceReading < 200) {
      Serial.println("FORWARD PROXIMITY **************************");
      mode = STATE_DO_TURN;
      Serial.println("STATE_DOING_FORWARD -> STATE_DO_TURN");
    }

  } else if (mode == STATE_DO_TURN) {
    delay(1000);
    robot.rightTurn(600);
    robot.forMilliseconds(2000);
    mode = STATE_DOING_TURN;
    Serial.println("STATE_DO_TURN -> STATE_DOING_TURN");
    
  } else if (mode == STATE_DOING_TURN) {
    if (fwdDistanceReading < 100) {
      Serial.println("TURN PROXIMITY **************************");
      robot.rightTurn(600);
      robot.forMilliseconds(2000);
    }
    if (robot.moveJustFinished()) {
      mode = STATE_DO_FORWARD;
      Serial.println("STATE_DOING_TURN -> STATE_DO_FORWARD");
    }

  } else {
    robot.stop();
  }

  delay(500);
}
