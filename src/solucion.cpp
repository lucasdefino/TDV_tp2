#include "solucion.h"

Solucion::Solucion() {}

Solucion::Solucion(int n, int m) {
    this->_n = n;
    this->_m = m;
    this->_asigancion_vendedores = std::vector<int>(n, -1);
}

int Solucion::getN() const {
    return this->_n;
}

int Solucion::getM() const {
    return this->_m;
}

void Solucion::assign(int deposito, int vendedor) {
    this->_asigancion_vendedores[vendedor] = deposito;
}

bool Solucion::isVendedorAssigned(int vendedor) const {
    return this->_asigancion_vendedores[vendedor] != -1;
}

int Solucion::getAssignedDeposito(int vendedor) const {
    return this->_asigancion_vendedores[vendedor];
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

