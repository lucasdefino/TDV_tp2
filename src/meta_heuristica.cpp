#include "meta_heuristica.h"
#include <iostream>
using namespace std;

MetaHeuristica::MetaHeuristica() {}

MetaHeuristica::MetaHeuristica(ReadInstance &instance) {
    this->_instance = instance;
    this->_solucion = Solucion(instance);
}

/////////// Heurística 0 - Los vendedores eligen ///////////
void MetaHeuristica::heuristica_0() {    
    int j = 0;
    while(j < this->_instance.n){
        int i = 0;
        double menor_costo = 999;
        int deposito_mas_barato = -1;

        while (i < this->_instance.m){
            double costo_actual = this->_instance.costos[i][j];
            
            if (costo_actual < menor_costo){

                if(_solucion.capacidades_restantes[i]-this->_instance.demandas[j] >= 0){
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

/////////// Heurística 1 - Los depósitos eligen ///////////
void MetaHeuristica::heuristica_1() {
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

                        if(this->_solucion.capacidades_restantes[i]-this->_instance.demandas[j] >= 0){
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

/////////// Heurística 2 - Capitanes de equipo ///////////
void MetaHeuristica::heuristica_2() {
    int i = 0;
    int j = 0;

    while(j < this->_instance.n){
        int vendedor_mas_barato = -1;
        int k = 0;
        double menor_costo = 999;

        while (k < this->_instance.n){
            if (_solucion.isVendedorAsignado(k)==false){
                double costo_actual = this->_instance.costos[i][k];

                if (costo_actual < menor_costo){
                    if(this->_solucion.capacidades_restantes[i]-this->_instance.demandas[k] >= 0){
                        vendedor_mas_barato=k;
                        menor_costo=costo_actual;
                    }
                }
            }
            k++;
        }
        
        if (vendedor_mas_barato != -1) {
            this->_solucion.assign(i,vendedor_mas_barato,_instance);
        }
        
        i++;
        if (i == this->_instance.m) {
            i = 0;
        }
        j++;
    }

    this->_solucion.objective_value += (_instance.n - this->_solucion.getVendedoresAsignados())*this->_instance.demanda_maxima*3;
}

/////////// Operador de Búsqueda Local 1 - Swap ///////////
void MetaHeuristica::swap() {
    Solucion best_sol = this->_solucion;

    int i = 0;
    while(i < this->_instance.n){
        if (this->_solucion.isVendedorAsignado(i)){
            int j = i+1;
            while (j<this->_instance.n){
                if (this->_solucion.isVendedorAsignado(j)){
                    int capres_dep_i = this->_solucion.capacidades_restantes[this->_solucion.getDepositoAsignado(i)] + this->_instance.demandas[i] - this->_instance.demandas[j];
                    int capres_dep_j = this->_solucion.capacidades_restantes[this->_solucion.getDepositoAsignado(j)] + this->_instance.demandas[j] - this->_instance.demandas[i];
                    
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

/////////// Operador de Búsqueda Local 2 - Relocate ///////////
void MetaHeuristica::relocate() {
    int aux_i = 0;
    int aux_j = 0;

    Solucion best_sol = this->_solucion;
    int j = 0;
    while(j < this->_instance.n){
        int i = 0;
        while (i < this->_instance.m){
            int capres = this->_solucion.capacidades_restantes[i] - this->_instance.demandas[j];
            if(capres >=0){              
                Solucion aux = this->_solucion;
                aux.assign(i,j,_instance);
                if (this->_solucion.isVendedorAsignado(j)==0){
                    aux.objective_value -= this->_instance.demanda_maxima*3; 
                }
                if (aux.objective_value < best_sol.objective_value){
                    best_sol = aux;
                    aux_i = i;
                    aux_j = j;
                }
            }
            i++;
        }
        j++;
    }
    this->_solucion = best_sol;
}

/////////// Metaheuristica Variable Neighborhood Descent ///////////
void MetaHeuristica::vnd() {
    int k = 0;
    int contador = 0;
    while(k<2){
        contador++;
        MetaHeuristica aux = *this;
        if(k==0){
            aux.swap();
        } else if (k==1) {
            aux.relocate();
        }
        if(aux.getObjectiveValue() < this->_solucion.objective_value){
            this->_solucion = aux._solucion;
            k=0;
        } else {
            k += 1;
        }
    }
}

double MetaHeuristica::getObjectiveValue() const {
    return this->_solucion.objective_value;
}