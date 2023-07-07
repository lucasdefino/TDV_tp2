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

        double getObjectiveValue() const;

        void solve();
        void swap();
        void relocate();

        Solucion _solucion;
	
	private:
        ReadInstance _instance;

};

#endif