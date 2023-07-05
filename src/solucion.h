#ifndef SOLUCION
#define SOLUCION

#include<vector>
#include<iostream>

class Solucion
{
	public:
        Solucion();
        Solucion(int n, int m);

        int getN() const;
        int getM() const;
        void assign(int deposito, int vendedor);
        bool isVendedorAssigned(int vendedor) const;
        int getAssignedVendedor(int deposito) const;
        int getAssignedDeposito(int vendedor) const;

        //friend std::ostream& operator<<(std::ostream& os, const Solucion& solution);

	
	private:
        int _n;
        int _m;
        std::vector<int> _asigancion_vendedores;
};
#endif