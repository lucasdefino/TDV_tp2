#include "heuristica_1.h"
#include <iostream>
using namespace std;

Heuristica1::Heuristica1() {}

Heuristica1::Heuristica1(ReadInstance &instance) {
    this->_instance = instance;
    this->_solution = vector<int>(this->_instance.n,-1);
    this->_objective_value = 0;
    this->_capacidades_restantes;
}
//POV DEPOSITOS
void Heuristica1::solve() {
    this->_capacidades_restantes = this->_instance.capacidades;
    int demanda_maxima = 0;
    vector<int> asignados(this->_instance.n,0);
    int i = 0;

    while(i < this->_instance.m){
        int vendedor_mas_barato = -2;

        while (vendedor_mas_barato != -1){
            int j = 0;
            double menor_costo = 999;
            vendedor_mas_barato = -1;

            while (j < this->_instance.n){
                if (asignados[j]==0){
                    double costo_actual = this->_instance.costos[i][j];
                    
                    if (costo_actual < menor_costo){

                        if(this->_capacidades_restantes[i]-this->_instance.demandas[j] >= 0){
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
                this->_capacidades_restantes[i] -= this->_instance.demandas[vendedor_mas_barato];
                _objective_value += this->_instance.costos[i][vendedor_mas_barato];
                asignados[vendedor_mas_barato] = 1;
            }
        }
        i++;
    }

    int vendedores_sin_asignar = 0; 
    for (int i = 0; i < asignados.size(); i++){
        if (asignados[i] == 0){
            vendedores_sin_asignar++;
        }
    }
    _objective_value += vendedores_sin_asignar*demanda_maxima*3;

}

double Heuristica1::getObjectiveValue() const {
    return this->_objective_value;
}

vector<int> Heuristica1::getSolution() const {
    return this->_solution;
}

vector<int> Heuristica1::getCapRes() const {
    return this->_capacidades_restantes;
}


