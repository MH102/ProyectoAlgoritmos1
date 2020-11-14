#ifndef COLOR
#define COLOR

#include "Country.hpp"

using namespace std;

class Color
{
private:
    string colorCode;
    vector<Country> paises;

public:
    Color(string pColorCode)
    {
        colorCode = pColorCode;
    }
    bool verificarColor(Country pais)
    {
        for (Country paisColor : paises)
        {
            if (pais.seIntersecan(paisColor))
            {
                return true;
            }
        }
        return false;
    }

    void insertarPais(Country pais)
    {
        paises.push_back(pais);
    }
    int getCantidadPaises()
    {
        return paises.size();
    }
    string getColorCode()
    {
        return colorCode;
    }
    vector<Country> getPaises()
    {
        return paises;
    }
};

#endif