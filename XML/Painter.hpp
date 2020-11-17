#ifndef PAINTER
#define PAINTER
#include "../Model/Color.hpp"
#include "XMLParser.hpp"

class Painter{

private:
    XMLParser *vista;

public:
    Painter(){}

    void pintarPais(vector<Color*> pColores, string pRuta){
        //codigo pintar
        vista->escribirASVG(pRuta);
    }


};

#endif