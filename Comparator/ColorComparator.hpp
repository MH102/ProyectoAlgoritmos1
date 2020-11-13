#include "../Model/Color.hpp"
#include <chrono>

using namespace std;
class ColorComparator
{
protected:
    vector<Color *> colores;
    vector<Country> paisesBlancos;
    int cantidadNecesariaPorPintar;
    chrono::time_point<chrono::steady_clock> inicioTimer, finTimer;
    chrono::duration<float> lapso;

public:
    ColorComparator() {}

    ColorComparator(vector<Color *> pColores, int pCantidadPorPintar)
    {
        this->colores = pColores;
        this->cantidadNecesariaPorPintar = pCantidadPorPintar;
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

    void Colorear(vector<Country> paises)
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