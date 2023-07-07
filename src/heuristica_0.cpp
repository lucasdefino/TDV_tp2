#include "heuristica_0.h"
#include <iostream>
using namespace std;

Heuristica0::Heuristica0() {}

Heuristica0::Heuristica0(ReadInstance &instance) {
    this->_instance = instance;
    this->_solucion = Solucion(instance);
}
//POV VENDEDORES
void Heuristica0::solve() {    
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

        if (deposito_mas_barato != -1) {
            this->_solucion.assign(deposito_mas_barato,j,_instance);
        }
        j++;
    }

    
    this->_solucion.objective_value += (_instance.n - this->_solucion.getVendedoresAsignados())*this->_instance.demanda_maxima*3;

}

void Heuristica0::swap() {
    
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
                int dep_j = aux.getDepositoAsignado(j);
                aux.assign(dep_i,j,_instance);
                aux.assign(dep_j,i,_instance);
                if (aux.objective_value < best_sol.objective_value){
                    best_sol = aux;
                }
            }
            j++;

        }

        i++;
    }
    this->_solucion = best_sol;
}

void Heuristica0::relocate() {
    
    Solucion best_sol = this->_solucion;

    int j = 0;
    while(j < this->_instance.n){
        int i = 0;
        while (i < this->_instance.m){
            int capres = this->_solucion.getCapacidadRestante(i) - this->_instance.demandas[j];
            
            if(capres >=0){              
                Solucion aux = this->_solucion; 
                aux.assign(i,j,_instance);
                if (aux.objective_value < best_sol.objective_value){
                    cout << "hola" << endl;
                    best_sol = aux;
                }
            }
            i++;
        }
        j++;
    }
    this->_solucion = best_sol;
}


double Heuristica0::getObjectiveValue() const {
    return this->_solucion.objective_value;
}

Solucion Heuristica0::getSolucion() const {
    return this->_solucion;
}