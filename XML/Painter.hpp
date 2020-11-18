#ifndef PAINTER
#define PAINTER
#include "../Model/Color.hpp"
#include "XMLParser.hpp"

class Painter
{

private:
    XMLParser *vista;

public:
    Painter(XMLParser *parser)
    {
        vista = parser;
    }

    void pintarPais(vector<Color *> pColores, string pRuta)
    {
        //codigo pintar
        int cantidadPintados = 0;
        for (Color *color : pColores)
        {
            cantidadPintados += color->getPaises().size();
            for (Country pais : color->getPaises())
            {
                vista->cambiarColorPais(pais.getCountryName(), color->getColorCode());
            }
        }
        vista->cambiarCantidadPaisesEnBlanco(211 - cantidadPintados);
        vista->cambiarCantidadPaisesPintados(cantidadPintados);
        vista->escribirASVG(pRuta);
    }
};

#endif