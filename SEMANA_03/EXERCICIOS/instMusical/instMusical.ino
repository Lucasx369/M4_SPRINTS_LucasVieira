//4 Leds do circuito
const int ledLaranja = 47;
const int ledAzul = 0;
const int ledRoxo = 37;
const int ledCiano = 40;
//Dispositivo de sinalização de áudio
const int buzzer = 2;
//Sensor de luminosidade
const int ldr = 8;
//Botão de armazenamento de um valsor binário lido pelo LDR
const int botaoVermelho = 7;
//Botão para exibir no led os valores armazenados 
const int botaoAmarelo = 5;
//Array que armazeno os valores
int valores[1000];
int atual = 0;

//Função que é executada quando o programa começar
void setup() {
  //Configuração da taxa de comunicação em bits por segundo
  Serial.begin(115200);
  //Configuração para o pino se comportar com saída
  pinMode(ledLaranja, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledRoxo, OUTPUT);
  pinMode(ledCiano, OUTPUT);
  //Entrada com pull-up ativado
  pinMode(botaoVermelho, INPUT_PULLUP);
  pinMode(botaoAmarelo, INPUT_PULLUP);
  //Criação dos campos
  for(int i = 0; i <100; i++){
    valores[i] = -1;
  }
}

//Função tocar música
void tocarMusica(int value){
  tone(buzzer, 100*value, 500); //audio, tom, tempo
}
void leds(int valor){
  switch (valor){
    case 0:
      digitalWrite(ledLaranja, LOW);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledRoxo, LOW);
      digitalWrite(ledCiano, LOW);
    case 1:
      digitalWrite(ledLaranja, LOW);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledRoxo, LOW);
      digitalWrite(ledCiano, HIGH);
    case 2:
      digitalWrite(ledLaranja, LOW);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledRoxo, HIGH);
      digitalWrite(ledCiano, LOW);
    case 3:
      digitalWrite(ledLaranja, LOW);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledRoxo, HIGH);
      digitalWrite(ledCiano, HIGH);
    case 4:
      digitalWrite(ledLaranja, LOW);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledRoxo, LOW);
      digitalWrite(ledCiano, LOW);
    case 5:
      digitalWrite(ledLaranja, LOW);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledRoxo, LOW);
      digitalWrite(ledCiano, HIGH);
    case 6:
      digitalWrite(ledLaranja, LOW);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledRoxo, HIGH);
      digitalWrite(ledCiano, LOW);
    case 7:
      digitalWrite(ledLaranja, LOW);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledRoxo, HIGH);
      digitalWrite(ledCiano, HIGH);
    case 8:
      digitalWrite(ledLaranja, HIGH);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledRoxo, LOW);
      digitalWrite(ledCiano, LOW);
    case 9:
      digitalWrite(ledLaranja, HIGH);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledRoxo, LOW);
      digitalWrite(ledCiano, HIGH);
    case 10:
      digitalWrite(ledLaranja, HIGH);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledRoxo, HIGH);
      digitalWrite(ledCiano, LOW);
    case 11:
      digitalWrite(ledLaranja, HIGH);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledRoxo, HIGH);
      digitalWrite(ledCiano, HIGH);
    break;
      digitalWrite(ledLaranja, HIGH);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledRoxo, LOW);
      digitalWrite(ledCiano, LOW);
    case 13:
      digitalWrite(ledLaranja, HIGH);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledRoxo, LOW);
      digitalWrite(ledCiano, HIGH);
    case 14:
      digitalWrite(ledLaranja, HIGH);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledRoxo, HIGH);
      digitalWrite(ledCiano, LOW);
    case 15:
      digitalWrite(ledLaranja, HIGH);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledRoxo, HIGH);
      digitalWrite(ledCiano, HIGH);
  }
}

void loop() {
  if(!digitalRead(botaoVermelho)){
    //Conversão de valores
    int a = map(analogRead(ldr), 32, 4063, 0, 15);
    Serial.println(a);
    //Valor atual 
    valores[atual] = a;
    //Chamar a função de tocar musica
    tocarMusica(a);
    leds(a);
    atual += 1;
    delay(1000);
    digitalWrite(ledLaranja, LOW);
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledRoxo, LOW);
    digitalWrite(ledCiano, LOW);
  }

  if(!digitalRead(botaoAmarelo)){
    for(int i = 0; i < atual; i++){
      tocarMusica(valores[i]);
      leds(valores[i]);
      valores[i] = -1;
      delay(1000);
    }
  }
}