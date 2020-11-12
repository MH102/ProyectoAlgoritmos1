#ifndef DINAMICO
#define DINAMICO
#include "ColorComparator.hpp"

class ComparatorDinamico : ColorComparator{

public:
    ComparatorDinamico();

    ComparatorDinamico(vector<Color *> pColores, int pCantidadPorPintar) : ColorComparator(pColores, pCantidadPorPintar){}

    void comparar(vector<Country> paises)
    {
        //Aqui va la solucion en programacion dinamica
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