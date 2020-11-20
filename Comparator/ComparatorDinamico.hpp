#ifndef DINAMICO
#define DINAMICO
#include "ColorComparator.hpp"

class ComparatorDinamico : public ColorComparator
{

private:
    int contadorParaBlanco;

public:
    ComparatorDinamico(XMLParser *parser) : ColorComparator()
    {
        setPintador(parser);
        contadorParaBlanco = 0;
    }

    ComparatorDinamico(vector<Color *> pColores, int pCantidadPorPintar) : ColorComparator(pColores, pCantidadPorPintar) {}

    vector<Country> alimentacion(vector<Country> pPaises, Color *pColor){
        for(int index= 0; index < pPaises.size(); index++){
            Country pais = pPaises.at(index);
            if (contadorPintados == cantidadNecesariaPorPintar){
                contadorPintados = 0;
                pintador->pintarPais(colores, "svg//dinamic.svg");
            }
            if(!pColor->verificarColor(pais)){
                pColor->insertarPais(pais);
                contadorPintados++;
                pPaises.erase( pPaises.begin()+index);
            }else{
                contadorParaBlanco++;
                return pPaises;
                break;
            }
        }
        return pPaises;
    }

    void comparar(vector<Country> pPaises)
    {

        Color *colorActual = colores.front();
        int colorCounter = 0;

        while (pPaises.size() > 0){
            if(colorCounter == colores.size()){
                colorCounter = 0;
            }
            colorActual = colores.at(colorCounter);
            pPaises = alimentacion(pPaises, colorActual);
            if(contadorParaBlanco == colores.size()){
                Country pais = pPaises.at(0);
                paisesBlancos.push_back(pais);
                pPaises.erase(pPaises.begin());
                contadorParaBlanco = 0;
            }else{
                colorCounter++;
            }
        }
        pintador->pintarPais(colores, "svg//dinamic.svg");
    }
};

#endif