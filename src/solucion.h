#ifndef SOLUCION
#define SOLUCION

#include<vector>
#include<iostream>
#include "read_instance.h"

class Solucion
{
	public:
        Solucion();
        Solucion(ReadInstance &instance);

        int getN() const;
        int getM() const;
        void assign(int deposito, int vendedor, ReadInstance &instance);
        bool isVendedorAsignado(int vendedor) const;
        int getVendedoresAsignado() const;
        int getDepositoAsignado(int vendedor) const;
        int getCapacidadRestante(int deposito) const;
        double getObjectiveValue() const;
        int getDemanda(int vendedor) const;

        //friend std::ostream& operator<<(std::ostream& os, const Solucion& solution);
	
	private:
        int _n;
        int _m;
        int _vendedores_asignados;
        double _objective_value;
        std::vector<int> _asigancion_vendedores;
        std::vector<int> _capacidades_restantes;
        std::vector<int> _demandas;
        
};
#endif