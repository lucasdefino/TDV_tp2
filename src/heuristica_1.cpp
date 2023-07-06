#include "heuristica_1.h"
#include <iostream>
using namespace std;

Heuristica1::Heuristica1() {}

Heuristica1::Heuristica1(ReadInstance &instance) {
    this->_instance = instance;
    this->_solucion = Solucion(instance);
    this->_objective_value = 0;
}
//POV DEPOSITOS
void Heuristica1::solve() {
    int i = 0;

    while(i < this->_instance.m){
        int vendedor_mas_barato = 0;

        while (vendedor_mas_barato != -1){
            int j = 0;
            double menor_costo = 999;
            vendedor_mas_barato = -1;

            while (j < this->_instance.n){
                if (_solucion.isVendedorAsignado(j)==false){
                    double costo_actual = this->_instance.costos[i][j];
                    
                    if (costo_actual < menor_costo){

                        if(this->_solucion.getCapacidadRestante(i)-this->_instance.demandas[j] >= 0){
                            vendedor_mas_barato=j;
                            menor_costo=costo_actual;
                        }
                    }
                }
                j++;
            }

            if (vendedor_mas_barato != -1) {
                this->_solucion.assign(i,vendedor_mas_barato,_instance);
                _objective_value += this->_instance.costos[i][vendedor_mas_barato];
            }
        }
        i++;
    }
    
    //_objective_value += this->_solucion.getVendedoresAsignado()*this->_instance.demanda_maxima*3;

}

double Heuristica1::getObjectiveValue() const {
    return this->_objective_value;
}

Solucion Heuristica1::getSolucion() const {
    return this->_solucion;
}
