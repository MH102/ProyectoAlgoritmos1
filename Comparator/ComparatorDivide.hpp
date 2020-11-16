#ifndef DIVIDE
#define DIVIDE
#include "ColorComparator.hpp"

class ComparatorDivide : public ColorComparator{

private:
    int cantidadColores;

public:
    ComparatorDivide(): ColorComparator() {}

    ComparatorDivide(vector<Color *> pColores, int pCantidadPorPintar) : ColorComparator(pColores, pCantidadPorPintar)
    {
        this->cantidadColores = pColores.size();
    }

    bool determinarVecinos(vector<Country> paises, Country pais,int pIndexPaisInicio, int pIndexPaisFinal)
    {
        for(int indexPais = pIndexPaisInicio; indexPais < pIndexPaisFinal; indexPais++){
            Country currentCountry = paises.at(indexPais);
            bool existeFrontera = pais.seIntersecan(currentCountry);
            if(existeFrontera){
                return true;
            }
        }
        return false;
    }

    void colorearPaises(vector<Country> paises, int pIndexPaisInicio, int pIndexColor){
        int indexFinal;
        cantidadColores = colores.size();
        int cantidadPorPintar = pIndexPaisInicio + cantidadColores;

        if( cantidadPorPintar > paises.size()){
            indexFinal = paises.size();
        }else{
            indexFinal = cantidadPorPintar-1;
        }
        Color *colorEscogido = colores.at(pIndexColor);
        Country paisPorPintar;
        for(int indexPais = pIndexPaisInicio; indexPais < indexFinal; indexPais++){
            paisPorPintar = paises.at(indexPais);

            bool tieneVecino = determinarVecinos(paises, paisPorPintar, pIndexPaisInicio+1, indexFinal);

            if(tieneVecino){
                paisesBlancos.push_back(paisPorPintar);
            }else{
                colorEscogido->insertarPais(paisPorPintar);
            }

        }

    }

    void comparar(vector<Country> paises, int pIndexPais, int pIndexColor)
    {
        //Aqui va la solucion en Divide y venceras
        if(pIndexPais >= paises.size())
        {
            return;
        }
        if (pIndexColor == cantidadColores)
        {
            pIndexColor = 0;
        }
        colorearPaises(paises, pIndexPais, pIndexColor);
        comparar(paises, pIndexPais+cantidadColores, pIndexColor+1);
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