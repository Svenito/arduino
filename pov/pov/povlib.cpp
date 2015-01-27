#include <Arduino.h>
#include "povlib.h"

Pov::Pov(int pins[], int col_size, int row_size):
    _col_size(col_size),
    _row_size(row_size),
    _display_time(3),
    _kerning(6)
{
    _pins = (int*) malloc (col_size);

    int loop;
    for(loop = 0; loop < _col_size; loop++) {
        _pins[loop] = pins[loop];
        pinMode(pins[loop], OUTPUT);
        digitalWrite(pins[loop], LOW);
    }
}

Pov::~Pov(){
    free(_pins);
}

void Pov::print(int* character){
    int row, col;

    // Print the letter
    for (row = 0; row < _row_size; row++) {
        for (col = 0; col < _col_size; col++) {
            digitalWrite(_pins[col], letter[(_col_size*row)+col]);
        }
    delay(_display_time);
    }

    // Blank for kerning
    for (col = 0; col < _col_size; col++) {
        digitalWrite(_pins[col], LOW);
    }
    delay(_kerning);
}
