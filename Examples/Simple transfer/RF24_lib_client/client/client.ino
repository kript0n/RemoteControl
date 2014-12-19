#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <ClientRemoteControl.h>


ClientRemoteControl* client_role;

void setup() {

  Serial.begin(57600);
  client_role = new ClientRemoteControl();
  
}


void loop() {
  
  client_role->read();
  
  if(client_role->isRead()) {
    
    QuadroInfo info = client_role->getQuadroInfo();
    
    Serial.print("Gyro: ");
    Serial.println(info.gyro);
    
    Serial.print("Accel: ");
    Serial.println(info.accel);
  
  }
  
  
  if(client_role->sendFlyCommand(1, 2, 3, 4)) {
    
    Serial.println("Sent");
  
  }

  delay(20);
  
  
}
