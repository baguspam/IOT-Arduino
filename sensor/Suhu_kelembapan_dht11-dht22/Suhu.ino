// include external method
#include <DHT.h>       // getting beegee library for DHT

// constant definition
#define DHT_PIN 4       // location of DHT out pin
#define DHT_TYP DHT11
#define MAX_DOT 20        // maximum dot for same result
#define HEADER_REPEAT 5   // number of row before header repeat

//public variable declaration
DHT dht(DHT_PIN,DHT_TYP);                       // instance of DHT
int dotCount, newHead = 0;        // counter for number of dot and line between header
float humidity, oldHumidity = 0;  // variable for humidity and last humidity
float suhu, oldSuhu = 0;          // variable for temp celcius and last temp

// function to create header
void header() {
  Serial.println("Kelembaban\tTemperatur\tTemperatur");
  Serial.println("    %  \t\tCelcius \tFahrenheit");
}

// setup function
void setup() {
  Serial.begin(115200);               // serial monitor init at 115200 baud
  header();
}

float toFahrenheit(float celcius){
  return 1.8 * celcius + 32.0; 
}
// loop function
void loop() {
  humidity = dht.readHumidity();                         // get Humidity data
  suhu = dht.readTemperature();                          // get Celcius data
  if ((suhu == oldSuhu) && (humidity == oldHumidity)){  // if Humidity & Celcius same, dont write
    if (dotCount < MAX_DOT){                            // after dot reach maximum, do nothing
      Serial.printf(".");
      dotCount++;
    }
  } else if ((!isnan(suhu)) && !isnan(humidity)){
    if (dotCount > 0){                                  // if data diff, reset dotCount and newLine
      dotCount = 0;
      Serial.println();
    }
    if (newHead == HEADER_REPEAT){
      header();
      newHead = 0;
    }
    newHead++;   
    Serial.printf("%6.2f",humidity);
    Serial.printf("\t\t");
    Serial.printf("%6.2f",suhu);
    Serial.printf("\t\t");
    Serial.printf("%6.2f",toFahrenheit(suhu));
    Serial.println();
    oldSuhu = suhu;
    oldHumidity = humidity;
  }
  delay(1000);
}
