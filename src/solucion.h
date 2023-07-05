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
        bool isVendedorAsignado(int vendedor) const;
        int getVendedoresAsignado(int deposito) const;
        int getDepositoAsignado(int vendedor) const;

        //friend std::ostream& operator<<(std::ostream& os, const Solucion& solution);

	
	private:
        int _n;
        int _m;
        std::vector<int> _asigancion_vendedores;
};
#endif