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

        double getObjectiveValue() const;

        void solve();
        void swap();
        void relocate();

        Solucion _solucion;

	private:
        ReadInstance _instance;
        

};

#endif