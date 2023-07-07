#include "heuristica_1.h"
#include <iostream>
using namespace std;

Heuristica1::Heuristica1() {}

Heuristica1::Heuristica1(ReadInstance &instance) {
    this->_instance = instance;
    this->_solucion = Solucion(instance);
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
            }
        }
        i++;
    }
    
    this->_solucion.objective_value += (_instance.n - this->_solucion.getVendedoresAsignados())*this->_instance.demanda_maxima*3;

}

void Heuristica1::swap() {
    
    Solucion best_sol = this->_solucion;

    int i = 0;
    while(i < this->_instance.n){
        if (this->_solucion.isVendedorAsignado(i)){
            int j = i+1;
            while (j<this->_instance.n){
                if (this->_solucion.isVendedorAsignado(j)){
                    int capres_dep_i = this->_solucion.getCapacidadRestante(this->_solucion.getDepositoAsignado(i)) + this->_instance.demandas[i] - this->_instance.demandas[j];
                    int capres_dep_j = this->_solucion.getCapacidadRestante(this->_solucion.getDepositoAsignado(j)) + this->_instance.demandas[j] - this->_instance.demandas[i];
                    
                    if( capres_dep_i >=0 && capres_dep_j >=0 ){              
                        Solucion aux = this->_solucion; 
                        int dep_i = aux.getDepositoAsignado(i);
                        int dep_j = aux.getDepositoAsignado(j);
                        aux.assign(dep_i,j,_instance);
                        aux.assign(dep_j,i,_instance);
                        if (aux.objective_value < best_sol.objective_value){
                            best_sol = aux;
                        }
                    }
                }
                j++;
            }
        }
        i++;
    }
    this->_solucion = best_sol;
}

double Heuristica1::getObjectiveValue() const {
    return this->_solucion.objective_value;
}

Solucion Heuristica1::getSolucion() const {
    return this->_solucion;
}
