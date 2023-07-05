#include "heuristica_0.h"
#include <iostream>
using namespace std;

Heuristica0::Heuristica0() {}

Heuristica0::Heuristica0(ReadInstance &instance) {
    this->_instance = instance;
    this->_solucion = Solucion(instance);
    this->_objective_value = 0;
}
//POV VENDEDORES
void Heuristica0::solve() {
    int demanda_maxima = 0;
    
    int j = 0;
    while(j < this->_instance.n){
        int i = 0;
        double menor_costo = 999;
        int deposito_mas_barato = -1;

        while (i < this->_instance.m){
            double costo_actual = this->_instance.costos[i][j];
            
            if (costo_actual < menor_costo){

                if(_solucion.getCapacidadRestante(i)-this->_instance.demandas[j] >= 0){
                    deposito_mas_barato=i;
                    menor_costo=costo_actual;
                }
            }
            i++;
        }


        if (demanda_maxima < this->_instance.demandas[j]){
            demanda_maxima = this->_instance.demandas[j];
        }

        if (deposito_mas_barato != -1) {
            this->_solucion.assign(deposito_mas_barato,j);
            _objective_value += this->_instance.costos[deposito_mas_barato][j];
        }

        j++;
    }

    _objective_value += this->_solucion.getVendedoresAsignado()*demanda_maxima*3;

}


double Heuristica0::getObjectiveValue() const {
    return this->_objective_value;
}

Solucion Heuristica0::getSolucion() const {
    return this->_solucion;
}

vector<int> Heuristica0::getCapRes() const {
    return this->_capacidades_restantes;
}