
#include <PS4Controller.h>
int x = 0;
int X = 0; 
int Y = 0; 
int y = 0; 
int x1 = 0;
#define PIN_IN1  2 // ESP32 pin GPIO19 connected to the IN1 pin L298N
#define PIN_IN2  4 // ESP32 pin GPIO18 connected to the IN2 pin L298N
#define PIN_ENA  25 // ESP32 pin GPIO17 connected to the EN1 pin L298N
#define PIN_IN3  32 // ESP32 pin GPIO19 connected to the IN1 pin L298N
#define PIN_IN4  33 // ESP32 pin GPIO18 connected to the IN2 pin L298N
#define PIN_ENB  26 // ESP32 pin GPIO17 connected to the EN1 pin L298N
void setup() {
  Serial.begin(115200);

  // Replace the "1a:2b:3c:01:01:01" with the MAC address
  // the controller wants to pair to
  // Note: MAC address must be unicast
  PS4.begin("e8:9e:b4:9f:ef:7e");
  Serial.println("Ready.");
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
}

void loop() {
  digitalWrite(PIN_IN1, HIGH); // control the motor's direction in clockwise
  digitalWrite(PIN_IN2, LOW);  // control the motor's direction in clockwise
  if (PS4.isConnected()) {
    x = PS4.LStickY();
    y = PS4.RStickY();
    X = map(x, 0, 127, 0, 256); // переводим значение X в новый диапазон
    Y = map(y, 0, 127, 0, 256);
    analogWrite(PIN_ENA, X);
    analogWrite(PIN_ENB, Y);
 

    
    
    
    delay(15);
    
  }

  
}
