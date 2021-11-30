# **Análisis de complejidad temporal (peor de los casos)**

## ordenaSeleccion
Su complejidad es O(n^2) porque son dos ciclos for anidados con los que se recorre el
arreglo.

## ordenaBurbuja
Este algoritmo también es O(n^2) porque son dos ciclos anidados que recorren el arreglo e
intercambian posiciones.

## ordenaMerge 
Este algoritmo es O(n log(n)), porque va haciendo subdivisiones por la mitad con recursión, 
por lo que va arreglando parcialmente, por lo que es más rápido.

## busqSecuencial 
Este algoritmo es O(n), porque recorre todo el arreglo en el peor de los casos, así que 
el número de pasos depende de el valor de n.

## busqBinaria 

Este algoritmo divide el arreglo a la mitad varias veces así y los pasos se reducen a la mitad con
forme se acerca al valor, por lo tanto el algoritmo de complejidad es O(log(n)).
