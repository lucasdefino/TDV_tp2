#include <string>
#include <iostream>
#include "read_instance.h"
#include "greedy_solver.h"


int main(int argc, char** argv) {
    std::string filename = "instances/gap/gap_a/a05100";

    ReadInstance instance(filename);

    GreedySolver solve(instance);

    solve.solve();

    std::vector<int> solucion = solve.getSolution();

    for(auto i : solucion){
        std::cout << i << " ";
    }
    
    std::cout << std::endl;

    std::cout << solucion.size() << std::endl;

    std::cout << solve.getObjectiveValue() << std::endl; 

    return 0;
}