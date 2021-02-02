int tg1 = 18, ech1 = 19;
int jarak;
int cek_sensor(int out, int in){
  long duration, distance;
  
  digitalWrite(out, LOW);
  delayMicroseconds(2);
  digitalWrite(out, HIGH);
  delayMicroseconds(10);
  digitalWrite(out, LOW);
  
  duration = pulseIn(in, HIGH);
  distance = (duration/2)/29;
  Serial.print("Jarak: ");
  Serial.println(distance);
  return distance;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(tg1, OUTPUT); 
  pinMode(ech1, INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  jarak = cek_sensor(tg1, ech1);
  delay(2000);
}
