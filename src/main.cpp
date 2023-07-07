#include <string>
#include <vector>
#include <iostream>
#include "read_instance.h"
#include "heuristica_0.h"
#include "heuristica_1.h"
#include "heuristica_2.h"
#include "meta_heuristica.h"
using namespace std;

int main(int argc, char** argv) {

    //vector<string> filenames = {"instances/gap/gap_e/e05100","instances/gap/gap_e/e05200","instances/gap/gap_e/e10100","instances/gap/gap_e/e10200","instances/gap/gap_e/e20100","instances/gap/gap_e/e20200"};
    vector<string> filenames = {"instances/real/real_instance"};


    //ReadInstance instance("instances/real/real_instance");
    // ReadInstance instance("instances/gap/gap_e/e20100");

    // MetaHeuristica solucion(instance);

    // solucion.heuristica_0();

    // cout << solucion.getObjectiveValue() << endl;

    // cout << solucion._solucion.getVendedoresAsignados() << endl;

    // solucion.vnd();

    // cout << solucion._solucion.getVendedoresAsignados() << endl;

    // cout << solucion.getObjectiveValue() << endl;


    for (auto i : filenames){

        ReadInstance instance(i);

        MetaHeuristica solucion(instance);

        solucion.heuristica_2();

        cout << solucion.getObjectiveValue();
        
        solucion.vnd();

        cout << " -> " << solucion.getObjectiveValue() << endl;

    }



    return 0;
}