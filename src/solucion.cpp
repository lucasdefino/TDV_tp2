#include "solucion.h"

Solucion::Solucion() {}

Solucion::Solucion(ReadInstance &instance) {
    this->_n = instance.n;
    this->_m = instance.m;
    this->objective_value = 0;
    this->_vendedores_asignados = 0;
    this->_asigancion_vendedores = std::vector<int>(instance.n, -1);
    this->_capacidades_restantes = instance.capacidades;
    this->_demandas = instance.demandas;
}

int Solucion::getN() const {
    return this->_n;
}

int Solucion::getM() const {
    return this->_m;
}

void Solucion::assign(int deposito, int vendedor, ReadInstance &instance) {
    if(this->_asigancion_vendedores[vendedor] != -1){
        this->_vendedores_asignados--;
        this->_capacidades_restantes[this->_asigancion_vendedores[vendedor]] += instance.demandas[vendedor];
        this->objective_value -= instance.costos[this->_asigancion_vendedores[vendedor]][vendedor];
    }
    
    this->_asigancion_vendedores[vendedor] = deposito;
    this->_vendedores_asignados++;
    this->_capacidades_restantes[deposito] -= instance.demandas[vendedor];
    this->objective_value += instance.costos[deposito][vendedor];
}

bool Solucion::isVendedorAsignado(int vendedor) const {
    return this->_asigancion_vendedores[vendedor] != -1;
}

int Solucion::getDepositoAsignado(int vendedor) const {
    return this->_asigancion_vendedores[vendedor];
}

int Solucion::getCapacidadRestante(int deposito) const {
    return this->_capacidades_restantes[deposito];
}

int Solucion::getVendedoresAsignados() const {
    return this->_vendedores_asignados;
}

int Solucion::getDemanda(int vendedor) const {
    return this->_demandas[vendedor];
}

// std::ostream& operator<<(std::ostream& os, const TaxiAssignmentSolution& solution) {
//     os << "taxis: ";
//     for (int i = 0; i < solution.getN(); i++)
//         os << solution.getAssignedPax(i) << " ";
//     os << std::endl;
//     os << "paxs: ";
//     for (int i = 0; i < solution.getN(); i++)
//         os << solution.getAssignedTaxi(i) << " ";
//     os << std::endl;
//     os << "taxi \t --> \t pax" << std::endl;
//     for (int i = 0; i < solution.getN(); i++) {
//         os << i << " \t --> \t" << solution.getAssignedPax(i) << std::endl;
//     }

//     return os;
// }

