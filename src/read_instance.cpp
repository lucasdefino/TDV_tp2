#include "read_instance.h"

void split(std::string &str, char &delim, std::vector<std::string> &out) {
            // create a stream from the string  
            std::stringstream s(str);  
              
            std::string s2;  
            while (std::getline(s, s2, delim) )  
            {  
                out.push_back(s2); // store the string in s2  
            } 
}

ReadInstance::ReadInstance() {}

ReadInstance::ReadInstance(std::string filename) {

    this->ReadFromFile(filename);
}

void ReadInstance::ReadFromFile(std::string filename) {
    
    std::ifstream myfile; 
    myfile.open(filename);
    
    // Leo la primera linea para juntar los tama;os de deposito y clientes
    char delim = ' ';
    std::string line;
    getline(myfile, line);
    std::vector<std::string> elems;
    split(line, delim, elems);
    this->m = std::stoi(elems[1]);
    this->n = std::stoi(elems[2]);

    // Leo los siguientes m grupos para levantar los costos a cada cliente
    this->costos = std::vector<std::vector<int>>(m);

    for (int i = 0; i < m; i++) {
        for (int k = 0; costos[i].size() != n; k++){
            std::string line;
            getline(myfile, line);
            std::vector<std::string> elems;
            split(line, delim, elems);
            for (int j = 1; j < elems.size(); j++){
                costos[i].push_back(std::stoi(elems[j]));
            }
        }
    }

    // Leo los siguientes n valores para levantar las demandas del primer deposito
    // y como son todos iguales basta con guardarlo en una lista (GAP simplificado)
    for (int i = 0; this->demandas.size() != n; i++){
            std::string line;
            getline(myfile, line);
            std::vector<std::string> elems;
            split(line, delim, elems);
            for (int j = 1; j < elems.size(); j++){
                this->demandas.push_back(std::stoi(elems[j])); 
            }
    }
    // Avanzo los proximos m-1 grupos para llevar la lectura del archivo a la proxima
    // "seccion" donde estan las capacidades
    for (int i = 0; i < m-1; i++){
        int cnt = 0;
        for (int j = 0; cnt != n; j++){
            std::string line;
            getline(myfile, line);
            std::vector<std::string> elems;
            split(line, delim, elems);
            cnt = cnt + elems.size()-1;
        }
    }

    // Leo la capacidad de los depositos
    for (int i = 0; this->capacidades.size() != m; i++){
            std::string line;
            getline(myfile, line);
            std::vector<std::string> elems;
            split(line, delim, elems);
            for (int j = 1; j < elems.size(); j++){
                this->capacidades.push_back(std::stoi(elems[j])); 
            }
    }

}