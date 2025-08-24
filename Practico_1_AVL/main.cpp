#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "TAD/avl.cpp"
using namespace std;

int main()
{
    int n;
    if (!(cin >> n)) return 0;

    AVL a = crearAVL();
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        insertarAVLRec(a->raiz, x);
    }

    // imprimir in-order, un número por línea
    inorderAVLRec(a->raiz); // cambia la línea de impresión si querés \n (ver nota)
    cout << '\n';
    return 0;
}