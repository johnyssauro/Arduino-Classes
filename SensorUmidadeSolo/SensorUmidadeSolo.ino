const int sensor = A0;

int valorLido = 0;
int percentual = 0;

void setup() {

  pinMode(sensor, INPUT);
  Serial.begin(9600);

}

void loop() {

  valorLido = analogRead(sensor);

  percentual = map(valorLido, 1023, 0, 0, 100);

  Serial.print("Porcentagem: ");
  Serial.print(percentual);
  Serial.println("%");
  delay(1000);

}
