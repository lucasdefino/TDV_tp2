#ifndef HEURISTICA_2_H
#define HEURISTICA_2_H

#include <cstdint>
#include <vector>
#include <iostream>
#include "read_instance.h"
#include "solucion.h"


class Heuristica2
{
	public:
        Heuristica2();
        Heuristica2(ReadInstance &instance);

        void solve();
        double getObjectiveValue() const;
        Solucion getSolucion() const;
        void swap();
        void relocate();

	
	private:
        ReadInstance _instance;
        Solucion _solucion;

};

#endif