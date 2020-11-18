#ifndef DINAMICO
#define DINAMICO
#include "ColorComparator.hpp"

class ComparatorDinamico : public ColorComparator
{

public:
    ComparatorDinamico(XMLParser *parser) : ColorComparator()
    {
        setPintador(parser);
    }

    ComparatorDinamico(vector<Color *> pColores, int pCantidadPorPintar) : ColorComparator(pColores, pCantidadPorPintar) {}

    void comparar(vector<Country> pPaises)
    {
        //Aqui va la solucion en programacion dinamica

        Color *colorActual = colores.front();
        int colorCounter = 0;

        bool esBlanco = false;
        for (Country pais : pPaises)
        {
            if (contadorPintados == cantidadNecesariaPorPintar)
            {
                contadorPintados = 0;
                pintador->pintarPais(colores, "svg//dinamic.svg");
            }
            int nextColor = colorCounter + 1;
            while (colorActual->verificarColor(pais))
            {
                if (nextColor >= colores.size())
                {
                    nextColor = 0;
                }
                if (colorCounter == nextColor)
                {
                    esBlanco = true;
                    colorActual = colores.at(nextColor);
                    nextColor++;
                    break;
                }
                colorActual = colores.at(nextColor);
                nextColor++;
            }
            if (!esBlanco)
            {
                colorActual->insertarPais(pais);
                colorCounter = nextColor - 1;
            }
            else
            {
                paisesBlancos.push_back(pais);
                esBlanco = false;
            }
            contadorPintados++;
        }
    }
};

#endif