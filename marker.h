#include <iostream>
 

class marker
 {
public:
    marker();
    marker(std::size_t r, std::size_t c, char t);

    size_t getRow();
    
    size_t getCol();

    char getType();

    size_t setRow(size_t r);
    size_t setCol(size_t c);
    char setType(char t);

marker& operator=(marker other); //this needs to be tested.
 

protected:
    size_t row; size_t col; char type;
 };