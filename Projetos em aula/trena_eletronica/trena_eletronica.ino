#define pinTrg 3
#define pinEch 4

float tempoEcho = 0;

const float velocidadeSom_mps = 340;
const float velocidadeSom_mpus = 0.000340;

void setup() {
  
  pinMode(pinTrg, OUTPUT);
  digitalWrite(pinTrg, LOW);
  
  pinMode(pinEch, INPUT);

  Serial.begin(9600);
  delay(1000);

}

void loop() {
  
  DisparaPulsoUltrassonico();
  tempoEcho = pulseIn(pinEch, HIGH);
  Serial.print("Distancia em metros: ");
  Serial.println(CalculaDistancia(tempoEcho));
  Serial.print("Distancia em centimetros: ");
  Serial.println(CalculaDistancia(tempoEcho) * 100);
  delay(2000);

}

void DisparaPulsoUltrassonico(){

  digitalWrite(pinTrg, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrg, LOW);

}

float CalculaDistancia(float tempo_us){

  return ((tempo_us * velocidadeSom_mpus) / 2);

}
