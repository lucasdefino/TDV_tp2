#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include "read_instance.h"
#include "solver.h"
using namespace std;
using namespace std::chrono;


int main(int argc, char** argv) {

///////////////EXPERIMENTACION GAP////////////////////////////

    vector<string> gap_filenames = {"instances/gap/gap_a/a05100","instances/gap/gap_a/a05200","instances/gap/gap_a/a10100","instances/gap/gap_a/a10200","instances/gap/gap_a/a20100","instances/gap/gap_a/a20200",
                                    "instances/gap/gap_b/b05100","instances/gap/gap_b/b05200","instances/gap/gap_b/b10100","instances/gap/gap_b/b10200","instances/gap/gap_b/b20100","instances/gap/gap_b/b20200",
                                    "instances/gap/gap_e/e05100","instances/gap/gap_e/e05200","instances/gap/gap_e/e10100","instances/gap/gap_e/e10200","instances/gap/gap_e/e10400","instances/gap/gap_e/e20100","instances/gap/gap_e/e20200","instances/gap/gap_e/e20400",
                                    "instances/gap/gap_e/e15900","instances/gap/gap_e/e30900","instances/gap/gap_e/e40400","instances/gap/gap_e/e60900","instances/gap/gap_e/e201600",
                                    "instances/gap/gap_e/e801600","instances/gap/gap_e/e401600"};
    
    std::ofstream myfile;
    myfile.open("experimentacion_gap_e.csv");
    myfile << "Input,Heuristica 0,MetaH0,Tiempo Tot0,Heuristica 1,MetaH1,Tiempo Tot1,Heuristica 2,MetaH2,Tiempo Tot2\n";

    int i = 0;
    while(i < gap_filenames.size()){   

        ReadInstance instance(gap_filenames[i]);
        cout << "Input:" << gap_filenames[i] << endl;

        auto start = high_resolution_clock::now();

        Solver solucion0(instance);
        solucion0.heuristica_0();
        double H0 = solucion0.getObjectiveValue();
        solucion0.ils(10,0.1,50,1);
        double MH0 = solucion0.getObjectiveValue();
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(stop - start);
        double tiempo0 = duration.count();

        cout << "H0:" << H0 << " MetaH0:" << MH0 << " T0:" << tiempo0 << endl;

        start = high_resolution_clock::now();

        Solver solucion1(instance);
        solucion1.heuristica_1();
        double H1 = solucion1.getObjectiveValue();
        solucion1.ils(10,0.1,50,1);
        double MH1 = solucion1.getObjectiveValue();

        stop = high_resolution_clock::now();
        duration = duration_cast<seconds>(stop - start);
        double tiempo1 = duration.count();

        cout << "H1:" << H1 << " MetaH1:" << MH1 << " T1:" << tiempo1 << endl;

        start = high_resolution_clock::now();


        Solver solucion2(instance);
        solucion2.heuristica_2();
        double H2 = solucion2.getObjectiveValue();
        solucion2.ils(10,0.1,50,1);
        double MH2 = solucion2.getObjectiveValue();

        stop = high_resolution_clock::now();
        duration = duration_cast<seconds>(stop - start);
        double tiempo2 = duration.count();

        cout << "H2:" << H2 << " MetaH2:" << MH2 << " T2:" << tiempo2 << endl;
        
        cout << endl;

        myfile << gap_filenames[i] << "," << H0 << "," << MH0 << "," << tiempo0 << "," << H1 << "," << MH1 << ","  << tiempo1 << "," << H2 << "," << MH2 << "," << tiempo2 <<"\n";
        
        i++;

    }
    

    myfile.close();

///////////////EXPERIMENTACION REAL////////////////////////////

    string real_filename = "instances/real/real_instance";

    myfile.open("experimentacion_real.csv");
    myfile << "Input,Heuristica 0,MetaH0,Tiempo Tot0,Heuristica 1,MetaH1,Tiempo Tot1,Heuristica 2,MetaH2,Tiempo Tot2\n";

    ReadInstance instance(real_filename);

    auto start = high_resolution_clock::now();

    Solver solucion0(instance);
    solucion0.heuristica_0();
    double H0 = solucion0.getObjectiveValue();
    solucion0.ils(15,0.1,200,1);
    double MH0 = solucion0.getObjectiveValue();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    double tiempo0 = duration.count();

    start = high_resolution_clock::now();

    Solver solucion1(instance);
    solucion1.heuristica_1();
    double H1 = solucion1.getObjectiveValue();
    solucion1.ils(15,0.1,200,1);
    double MH1 = solucion1.getObjectiveValue();

    stop = high_resolution_clock::now();
    duration = duration_cast<seconds>(stop - start);
    double tiempo1 = duration.count();

    start = high_resolution_clock::now();

    Solver solucion2(instance);
    solucion2.heuristica_2();
    double H2 = solucion2.getObjectiveValue();
    solucion2.ils(15,0.1,200,1);
    double MH2 = solucion2.getObjectiveValue();

    stop = high_resolution_clock::now();
    duration = duration_cast<seconds>(stop - start);
    double tiempo2 = duration.count();

    myfile << real_filename << "," << H0 << "," << MH0 << "," << tiempo0 << "," << H1 << "," << MH1 << ","  << tiempo1 << "," << H2 << "," << MH2 << "," << tiempo2 <<"\n";
    
    myfile.close();

    return 0;
}

/////////////////EXPERIMENTACION DE PRUEBA////////////////////////////

/*
    Debido a que correr todas las instancias de GAP al mismo tiempo tarda demasiado tiempo,
    en el caso de que se quiera correr instancias por separado para prbar dejamos código comentado. Para poder correrlo
    simplemente comentar el main de arriba y descomentar el main de abajo.
*/
// int main(int argc, char** argv) {

//     string real_filename = "instances/gap/gap_e/e60900";

//     ReadInstance instance(real_filename);
//     cout << "Input:" << real_filename << endl;

//     auto start = high_resolution_clock::now();

//     Solver solucion0(instance);
//     solucion0.heuristica_0();
//     double H0 = solucion0.getObjectiveValue();
//     //solucion0.ils(2,0.1,2,1);
//     double MH0 = solucion0.getObjectiveValue();

//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<seconds>(stop - start);
//     double tiempo0 = duration.count();

//     cout << "Heuristica 0:" << H0 << " MetaH0:" << MH0 << " Tiempo Tot0:" << tiempo0 << endl;

//     start = high_resolution_clock::now();

//     Solver solucion1(instance);
//     solucion1.heuristica_1();
//     double H1 = solucion1.getObjectiveValue();
//     solucion1.ils(10,0.1,50,1);
//     double MH1 = solucion1.getObjectiveValue();

//     stop = high_resolution_clock::now();
//     duration = duration_cast<seconds>(stop - start);
//     double tiempo1 = duration.count();

//     cout << "Heuristica 1:" << H1 << " MetaH1:" << MH1 << " Tiempo Tot1:" << tiempo1 << endl;


//     start = high_resolution_clock::now();

//     Solver solucion2(instance);
//     solucion2.heuristica_2();
//     double H2 = solucion2.getObjectiveValue();
//     solucion2.ils(10,0.1,50,1);
//     double MH2 = solucion2.getObjectiveValue();

//     stop = high_resolution_clock::now();
//     duration = duration_cast<seconds>(stop - start);
//     double tiempo2 = duration.count();

//     cout << "Heuristica 2:" << H2 << " MetaH2:" << MH2 << " Tiempo Tot2:" << tiempo2 << endl;

//     return 0;
// }