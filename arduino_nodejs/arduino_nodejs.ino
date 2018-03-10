void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Hola soy un Arduino");
pinMode (13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()) {
  char Letra = Serial.read();
  Serial.print(Letra); 
  if (Letra == 'H'){ 
    digitalWrite(13, 1);
    }
  else if (Letra == 'L') {
    digitalWrite(13, 0); 
    }
  }
}
