int pins[] = {1, 2, 3, 4, 5, 6};
int col_size = 7;

void setup() {
  //Serial.begin(9600);
  int loop;
  for(loop = 1; loop < col_size; loop++) {
    pinMode(loop, OUTPUT);
    digitalWrite(loop, LOW);
  }
}

void loop() {
  int loop;
  for (loop = 1; loop < col_size; loop++) {
    if (loop > 0) {
      digitalWrite(loop-1, LOW);
    }
    if (loop == 1) {
      digitalWrite(6, LOW);
    }
    digitalWrite(loop, HIGH);
    // Small delay before next loop
    delay(500);
  }
}
