const int led = 10;
const int ldr = A0;

int valorLido = 0;

void setup() {

  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);

  Serial.begin(9600);

}

void loop() {

  valorLido = analogRead(ldr);

  if(valorLido > 650){

    digitalWrite(led, HIGH);

  } else {

    digitalWrite(led,LOW);

  }

}
