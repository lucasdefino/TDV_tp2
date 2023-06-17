#include "heuristica_1.h"
#include <iostream>
using namespace std;

Heuristica1Solver::Heuristica1Solver() {}

Heuristica1Solver::Heuristica1Solver(ReadInstance &instance) {
    this->_instance = instance;
    this->_solution;
    this->_objective_value = 0;
    this->_capacidades_restantes;
}
//POV VENDEDORES
void Heuristica1Solver::solve() {
    this->_capacidades_restantes = this->_instance.capacidades;
    int vendedores_sin_asignar = 0; 
    int demanda_maxima = 0;
    
    int j = 0;
    while(j < this->_instance.n){
        int i = 0;
        double menor_costo = 999;
        int deposito_mas_barato = -1;

        while (i < this->_instance.m){
            double costo_actual = this->_instance.costos[i][j];
            
            if (costo_actual < menor_costo){

                if(this->_capacidades_restantes[i]-this->_instance.demandas[j] >= 0){
                    deposito_mas_barato=i;
                    menor_costo=costo_actual;
                }
            }
            i++;
        }


        _solution.push_back(deposito_mas_barato);

        if (demanda_maxima < this->_instance.demandas[j]){
            demanda_maxima = this->_instance.demandas[j];
        }

        if (deposito_mas_barato != -1) {
            this->_capacidades_restantes[i] -= this->_instance.demandas[j];
            _objective_value += this->_instance.costos[deposito_mas_barato][j];
        } else {
            vendedores_sin_asignar++;
        }

        j++;
    }

    _objective_value += vendedores_sin_asignar*demanda_maxima*3;

}


double Heuristica1Solver::getObjectiveValue() const {
    return this->_objective_value;
}

vector<int> Heuristica1Solver::getSolution() const {
    return this->_solution;
}

vector<int> Heuristica1Solver::getCapRes() const {
    return this->_capacidades_restantes;
}