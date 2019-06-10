//Tomás de Camino Beck
//www.tomasdecamino.com

//Lista de números
const int n = 5000;
int list[n];

//Marcador de tiempo
long lastMillis;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //tiempo antes del sort
  lastMillis = millis();
  randomizeList(&list[0], n);
  sort(&list[0], n);

  //muestra el teimpo transcurrido en milisegundos
  Serial.println(millis() - lastMillis);
}

//Aleatorización de una arreglo
void randomizeList(int *data, int l) {
  for (int i = 0; i < l - 1; i++) {
    data[i] = random(100);
  }

}


//Función de ordenamiento de burbuja
void sort(int *data, int l)
{
  int i, j;
  for (i = 0; i < l - 1; i++) {
    for (j = 0; j < l - i - 1; j++) {
      if (data[j] > data[j + 1]) {
        //swap fitnes
        int f = data[j];
        data[j] = data[j + 1];
        data[j + 1] = f;
      }
    }
  }
}


//En caso de que quieran ver el arreglo
void printList() {
  for (int i = 0; i < n - 1; i++) {
    Serial.print(list[i]);
    Serial.print(",");
  }
  Serial.println();
  Serial.println("----");
}
