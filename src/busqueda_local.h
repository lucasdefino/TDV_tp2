#ifndef BUSQUEDA_LOCAL_2_H
#define BUSQUEDA_LOCAL_2_H

#include <cstdint>
#include <vector>
#include <iostream>
#include "read_instance.h"
#include "heuristica_2.h"
#include "heuristica_1.h"

class BusquedaLocal2
{
    public:
    BusquedaLocal2();
    BusquedaLocal2(ReadInstance &instance);


    void Swap(double objective_value, std::vector<int> solution, std::vector<int> capres);
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
