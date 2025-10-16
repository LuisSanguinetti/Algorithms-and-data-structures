#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "./datastructures/HashTable.cpp"
using namespace std;

int main() {
    int largo, ret = 0;
    string palabra;
    cin >> largo;
    HashTable<string, int>* hash = new HashTable<string, int>(largo, fHash);
    for (int i = 0; i < largo; i++)
    {
        cin >> palabra;
        bool existePalabra = hash->exist(palabra);
        if(!existePalabra){
            hash->add(palabra, 1);
        } else {
           int ocurrencias = hash->get(palabra);
            // update ret BEFORE increasing the stored count
            if (ocurrencias == 1) {
                ret++;          // just reached exactly 2
            } else if (ocurrencias == 2) {
                ret--;          // just left exactly 2 (now 3)
            }
            hash->remove(palabra);
            hash->add(palabra, ocurrencias + 1);
        }
    }
    cout << ret;
}