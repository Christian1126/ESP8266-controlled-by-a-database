//include libraries
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h> 

//Access point credentials
const char* ssid = "myccidfd6";
const char* pwd = "00027178DFD6";
const char* host = "";
String get_host = "";

WiFiServer server(80);  // open port 80 for server connection

void setup() 
{
  Serial.begin(115200); //initialise the serial communication
  delay(20);

  WiFi.begin(ssid, pwd);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println(WiFi.localIP());
  server.begin();
   
    //starting the server
    server.begin();

    pinMode(2, OUTPUT);
}

void loop()
{
  //call_test();
  get_device_status("tv","TV");
  get_device_status("fan","Fan");
 
}


void call_test()
{
  Serial.println("It is test");
  }

void get_device_status(String device_name, String device_text)
  {   
    
    WiFiClient client = server.available();

        HTTPClient http;
        String url = get_host+"/esp_running/get_status.php?device_name="+device_name;
        
        http.begin(url);
       
        //GET method
        int httpCode = http.GET();
        String payload = "";
        if (httpCode > 0) {
          payload = http.getString();
          //Serial.println("payload: " + payload);
        }
        else
        Serial.println("No response");

        //Serial.println("http code: " + String(httpCode));
        if(payload=="1")
        {
          Serial.println(device_text + " is ON");
          if (device_text == "TV") digitalWrite(2, LOW);
        }
        else 
        {
          Serial.println(device_text + " is Off");
          if (device_text == "TV") digitalWrite(2, HIGH); 
          }
        http.end();
        delay(1000);
  
  }
