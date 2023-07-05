#ifndef HEURISTICA_1_H
#define HEURISTICA_1_H

#include <cstdint>
#include <vector>
#include <iostream>
#include "read_instance.h"
#include "solucion.h"


class Heuristica1
{
	public:
        Heuristica1();
        Heuristica1(ReadInstance &instance);

        void solve();
        double getObjectiveValue() const;
        Solucion getSolution() const;
        std::vector<int> getCapRes() const;

	
	private:
        ReadInstance _instance;
        Solucion _solution;
        double _objective_value;

};

#endif