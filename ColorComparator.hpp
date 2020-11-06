#include "Color.hpp"

class ColorComparator
{
private:
    vector<Country> paises;
    vector<Color *> colores;
    vector<Country> blanco;

public:
    ColorComparator(vector<Country> pPaises)
    {
        paises = pPaises;
    }
    void comparar()
    {
        if (colores.size() < 3)
        {
            cout << "No hay suficientes colores" << endl;
            return;
        }
        for (Country pais : paises)
        {
            bool insertado = false;
            for (Color *color : colores)
            {
                if (!color->verificarColor(pais))
                {
                    insertado = true;
                    color->insertarPais(pais);
                    break;
                }
            }
            if (!insertado)
                blanco.push_back(pais);
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
        cout << "Color: Blanco \nCantidad de paises: " << blanco.size() << endl;
    }
};