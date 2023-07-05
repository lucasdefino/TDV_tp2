#include "heuristica_3.h"
#include <iostream>
using namespace std;

Heuristica3::Heuristica3() {}

Heuristica3::Heuristica3(ReadInstance &instance) {
    this->_instance = instance;
    this->_solucion;
    this->_objective_value = 0;
    this->_capacidades_restantes;
}
//POV CAPITANES DE EQUIPO
void Heuristica3::solve() {
    this->_capacidades_restantes = this->_instance.capacidades;
    int demanda_maxima = 0;
    int i = 0;

    while(i < this->_instance.m){
        int vendedor_mas_barato = -2;

        while (vendedor_mas_barato != -1){
            int j = 0;
            double menor_costo = 999;
            vendedor_mas_barato = -1;

            while (j < this->_instance.n){
                if (this->_solucion.isVendedorAsignado(j)==0){
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
                this->_solucion.assign(vendedor_mas_barato, i);
                this->_capacidades_restantes[i] -= this->_instance.demandas[vendedor_mas_barato];
                _objective_value += this->_instance.costos[i][vendedor_mas_barato];
            }
        }
        i++;
    }

    int vendedores_sin_asignar = 0; 
    for (int i = 0; i < this->_instance.n; i++){
        if (this->_solucion.isVendedorAsignado(i) != 0){
            vendedores_sin_asignar++;
        }
    }
    _objective_value += vendedores_sin_asignar*demanda_maxima*3;

}

double Heuristica3::getObjectiveValue() const {
    return this->_objective_value;
}

Solucion Heuristica3::getSolucion() const {
    return this->_solucion;
}

vector<int> Heuristica3::getCapRes() const {
    return this->_capacidades_restantes;
}


