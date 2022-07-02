# 8-Puzzle
Autores:
aPonce2001  
AnthonySimbaña  

Este problema intenta resolver el juego 8- Puzzle  
## Estado inicial  
|7|2|4|
|-|-|-|
|5|0|4|
|6|3|8|

## Estado objetivo
|0|1|2|
|-|-|-|
|3|4|5|
|6|7|8|

con el algoritmo A* donde al expandir el árbol generado, el siguiente nodo a expandir es aquel con la mejor Funcion de evaluación F(n), sabiendo que F(n)=g(n)+h(n), donde g(n) es el costos del recorrido del nodo raiz al actual y h(n) es la heuristica.  

