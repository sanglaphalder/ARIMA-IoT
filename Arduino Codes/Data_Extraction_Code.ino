// Pin Definitions
const int motorEnable = 9;   
const int motorIn1 = 8;      
const int motorIn2 = 7;      
const int tempPin = A0;      
const int trigPin = 12;      
const int echoPin = 11;      

void setup() {
  Serial.begin(9600); // Standard baud rate for data logging
  
  pinMode(motorEnable, OUTPUT);
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // 1. Operational State: Constant Forward Speed
  digitalWrite(motorIn1, HIGH);
  digitalWrite(motorIn2, LOW);
  analogWrite(motorEnable, 255); 
  
  // 2. Data Acquisition
  float temperature = getTemperature();
  long swayDistance = getSwayDistance();
  int currentSpeed = 255; // Logged as a feature for the ML model
  
  // 3. CSV Data Stream Output
  // Format: Temperature,Sway,Speed
  Serial.print(temperature);
  Serial.print(",");
  Serial.print(swayDistance);
  Serial.print(",");
  Serial.println(currentSpeed);
  
  delay(200); // 5 data points per second: Great balance for simulation speed
}

// --- CALIBRATION FUNCTIONS ---

float getTemperature() {
  int raw = analogRead(tempPin);
  float voltage = raw * (5.0 / 1024.0);
  return (voltage - 0.5) * 100; // Result in Celsius
}

long getSwayDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return (duration * 0.034) / 2; // Result in Centimeters
}