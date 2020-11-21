#ifndef COMPARATOR
#define COMPARATOR

#include "../XML/Painter.hpp"
#include <chrono>

using namespace std;
class ColorComparator
{
protected:
    vector<Color *> colores;
    vector<Country> paisesBlancos;
    int cantidadNecesariaPorPintar;
    int contadorPintados;
    Painter *pintador;

    chrono::time_point<chrono::high_resolution_clock> inicioTimer, finTimer;
    chrono::duration<float> lapso;

public:
    ColorComparator()
    {
        // test
        this->contadorPintados = 0;
        this->cantidadNecesariaPorPintar = 10;
    }

    ColorComparator(vector<Color *> pColores, int pCantidadPorPintar)
    {
        this->colores = pColores;
        this->cantidadNecesariaPorPintar = pCantidadPorPintar;
        this->cantidadNecesariaPorPintar = 10;
    }

    void setPintador(XMLParser *parser)
    {
        this->pintador = new Painter(parser);
    }

    vector<Color *> getColores()
    {
        return colores;
    }

    vector<Country> getPaisesBlancos()
    {
        return paisesBlancos;
    }

    int getCantidadNecesaria()
    {
        return cantidadNecesariaPorPintar;
    }

    void setCantidadNecesaria(int pCantidadNecesaria)
    {
        this->cantidadNecesariaPorPintar = pCantidadNecesaria;
    }

    void comparar(vector<Country> pPaises)
    {
        //Se implementa el pintado;
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