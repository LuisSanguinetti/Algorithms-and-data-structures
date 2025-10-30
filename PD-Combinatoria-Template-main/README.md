# Combinatoria

Dados dos números, N y K, se pide retornar el resultado de calcular C(N,K), es decir, la cantidad de maneras de tomar N elementos en grupos de K sin repetir, con 0≤K≤N.

Se pide resolver en tiempo O(N^2) peor caso y espacio O(N) para todas las pruebas en su totalidad.
 
Debe de usar programación dinámica.

Por ejemplo, C(5,2)=10. Corresponde a los siguientes conjuntos: |{1,2}, {1,3}, {1,4}, {1,5}, {2,3}, {2,4}, {2,5}, {3,4}, {3,5}, {4,5}|=10.

**Formato de entrada**

    N
    
    P
    
    N1 K1
    
    N2 K2
    
    …
    
    NP KP

La primera línea indica las cota N para los siguientes P casos, es decir, Ni≤N y Ki≤N para todo i con 1≤i≤P. La segunda indica la cantidad de casos de prueba, P. Las siguientes P líneas contienen cada caso dado por dos números Ni y Ki con 1≤i≤P y 0≤Ki≤Ni≤N ordenados según el par (Ni,Ki) para los cuales se desea calcular la cantidad de combinaciones C(Ni,Ki).

**Formato de salida**

    C(N1,K1)
    
    C(N2,K2)
    
    …
    
    C(NP,KP)


La salida contendrá P líneas, cada una indicando la cantidad de combinaciones C(Ni,Ki) con 1≤i≤P.