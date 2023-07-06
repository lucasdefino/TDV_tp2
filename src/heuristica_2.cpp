#include "heuristica_2.h"
#include <iostream>
using namespace std;

Heuristica2::Heuristica2() {}

Heuristica2::Heuristica2(ReadInstance &instance) {
    this->_instance = instance;
    this->_solucion = Solucion(instance);
    this->_objective_value = 0;
}
//POV DEPOSITOS
void Heuristica2::solve() {
    int demanda_maxima = 0;
    int i = 0;

    while(i < this->_instance.m){
        int vendedor_mas_barato = -2;

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

            if (demanda_maxima < this->_instance.demandas[vendedor_mas_barato]){
                demanda_maxima = this->_instance.demandas[vendedor_mas_barato];
            }
            if (vendedor_mas_barato != -1) {
                this->_solucion.assign(i,vendedor_mas_barato);
                _objective_value += this->_instance.costos[i][vendedor_mas_barato];
            }
        }
        i++;
    }
    
    _objective_value += this->_solucion.getVendedoresAsignado()*demanda_maxima*3;

}

double Heuristica2::getObjectiveValue() const {
    return this->_objective_value;
}

Solucion Heuristica2::getSolucion() const {
    return this->_solucion;
}
