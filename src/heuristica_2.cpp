#include "heuristica_2.h"
#include <iostream>
using namespace std;

Heuristica2::Heuristica2() {}

Heuristica2::Heuristica2(ReadInstance &instance) {
    this->_instance = instance;
    this->_solucion = Solucion(instance);
    this->_objective_value = 0;
}
//POV CAPITANES DE EQUIPO
void Heuristica2::solve() {
    int i = 0;
    int j = 0;

    while(j < this->_instance.n){
        int vendedor_mas_barato = 0;
        int k = 0;
        double menor_costo = 999;

        while (k < this->_instance.n){
            if (_solucion.isVendedorAsignado(k)==false){
                double costo_actual = this->_instance.costos[i][k];

                if (costo_actual < menor_costo){
                    if(this->_solucion.getCapacidadRestante(i)-this->_instance.demandas[k] >= 0){
                        vendedor_mas_barato=k;
                        menor_costo=costo_actual;
                    }
                }
            }
            k++;
        }
        
        if (vendedor_mas_barato != -1) {
            this->_solucion.assign(i,vendedor_mas_barato,_instance);
            _objective_value += this->_instance.costos[i][vendedor_mas_barato];
        }
        
        i++;
        if (i == this->_instance.m) {
            i = 0;
        }
        j++;
    }
    //_objective_value += this->_solucion.getVendedoresAsignado()*this->_instance.demanda_maxima*3;
}

void Heuristica2::swap() {
    
    Solucion best_sol = this->_solucion;

    int i = 0;
    while(i < this->_instance.n){

        int j = i+1;
        while (j<this->_instance.n){
            int capres_dep_i = this->_solucion.getCapacidadRestante(this->_solucion.getDepositoAsignado(i)) + this->_instance.demandas[i] - this->_instance.demandas[j];
            int capres_dep_j = this->_solucion.getCapacidadRestante(this->_solucion.getDepositoAsignado(j)) + this->_instance.demandas[j] - this->_instance.demandas[i];
            
            if( capres_dep_i >=0 && capres_dep_j >=0 ){              
                Solucion aux = this->_solucion; 
                int dep_i = aux.getDepositoAsignado(i);
                //aux.unassign(dep_i,i,_instance);
                int dep_j = aux.getDepositoAsignado(j);
                //aux.unassign(dep_j,j,_instance);
                aux.assign(dep_i,j,_instance);
                aux.assign(dep_j,i,_instance);
                if (aux.getObjectiveValue() < best_sol.getObjectiveValue()){
                    best_sol = aux;
                }
            }
            j++;

        }

        i++;
    }
    this->_solucion = best_sol;
}

double Heuristica2::getObjectiveValue() const {
    return this->_solucion.getObjectiveValue();
}

Solucion Heuristica2::getSolucion() const {
    return this->_solucion;
}
