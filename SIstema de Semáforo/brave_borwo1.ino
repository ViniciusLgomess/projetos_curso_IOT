#define vermelho 7
#define verde 6
#define amarelo 5
#define azul 4
#define sensor A0

int dtempov = 4000;
int dtempovd = 6000;
int dtempoa = 2000;

int ntempov = 4000;
int ntempovd = 8000;
int ntempoa = 1000;

int limiteLuminosidade = 500;


void setup () {
 
  Serial.begin(9600);
  
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  
  Serial.println("Iniciando sistems...");
 
}

void loop () {
  
  int leituraLuminosidade = analogRead(sensor);
  
  if  (leituraLuminosidade > limiteLuminosidade) {
    
    
    digitalWrite(azul, LOW);
    
    
    Serial.println("Modo: Dia...");
    
  //ligar led vermelho durante o dia
  
  Serial.println("Led vermelho ligado por 4 segundos");
  digitalWrite(vermelho, HIGH);
  delay(dtempov);
  Serial.println("Led vermelho desligado");
  digitalWrite(vermelho, LOW);
  

  
  //ligar led verde
  
  Serial.println("Led verde ligado por 6 segundos");
  digitalWrite(verde, HIGH);
  delay(dtempovd); 
  Serial.println("Led verde desligado");
  digitalWrite(verde, LOW);
 
  
  //ligar led amarelo
  
  Serial.println("Led amarelo ligado por 2 segundos");
  digitalWrite(amarelo, HIGH);
  delay(dtempoa); 
  Serial.println("Led amarelo desligado");
  digitalWrite(amarelo, LOW);
    
  } else { 
    
   Serial.println("Modo: Noite...");
   
   digitalWrite(azul, HIGH);
    
    
    //ligar led vermelho durante a noite
  
  Serial.println("Led vermelho ligado por 4 segundos");
  digitalWrite(vermelho, HIGH);
  delay(ntempov);
  Serial.println("Led vermelho desligado");
  digitalWrite(vermelho, LOW);
  
    
    
    //ligar led verde durante a noite
  
  Serial.println("Led verde ligado por 8 segundos");
  digitalWrite(verde, HIGH);
  delay(ntempovd);
  Serial.println("Led verde desligado");
  digitalWrite(verde, LOW);
    
    
    
    //ligar led amarelo durante a noite
  
  Serial.println("Led amarelo ligado por 1 segundos");
  digitalWrite(amarelo, HIGH);
  delay(ntempoa); 
  Serial.println("Led amarelo desligado");
  digitalWrite(amarelo, LOW);
    
  }
  
  delay(100);
  
}
 