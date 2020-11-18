#ifndef PAINTER
#define PAINTER
#include "../Model/Color.hpp"
#include "XMLParser.hpp"

class Painter{

private:
    XMLParser vista;

public:
    Painter(){}

    void pintarPais(vector<Color*> pColores, string pRuta){
        //codigo pintar
        for(Color * color : pColores){
            for(Country pais: color->getPaises()){
                vista.cambiarColorPais(pais.getCountryName(), color->getColorCode());
            }
        }
        vista.escribirASVG(pRuta);

    }


};

#endif