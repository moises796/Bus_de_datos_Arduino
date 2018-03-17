#define BuscarLed 1
#define BuscarNumero 2

int Led = 0;
int Dato = 0;
int EstadoBusqueda = 0;
int Boton=2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hola soy un Arduino");
  pinMode (13, OUTPUT);
  pinMode(Boton, INPUT);
}

void loop() {
  if (digitalRead(Boton)==1) {
    Serial.print("H");
    delay(500);
  }
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char Letra = Serial.read();
    if (Letra == 'L') {
      EstadoBusqueda = BuscarLed;
    }
    else if (Letra == 'D') {
      EstadoBusqueda = BuscarNumero;
    }
    else if (Letra == '.') {
      analogWrite (Led, Dato);
      Serial.print("El Led es: ");
      Serial.print(Led);
      Serial.print(" El Dato es: ");
      Serial.println(Dato);
      Led = 0;
      Dato = 0;
      EstadoBusqueda = 0;
    }
    else if (Letra >= '0' && Letra <= '9') {
      int NumeroActual = int(Letra - '0');
      if (EstadoBusqueda == BuscarLed) {
        Led = Led * 10 + NumeroActual;
      }
      else if (EstadoBusqueda == BuscarNumero) {
        Dato = Dato * 10 + NumeroActual;
      }
    }
  }
}
