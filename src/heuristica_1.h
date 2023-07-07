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

        double getObjectiveValue() const;

        void solve();
        void swap();
        void relocate();

        Solucion _solucion;
	
	private:
        ReadInstance _instance;

};

#endif