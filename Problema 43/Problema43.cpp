// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using diccionario=std::map<std::string,int>;
using lista=std::vector<std::string>;
using par=std::pair<std::string,int>;

diccionario leer_diccionario(){
    std::string line;
    std::string clave;
    int valor;
    std::getline(std::cin,line);
    std::stringstream ss(line);
    diccionario d;
    while(ss>>clave>>valor){
        d[clave]=valor;
    }
    return d;
}

void comparar(diccionario & antiguo,diccionario & nuevo, lista& added, lista& deleted, lista& modified){
    for(par p:antiguo){
        if(nuevo.find(p.first)==nuevo.end()){
            deleted.push_back(p.first);
        }
        else if(nuevo[p.first]!=p.second){
            modified.push_back(p.first);
        }
    }
    for(par p:nuevo){
        if(antiguo.find(p.first)==antiguo.end()){
            added.push_back(p.first);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    diccionario antiguo,nuevo;
    antiguo=leer_diccionario();
    nuevo=leer_diccionario();
    lista added,deleted,modified;
    comparar(antiguo,nuevo,added,deleted,modified);
    if(added.size()==0&&deleted.size()==0&&modified.size()==0){
        std::cout<<"Sin cambios\n";
    }
    else{
        if(added.size()>0){
            std::cout<<"+ ";
            for(std::string s:added){
                std::cout<<s<<" ";
            }
            std::cout<<"\n";
        }
        if(deleted.size()>0){
            std::cout<<"- ";
            for(std::string s:deleted){
                std::cout<<s<<" ";
            }
            std::cout<<"\n";
        }
        if(modified.size()>0){
            std::cout<<"* ";
            for(std::string s:modified){
                std::cout<<s<<" ";
            }
            std::cout<<"\n";
        }
    }

    std::cout<<"---\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    std::cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}