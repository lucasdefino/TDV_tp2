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

        // Heurística 0 - Los vendedores eligen
        void heuristica_0();

        // Heurística 1 - Los depósitos eligen
        void heuristica_1();

        // Heurística 2 - Capitanes de equipo
        void heuristica_2();

        // Operador de Búsqueda Local 1 - Swap 
        void swap();

        // Operador de Búsqueda Local 2 - Relocate 
        void relocate();

        // Metaheuristica Variable Neighborhood Descent
        void vnd(int max_iter);

        // ILS
        void ils(int max_iter, float porcentaje_pert);

        void perturbacion(int cant_ran);

        Solucion _solucion;
	
	private:
        ReadInstance _instance;

};

#endif