#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void split(std::string &str, char &delim, std::vector<std::string> &out){
            // create a stream from the string  
            std::stringstream s(str);  
              
            std::string s2;  
            while(getline(s, s2, delim)){  
                out.push_back(s2); // store the string in s2  
            } 
    }
    

int main(int argc, char** argv) {
    std::string filename = "instances/gap/gap_a/a05100";
    //std::cout << "Reading file " << filename << std::endl;
    
    std::ifstream myfile; 
    myfile.open(filename);
    
    // Leo la primera linea para juntar los tama;os de deposito y clientes
    char delim = ' ';
    std::string line;
    getline(myfile, line);
    std::vector<std::string> elems;
    split(line, delim, elems);
    int m = std::stoi(elems[1]);
    int n = std::stoi(elems[2]);

    // Leo los siguientes m grupos para levantar los costos a cada cliente
    std::vector<std::vector<int>> costos;
    costos = std::vector<std::vector<int>>(m);

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
    std::vector<int> demandas;
    for (int i = 0; demandas.size() != n; i++){
            std::string line;
            getline(myfile, line);
            std::vector<std::string> elems;
            split(line, delim, elems);
            for (int j = 1; j < elems.size(); j++){
                demandas.push_back(std::stoi(elems[j])); 
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
    std::vector<int> capacidades;
    for (int i = 0; capacidades.size() != m; i++){
            std::string line;
            getline(myfile, line);
            std::vector<std::string> elems;
            split(line, delim, elems);
            for (int j = 1; j < elems.size(); j++){
                capacidades.push_back(std::stoi(elems[j])); 
            }
    }

    for (int i = 0; i < m; i++){
        cout << capacidades[i] << endl;
    }

    // Aca empieza la magia.

    return 0;
}