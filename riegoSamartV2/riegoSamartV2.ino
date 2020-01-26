#define SENSOR A0
#define SENSORDOS A1
#define LDR A3
#define VALVULA 4
#define ESPERA_LECTURAS 1000 // tiempo en milisegundos entre lecturas de la intensidad de la luz
 
long cronometro_lecturas=0;
long tiempo_transcurrido;
unsigned int luminosidad;
float coeficiente_porcentaje=100.0/1023.0; // El valor de la entrada analógica va de 0 a 1023 y se quiere convertir a porcentaje que va de cero a 100
int trigger = 30;

void setup() {
  pinMode(SENSOR, INPUT);
  pinMode(SENSORDOS, INPUT);
  pinMode(VALVULA, OUTPUT);
  Serial.begin(9600);
}

void loop() {


    tiempo_transcurrido=millis()-cronometro_lecturas;
  if(tiempo_transcurrido>ESPERA_LECTURAS)
  {
    cronometro_lecturas=millis();
    luminosidad=analogRead(LDR);
    Serial.print("La luminosidad es del ");
    Serial.print(luminosidad*coeficiente_porcentaje);
    Serial.println("%");
  }

if(luminosidad > 30)
{
  int valorS1 = mapeoHumedad(SENSOR);
  int valorS2 = mapeoHumedad(SENSORDOS);


  if((valorS1 > trigger) && (valorS2 > trigger))
  {
    digitalWrite(VALVULA, LOW);
  }
  else
  {
    digitalWrite(VALVULA, HIGH);
  }

  
  Serial.print("HumedadS1: ");
  Serial.print(valorS1);
  Serial.println("%");

  Serial.print("HumedadS2: ");
  Serial.print(valorS2);
  Serial.println("%");

  delay(100);

}

}

int mapeoHumedad(int pinSensor)
{
  int valorHumedad = map(analogRead(pinSensor), 0, 1023, 100, 0);
  return valorHumedad;
}
