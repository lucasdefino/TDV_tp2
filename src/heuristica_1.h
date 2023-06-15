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