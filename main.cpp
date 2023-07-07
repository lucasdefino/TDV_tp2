#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include "read_instance.h"
#include "meta_heuristica.h"
using namespace std;
using namespace std::chrono;


int main(int argc, char** argv) {

/////////////////EXPERIMENTACION GAP////////////////////////////

    vector<string> gap_filenames = {"instances/gap/gap_a/a05100","instances/gap/gap_a/a05200","instances/gap/gap_a/a10100","instances/gap/gap_a/a10200","instances/gap/gap_a/a20100","instances/gap/gap_a/a20200",
                                "instances/gap/gap_b/b05100","instances/gap/gap_b/b05200","instances/gap/gap_b/b10100","instances/gap/gap_b/b10200","instances/gap/gap_b/b20100","instances/gap/gap_b/b20200",
                                "instances/gap/gap_e/e05100","instances/gap/gap_e/e05200","instances/gap/gap_e/e10100","instances/gap/gap_e/e10200","instances/gap/gap_e/e10400","instances/gap/gap_e/e15900","instances/gap/gap_e/e20100","instances/gap/gap_e/e20200","instances/gap/gap_e/e20400","instances/gap/gap_e/e30900","instances/gap/gap_e/e40400","instances/gap/gap_e/e60900","instances/gap/gap_e/e201600","instances/gap/gap_e/e401600","instances/gap/gap_e/e801600"};
    
    std::ofstream myfile;
    myfile.open("experimentacion_gap.csv");
    myfile << "Input,Heuristica 0,MetaH0,Heuristica 1,MetaH1,Heuristica 2,MetaH2\n";

    int i = 0;
    while(i != gap_filenames.size()){
        ReadInstance instance(gap_filenames[i]);

        MetaHeuristica solucion0(instance);
        solucion0.heuristica_0();
        double H0 = solucion0.getObjectiveValue();
        solucion0.vnd();
        double MH0 = solucion0.getObjectiveValue();

        MetaHeuristica solucion1(instance);
        solucion1.heuristica_1();
        double H1 = solucion1.getObjectiveValue();
        solucion1.vnd();
        double MH1 = solucion1.getObjectiveValue();

        MetaHeuristica solucion2(instance);
        solucion2.heuristica_2();
        double H2 = solucion2.getObjectiveValue();
        solucion2.vnd();
        double MH2 = solucion2.getObjectiveValue();

        myfile << gap_filenames[0] << "," << H0 << "," << MH0 << "," << H1 << "," << MH1 << "," << H2 << "," << MH2 <<"\n";
        
        i++;
    }
    myfile.close();

/////////////////EXPERIMENTACION REAL////////////////////////////

    string real_filename = "instances/real/real_instance";

    myfile.open("experimentacion_real.csv");
    myfile << "Input,Heuristica 0,MetaH0,Tiempo Tot0,Heuristica 1,MetaH1,Tiempo Tot1,Heuristica 2,MetaH2,Tiempo Tot2\n";

    ReadInstance instance(real_filename);

    auto start = high_resolution_clock::now();

    MetaHeuristica solucion0(instance);
    solucion0.heuristica_0();
    double H0 = solucion0.getObjectiveValue();
    solucion0.vnd();
    double MH0 = solucion0.getObjectiveValue();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    double tiempo0 = duration.count();

    start = high_resolution_clock::now();

    MetaHeuristica solucion1(instance);
    solucion1.heuristica_1();
    double H1 = solucion1.getObjectiveValue();
    solucion1.vnd();
    double MH1 = solucion1.getObjectiveValue();

    stop = high_resolution_clock::now();
    duration = duration_cast<seconds>(stop - start);
    double tiempo1 = duration.count();

    start = high_resolution_clock::now();

    MetaHeuristica solucion2(instance);
    solucion2.heuristica_2();
    double H2 = solucion2.getObjectiveValue();
    solucion2.vnd();
    double MH2 = solucion2.getObjectiveValue();

    stop = high_resolution_clock::now();
    duration = duration_cast<seconds>(stop - start);
    double tiempo2 = duration.count();

    myfile << real_filename << "," << H0 << "," << MH0 << "," << tiempo0 << "," << H1 << "," << MH1 << ","  << tiempo1 << "," << H2 << "," << MH2 << "," << tiempo2 <<"\n";
    
    myfile.close();

    return 0;
}