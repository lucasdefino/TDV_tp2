#include <string>
#include <iostream>
#include "read_instance.h"


int main(int argc, char** argv) {
    std::string filename = "instances/gap/gap_a/a05100";
    std::cout << "Reading file " << filename << std::endl;

    ReadInstance instance(filename);

    std::cout << instance.m << std::endl;

    

    return 0;
}