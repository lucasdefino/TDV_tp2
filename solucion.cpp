#include "solucion.h"

Solucion::Solucion() {}

Solucion::Solucion(ReadInstance &instance) {
    this->_n = instance.n;
    this->_m = instance.m;
    this->objective_value = 0;
    this->_vendedores_asignados = 0;
    this->_asigancion_vendedores = std::vector<int>(instance.n, -1);
    this->capacidades_restantes = instance.capacidades;
    this->_demandas = instance.demandas;
}

int Solucion::getN() const {
    return this->_n;
}

int Solucion::getM() const {
    return this->_m;
}

void Solucion::assign(int deposito, int vendedor, ReadInstance &instance) {
    //si el vendedor estaba asignado a otro deposito lo desasigno primero
        if(this->_asigancion_vendedores[vendedor] != -1){
            this->_vendedores_asignados--;
            this->capacidades_restantes[this->_asigancion_vendedores[vendedor]] += instance.demandas[vendedor];
            this->objective_value -= instance.costos[this->_asigancion_vendedores[vendedor]][vendedor];
        }
        
        this->_asigancion_vendedores[vendedor] = deposito;
        this->_vendedores_asignados++;
        this->capacidades_restantes[deposito] -= instance.demandas[vendedor];
        this->objective_value += instance.costos[deposito][vendedor];
}

void Solucion::reassign(int deposito, int vendedor, ReadInstance &instance) {
    if(deposito == -1){
        if(this->_asigancion_vendedores[vendedor] != -1){
            
        } else {
        this->_vendedores_asignados--;
        this->capacidades_restantes[this->_asigancion_vendedores[vendedor]] += instance.demandas[vendedor];
        this->objective_value -= instance.costos[this->_asigancion_vendedores[vendedor]][vendedor];
        this->objective_value += 3*instance.demanda_maxima;
        }
    } else {
        //si el vendedor estaba asignado a otro deposito lo desasigno primero
        if(this->_asigancion_vendedores[vendedor] != -1){
            this->_vendedores_asignados--;
            this->capacidades_restantes[this->_asigancion_vendedores[vendedor]] += instance.demandas[vendedor];
            this->objective_value -= instance.costos[this->_asigancion_vendedores[vendedor]][vendedor];
            this->objective_value += 3*instance.demanda_maxima;
        }
        
        this->_asigancion_vendedores[vendedor] = deposito;
        this->_vendedores_asignados++;
        this->capacidades_restantes[deposito] -= instance.demandas[vendedor];
        this->objective_value += instance.costos[deposito][vendedor];
        this->objective_value -= 3*instance.demanda_maxima;
    }
}

bool Solucion::isVendedorAsignado(int vendedor) const {
    return this->_asigancion_vendedores[vendedor] != -1;
}

int Solucion::getDepositoAsignado(int vendedor) const {
    return this->_asigancion_vendedores[vendedor];
}

int Solucion::getVendedoresAsignados() const {
    return this->_vendedores_asignados;
}

int Solucion::getDemanda(int vendedor) const {
    return this->_demandas[vendedor];
}


