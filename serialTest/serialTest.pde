
#include <NewSoftSerial.h>

NewSoftSerial mySerial(3, 2);

void setup()  
{
  Serial.begin(9600);
  
  // set the data rate for the NewSoftSerial port
  mySerial.begin(9600);
  mySerial.print("IPA");
  mySerial.print(13, BYTE);
 
}

void loop()                     // run over and over again
{
  int incoming = 0;
  if (Serial.available()) {
        incoming = Serial.read();
  }
  
  if (incoming =='1'){
    //Serial.println("printing to VDIP");
    Serial.print("DIR");
    Serial.print(13, BYTE);
    incoming = 0;
  }
  
  if (mySerial.available()) {
      Serial.print((char)mySerial.read());
  }
  
}
