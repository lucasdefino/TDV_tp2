#include "busqueda_local.h"
#include <iostream>
using namespace std;

BusquedaLocal::BusquedaLocal() {}

BusquedaLocal::BusquedaLocal(Solucion &solucion) {
    this->_solucion = solucion;
    this->_objective_value = solucion.getObjectiveValue();
}

void BusquedaLocal::Swap() {
    
    Solucion best_sol = this->_solucion;

    int i = 0;
    while(i < this->_solucion.getN()){

        int j = i+1;
        // while (j<this->_solucion.getN()){
        //     int capres_dep_i = this->_solucion.getCapacidadRestante(this->_solucion.getDepositoAsignado(i)) + this->_solucion.getDemanda(i) - this->_solucion.getDemanda(j);
        //     int capres_dep_j = this->_solucion.getCapacidadRestante(this->_solucion.getDepositoAsignado(j)) + this->_solucion.getDemanda(j) - this->_solucion.getDemanda(i);
        //     if( capres_dep_i >=0 && capres_dep_j >=0 ){
        //         Solucion aux = this->_solucion;
        //         int dep_i = aux.getDepositoAsignado(i);
        //         aux.unassign(i);
        //         int dep_j = aux.getDepositoAsignado(j);
        //         aux.unassign(j);
        //         aux.assign(dep_i,j);
        //         aux.assign(dep_j,i);
        //         if (aux.getObjectiveValue() < best_sol.getObjectiveValue()){
        //             best_sol = aux;
        //         }
        //     }
        //     j++;

        // }

        i++;
    }
    this->_solucion = best_sol;
}

double BusquedaLocal::getObjectiveValue() const {
    return this->_solucion.getObjectiveValue();
}

Solucion BusquedaLocal::getSolucion() const {
    return this->_solucion;
}