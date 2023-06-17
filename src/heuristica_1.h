#ifndef HEURISTICA_1_H
#define HEURISTICA_1_H

#include <cstdint>
#include <vector>
#include <iostream>
#include "read_instance.h"


class Heuristica1Solver
{
	public:
        Heuristica1Solver();
        Heuristica1Solver(ReadInstance &instance);

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