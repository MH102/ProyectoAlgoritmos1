#ifndef DINAMICO
#define DINAMICO
#include "ColorComparator.hpp"

class ComparatorDinamico : ColorComparator{

public:
    ComparatorDinamico();

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
        cout << "Color: Blanco \nCantidad de paises: " << blanco.size() << endl;
    }

};

#endif