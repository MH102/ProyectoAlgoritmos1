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
        fillQueue();
        Color *colorActual = priorityQueue.top();
        bool esBlanco = false;
        for (Country pais : pPaises)
        {
            if (contadorPintados == cantidadNecesariaPorPintar)
            {
                contadorPintados = 0;
                pintador->pintarPais(colores, "svg//dinamic.svg");
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
        pintador->pintarPais(colores, "svg//dinamic.svg");
    }
};

#endif