#ifndef BACKTRACKING
#define BACKTRACKING
#include "ColorComparator.hpp"
#include <math.h>

#define AUMENTOCRITERIO 10
#define MAXANCHO 2000
class ComparatorBacktracking : public ColorComparator{

private:

    int cantidadBlancosMejorSolucion;
    int criterioMejorSolucion;

public:
    ComparatorBacktracking() {
        this->cantidadBlancosMejorSolucion = -1;
        this->criterioMejorSolucion = -1;
    }

    ComparatorBacktracking(vector<Color *> pColores, int pCantidadPorPintar) : ColorComparator(pColores, pCantidadPorPintar){
        this->cantidadBlancosMejorSolucion = -1;
        this->criterioMejorSolucion = -1;
    }

    void comparar(vector<Country> pPaises)
    {
        for(int posicion = 0; posicion <= MAXANCHO; posicion += AUMENTOCRITERIO){
            pPaises = ordenamiento(pPaises, posicion);
            if( compararMejorSolucion(pPaises) ){
                this->cantidadBlancosMejorSolucion = paisesBlancos.size();
                this->criterioMejorSolucion = posicion;
            }
        }
    }

    vector<Country> ordenamiento(vector<Country> pPaises, int pPosicion){
        int posicionAltura = pPosicion/2;
        vector<Country> world;
        for(Country pais: pPaises){
            float distancia = distanciaEntrePuntos(pais.getCountryBorder().front().first, pais.getCountryBorder().front().second, pPosicion, posicionAltura);
            vector<Country>::iterator index = world.begin();
            if(distancia >= MAXANCHO/2){
                world.push_back(pais);
            } else {
                world.insert(index, pais);
            }
        }
        return world;
    }
    
    float distanciaEntrePuntos(float pFirstValueX, float pFirstValueY, float pSecondValueX, float pSecondValueY){
        float firstOperando = pow( pSecondValueX - pFirstValueX, 2);
        float secondOperando = pow( pSecondValueX - pFirstValueX, 2);
        float distancia = sqrt(firstOperando + secondOperando);
        return distancia;
    }

    bool compararMejorSolucion(vector<Country> pPaises){
        limpieza();
        for (Country pais : pPaises)
        {
            if(paisesBlancos.size() > cantidadBlancosMejorSolucion){
                return false;
            }
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
                paisesBlancos.push_back(pais);
        }
        return true;
    }

    void limpieza(){
        paisesBlancos.clear();
        for(Color* color: colores){
            color->getPaises().clear();
        }
    }

    void imprimir()
    {
        for (Color *color : colores)
        {
            cout << "Color: " << color->getColorCode() << "\nCantidad de paises: " << color->getCantidadPaises() << endl;
            cout << endl;
        }
        cout << "Color: Blanco \nCantidad de paises: " << cantidadBlancosMejorSolucion << endl;
        cout << "Mejor Criterio: " << criterioMejorSolucion << endl;
    }

};

#endif