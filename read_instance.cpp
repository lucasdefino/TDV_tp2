#include "read_instance.h"

#include "iostream"

void split(std::string &str, char &delim, std::vector<std::string> &out) {
            std::stringstream s(str);  
              
            std::string s2;  
            while (std::getline(s, s2, delim) )  
            {  
                out.push_back(s2);
            }
}

ReadInstance::ReadInstance() {}

ReadInstance::ReadInstance(std::string filename) {
    this->costos={};
    this->capacidades={};
    this->demandas={};
    this->costo_maximo=0;
    this->ReadFromFile(filename);
}

void ReadInstance::ReadFromFile(std::string filename) {
    
    std::ifstream myfile; 
    myfile.open(filename);
    
    // Leo la primera linea para juntar los tamaños de deposito y clientes
    char delim = ' ';
    std::string line;
    myfile >> line;
    this->m = std::stoi(line);
    myfile >> line;
    this->n = std::stoi(line);
    
    // Leo los siguientes m grupos para levantar los costos a cada cliente
    this->costos = std::vector<std::vector<double>>(m);

    for (int i = 0; i < m; i++) {
        for (int k = 0; costos[i].size() < n; k++){
            std::string line;
            myfile >> line;
            double costo_actual = std::stod(line);
            costos[i].push_back(costo_actual);
            if(costo_actual > this->costo_maximo){this->costo_maximo = costo_actual;}
        }
    }

    // Leo los siguientes n valores para levantar las demandas del primer deposito y como
    // son todos iguales tanto para GAP como para la real basta con guardarlo en una lista
    for (int i = 0; this->demandas.size() < n; i++){
            std::string line;
            myfile >> line;
            this->demandas.push_back(std::stoi(line));
    }
    // Avanzo los proximos m-1 grupos para llevar la lectura del archivo a la proxima
    // "seccion" donde estan las capacidades
    for (int i = 0; i < (m-1)*n; i++){
        std::string line;
        myfile >> line;
    }

    // Leo la capacidad de los depositos
    for (int i = 0; this->capacidades.size() < m; i++){
            std::string line;
            myfile >> line;
            this->capacidades.push_back(std::stoi(line)); 
    }

}