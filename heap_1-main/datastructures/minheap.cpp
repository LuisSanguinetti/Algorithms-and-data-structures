#ifndef HEAP
#define HEAP
#include <cassert>
#include <string>
#include <iostream>
using namespace std;

template<class T>
class NodoHeap {
    public:
        int prioridad;
        T dato;

        NodoHeap(int prioridad, T dato) : prioridad(prioridad), dato(dato) {}
};

template<class T>
class Heap
{
private:
    NodoHeap<T>** heap;
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
        NodoHeap<T>* aux = heap[a];
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

    // repasar
    void hundir(int pos)
    {
        int miHijoIzq = hijoIzq(pos), miHijoDer = hijoDer(pos);
        if(miHijoIzq<cantidad)
        {
            int minHijo = miHijoIzq;
            if(miHijoDer<cantidad && heap[miHijoDer]->prioridad<heap[miHijoIzq]->prioridad)
            {
                minHijo++;
            }
            if(heap[minHijo]->prioridad <= heap[pos]->prioridad)
            {
                intercambiar(pos,minHijo);
                hundir(minHijo);
            }
        }
    }
    

public:
    Heap(int size)
    {
        this->largoMax = largoMax;
        this->cantidad = 0;
        this->heap = new NodoHeap<T>*[largoMax]();
    }

    void ~Heap()
    {
        for(int i =0;i<cantidad;i++)
        {
            delete heap[i];
        }
        delete []heap;
    }

    void insertar(int prioridad, T dato)
    {
        // inserto al final
        heap[cantidad++] = new NodoHeap<T>(prioridad, dato);
        // lo hago flotar a su posicion
        flotar(cantidad-1);
    }

    T valorTope() {
        return heap[0]->dato;
    }


    int listaDeOrigenTope() {
        cout << "[";
        for (int i = 0; i < cantidad-1; i++)
        {
            cout << heap[i]->dato << ", ";
        }
        if(cantidad>0){
            cout << heap[cantidad-1]->dato;
        }
        cout << "]" << endl;
    }

    // hago que el max remplaze al primero, elimino la memoria del primero y hago null al ultimo y undo al primero a su nueva posicion
    void eliminarTope() {
        NodoHeap<T>* aBorrar = heap[0];
        heap[0]= heap[--cantidad];
        heap[cantidad]=NULL;
        delete aBorrar;
        hundir(0);
    }

    bool esVacia()
    {
        return cantidad ==0;
    }
};

#endif