#include <povlib.h>

int pins[] = {1, 2, 3, 4, 5, 6};
int col_size = 6;
int row_size = 5;
Pov pov;

void setup() {
  pov.init(pins, col_size, row_size);
}

void loop() {
  pov.print("ABCDE");  
}
