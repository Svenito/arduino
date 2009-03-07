#ifndef __POV_H__
#define __POV_H__

#include <inttypes.h>

class Pov {
    private:
        int _col_size;
        int _row_size;
        int* _pins;
    
    public:
        Pov(){};
        void init(int pins[], int col_size, int _row_size);
        ~Pov();
        
        void print(int* letter);

};



#endif
