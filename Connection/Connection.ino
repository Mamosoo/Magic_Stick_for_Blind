#include <SoftwareSerial.h>

int bluetoothTx =2;
int bluetoothRx =3;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
void setup()
{
  Serial.begin(9600);

  bluetooth.begin(9600);
  bluetooth.print("$");
  bluetooth.print("$");
  bluetooth.print("$");
  delay(100);
  bluetooth.println("U,9600,N");
  bluetooth.begin(9600);
 
}
void loop(){
  bluetooth.println(600);

  if(bluetooth.available())
  {
    Serial.print((char)bluetooth.read());
  }
  else if(Serial.available())
  {
   bluetooth.print((char)Serial.read());
  }
  else{
    Serial.println(0);
  }
  delay(100);
}
