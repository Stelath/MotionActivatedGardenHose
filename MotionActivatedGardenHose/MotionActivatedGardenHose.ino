// Define the pins
#define relay 10
#define motionSensor 2

int motionSensorState = LOW; // By default, no motion detected
int val = 0;                 // Variable to store the sensor status (value)

void setup()
{
  pinMode(relay, OUTPUT);
  pinMode(motionSensor, INPUT);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(motionSensor);
  // If the motion sensor detected something
  if (val == HIGH && motionSensorState == LOW)
  {
    // Activate the Garden Hose and Declare "Motion Detected!"
    pinMode(relay, HIGH);
    Serial.println("Motion Detected!");
    motionSensorState = HIGH;
  }
  else if (motionSensorState == HIGH && val != HIGH)
  {
    // Deactivate the garden hose and Delcare "Motion Stopped!"
    pinMode(relay, LOW);
    Serial.println("Motion Stopped!");
    motionSensorState = LOW;
  }
}
