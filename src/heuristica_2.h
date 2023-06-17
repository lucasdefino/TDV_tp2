#ifndef HEURISTICA_2_H
#define HEURISTICA_2_H

#include <cstdint>
#include <vector>
#include <iostream>
#include "read_instance.h"


class Heuristica2Solver
{
	public:
        Heuristica2Solver();
        Heuristica2Solver(ReadInstance &instance);

        void solve();
        double getObjectiveValue() const;
        std::vector<int> getSolution() const;
        std::vector<int> getCapRes() const;

	
	private:
        // Instance, problem and results attributes
        ReadInstance _instance;
        //TaxiAssignmentSolution _solution;
        double _objective_value;
        std::vector<int> _solution;
        std::vector<int> _capacidades_restantes;


};

#endif