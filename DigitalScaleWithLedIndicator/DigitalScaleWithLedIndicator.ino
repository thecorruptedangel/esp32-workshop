#define TRIG_PIN 5  
#define ECHO_PIN 18 

#define RED_LED_PIN 2   
#define YELLOW_LED_PIN 4 
#define GREEN_LED_PIN 16 

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
}

void loop() {
  long duration;
  int distance;

  // Clear the TrigPin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Set the TrigPin on HIGH state for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the EchoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

 
  if (distance < 10) {
    digitalWrite(RED_LED_PIN, HIGH);   
    digitalWrite(YELLOW_LED_PIN, LOW); 
    digitalWrite(GREEN_LED_PIN, LOW);  
  } else if (distance >= 10 && distance < 20) {
    digitalWrite(RED_LED_PIN, LOW);    
    digitalWrite(YELLOW_LED_PIN, HIGH); 
    digitalWrite(GREEN_LED_PIN, LOW);  
  } else {
    digitalWrite(RED_LED_PIN, LOW);    
    digitalWrite(YELLOW_LED_PIN, LOW); 
    digitalWrite(GREEN_LED_PIN, HIGH); 
  }

  delay(100); 
}
