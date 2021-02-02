int do1 = 22;
int ao2 =36, do2 = 23;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ao2, OUTPUT);
  pinMode(do2, OUTPUT);
  pinMode(do1, INPUT);
  pinMode(2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int AnalogValue, DigitalValue, DigitalValue1;
  AnalogValue =  analogRead(ao2);
  DigitalValue = digitalRead(do2);
  DigitalValue1 = digitalRead(do1);
  Serial.print(AnalogValue);
  Serial.print(" & ");
  Serial.print(DigitalValue);
  Serial.print(" & ");
  Serial.println(DigitalValue1);
  delay(1000);

  if(DigitalValue1 == 1) 
    digitalWrite(2, HIGH);
  else digitalWrite(2, LOW);
}
