#ifndef GREEDY_SOLVER_H
#define GREEDY_SOLVER_H

#include <cstdint>
#include <vector>
#include <iostream>
#include "read_instance.h"


class GreedySolver
{
	public:
        GreedySolver();
        GreedySolver(ReadInstance &instance);

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