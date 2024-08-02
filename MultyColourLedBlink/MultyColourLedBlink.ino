#define Blue 2 
#define Red 4
#define Green 16

void setup() {
  pinMode(Blue, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
}


void loop() {
  digitalWrite(Blue, HIGH); 
  delay(1000);                 
  digitalWrite(Blue, LOW);  
  delay(1000);   
  
  digitalWrite(Red, HIGH); 
  delay(1000);                 
  digitalWrite(Red, LOW);  
  delay(1000);
  
  digitalWrite(Green, HIGH); 
  delay(1000);                 
  digitalWrite(Green, LOW);  
  delay(1000);


  digitalWrite(Blue, HIGH); 
  digitalWrite(Red, HIGH);
  delay(1000);  
  digitalWrite(Blue, LOW); 
  digitalWrite(Red, LOW);
  delay(1000); 

  digitalWrite(Blue, HIGH);
  digitalWrite(Green, HIGH); 
  delay(1000);
  digitalWrite(Blue, LOW);
  digitalWrite(Green, LOW); 
  delay(1000);

  digitalWrite(Red, HIGH);
  digitalWrite(Green, HIGH); 
  delay(1000); 
  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW); 
  delay(1000);
  
}
