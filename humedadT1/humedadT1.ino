#define SENSOR A0
#define SENSORDOS A1
#define VALVULA 4

void setup() {
  pinMode(SENSOR, INPUT);
  pinMode(SENSORDOS, INPUT);
  pinMode(VALVULA, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  //Se hace la lectura analoga del pin A0 (sensor) y se pasa por la funcion
  //map() para ajustar los valores leidos a los porcentajes que queremos utilizar
  int valorS1 = mapeoHumedad(SENSOR);
  int valorS2 = mapeoHumedad(SENSORDOS);


  if((valorS1 > 20) && (valorS2>20))
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

int mapeoHumedad(int pinSensor)
{
  int valorHumedad = map(analogRead(pinSensor), 0, 1023, 100, 0);
  return valorHumedad;
}
