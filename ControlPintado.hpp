#ifndef CONTROL_PINTADO
#define CONTROL_PINTADO
// #include "Color.hpp"
#include "Painter.hpp"
#include <vector>


class ControlPintado{
private:
    
    int medidorPaisesPintados;
    vector<Country*> paisesPorPintar;

public:
    ControlPintado(int pMedidorPaises, vector<Country*> pPaisesPorPintar){
        this->medidorPaisesPintados = pMedidorPaises;
        this->paisesPorPintar = pPaisesPorPintar;
    }
    
    void hacerPintado(){
        Painter* pintor = new Painter();
        //Llama al metodo de painter
    }
    
};

#endif