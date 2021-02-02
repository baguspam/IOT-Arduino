# define merah 16
# define kuning 4
# define hijau 2
int merah1 = 22, kuning1 = 23, hijau1 = 21;
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
//
//int jarak(){
//  cek_sensor(tg1, ech1);
//  delay(200);
//}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(tg1, OUTPUT); 
  pinMode(ech1, INPUT); 

  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(merah1, OUTPUT);
  pinMode(kuning1, OUTPUT);
  pinMode(hijau1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 1
  digitalWrite(merah, LOW);
  digitalWrite(hijau, HIGH);
  digitalWrite(kuning, LOW);

  digitalWrite(merah1, HIGH);
  digitalWrite(hijau1, LOW);
  digitalWrite(kuning1, LOW);
  jarak = cek_sensor(tg1, ech1);
  delay(200);
  if(jarak<10){delay(7000);}else{delay(1000);}

// 2
  digitalWrite(merah, LOW);
  digitalWrite(hijau, LOW);
  digitalWrite(kuning, HIGH);

  digitalWrite(merah1, HIGH);
  digitalWrite(hijau1, LOW);
  digitalWrite(kuning1, LOW);
  jarak = cek_sensor(tg1, ech1);
  delay(200);
  delay(1000);

//  3
  digitalWrite(merah, HIGH);
  digitalWrite(hijau, LOW);
  digitalWrite(kuning, LOW);

  digitalWrite(merah1, LOW);
  digitalWrite(hijau1, HIGH);
  digitalWrite(kuning1, LOW);
  jarak = cek_sensor(tg1, ech1);
  delay(200);
  if(jarak<10){delay(7000);}else{delay(1000);}

//  4
  digitalWrite(merah, HIGH);
  digitalWrite(hijau, LOW);
  digitalWrite(kuning, LOW);

  digitalWrite(merah1, LOW);
  digitalWrite(hijau1, LOW);
  digitalWrite(kuning1, HIGH);
  jarak = cek_sensor(tg1, ech1);
  delay(200);
  delay(1000);

//  5
  digitalWrite(merah, LOW);
  digitalWrite(hijau, HIGH);
  digitalWrite(kuning, LOW);
  
  digitalWrite(merah1, HIGH);
  digitalWrite(hijau1, LOW);
  digitalWrite(kuning1, LOW);
  jarak = cek_sensor(tg1, ech1);
  delay(200);
  if(jarak<10){delay(7000);}else{delay(1000);}

}
