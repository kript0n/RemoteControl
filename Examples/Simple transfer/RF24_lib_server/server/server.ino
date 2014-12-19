#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <ServerRemoteControl.h>


ServerRemoteControl* server_role;

void setup() {

  Serial.begin(57600);
  server_role = new ServerRemoteControl();
  
}


void loop() {
  
  server_role->read();
  
  if(server_role->isRead()) {
   
     QuadroCommand command = server_role->getFlyCommand();
     
     Serial.print("Pitch: ");
     Serial.println(command.pitch);
     
     Serial.print("Yaw: ");
     Serial.println(command.yaw);
     
     Serial.print("Roll: ");
     Serial.println(command.roll);
 
     Serial.print("Power: ");
     Serial.println(command.power);    
  }
  
  
  
  if(server_role->sendQuadroInfo(5, 6)) {
    Serial.println("Sent");
  }
  
  delay(20);

}
