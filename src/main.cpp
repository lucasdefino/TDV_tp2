#include <string>
#include <vector>
#include <iostream>
#include "read_instance.h"
#include "heuristica_0.h"
#include "heuristica_1.h"
#include "heuristica_2.h"
using namespace std;

int main(int argc, char** argv) {

    //vector<string> filenames = {"instances/gap/gap_a/a05100","instances/gap/gap_a/a05200","instances/gap/gap_a/a10100","instances/gap/gap_a/a10200","instances/gap/gap_a/a20100","instances/gap/gap_a/a20200"};

    ReadInstance instance("instances/real/real_instance");
    //ReadInstance instance("instances/gap/gap_e/e20100");

    Heuristica2 heuristica(instance);

    heuristica.solve();

    cout << heuristica.getObjectiveValue() << endl;

    cout << heuristica.getSolucion().getVendedoresAsignados() << endl;

    heuristica.relocate();

    cout << heuristica.getSolucion().getVendedoresAsignados() << endl;

    cout << heuristica.getObjectiveValue() << endl;


    // for (auto i : filenames){

    //     ReadInstance instance(i);

    //     cout << instance.capacidades[0]  << endl;

    //     Heuristica0 heuristica0(instance);
    //     Heuristica1 heuristica1(instance);
    //     Heuristica2 heuristica2(instance);

    //     heuristica0.solve();
    //     heuristica1.solve();
    //     heuristica2.solve();

    //     //cout << heuristica0.getObjectiveValue() << " " << heuristica1.getObjectiveValue() << " " << heuristica2.getObjectiveValue() << endl;

    // }

    // heuristica.swap();

    // cout << heuristica.getObjectiveValue() << endl;

    return 0;
}