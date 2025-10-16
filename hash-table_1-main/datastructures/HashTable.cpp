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
        bool deleted;
        NodoHash(K clave, V valor) : clave(clave), valor(valor), deleted(false){}
};

template<class K, class V>
class HashTable
{
private:
    NodoHash<K,V>** hash;
    int cantidad;
    int largoArray;
    int maxCant;
    int (*fHash)(K);

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
    HashTable(int maxCant, int (*fHash)(K))
    {
        this->cantidad =0;
        this->maxCant=maxCant;
        largoArray = primoSup(maxCant * 2); 
        hash = new NodoHash<K,V>*[largoArray]();
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
        //cosigo posicion
        int posHash = abs(fHash(clave)) % largoArray;
        // if the hash is already occupied, meaning exists and not deleted
        while(hash[posHash] && !hash[posHash]->deleted)
        {
            // busco siguiente posicion disponible
            posHash = (posHash + 1)% largoArray;
        }
        //porque esto esta aca se supone que busco un hashposhash que no exista ?
        if(hash[posHash])
        {
            delete hash[posHash];
        }
        hash[posHash] = new NodoHash<K,V>(clave,valor);
        cantidad++;
    }
    // pre: existe
    void remove(K clave)
    {
         int posHash = getPosHash(clave);
        if(posHash==-1)
        {
            return;
        }
        hash[posHash]->deleted=true;

    }

    // sque los pre existe para todos menos el add usando el get pos hash
    V get(K clave)
    {
        int posHash = getPosHash(clave);
        if(posHash==-1)
        {
            return V();
        }
        return hash[posHash]->valor;
    }
    bool exist(const K& clave)
    {
        int posHash = getPosHash(clave);
        if(posHash==-1)
        {
            return false;
        }
        return hash[posHash] && !hash[posHash]->deleted;
    }
    int getPosHash(const K& clave)
    {
        int posHash = abs(fHash(clave))%largoArray;
        int count =0;
        while(hash[posHash]&& hash[posHash]->clave!=clave&&count<largoArray)
        {
            posHash = (posHash+1)%largoArray;
            count++;
        }
        if(count>=largoArray)
        {
            return -1;
        }
        return posHash;
    }
};

int fHash(string key) {
  int h = 0;
  for (int i = 0; i < key.length(); i++)
    h = 31 * h + int(key[i]);
  return h;
}

#endif