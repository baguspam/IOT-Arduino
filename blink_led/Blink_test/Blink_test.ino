/*
 * Blink testing
 */
int merah = 17;
int kuning = 4;
int hijau = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(merah, HIGH);
  delay(500);
  digitalWrite(merah, LOW);
  delay(500);
  digitalWrite(kuning, HIGH);
  delay(500);
  digitalWrite(kuning, LOW);
  delay(500);
  digitalWrite(hijau, HIGH);
  delay(500);
  digitalWrite(hijau, LOW);
  delay(500);
}
