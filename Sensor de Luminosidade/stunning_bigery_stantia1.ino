int verde = 12;
int vermelho = 11;
int sensor = A0;

int tempo = 1000;
int limiteLuminosidade = 500;



void setup () {
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(sensor, INPUT);
  
}  
  
  void loop (){
    
   int leituraLuminosidade = analogRead(sensor);
    
    
    if (leituraLuminosidade > limiteLuminosidade) {
    digitalWrite(verde, HIGH);
    delay(tempo);
    digitalWrite(verde, LOW);
    delay(tempo);  
    
} else { 
      
      digitalWrite(vermelho, HIGH);
      delay(tempo);
      digitalWrite(vermelho, LOW);
      delay(tempo);

    }
      
  }
      