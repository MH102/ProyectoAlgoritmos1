#ifndef PAINTER
#define PAINTER
#include "../Model/Color.hpp"
#include "../Comparator/ColorComparator.hpp"
#include "XMLParser.hpp"

class Painter{

private:
    ColorComparator comparator;

public:
    Painter(ColorComparator pComparator){
        this->comparator = pComparator;
    };

    void pintarPais(){
        //codigo pintar
    }


};

#endif