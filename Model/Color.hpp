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
    bool operator<(const Color &col) const
    {
        return (paises.size() < col.paises.size());
    }

    Color(string pColorCode)
    {
        colorCode = pColorCode;
    }
    bool verificarColor(Country pPais)
    {
        for (Country paisColor : paises)
        {
            if (pPais.seIntersecan(paisColor))
            {
                return true;
            }
        }
        return false;
    }

    void insertarPais(Country pPais)
    {
        paises.push_back(pPais);
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

    void setPaises(vector<Country> pPaises)
    {
        this->paises = pPaises;
    }

    void limpiarPaises()
    {
        this->paises.clear();
    }
};

#endif