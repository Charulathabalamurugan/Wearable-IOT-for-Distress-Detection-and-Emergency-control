#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

static const int RXPin = 2, TXPin = 3;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);
#define sw  5
String LatLng = "";

//================================= LOCATION GET FUNCTION ============================//
void displayInfo()
{
  if (gps.location.isValid())
  {
    LatLng = String(gps.location.lat(), 6);
    LatLng += ",";
    LatLng += String(gps.location.lng(), 6);
    Serial.println("Location: " + LatLng);
    delay(500);
  }
}

//==================================== FLASH SMS FUNCTION ============================//
void Alert_sms(String Phone_Number)
{
  Serial.println("\n\rFLASH SMS SENDING.....");
  Serial.println();
  Serial.println("AT");
  delay(500);

  Serial.println("AT+CSMP=17,167,0,240");  // Modified for flash SMS
  delay(500);

  Serial.println("AT+CMGF=1");
  delay(500);

  Serial.print("AT+CMGS=");
  Serial.write('"');
  Serial.print(Phone_Number);
  Serial.write('"');
  Serial.println();
  delay(500);

  Serial.print("Emergency alert BUZZER!!! \r\n");
  Serial.println();
  Serial.print("http://maps.google.com/maps?q=loc:     ");
  Serial.print(LatLng);
  delay(500);

  Serial.println();
  Serial.write(26);  // End of message
  delay(2000);
  Serial.println("\n\rFLASH SMS SUCCESSFULLY DELIVERED !!!");
}

//================================= SEND LOCATION TO SERVER FUNCTION ============================//
void SendLocationToServer(String LatLng) {
  Serial.println("AT+CSQ");  // Check signal strength
  delay(500);

  Serial.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\""); // Set connection type to GPRS
  delay(500);

  Serial.println("AT+SAPBR=3,1,\"APN\",\"airtelgprs.com\"");  // Set APN, replace with your APN
  delay(500);

  Serial.println("AT+SAPBR=1,1");  // Open bearer
  delay(500);

  Serial.println("AT+HTTPINIT");  // Initialize HTTP service
  delay(500);

  Serial.println("AT+HTTPPARA=\"CID\",1");  // Set CID parameter
  delay(500);

  // Set the server URL (replace "localhost" with your actual domain/IP)
  Serial.print("AT+HTTPPARA=\"URL\",\"http://localhost/location.php?latlng=");
  Serial.print(LatLng);
  Serial.println("\"");
  delay(500);

  Serial.println("AT+HTTPACTION=0");  // Start HTTP GET session
  delay(5000);  // Wait for the server's response

  Serial.println("AT+HTTPREAD");  // Read the response from the server
  delay(1000);

  Serial.println("AT+HTTPTERM");  // Terminate HTTP service
  delay(500);

  Serial.println("AT+SAPBR=0,1");  // Close bearer
  delay(500);
}

//================================= SEND MISSED CALL FUNCTION ============================//
void MissedCall(String Phone_Number)
{
  Serial.println("\n\rINITIATING MISSED CALL.....");
  Serial.println();

  // Send AT command to dial the number
  Serial.print("ATD");
  Serial.print(Phone_Number);
  Serial.println(";");  // Semicolon makes it a voice call
  delay(500);

  // Wait for a while before hanging up
  Serial.println("Waiting for call to connect...");
  delay(10000);  // Wait for 10 seconds

  // Send AT command to hang up
  Serial.println("Hanging up...");
  Serial.println("ATH");  // Hang up the call
  delay(500);

  Serial.println("\n\rMISSED CALL SENT SUCCESSFULLY !!!");
}

//================================= POWER UP ONE TIME RUN MAIN FUNCTION ============================//
void setup()
{
  Serial.begin(9600);
  ss.begin(GPSBaud);
  pinMode(sw, INPUT_PULLUP);
  Serial.println("ok");
  delay(500);
}

//================================= MAIN LOOP FUNCTION ============================//
void loop()
{
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

  if (digitalRead(sw) == 0)
  {
    Alert_sms("6379060112");
    delay(500);
    Alert_sms("6380079121");
    delay(500);

    // Send location to the server
    SendLocationToServer(LatLng);

    // Send a missed call
    MissedCall("91+6380079121");
  }
}
