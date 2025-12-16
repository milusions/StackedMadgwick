#include <IMU.h>
#include <StackedMadgwick.h>



long mdwkLogTimer = millis(); // print timer state variable

long mdwkLogDelay = 250; // print delay of 250ms


const float samplingFrequency = 1000.0; // Samples at 1000 Hz

IMU imu(samplingFrequency); // IMU object

StackedMadgwick stackedMadgwick(samplingFrequency); // Stacked Madgwick Object

void setup() {
  Serial.begin(9600); // intiating the serial connection

  imu.begin(); // intializing the imu

  imu.calibrate(); // calibrating the imu at startup

  stackedMadgwick.begin(); // initializing the stacked madgwick
}

void loop() {
  imu.update(); // refreshes imu data
  if (imu.isUpToDate()) { // checks if imu has the next data

    // Extracts the acceleration and gyroscopic values from the imu
    float accX = imu.getAccX();
    float accY = imu.getAccY();
    float accZ = imu.getAccZ();
    float gyroX = imu.getGyroX();
    float gyroY = imu.getGyroY();
    float gyroZ = imu.getGyroZ(); 

    /* Update the Raw IMU value to the library.
       It automatically implements filter flow for raw IMU data
       Flow: Raw Data -> Average Filter --> Low Pass Filter --> Moving Average Filter --> Filtered Value 
    */

    stackedMadgwick.updateIMU(gyroX, gyroY, gyroZ, accX, accY, accZ);

    /* Use update() function for 9 axis stacked madgwick filter
      stackedMadgwick.update(gyroX, gyroY, gyroZ, accX, accY, accZ, magX,magY,magZ);
    */
  }

  if (millis() - mdwkLogTimer > mdwkLogDelay) {
    
    // Extracting the roll, pitch and yaw from the Stacked Madgwick
    float roll = stackedMadgwick.getRoll();
    float pitch = stackedMadgwick.getPitch();
    float heading = stackedMadgwick.getYaw();

    // Prints roll, pitch and yaw to the console
    Serial.print("R/P/Y: ");
    Serial.print(roll);
    Serial.print(", ");
    Serial.print(pitch);
    Serial.print(", ");
    Serial.println(heading);

    mdwkLogTimer = millis();  // resets timer
  }
}