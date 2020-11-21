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

    void blanquearMapa(vector<Country> pPaises)
    {
        for (Country pais : pPaises)
        {
            vista->cambiarColorPais(pais.getCountryName(), "#f2f2f2");
        }
    }

    void pintarPais(vector<Color *> pColores, string pRuta, float pTime)
    {
        //codigo pintar listo
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
        vista->cambiarTiempo(pTime);
        vista->escribirASVG(pRuta);
    }
};

#endif