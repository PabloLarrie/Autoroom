// Import libraries

#include "DHT.h" // librerie humidity and temperature sensor
#include <WiFi.h> // librarie to connect to API
#include <HTTPClient.h> // librarie to connect to API


// Define the libraries

#define DHTPIN 4 //we define the sensor input pin
#define DHTTYPE DHT11 //define the type of sensor

DHT dht(DHTPIN, DHTTYPE);

// definitions of external files

//#include "Lydia.h"
#include "Haya.h"
//#include "Lucia.h"
#include "Settings.h"




// Time esp32 is in sleep mode 
const uint32_t sleepTime = 4 * 1000000; // microsegconds = 4 seg
// Si queremos cada hora seria: 360

void setup() {
  Serial.begin(115200);
  // Start the DHT11 sensor
  dht.begin();
  //Start connection wifi
  WiFi.begin(ssid, password);

  Serial.println("\nDespertando y Conectando a la red WIFI...");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(250);
    Serial.print(".");
  }
  Serial.println("\nConectado a la Red WIFI!\n");
  Serial.print("Su IP es: ");
  Serial.println(WiFi.localIP());

  // Obtenemos info necesaria
  getData();

  // Entrando en deep sleep
  Serial.println("ESP entrando en deep sleep");
  Serial.flush();



esp_sleep_enable_timer_wakeup(sleepTime); 
esp_deep_sleep_start();


}

void loop() {
  // put your main code here, to run repeatedly:

}

void getData(){



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


       char json[300];

//      

          snprintf(json,sizeof(json), "{\"api_key\":%d, \"room_id\":%d, \"room_name\":\"%s\", \"temperature\":%d, \"humidity\":%d}",api_key,room_id,room_name,temperature,humidity);

       Serial.println(json);


      //SEND THE DATA METHOD JSON
      
      http.addHeader("Content-Type", "application/json");
      int httpResponseCode = http.POST(json);
        

      // TO VIEW THE SERVER RESPONSE CODE
      
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);

      http.end(); 
  } else {
    Serial.println("No connect");
  }
}
