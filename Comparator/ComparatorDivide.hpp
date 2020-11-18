#ifndef DIVIDE
#define DIVIDE
#include "ColorComparator.hpp"

class ComparatorDivide : public ColorComparator
{

private:
    int cantidadColores;

public:
    ComparatorDivide(XMLParser *parser) : ColorComparator()
    {
        // painter a puntero
        setPintador(parser);
    }

    ComparatorDivide(vector<Color *> pColores, int pCantidadPorPintar) : ColorComparator(pColores, pCantidadPorPintar)
    {
        this->cantidadColores = pColores.size();
    }

    bool determinarVecinos(vector<Country> pPaises, Country pPais, int pIndexPaisInicio, int pIndexPaisFinal)
    {
        for (int indexPais = pIndexPaisInicio; indexPais < pIndexPaisFinal; indexPais++)
        {
            Country currentCountry = pPaises.at(indexPais);
            bool existeFrontera = pPais.seIntersecan(currentCountry);
            if (existeFrontera)
            {
                return true;
            }
        }
        return false;
    }

    void colorearPaises(vector<Country> pPaises, int pIndexPaisInicio, int pIndexColor)
    {
        int indexFinal;
        cantidadColores = colores.size();
        int cantidadPorPintar = pIndexPaisInicio + cantidadColores;

        if (cantidadPorPintar > pPaises.size())
        {
            indexFinal = pPaises.size();
        }
        else
        {
            indexFinal = cantidadPorPintar - 1;
        }
        Color *colorEscogido = colores.at(pIndexColor);
        Country paisPorPintar;
        for (int indexPais = pIndexPaisInicio; indexPais < indexFinal; indexPais++)
        {
            paisPorPintar = pPaises.at(indexPais);

            bool tieneVecino = determinarVecinos(pPaises, paisPorPintar, pIndexPaisInicio + 1, indexFinal);

            if (tieneVecino)
            {
                paisesBlancos.push_back(paisPorPintar);
            }
            else
            {
                colorEscogido->insertarPais(paisPorPintar);
            }
        }
    }

    void comparar(vector<Country> pPaises, int pIndexPais, int pIndexColor)
    {
        cantidadColores = colores.size();
        if (contadorPintados >= cantidadNecesariaPorPintar)
        {
            contadorPintados -= cantidadNecesariaPorPintar;
            pintador->pintarPais(colores, "svg//divideconquer.svg");
        }

        if (pIndexPais >= pPaises.size())
        {
            return;
        }
        if (pIndexColor == cantidadColores)
        {
            pIndexColor = 0;
        }
        colorearPaises(pPaises, pIndexPais, pIndexColor);
        contadorPintados += cantidadColores;
        comparar(pPaises, pIndexPais + cantidadColores, pIndexColor + 1);
    }
};

#endif