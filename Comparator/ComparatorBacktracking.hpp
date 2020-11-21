#ifndef BACKTRACKING
#define BACKTRACKING
#include "ColorComparator.hpp"
#include <math.h>

#define AUMENTO_CRITERIO 10
#define MAX_ANCHO 2000
#define FRAGMENTO MAX_ANCHO / 4
class ComparatorBacktracking : public ColorComparator
{

private:
    int cantidadBlancosMejorSolucion;
    int criterioMejorSolucion;
    vector<vector<Country>> coloresMejorSolucion;

public:
    ComparatorBacktracking(XMLParser *parser)
    {
        this->cantidadBlancosMejorSolucion = -1;
        this->criterioMejorSolucion = -1;
        setPintador(parser);
    }

    ComparatorBacktracking(vector<Color *> pColores, int pCantidadPorPintar) : ColorComparator(pColores, pCantidadPorPintar)
    {
        //test thi
        this->cantidadBlancosMejorSolucion = -1;
        this->criterioMejorSolucion = -1;
    }

    void comparar(vector<Country> pPaises)
    {
        inicioTimer = chrono::high_resolution_clock::now();
        for (int posicion = 0; posicion <= MAX_ANCHO; posicion += AUMENTO_CRITERIO)
        {
            pPaises = ordenamiento(pPaises, posicion);
            if (compararMejorSolucion(pPaises))
            {
                this->cantidadBlancosMejorSolucion = paisesBlancos.size();
                this->criterioMejorSolucion = posicion;
                this->coloresMejorSolucion.clear();
                for (Color *color : colores)
                {
                    coloresMejorSolucion.push_back(color->getPaises());
                }
                coloresMejorSolucion.push_back(paisesBlancos);
            }
            finTimer = chrono::high_resolution_clock::now();
            lapso = finTimer - inicioTimer;
            pintador->blanquearMapa(paisesBlancos);
            pintador->pintarPais(colores, "svg//backtracking.svg", lapso.count());
        }
        int contador = 0;
        for (Color *color : colores)
        {
            color->setPaises(coloresMejorSolucion.at(contador));
            contador++;
        }
        paisesBlancos = coloresMejorSolucion.at(contador);
        finTimer = chrono::high_resolution_clock::now();
        lapso = finTimer - inicioTimer;
        pintador->blanquearMapa(paisesBlancos);
        pintador->pintarPais(colores, "svg//backtracking.svg", lapso.count());
    }

    vector<Country> ordenamiento(vector<Country> pPaises, int pPosicion)
    {
        int posicionAltura = pPosicion / 2;
        vector<Country> world;
        for (Country pais : pPaises)
        {
            float distancia = distanciaEntrePuntos(pais.getCountryBorder().front().first, pais.getCountryBorder().front().second, pPosicion, posicionAltura);
            vector<Country>::iterator index = world.begin();
            if (distancia <= FRAGMENTO)
            {
                world.insert(index, pais);
            }
            else if (distancia <= FRAGMENTO * 2)
            {
                index = world.begin() + world.size() / 4;
                world.insert(index, pais);
            }
            else if (distancia <= FRAGMENTO * 3)
            {
                index = world.begin() + world.size() / 2;
                world.insert(index, pais);
            }
            else
            {
                world.push_back(pais);
            }
        }
        return world;
    }

    float distanciaEntrePuntos(float pFirstValueX, float pFirstValueY, float pSecondValueX, float pSecondValueY)
    {
        float firstOperando = pow(pSecondValueX - pFirstValueX, 2);
        float secondOperando = pow(pSecondValueX - pFirstValueX, 2);
        float distancia = sqrt(firstOperando + secondOperando);
        return distancia;
    }

    bool compararMejorSolucion(vector<Country> pPaises)
    {
        limpieza();
        for (Country pais : pPaises)
        {
            if (paisesBlancos.size() > cantidadBlancosMejorSolucion)
            {
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

    void limpieza()
    {
        paisesBlancos.clear();
        for (Color *color : colores)
        {
            color->limpiarPaises();
        }
    }

    void imprimir()
    {
        for (Color *color : colores)
        {
            cout << "Color: " << color->getColorCode() << "\nCantidad de paises: " << color->getCantidadPaises() << endl;
            cout << endl;
        }
        cout << "Color: Mejor Blanco \nCantidad de paises: " << cantidadBlancosMejorSolucion << endl;
        cout << "Mejor Criterio: " << criterioMejorSolucion << endl;
    }
};

#endif