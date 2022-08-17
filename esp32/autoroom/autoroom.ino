//Use board firebeattle at 115200 speed

//we include the sensor library
#include "DHT.h"

//we define the sensor input pin
#define DHTPIN 4 

//define the type of sensor
#define DHTTYPE DHT11 


DHT dht(DHTPIN, DHTTYPE);

//we include the libraries to connect to the API
#include <WiFi.h>
#include <HTTPClient.h>



#include "Lydia.h"
//#include "Haya.h"
//#include "LUCIA.h"
#include "settings.h"



unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

void setup()
{
  // Start the Serial Monitor
  Serial.begin(115200);
  // Start the DHT11 sensor
  dht.begin();
// start connection wifi
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

}

void loop()
{
  if ((millis() - lastTime) > timerDelay)
  {
    // Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED)
    {

      //we start reading the data
      int humidity = dht.readHumidity();
      // Read temperature as Celsius (the default)
      int temperature = dht.readTemperature();
      // Read temperature as Fahrenheit (isFahrenheit = true)
      int f = dht.readTemperature(true);


      WiFiClient client;
      HTTPClient http;

      // Your Domain name with URL path or IP address with path
      http.begin(client, serverName);


       char json[100];

//      

          snprintf(json,sizeof(json), "{\"api_key\":%d, \"room_id\":%d, \"room_name\":%d, \"temperature\":%d, \"humidity\":%d}",api_key,room_id,room_name,temperature,humidity);

       Serial.println(json);


      //SEND THE DATA METHOD JSON
      
      http.addHeader("Content-Type", "application/json");
      int httpResponseCode = http.POST(json);
        

      // TO VIEW THE SERVER RESPONSE CODE
      
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);

      http.end();
    }
    else
    {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}
