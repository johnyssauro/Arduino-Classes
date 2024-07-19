#define pinSom 7
#define pinVerde 2
#define pinVermelho 3
#define tempoMaximoDeUmaPalma 150
#define tempoMaximoEntrePalmas 500

int contaPalmas = 0;
long tempoEspera = 0;
long tempoEsperaEntrePalmas = 0;

void setup() {

  pinMode(pinSom, INPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinVermelho, OUTPUT);

  digitalWrite(pinVermelho, HIGH);

}

void loop() {

  int sensorSom = digitalRead(pinSom);

  if(sensorSom == LOW){

    if(tempoEspera == 0){

      tempoEspera = tempoEsperaEntrePalmas = millis();
      contaPalmas++;

    } else if ((millis() - tempoEspera) >= tempoMaximoDeUmaPalma) {

      tempoEspera = 0;

    }

  }

  if ( (contaPalmas != 0) && ((millis() - tempoEsperaEntrePalmas) > 500) ){

    executarAcao();
    contaPalmas = 0;
    tempoEsperaEntrePalmas = millis();

  }

}

void executarAcao() {

  switch (contaPalmas) {

    case 2:

      digitalWrite(pinVermelho, digitalRead(pinVerde));
      digitalWrite(pinVerde, digitalRead(pinVermelho));

  }

}
