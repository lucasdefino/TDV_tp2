#include <string>
#include <iostream>
#include "read_instance.h"
#include "heuristica_0.h"
#include "heuristica_1.h"
#include "heuristica_2.h"
using namespace std;

int main(int argc, char** argv) {
    std::string filename = "instances/gap/gap_a/a05100";

    ReadInstance instance(filename);

    Heuristica0 heuristica(instance);

    heuristica.solve();

    // Solucion solucion = heuristica.getSolucion();

    // int i = 0;
    // while (i < solucion.getN())
    // {
    //     std::cout << solucion.getDepositoAsignado(i) << " ";
    //         i++;
    // }

    // std::cout << std::endl;

    cout << heuristica.getObjectiveValue() << endl;

    //Solucion solucion = heuristica.getSolucion();

    return 0;
}