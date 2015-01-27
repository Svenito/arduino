#ifndef __POV_H__
#define __POV_H__

#include <inttypes.h>

class Pov {
    private:
        int _col_size;
        int _row_size;
        int* _pins;

        int _display_time;
        int _kerning;

    public:
        /// pins: The pin numbers to which the LEDs are attached
        /// col_size: The height of the chars
        /// row_size: The width of the chars
        Pov(int pins[], int col_size, int row_size);
        ~Pov();

        /// Print the given character
        void print(int* character);

        /// How long to display each column for
        void set_display_time(int value) {_display_time = value;}

        /// Time between letters, or kerning
        void set_kerning(int value) {_kerning = value;}

};



#endif
