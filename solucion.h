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

        // assign realiza las operaciones necesarias para asociar a un vendedor con un deposito
        void assign(int deposito, int vendedor, ReadInstance &instance);
        void reassign(int deposito, int vendedor, ReadInstance &instance);

        // devuelve true si el vendedor ya fue asignado a un deposito
        bool isVendedorAsignado(int vendedor) const;

        // devuelve la cantidad de vendedores asignados
        int getVendedoresAsignados() const;

        // para un vendedor devuelve su deposito asignado
        int getDepositoAsignado(int vendedor) const;

        // para un vendedor devuelve su demanda asociada
        int getDemanda(int vendedor) const;
	
        double objective_value;
        std::vector<int> capacidades_restantes;

	private:
        int _n;
        int _m;
        int _vendedores_asignados;
        
        std::vector<int> _asigancion_vendedores;
        std::vector<int> _demandas;
        
};
#endif