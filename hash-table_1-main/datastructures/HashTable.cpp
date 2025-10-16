#ifndef TABLA_HASH
#define TABLA_HASH
#include <cassert>
#include <string>
#include <iostream>
using namespace std;

// TODO:
// - Implementar la Tabla de hash

template<class K, class V>
class NodoHash {
    public:
        K clave;
        V valor;
        bool susuki;
        NodoHash(K clave, V valor) : clave(clave), valor(valor), susuki(false){}
};

template<class K, class V>
class HashTable
{
private:
    NodoHash<K,V>** hash;
    int cantidad;
    int largoArray;
    int maxCant;
    int (*fHash)(k)

    bool esPrimo(int num)
    {
        if(num<=1)
        {
            return false;
        }
        else
        {
            for(int i =2;i<num/2;i++)
            {
                if(num%i==0)
                {
                    return false;
                }
            }
            return true;
        }
    }

    int primoSup(int num)
    {
        while(!esPrimo(++num));
        return num;
    }
public:
    HashTable(int maxCant, int (*fHash)(k))
    {
        this->cantidad =0;
        this->maxCant=maxCant;
        this->hash = new NodoHash<K,V>*[this->largoArray]();
        this->fHash = fHash;
    }
    ~HashTable()
    {
        for (int i = 0; i < largoArray; i++)
        {
            if(hash[i]){
                delete hash[i];
            }
        }
        
        delete [] this->hash;
    }

    //probar rehashing
    //!EsLleno()
    void add(K clave, V valor)
    {
        int posHash = abs(fHash(clave)) % largoArray;
    }
    void remove(string clave)
    {
        // TODO
    }
    int get(string clave)
    {
        // TODO
    }
    bool exist(string clave)
    {
        // TODO
    }
};

int fHash(string key) {
  int h = 0;
  for (int i = 0; i < key.length(); i++)
    h = 31 * h + int(key[i]);
  return h;
}

#endif