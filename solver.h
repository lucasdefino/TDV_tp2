#ifndef SOLVER_H
#define SOLVER_H

#include <cstdint>
#include <vector>
#include <iostream>
#include "read_instance.h"
#include "solucion.h"


class Solver
{
	public:
        Solver();
        Solver(ReadInstance &instance);

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

        // Solver Variable Neighborhood Descent
        void vnd(int max_iter, bool orden);

        // ILS
        void ils(int max_iter, float porcentaje_pert, int max_iter_vnd, bool orden);

        void perturbacion(int cant_ran);

        Solucion _solucion;
	
	private:
        ReadInstance _instance;

};

#endif