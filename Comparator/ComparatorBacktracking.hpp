#ifndef BACKTRACKING
#define BACKTRACKING
#include "ColorComparator.hpp"

class ComparatorBacktracking : ColorComparator{

public:
    ComparatorBacktracking();

    ComparatorBacktracking(vector<Color *> pColores, int pCantidadPorPintar) : ColorComparator(pColores, pCantidadPorPintar){}

    void comparar(vector<Country> paises)
    {
        //Aqui va la solucion en backtracking
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