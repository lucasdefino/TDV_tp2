#ifndef HEURISTICA_0_H
#define HEURISTICA_0_H

#include <cstdint>
#include <vector>
#include <iostream>
#include "read_instance.h"
#include "solucion.h"


class Heuristica0
{
	public:
        Heuristica0();
        Heuristica0(ReadInstance &instance);

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