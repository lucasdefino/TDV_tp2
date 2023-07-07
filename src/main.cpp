#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "read_instance.h"
#include "meta_heuristica.h"
using namespace std;

int main(int argc, char** argv) {

    vector<string> gap_filenames = {//"instances/gap/gap_a/a05100","instances/gap/gap_a/a05200","instances/gap/gap_a/a10100","instances/gap/gap_a/a10200","instances/gap/gap_a/a20100","instances/gap/gap_a/a20200",
                                //"instances/gap/gap_b/b05100","instances/gap/gap_b/b05200","instances/gap/gap_b/b10100","instances/gap/gap_b/b10200","instances/gap/gap_b/b20100","instances/gap/gap_b/b20200",
                                "instances/gap/gap_e/e05100","instances/gap/gap_e/e05200","instances/gap/gap_e/e10100","instances/gap/gap_e/e10200","instances/gap/gap_e/e10400","instances/gap/gap_e/e15900","instances/gap/gap_e/e20100","instances/gap/gap_e/e20200","instances/gap/gap_e/e20400","instances/gap/gap_e/e30900","instances/gap/gap_e/e40400","instances/gap/gap_e/e60900","instances/gap/gap_e/e201600","instances/gap/gap_e/e401600","instances/gap/gap_e/e801600"};

    string real_filename = "instances/real/real_instance";

    // std::ofstream myfile;
    // myfile.open("experimentacion_gap.csv");
    // myfile << "Input,Heuristica 0,Metaheuristica 0,Heuristica 1,Metaheuristica 1,Heuristica 2,Metaheuristica 2\n";

    // int i = 0;
    // while(i != gap_filenames.size()){
    //     ReadInstance instance(gap_filenames[i]);

    //     MetaHeuristica solucion0(instance);
    //     solucion0.heuristica_0();
    //     double H0 = solucion0.getObjectiveValue();
    //     solucion0.vnd();
    //     double MH0 = solucion0.getObjectiveValue();

    //     MetaHeuristica solucion1(instance);
    //     solucion1.heuristica_1();
    //     double H1 = solucion1.getObjectiveValue();
    //     solucion1.vnd();
    //     double MH1 = solucion1.getObjectiveValue();

    //     MetaHeuristica solucion2(instance);
    //     solucion2.heuristica_2();
    //     double H2 = solucion2.getObjectiveValue();
    //     solucion2.vnd();
    //     double MH2 = solucion2.getObjectiveValue();

    //     myfile << gap_filenames[i] << "," << H0 << "," << MH0 << "," << H1 << "," << MH1 << "," << H2 << "," << MH2 << "\n";
        
    //     i++;
    // }
    // myfile.close();


    ReadInstance instance("instances/real/real_instance");
    // ReadInstance instance("instances/gap/gap_b/b20200");

    MetaHeuristica solucion(instance);

    solucion.heuristica_2();

    cout << solucion.getObjectiveValue();
        
    solucion.vnd();

    cout << " -> " << solucion.getObjectiveValue() << endl;


    //cout << solucion.getObjectiveValue() << endl;


    //cout << endl;

    //cout << solucion.getObjectiveValue() << endl;


    //cout << " -> " << solucion.getObjectiveValue() << endl;

    //cout << " - " << solucion._solucion.getVendedoresAsignados() << endl;


    // for (auto i : filenames){

    //     ReadInstance instance(i);

    //     MetaHeuristica solucion(instance);

    //     solucion.heuristica_0();

    //     cout << solucion.getObjectiveValue();
        
    //     solucion.vnd();

    //     cout << " -> " << solucion.getObjectiveValue() << endl;

    // }



    return 0;
}