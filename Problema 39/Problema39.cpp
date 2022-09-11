//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno: Daniel Lopez Marques
// Usuario del juez de clase: A39
// Usuario del juez de examen que has utilizado en la prueba de hoy: A23
//
//***************************************************
#include <iostream>
#include <fstream>
#include "bintree_eda.h"
// Explicación de la solución
//La funcion recorre de forma recursiva el arbol binario que representa el rio y sus afluentes.
//En cada nodo se suman los caudales de los dos afluentes que llegan a el, y se resta caudal
//si hay un embalse. Además, se comprueba si alguno de los afluentes que llegan a él son
//navegables.

    // Coste de la solución. Indicar la recurrencia utilizada para calcular el coste de la solución.
    //El coste del algoritmo es de orden n (lineal), siendo n el número de nodos del arbol.
    //T(n)= { c0 si arbol.empty
    // { c1 si arbol.left.empty && arbol.right.empty
    // { T(ni)+T(nd)+c2 si !arbol.empty && !arbol.left.empty && !arbol.right.empty

    // Función que resuelve el problema
    struct tSol
{
    int caudal;
    int count;
};
tSol tramos_navegables(bintree<int> arbol)
{
    if (arbol.empty())
        return {0, 0};
    else if (arbol.left().empty() && arbol.right().empty())
    {
        if (arbol.root() > 0)
            return {0, 0};
        else
            return {1, 0};
    }
    else
    {
        tSol iz = tramos_navegables(arbol.left());
        tSol dcha = tramos_navegables(arbol.right());
        int caudal = iz.caudal + dcha.caudal;
        if (arbol.root() > 0)
            caudal -= arbol.root();
        if (caudal < 0)
            caudal = 0;
        int count = iz.count + dcha.count;
        if (iz.caudal >= 3)
            count++;
        if (dcha.caudal >= 3)
            count++;
        return {caudal, count};
    }
}

// Lee los datos de entrada y muestra el resultado
void resuelveCaso()
{
    bintree<int> arbol = leerArbol(-1);
    // LLamada a la función y escribir resultado
    std::cout << tramos_navegables(arbol).count << "\n";
}
int main()
{
// Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //redirect std::cin to casos.txt
#endif
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
    {
        resuelveCaso();
    }
// Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}