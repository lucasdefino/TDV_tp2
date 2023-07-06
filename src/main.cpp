#include <string>
#include <iostream>
#include "read_instance.h"
#include "heuristica_0.h"
#include "heuristica_1.h"
#include "heuristica_2.h"
#include "busqueda_local.h"
using namespace std;

int main(int argc, char** argv) {
    std::string filename = "instances/gap/gap_a/a10200";

    ReadInstance instance(filename);

    Heuristica2 heuristica(instance);

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

    return 0;
}