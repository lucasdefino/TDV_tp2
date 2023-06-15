#include <string>
#include <iostream>
#include "read_instance.h"
#include "heuristica_1.h"
#include "heuristica_2.h"



int main(int argc, char** argv) {
    std::string filename = "instances/gap/gap_a/a05100";

    ReadInstance instance(filename);

    Heuristica2Solver heuristica2(instance);

    heuristica2.solve();

    for(auto i : heuristica2.getSolution()){
        std::cout << i << " ";
    }

    std::cout <<  std::endl << heuristica2.getObjectiveValue() << std::endl;

    return 0;
}