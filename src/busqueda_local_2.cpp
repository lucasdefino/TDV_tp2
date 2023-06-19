#include "busqueda_local_2.h"
#include <iostream>
using namespace std;

BusquedaLocal2::BusquedaLocal2() {}

BusquedaLocal2::BusquedaLocal2(ReadInstance &instance) {
    this->_instance = instance;
    this->_objective_value = 0;
    this->_capacidades_restantes;
    this->_solution;
}

void BusquedaLocal2::MejorMejor(double objective_value,vector<int> solution, vector<int> capres) {
    this->_solution = solution;
    this->_capacidades_restantes = capres;
    this->_objective_value = objective_value;

    int i = 0;
    while(i<this->_instance.n){
        double best_obj_val = this->_objective_value;
        vector<int> best_sol = this->_solution;
        vector<int> best_capres = this->_capacidades_restantes;

        int j = i+1;
        while (j<this->_instance.n){
            int capres_dep_i = this->_capacidades_restantes[this->_solution[i]] + this->_instance.demandas[i] - this->_instance.demandas[j];
            int capres_dep_j = this->_capacidades_restantes[this->_solution[j]] + this->_instance.demandas[j] - this->_instance.demandas[i];
            if( capres_dep_i >=0 && capres_dep_j >=0 ){
                int obj_val_aux = this->_objective_value + this->_instance.costos[this->_solution[i]][j] + this->_instance.costos[this->_solution[j]][i] - this->_instance.costos[this->_solution[i]][i] - this->_instance.costos[this->_solution[j]][j];
                if (obj_val_aux < best_obj_val){
                    best_obj_val = obj_val_aux;
                    int deposito_aux = best_sol[i];
                    best_sol[i] = best_sol[j];
                    best_sol[j] = deposito_aux;
                    best_capres[best_sol[i]] = capres_dep_i;
                    best_capres[best_sol[j]] = capres_dep_j;
                }
            }
            j++;
        }
        this->_objective_value = best_obj_val;
        this->_solution[i] = best_sol[i];
        this->_solution[j] = best_sol[j];
        this->_capacidades_restantes[this->_solution[i]] = best_capres[best_sol[i]];
        this->_capacidades_restantes[this->_solution[j]] = best_capres[best_sol[j]];
        i++;
    }
}

double BusquedaLocal2::getObjectiveValue() const {
    return this->_objective_value;
}

vector<int> BusquedaLocal2::getSolution() const {
    return this->_solution;
}

vector<int> BusquedaLocal2::getCapRes() const {
    return this->_capacidades_restantes;
}