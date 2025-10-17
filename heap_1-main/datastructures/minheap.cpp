#ifndef HEAP
#define HEAP
#include <cassert>
#include <string>
#include <iostream>
using namespace std;

template<class T>
class NodoHeapComp {
    public:
        T dato;

        NodoHeapComp(T dato) : dato(dato) {}
};

template<class T>
class MinHeap
{
private:
    NodoHeapComp<T>** heap;
    int cantidad;
    int largoMax;
    int (*fComp)(T,T);
    
    // funciones
    int padre(int pos)
    {
        return (pos-1)/2;
    }

    // se suma de  1 o dos porque hay 2 hijos cada padre
    int hijoIzq(int pos)
    {
        return (pos*2)+1
    }

    int hijoDer(int pos)
    {
        return (pos*2)+2
    }

    void intercambiar(int a, int b)
    {
        NodoHeapComp<T>* aux = heap[a];
        heap[a] = heap[b];
        heap[b] = aux;
    }

    // lo sube en el arbol
    // lo sube hasta que la posicion sea 0, exista dato padre y 
    void flotar(int pos)
    {
        int miPadre = padre(pos);
        if(pos>0 && heap[miPadre]->dato >heap[pos]->dato)
        {
            intercambiar(pos, miPadre);
            flotar(miPadre);
        }
    }
    

public:
    MinHeap(int size)
    {
        // TODO
    }
    void insertar(int valor, int listaDeOrigen)
    {
        // TODO
    }
    int valorTope() {
        // TODO
        return 0;
    }
    int listaDeOrigenTope() {
        // TODO
        return 0;
    }
    void eliminarTope() {
        // TODO
    }
};

#endif