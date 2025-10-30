# DAC - Sombras
Dada una vista horizontal de una ciudad que consta únicamente de edificios rectangulares, le piden diseñar un algoritmo que dada la ubicación y altura exacta de los edificios de la ciudad, halle la “silueta” o línea de corte de todos los edificios con el cielo, es decir, la silueta de todos los edificios juntos, pero eliminando las intersecciones ocultas entre los mismos. Por ejemplo, sean los siguientes cuatro edificios:

<img width="445" alt="Screen Shot 2022-05-30 at 14 20 44" src="https://user-images.githubusercontent.com/35345672/171037711-d4907ec8-c926-44e9-bded-c26f5a4787bd.png">

Los mismos se representarán mediante la secuencia de tripletas [(0,7,4), (5,10,3), (1,6,6), (8,10,5)], donde cada componente de la tripleta (I,F,H) representa: I la coordenada en el eje horizontal donde comienza el edificio, F la coordenada donde termina y H la altura del mismo.

Se debe resolver en tiempo O(N log N) usando la técnica “Dividir para conquistar” o “Divide and conquer”, siendo N la cantidad de edificios.

La solución al problema anterior deberá ser la siguiente:

<img width="465" alt="Screen Shot 2022-05-30 at 14 21 48" src="https://user-images.githubusercontent.com/35345672/171037820-bb2d9148-365a-4594-af79-698bd167ebd0.png">

La solución retornada debe ser una secuencia de tuplas. Cada tupla representa una “tira” o vector en el plano dada por el punto (x,h) de destino. El punto de origen quedará determinado por la altura de la tira anterior. Para entenderlo mejor, veamos qué debería retornar el ejemplo anterior. La solución es la siguiente: [(0,4), (1,6), (6,4), (7,3), (8,5),(10,0)].

<img width="488" alt="Screen Shot 2022-05-30 at 14 22 14" src="https://user-images.githubusercontent.com/35345672/171037873-f2543df2-c20d-48d3-a795-031664526a0e.png">

Inicialmente, convendremos que la silueta comienza con h0=0. La primera tira de la secuencia es (0,4). Esto quiere decir que el vector comienza desde (0,0) y va hasta (0,4). En la segunda tira, tenemos (1,6). Como la altura actual de la silueta h1=4 (punto anterior), ahora la nueva tira va desde (1,4) hasta (1,6). Y así, sucesivamente.

## Formato de entrada
N \
I1 F1 H1 \
I2 F2 H2 \
… \
IN FN HN

La primera línea, N, indica la cantidad de edificios que se recibirán. Las siguientes N líneas contiene tres números Ii Fi Hi representando a la tripleta (Ii,Fi,Hi) que describe al edificio i, es decir, siendo Ii su coordenada inicial, Fi la final y Hi su altura.

## Formato de salida
La salida contendrá una secuencia de tuplas describiendo la silueta final, cada una separada por EOL.
La secuencia devuelta no puede contener tiras consecutivas con la misma altura, es decir, no puede existir ninguna ocurrencia […, (xi,h),(xi+1,h), …].
