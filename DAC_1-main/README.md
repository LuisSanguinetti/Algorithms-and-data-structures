# DAC - Cambio
Se desea implementar una solución al problema de la moneda. Es decir, dado un conjunto de monedas y un cambio a devolver, se quiere saber la cantidad minima de monedas a usar para devolver el cambio.

> Nota: siempre se puede devolver el cambio ya que en todos los casos existe la moneda unitaria (de 1).

## Formato de entrada
M \
m1 \
m2 \
.. \
mM \
C \
c1 \
c2 \
.. \
cC \

* La primera linea (M), dice la cantidad de tipos de monedas que tenemos.
* Luego siguen las M tipos/valores de monedas disponibles.
* La siguiente linea (C), dice los casos a resolver.
* Las siguientes C lineas son los cambios a devolver.

### Ejemplo 
3 \
1 \
5 \
2 \
2 \
20 \
16

Tenemos tres tipos de monedas (1, 5 y 2) y tenemos que resolver el cambio de 20 y de 16.

## Formato de salida
Se retornarn C lineas, correspondientes a los C casos.
