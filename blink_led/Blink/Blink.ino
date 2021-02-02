/*
  Blink merah, kuning, hijau

*/
# define merah 2
int kuning = 0, hijau = 4;
int merah1 = 16, kuning1 = 17, hijau1 = 5;
int delay1 = 1000;
int delay3 = 3000;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(merah1, OUTPUT);
  pinMode(kuning1, OUTPUT);
  pinMode(hijau1, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
// 1
  digitalWrite(merah, LOW);
  digitalWrite(hijau, HIGH);
  digitalWrite(kuning, LOW);

  digitalWrite(merah1, HIGH);
  digitalWrite(hijau1, LOW);
  digitalWrite(kuning1, LOW);
  delay(1000);

// 2
  digitalWrite(merah, LOW);
  digitalWrite(hijau, LOW);
  digitalWrite(kuning, HIGH);

  digitalWrite(merah1, HIGH);
  digitalWrite(hijau1, LOW);
  digitalWrite(kuning1, LOW);
  delay(1000);

//  3
  digitalWrite(merah, HIGH);
  digitalWrite(hijau, LOW);
  digitalWrite(kuning, LOW);

  digitalWrite(merah1, LOW);
  digitalWrite(hijau1, HIGH);
  digitalWrite(kuning1, LOW);
  delay(1000);

//  4
  digitalWrite(merah, HIGH);
  digitalWrite(hijau, LOW);
  digitalWrite(kuning, LOW);

  digitalWrite(merah1, LOW);
  digitalWrite(hijau1, LOW);
  digitalWrite(kuning1, HIGH);
  delay(1000);

//  5
  digitalWrite(merah, LOW);
  digitalWrite(hijau, HIGH);
  digitalWrite(kuning, LOW);
  
  digitalWrite(merah1, HIGH);
  digitalWrite(hijau1, LOW);
  digitalWrite(kuning1, LOW);
  delay(1000);


}
