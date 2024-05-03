byte photoR = 0; // analog 0 is the photoresistor
int base; // the base value, read only once
byte threshold = 100; // minimum difference
unsigned long time1, time2;
String morse = "";
bool flag = false;
bool flag2 = false;

void setup() {
 // Set pin modes and begin serial communication
  pinMode(interruptPin, INPUT_PULLUP);
  Serial.begin(9600); // starting serial comm
  attachInterrupt(digitalPinToInterrupt(interruptPin), addSign, CHANGE);
}

void loop() {
  
}

void addSign() {
  if (!flag) {
    time1 = millis();
    flag = !flag;
  }
  else {
    time2 = millis();
    if (time2 - time1 < 210 && time2 - time1 > 190) {
      morse += '.';
    }
    else if(time2 - time1 < 610 && time2 - time1 > 590){
      morse += '-';
    }
    flag = !flag;
  }
}