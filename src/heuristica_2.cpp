#include "heuristica_2.h"
#include <iostream>
using namespace std;

Heuristica2Solver::Heuristica2Solver() {}

Heuristica2Solver::Heuristica2Solver(ReadInstance &instance) {
    this->_instance = instance;
    this->_solution = vector<int>(this->_instance.n,-1);
    this->_objective_value = 0;
}
//POV DEPOSITOS
void Heuristica2Solver::solve() {
    vector<int> capacidad_restante = this->_instance.capacidades;
    int vendedores_sin_asignar = 0; 
    int demanda_maxima = 0;
    vector<int> asignados(this->_instance.n,0);
    
    int i = 0;
    while(i < this->_instance.m){
        int j = 0;
        double menor_costo = 999;
        int vendedor_mas_barato = -1;

        while (j < this->_instance.n){
            if (asignados[j]==0){
                double costo_actual = this->_instance.costos[i][j];
                
                if (costo_actual < menor_costo){

                    if(capacidad_restante[i]-this->_instance.demandas[j] >= 0){
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
            _solution[vendedor_mas_barato] = i;
            capacidad_restante[i] = capacidad_restante[i]-this->_instance.demandas[vendedor_mas_barato];
            _objective_value += this->_instance.costos[i][vendedor_mas_barato];
        } else {
            vendedores_sin_asignar++;
        }
        i++;
    }

    _objective_value += vendedores_sin_asignar*demanda_maxima*3;

}


double Heuristica2Solver::getObjectiveValue() const {
    return this->_objective_value;
}

vector<int> Heuristica2Solver::getSolution() const {
    return this->_solution;
}
