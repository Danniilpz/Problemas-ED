// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include <stack>


bool isVowel(char& c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
    else return false;
}

//función que resuelve el problema
std::deque<char> decodificar(std::deque<char>& mensaje) {
    std::deque<char> aux1,aux2,sol;
    int pos=0;
    while(mensaje.size()>0){
        if(pos%2==0) aux1.push_back(mensaje.front());
        else aux2.push_front(mensaje.front());
        mensaje.pop_front();
        pos=(pos+1)%2;
    }
    while(aux2.size()>0){
        aux1.push_back(aux2.front());
        aux2.pop_front();
    }

    std::stack<char> consonantes;
    while(aux1.size()>0){
        if(!isVowel(aux1.front())){
            consonantes.push(aux1.front());
            aux1.pop_front();
        }
        else{
            while(consonantes.size()>0){
                sol.push_back(consonantes.top());
                consonantes.pop();
            }
            sol.push_back(aux1.front());
            aux1.pop_front();
        }
    }
    while(consonantes.size()>0){
        sol.push_back(consonantes.top());
        consonantes.pop();
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string msg;
    std::getline(std::cin,msg);
    if (! std::cin)
        return false;
    std::deque<char> mensaje;
    for(char c:msg){
        mensaje.push_back(c);
    }
    mensaje=decodificar(mensaje);
    
    while(mensaje.size()>0){
        std::cout<<mensaje.front();
        mensaje.pop_front();
    }
    std::cout<<"\n";
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}