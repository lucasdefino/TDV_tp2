#ifndef READ_INSTANCE_H
#define READ_INSTANCE_H

#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>

class ReadInstance
{
	public:
        ReadInstance();
        ReadInstance(std::string filename);
        void ReadFromFile(std::string filename);
        
        // cantidad de depósitos
        int m;
        // cantidad de vendedores
        int n;
        // matriz de costos m x n. costos[i][j] contiene el costo incurrido si j es asignado a i con i perteneciente a depositos y j a vendedores
        std::vector<std::vector<int>> costos;
        // vector de longitud n. demandas[j] contiene la demanda del vendedor j para todo deposito i en M
        std::vector<int> demandas;
        // vector de longitud m. capacidad[i] contiene la capacidad del depósito i
        std::vector<int> capacidades;

        //int demanda_maxima;
	
	private:

};

#endif