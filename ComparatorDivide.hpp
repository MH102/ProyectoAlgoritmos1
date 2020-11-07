#ifndef DIVIDE
#define DIVIDE
#include "ColorComparator.hpp"

class ComparatorDivide : ColorComparator{

public:
    ComparatorDivide();

    void comparar(vector<Country> paises)
    {
        //Aqui va la solucion en Divide y venceras
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