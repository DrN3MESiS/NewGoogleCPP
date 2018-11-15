# Lufe Grammar
![](union.jpg)
Lufe Grammar es una una aplicacion en el que el usuario escribe un texto y devuelve las principales palabras que comienzan con ese texto. Dichas palabras seran elegidas de un diccionario ya dado. Por ejemplo si el usuario escribe ''hol'', la aplicacion podria devolver:

hola
holanda
holograma

Suponiendo que esas palabras se encuentran en el diccionario.

Escribe un programa que simule la aplicacion de Lufe Grammar. El programa recibira un diccionario de $n$ palabras, y $q$ queries. Cada query consiste de un texto $s$, el programa debe de imprimir por cada query todas aquellas palabras del diccionario que comienzan con $s$ y que tienen una longitud mayor $m$, pero no mayor a $m+5$, donde $m$ es la longitud de $s$.

## Entrada

La primera línea contiene 2 números $n$ $(1 \leq n \leq 10^5)$, $q$ $(1 \leq m \leq 10^6)$. Indicando la cantidad palabras en el diccionario y la cantidad de queries respectivamente.

Le siguen $n$ lineas con las palabras que forman el diccionario, la longitud de las palabras no seran mayor a 15 y solo contendran letras minusculas.

Le siguen $q$ queries, cada uno con un texto $s$.

## Salida

Por cada query imprime todas las palabras del diccionario que empiecen con $s$ y con una longitud mayor a $m$ pero no mayor a $m+5$, donde $m$ es la longitud de $s$. 

##Ejemplos

||input
||output 
||description
||end