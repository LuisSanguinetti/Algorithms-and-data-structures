# A último momento
El obligatorio de Estructuras de datos y algoritmos 3 es muy similar al de su materia antecesora, con la pequeña diferencia es que no todos los ejercicios tienen el mismo puntaje.

Un día antes de la entrega, el profesor le recuerda que la entrega de todos los archivos no debe superar los S MB (megabytes) ni las L líneas de código entre todos ellos.

Como usted olvidó este detalle y no tiene tiempo a refactorizar su código para que cumpla con las restricciones, decide elegir aquellos ejercicios/archivos que le garanticen un mejor puntaje.

De cada ejercicio/archivo, usted sabe su tamaño, cantidad de líneas de código y el puntaje.

Restricciones:

- O(N*S*L) temporal y espacial
- Debe realizarse con la táctica de **programación dinámica**.

**Formato de entrada**

    N
    
    S
    
    L
    
    t1 l1 p1
    
    t2 l2 p2
    
    … 
    
    tN lN pN

La primera línea (N) es la cantidad de archivos, la segunda (S) y tercera (L) es la cantidad máxima de tamaño y líneas de código respectivamente para la entrega.
Por último siguen N líneas con la información de tamaño, líneas de código y puntaje de cada archivo/entrega.

**Formato de salida**
Contendrá 1 sola línea con el puntaje máximo que se podría obtener dada la entrega realizada.