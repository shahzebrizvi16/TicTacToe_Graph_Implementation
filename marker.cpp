#include "marker.h" 

marker::marker() // default constructor
{
row = NULL; col = NULL; type = NULL;
};
     marker::marker(std::size_t r, std::size_t c, char t)
    {
        row = r; col = c; type = t;
    };

    size_t marker::getRow()
    {
        return row;
    };
    
    size_t marker::getCol()
    {
        return col;
    };

    char marker::getType()
    {
        return type;
    };

    size_t marker::setRow(size_t r)
    {
        row=r;
    };
    
    size_t marker::setCol(size_t c)
    {
        col=c;
    };

    char marker::setType(char t)
    {
        type=t;
    };

marker& marker::operator=(marker other) //this needs to be tested.
    {
        col = other.getCol();
        row = other.getRow();
        type = other.getType();

        return *this;
    };

    size_t row; size_t col; char type;
 