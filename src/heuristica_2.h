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

        void setInstance(ReadInstance &instance);
        void solve();
        double getObjectiveValue() const;
        std::vector<int> getSolution() const;
	
	private:
        // Instance, problem and results attributes
        ReadInstance _instance;
        //TaxiAssignmentSolution _solution;
        double _objective_value;
        std::vector<int> _solution;

};

#endif