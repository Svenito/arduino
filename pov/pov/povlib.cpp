#include <WProgram.h>
#include <povlib.h>

Pov::~Pov(){
    free(_pins);
}

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
        
void Pov::print(int* letter){
    int row, col;

    // Print the letter
    for (row = 0; row < _row_size; row++) {
        for (col = 0; col < _col_size; col++) {                
            digitalWrite(_pins[col], letter[(_col_size*row)+col]);
        }
    delay(3);
    }

    // Blank for kerning
    for (col = 0; col < _col_size; col++) {
        digitalWrite(_pins[col], LOW);
    }
    // Adjust this for kerning size
    delay(300);
}
