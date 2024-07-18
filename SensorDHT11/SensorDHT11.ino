#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT11
#define DHTPIN 2

DHT_Unified dht(DHTPIN, DHTTYPE);
int32_t delayMS = 500;

void setup() {

  Serial.begin(9600);
  dht.begin();
  Serial.println("Usando-se o Sensor DHT");
  sensor_t sensor;

}

void loop() {

  delay(delayMS);
  sensors_event_t event;
  dht.temperature().getEvent(&event);

  if(isnan(event.temperature))
  {

    Serial.println("Erro na leitura da Temperatura!");

  } else {

    Serial.print("Temperatura: ");
    Serial.print(event.temperature);
    Serial.println(" *C");

    dht.humidity().getEvent(&event);

    if(isnan(event.relative_humidity))
    {

      Serial.println("Erro na leitura da Umidade!");

    } else {

      Serial.print("Umidade: ");
      Serial.print(event.relative_humidity);
      Serial.println("%");

    }

  }


}
