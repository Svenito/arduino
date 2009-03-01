#include <WProgram.h>
#include <povlib.h>
#include <chars.h>

void Pov::init(int pins[], int col_size, int row_size){
    _col_size = col_size;
    _row_size = row_size;
    
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
        
void Pov::print(char* string){
    int row, col;

    for (row = 0; row < _row_size; row++) {
        for (col = 0; col < _col_size; col++) {
            digitalWrite(_pins[col], B[(6*row)+col]);
        }
    delay(3);
    }
    for (col = 0; col < _col_size; col++) {
        digitalWrite(_pins[col], LOW);
    }
    delay(200);
}
