#ifndef DINAMICO
#define DINAMICO
#include "ColorComparator.hpp"

class ComparatorDinamico : public ColorComparator
{

public:
    ComparatorDinamico() : ColorComparator() {}

    ComparatorDinamico(vector<Color *> pColores, int pCantidadPorPintar) : ColorComparator(pColores, pCantidadPorPintar) {}

    void comparar(vector<Country> paises)
    {
        //Aqui va la solucion en programacion dinamica

        Color *colorActual = colores.front();
        int colorCounter = 0;

        bool esBlanco = false;
        for (Country pais : paises)
        {
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
        }
    }
    void insertarColor(string colorCode)
    {
        colores.push_back(new Color(colorCode));
    }
    void imprimir()
    {
        for (Color *color : colores)
        {
            cout << "Color: " << color->getColorCode() << "\nCantidad de paises: " << color->getCantidadPaises() << endl;
            cout << endl;
        }
        cout << "Color: Blanco \nCantidad de paises: " << paisesBlancos.size() << endl;
    }
};

#endif