# 8-Puzzle
Autores:  
aPonce2001  
AnthonySimbaña  

Este problema intenta resolver el juego 8- Puzzle  

Estado inicial  
|7|2|4|
|-|-|-|
|5|0|6|
|8|3|1|

Estado objetivo
|0|1|2|
|-|-|-|
|3|4|5|
|6|7|8|

## Descripción
Considerando que el número cero (0) representa un espacio en blanco para simular el desplazamiento de fichas. Este programa en c++ resuelve el problema utilizando el algoritmo A* donde al expandir el árbol generado, el siguiente nodo a expandir es aquel con la mejor Funcion de evaluación F(n), sabiendo que F(n)=g(n)+h(n), donde g(n) es el costo del recorrido del nodo raiz al actual y h(n) es la heuristica.  

## Resultado

EXISTE UNA SOLUCION:  
SE DESCRIBE LOS PASOS A REALIZAR:  
7       2       4  
5       0       6  
8       3       1  
Costo recorrido: 0  

7       2       4  
0       5       6  
8       3       1  
Costo recorrido: 1  

0       2       4  
7       5       6  
8       3       1  
Costo recorrido: 2  

2       0       4  
7       5       6  
8       3       1  
Costo recorrido: 3  

2       5       4  
7       0       6  
8       3       1  
Costo recorrido: 4  

2       5       4  
7       3       6  
8       0       1  
Costo recorrido: 5  

2       5       4  
7       3       6  
0       8       1  
Costo recorrido: 6  

2       5       4  
0       3       6  
7       8       1  
Costo recorrido: 7  

2       5       4  
3       0       6  
7       8       1  
Costo recorrido: 8  

2       5       4  
3       6       0  
7       8       1  
Costo recorrido: 9  

2       5       0  
3       6       4  
7       8       1  
Costo recorrido: 10  

2       0       5  
3       6       4  
7       8       1  
Costo recorrido: 11  

0       2       5  
3       6       4  
7       8       1  
Costo recorrido: 12  

3       2       5  
0       6       4  
7       8       1  
Costo recorrido: 13  

3       2       5  
6       0       4  
7       8       1  
Costo recorrido: 14  

3       2       5  
6       4       0  
7       8       1  
Costo recorrido: 15  

3       2       5  
6       4       1  
7       8       0  
Costo recorrido: 16  

3       2       5  
6       4       1  
7       0       8  
Costo recorrido: 17  

3       2       5  
6       4       1  
0       7       8  
Costo recorrido: 18  

3       2       5  
0       4       1  
6       7       8  
Costo recorrido: 19  

3       2       5  
4       0       1  
6       7       8  
Costo recorrido: 20  

3       2       5  
4       1       0  
6       7       8  
Costo recorrido: 21  

3       2       0  
4       1       5  
6       7       8  
Costo recorrido: 22  

3       0       2  
4       1       5  
6       7       8  
Costo recorrido: 23  

3       1       2  
4       0       5  
6       7       8  
Costo recorrido: 24  

3       1       2  
0       4       5  
6       7       8  
Costo recorrido: 25  

0       1       2  
3       4       5  
6       7       8  
Costo recorrido: 26  

****** Solucion encontrada ******
