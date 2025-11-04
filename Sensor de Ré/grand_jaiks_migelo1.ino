// Definição dos pinos

#define trigPin 8
#define echoPin 7
#define piezoPin 2

#define ledVermelho 4
#define ledAmarelo 6 
#define ledVerde 5 


void setup() {
  // Inicializar pinos
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(piezoPin, OUTPUT);
  
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  Serial.begin(9600); // Inicializar monitor serial para depuração
}

void loop() {
  // Variáveis para medir a distância
  long duracao;
  int distancia;

  // Enviar pulso para o sensor ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Ler o tempo de retorno do ECHO
  duracao = pulseIn(echoPin, HIGH);
  
  // Calcular a distância em cm
  distancia = duracao * 0.034 / 2;

  // Mostrar a distância no monitor serial (opcional)
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println("cm");

  // Controlar LEDs e piezo com base na distância
  if (distancia > 100) { // Distância maior que 100 cm
    digitalWrite(ledVerde, HIGH); // Aciona LED verde
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    noTone(piezoPin);
   
  } 
  else if (distancia > 30 && distancia <= 100) { // Distância entre 30 cm e 100 cm
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH); // Aciona LED amarelo
    digitalWrite(ledVermelho, LOW);
    tone(piezoPin, 1000);
    delay(300);
    noTone(piezoPin);
    delay(300);
    
  } 
  else if (distancia >= 0 && distancia <= 30) { // Distância menor que 30 cm
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH); // Aciona LED vermelho
    tone(piezoPin, 1000);
    delay(100);
    noTone(piezoPin);
    delay(100);
  
  } 
  else { // Caso não detecte nenhum obstáculo
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    tone(piezoPin, 1000);
    delay(700);
    noTone(piezoPin);
    delay(700);
    
  }

  delay(100); // Delay para estabilizar o loop
}

void apitarLento() {
  tone(piezoPin, 1000); // Frequência do piezo (1000 Hz)
  delay(500); // Tempo que o som fica ativo
  noTone(piezoPin); // Desliga o som
  delay(500); // Pausa entre os bipes
}

void apitarMedio() {
  tone(piezoPin, 1000); // Frequência do piezo (1000 Hz)
  delay(300); // Tempo que o som fica ativo
  noTone(piezoPin); // Desliga o som
  delay(300); // Pausa entre os bipes
}

void apitarRapido() {
  tone(piezoPin, 1000); // Frequência do piezo (1000 Hz)
  delay(100); // Tempo que o som fica ativo
  noTone(piezoPin); // Desliga o som
  delay(100); // Pausa entre os bipes
}

void noSound() {
  noTone(piezoPin); // Garante que o piezo não está emitindo som
}