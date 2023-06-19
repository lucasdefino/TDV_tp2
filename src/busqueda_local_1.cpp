#include "busqueda_local_1.h"
#include <iostream>
using namespace std;

BusquedaLocal1::BusquedaLocal1() {}

BusquedaLocal1::BusquedaLocal1(ReadInstance &instance) {
    this->_instance = instance;
    this->_objective_value = 0;
    this->_capacidades_restantes;
    this->_solution;
}

void BusquedaLocal1::primerMejor(double objective_value,vector<int> solution, vector<int> capres) {
    this->_solution = solution;
    this->_capacidades_restantes = capres;
    this->_objective_value = objective_value;

    int i = 0;
    while(i<this->_instance.n){
        int j = i+1;
        while (j<this->_instance.n){
            int capres_dep_i = this->_capacidades_restantes[this->_solution[i]] + this->_instance.demandas[i] - this->_instance.demandas[j];
            int capres_dep_j = this->_capacidades_restantes[this->_solution[j]] + this->_instance.demandas[j] - this->_instance.demandas[i];
            if( capres_dep_i >=0 && capres_dep_j >=0 ){
                int obj_val_aux = this->_objective_value + this->_instance.costos[this->_solution[i]][j] + this->_instance.costos[this->_solution[j]][i] - this->_instance.costos[this->_solution[i]][i] - this->_instance.costos[this->_solution[j]][j];
                if (obj_val_aux < this->_objective_value){
                    this->_objective_value = obj_val_aux;
                    int deposito_aux = this->_solution[i];
                    this->_solution[i] = this->_solution[j];
                    this->_solution[j] = deposito_aux;
                    this->_capacidades_restantes[this->_solution[i]] = capres_dep_i;
                    this->_capacidades_restantes[this->_solution[j]] = capres_dep_j;
                    break;
                }
            }
            j++;
        }
        i++;
    }
}

double BusquedaLocal1::getObjectiveValue() const {
    return this->_objective_value;
}

vector<int> BusquedaLocal1::getSolution() const {
    return this->_solution;
}

vector<int> BusquedaLocal1::getCapRes() const {
    return this->_capacidades_restantes;
}