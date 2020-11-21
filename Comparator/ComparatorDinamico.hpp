#ifndef DINAMICO
#define DINAMICO
#include "ColorComparator.hpp"
#include <queue>

class ComparatorDinamico : public ColorComparator
{

private:
    int contadorParaBlanco;
    priority_queue<Color*> priorityQueue;
    priority_queue<Color*> priorityQueueAux;
public:

    ComparatorDinamico(XMLParser *parser) : ColorComparator()
    {
        setPintador(parser);
        contadorParaBlanco = 0;
    }

    ComparatorDinamico(vector<Color *> pColores, int pCantidadPorPintar) : ColorComparator(pColores, pCantidadPorPintar) {}
    void fillQueue(){        
        for(Color * color : colores){
            priorityQueue.push(color);
        }
    }
    void comparar(vector<Country> pPaises)
    {
        inicioTimer= chrono::high_resolution_clock::now();
        fillQueue();
        Color *colorActual = priorityQueue.top();
        bool esBlanco = false;
        for (Country pais : pPaises)
        {
            if (contadorPintados == cantidadNecesariaPorPintar)
            {
                finTimer = chrono::high_resolution_clock::now();
                lapso = finTimer-inicioTimer;
                contadorPintados = 0;
                pintador->blanquearMapa(paisesBlancos);
                pintador->pintarPais(colores, "svg//dinamic.svg", lapso.count());
            }
            while (colorActual->verificarColor(pais))
            {
                if(priorityQueue.empty()){
                    esBlanco = true;
                    break;
                }
                priorityQueueAux.push(priorityQueue.top());
                priorityQueue.pop();
                colorActual = priorityQueue.top();
            }        
            if (!esBlanco)
            {
                colorActual->insertarPais(pais);
                contadorPintados++;
            }
            else
            {
                paisesBlancos.push_back(pais);
                esBlanco = false;
            }
            while(!priorityQueueAux.empty()){
                priorityQueue.push(priorityQueueAux.top());
                priorityQueueAux.pop();
            }
        }
        finTimer = chrono::high_resolution_clock::now();
        lapso = finTimer-inicioTimer;
        pintador->blanquearMapa(paisesBlancos);
        pintador->pintarPais(colores, "svg//dinamic.svg", lapso.count());
    }
};

#endif