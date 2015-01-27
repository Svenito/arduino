#include "Arduino.h"
#include "unlogic/pov/povlib.h"
#include "unlogic/pov/chars.h"

int pins[] = {1, 4, 7, 10, 13};
int col_size = 5;
int row_size = 3;

Pov pov = Pov(pins, col_size, row_size);

void setup() {
}

void loop() {

  pov.print(I);
  pov.print(_);
  pov.print(heart);
  pov.print(Y);
  pov.print(O);
  pov.print(U);
  pov.print(_);
}
