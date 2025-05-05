# LAB04 CACHE
En este laboratorio usted trabajara en grupo para crear un programa que genera distintos
comportamientos de rendimiento para un algoritmo simple, solo como consecuencia de variar
el espaciado entre los valores accedidos.

Subir codigo fuente y mini-informe con graficos+analisis a la tarea creada en SIVEDUCMD.

RESUMEN: crearemos un programa que accede a numeros aleatorios en un array, pero este array
tiene GAPS (o espacios) entre cada valor. si GAP=0, no hay espacios (todo continuo).

Ejemplo 1), array de `n=10` y GAP=1
[4 x 2 x 10 x 13 x 25 x 5 x 0 x 34 x 99 x 100]

Ejemplo 2), array de `n=5` y GAP=2
[4 x x 2 x x 10 x x 13 x x 25]


NOTA: el programa C/C++ se debe poder ejecutar de esta forma:
    ./prog n gap
    ej:
        ./prog 10000 100

    n = tamano del array
    gap = tamano del gap (espacio) entre los valores accedidos.

    El programa debera primero generar el arreglo con numeros enteros aleatorios, espaciados por GAP (ceros o el valor que uds defina) entre cada valor.

    NOTA:
    La compilacion bastaria con:  g++ main.cpp -fopenmp -o prog, hacer "include <omp.h>"
	    - Forma de medir tiempo
		... (1) crear el arreglo...
		double t1 = omp_get_wtime();
		..  (2) sumar los numeros;
		double t2 = omp_get_wtime();
		double tiempo = t2 - t1;
        printf("tiempo de suma = %f secs\n", tiempo)


1) Hacer una funcion "gap_sum(array, n, gap)" que en cada valor (valido, no de GAP), haga la suma desde ese valor hasta el ultimo.
	NOTA:
	- numero de accesos al arreglo se debe mantener siempre en lo minimo y necesario, sin importar el GAP. Es decir no se deben leer los GAPS.
		OJO: hacer array[i] ya es un acceso de lectura a la memoria en la ubicacion "i".

	- Ejemplo: ./prog 4 2
		INPUT n=4: 1 2 3 4
		Con GAP 2:
		    Array:  1  0 0 2 0 0 3 0 0 4
		    Result: 10 0 0 9 0 0 7 0 0 4


2) Experimentar que pasa con el rendimiento del programa (tiempo de ejecucion de la funcion gap_sum) con n=10^6 cuando:
    a) el GAP es 0
    b) el GAP es 100
    c) el GAP es 1000 (bajar el `n` si para este caso no cabe en RAM)



3) Reportar los tiempos de computo en un breve informe con las secciones estandares (Introduccion, Desarrollo, Resultados, Conclusiones)
   y relacionar los resultados con sus conocimientos de Cache de la CPU. Tambien hacer el grafico tiempo (y) vs n (x), esta vez variando
   n desde valores bajos hasta 10^7, con los 3 modos de GAP de la pregunta anterior.









