#ifndef HEURISTICA_3_H
#define HEURISTICA_3_H

#include <cstdint>
#include <vector>
#include <iostream>
#include "read_instance.h"
#include "solucion.h"


class Heuristica3
{
	public:
        Heuristica3();
        Heuristica3(ReadInstance &instance);

        void solve();
        double getObjectiveValue() const;
        Solucion getSolucion() const;
        std::vector<int> getCapRes() const;

	
	private:
        ReadInstance _instance;
        Solucion _solucion;
        double _objective_value;
        std::vector<int> _capacidades_restantes;


};

#endif