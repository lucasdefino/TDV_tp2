#ifndef META_HEURISTICA_H
#define META_HEURISTICA_H

#include <cstdint>
#include <vector>
#include <iostream>
#include "read_instance.h"
#include "solucion.h"


class MetaHeuristica
{
	public:
        MetaHeuristica();
        MetaHeuristica(ReadInstance &instance);

        double getObjectiveValue() const;

        void vnd();

        void heuristica_0();
        void heuristica_1();
        void heuristica_2();

        void swap();
        void relocate();

        Solucion _solucion;
	
	private:
        ReadInstance _instance;

};

#endif