#include <string>
#include <iostream>
#include "read_instance.h"
#include "heuristica_1.h"
#include "heuristica_2.h"
#include "busqueda_local_1.h"
#include "busqueda_local_2.h"

int main(int argc, char** argv) {
    std::string filename = "instances/gap/gap_a/a05100";

    ReadInstance instance(filename);

    Heuristica2Solver heuristica1(instance);

    heuristica1.solve();

    for(auto i : heuristica1.getSolution()){
        std::cout << i << " ";
    }

    std::cout <<  std::endl << heuristica1.getObjectiveValue() << std::endl;

    BusquedaLocal2 BL(instance);

    BL.MejorMejor(heuristica1.getObjectiveValue(), heuristica1.getSolution(), heuristica1.getCapRes());
    
    int i = 0;
    while (i<2)
    {
        BL.MejorMejor(BL.getObjectiveValue(), BL.getSolution(), BL.getCapRes());
        i++;
    }
    



    
    std::cout << std::endl;

    for(auto i : BL.getSolution()){
        std::cout << i << " ";
    }

    std::cout <<  std::endl << BL.getObjectiveValue() << std::endl;
    

    return 0;
}