int pins[] = {1, 2, 3, 4, 5, 6};
int col_size = 6;
int row_size = 5;

int A[] = {0, 0, 0, 1, 1, 1,  
           0, 1, 1, 1, 0, 0,
           1, 0, 0, 1, 0, 0,
           0, 1, 1, 1, 0, 0,
           0, 0, 0, 1, 1, 1};

void setup() {
  //Serial.begin(9600);
  int loop;
  for(loop = 0; loop < col_size; loop++) {
    pinMode(pins[loop], OUTPUT);
    digitalWrite(pins[loop], LOW);
  }
}

void loop() {
  int row, col;
  
  for (row = 0; row < row_size; row++) {
    for (col = 0; col < col_size; col++) {
      digitalWrite(pins[col], A[(6*row)+col]);
      //delay(500);
    }
    delay(80);
  }
  for (col = 0; col < col_size; col++) {
    digitalWrite(pins[col], LOW);
    //delay(500);
  }
  delay(500);
}
