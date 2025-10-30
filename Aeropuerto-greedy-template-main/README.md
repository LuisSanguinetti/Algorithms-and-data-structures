# Aeropuerto
Se está construyendo un nuevo aeropuerto y no se sabe cuántas plataformas se deben construir. Lo que se sabe son los horarios de llegada y salida de cada avión. Se sabe además, que en cada plataforma solo puede haber un avión a la vez y que se quiere saber la cantidad mínima de plataformas para poder operar.

Restricciones:

- O(NLgN) temporal (siendo N la cantidad de vuelos)
- O(N) espacial (siendo N la cantidad de vuelos)
- Debe realizarse con la táctica **greedy**


# Formato de entrada

    N
    
    ll1 s1
    
    ll2 s2
    
    … 
    
    llN sN


La primera línea (N) es la cantidad de elementos de vuelos, las siguientes N líneas es la información de horarios de llegada y partida de cada avion.

# Formato de salida

Contendrá 1 sola línea con la cantidad mínima de líneas para poder operar.

Nota: Los horarios no tienen ningún orden en particular.
