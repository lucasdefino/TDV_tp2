#include "meta_heuristica.h"
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <limits>
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
        double menor_costo = std::numeric_limits<double>::max();
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

    
    this->_solucion.objective_value += (_instance.n - this->_solucion.getVendedoresAsignados())*this->_instance.costo_maximo*3;

}

/////////// Heurística 1 - Los depósitos eligen ///////////
void MetaHeuristica::heuristica_1() {
    int i = 0;

    while(i < this->_instance.m){
        int vendedor_mas_barato = 0;

        while (vendedor_mas_barato != -1){
            int j = 0;
            double menor_costo = std::numeric_limits<double>::max();
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
    
    this->_solucion.objective_value += (_instance.n - this->_solucion.getVendedoresAsignados())*this->_instance.costo_maximo*3;

}

/////////// Heurística 2 - Capitanes de equipo ///////////
void MetaHeuristica::heuristica_2() {
    int i = 0;
    int j = 0;

    while(j < this->_instance.n){
        int vendedor_mas_barato = -1;
        int k = 0;
        double menor_costo = std::numeric_limits<double>::max();

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

    this->_solucion.objective_value += (_instance.n - this->_solucion.getVendedoresAsignados())*this->_instance.costo_maximo*3;
}

// /////////// Operador de Búsqueda Local 1 - Swap ///////////
void MetaHeuristica::swap() {
	bool haymejora = true;
	while (haymejora) {
		haymejora = false;
        Solucion best_sol = this->_solucion;
        int i = 0;
        while(i < this->_instance.n){
            int j = i+1;
            while (j<this->_instance.n){
                if (this->_solucion.isVendedorAsignado(i)==0 && this->_solucion.isVendedorAsignado(j)==0){
                    
                } else {
                    int capres_dep_i = 0;
                    int capres_dep_j = 0;
                    if (this->_solucion.isVendedorAsignado(i)){
                        int capres_dep_i = this->_solucion.capacidades_restantes[this->_solucion.getDepositoAsignado(i)] + this->_instance.demandas[i] - this->_instance.demandas[j];
                    }
                    if (this->_solucion.isVendedorAsignado(j)){
                        int capres_dep_j = this->_solucion.capacidades_restantes[this->_solucion.getDepositoAsignado(j)] + this->_instance.demandas[j] - this->_instance.demandas[i];
                    }
                    if( capres_dep_i >=0 && capres_dep_j >=0 ){              
                        Solucion aux = this->_solucion; 
                        int dep_i = aux.getDepositoAsignado(i);
                        int dep_j = aux.getDepositoAsignado(j);
                        aux.reassign(dep_i,j,_instance);
                        aux.reassign(dep_j,i,_instance);
                        if (aux.objective_value < best_sol.objective_value){
                            best_sol = aux;
                            haymejora = true;
                        }
                    }
                }
                j++;
            }
            i++;
        }
        this->_solucion = best_sol;

	}
}

/////////// Operador de Búsqueda Local 2 - Relocate ///////////
void MetaHeuristica::relocate() {
    bool haymejora = true;
	while (haymejora) {
		haymejora = false;
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
                        aux.objective_value -= this->_instance.costo_maximo*3; 
                    }
                    if (aux.objective_value < best_sol.objective_value){
                        best_sol = aux;
                        haymejora = false;
                    }
                }
                i++;
            }
            j++;
        }
        this->_solucion = best_sol;

    }
}

/////////// Metaheuristica Variable Neighborhood Descent ///////////
void MetaHeuristica::vnd(int max_iter, bool orden) {
    int k = 0;
    int contador = 0;
    while(k<2 && contador<max_iter){
        contador++;
        MetaHeuristica aux = *this;
        if(k==0){
            if (orden == 0){aux.swap();}
            else {aux.relocate();}
        } else if (k==1) {
            if (orden == 1){aux.swap();}
            else {aux.relocate();}
        }
        if(aux.getObjectiveValue() < this->_solucion.objective_value){
            this->_solucion = aux._solucion;
            k=0;
        } else {
            k += 1;
        }
    }
}

/////////// ILS ///////////
void MetaHeuristica::ils(int max_iter, float porcentaje_pert) {
    Solucion best_sol = this->_solucion;
    MetaHeuristica aux = *this;
    int contador = 0;
    while (contador<max_iter) {
        contador++;
        //aux.swap();
        //aux.vnd(max_iter/2);
        if(aux.getObjectiveValue() < best_sol.objective_value){
            best_sol = aux._solucion;
        }
        aux.perturbacion((this->_instance.n)*porcentaje_pert); 
    }
    this->_solucion = best_sol;

}

void MetaHeuristica::perturbacion(int cant_ran) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, this->_instance.n-1);

    vector<int> randomNumbers;
    while (randomNumbers.size() < cant_ran) {
        int randomNumber = distribution(generator);
        if (find(randomNumbers.begin(), randomNumbers.end(), randomNumber) == randomNumbers.end()) {
            randomNumbers.push_back(randomNumber);
        }
    }

    for(auto i : randomNumbers){
        for(auto j : randomNumbers){
            if ((this->_solucion.isVendedorAsignado(i)==0 && this->_solucion.isVendedorAsignado(j)==0) || (j==i)){
            } else {
                int capres_dep_i = 0;
                int capres_dep_j = 0;
                if (this->_solucion.isVendedorAsignado(i)){
                    int capres_dep_i = this->_solucion.capacidades_restantes[this->_solucion.getDepositoAsignado(i)] + this->_instance.demandas[i] - this->_instance.demandas[j];
                }
                if (this->_solucion.isVendedorAsignado(j)){
                    int capres_dep_j = this->_solucion.capacidades_restantes[this->_solucion.getDepositoAsignado(j)] + this->_instance.demandas[j] - this->_instance.demandas[i];
                }
                if( capres_dep_i >=0 && capres_dep_j >=0 ){              
                    int dep_i = this->_solucion.getDepositoAsignado(i);
                    int dep_j = this->_solucion.getDepositoAsignado(j);
                    this->_solucion.reassign(dep_i,j,_instance);
                    this->_solucion.reassign(dep_j,i,_instance);
                }
            }
            j++;
        }
    }
        
}

double MetaHeuristica::getObjectiveValue() const {
    return this->_solucion.objective_value;
}