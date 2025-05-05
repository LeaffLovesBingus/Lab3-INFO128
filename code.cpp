#include <iostream>
#include <random>
#include <math.h>
#include <omp.h>

using namespace std;
#define MAX 10e3
#define DEBUG 1

void printArray(int *array, int n);
void gap_sum(int **Array, int n, int gap);


int main(int argc, char **argv){
    if(argc != 3){
        cout << "Error. Ejecutar como ./prog n gap" << endl;
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    int gap = atoi(argv[2]);

    // generamos un arreglo con valores aleatorios respetando los gaps (usamos -1)
    long arrayValuesLength = (n+((n-1)*gap));
    int *arrayValuesArray = new int[arrayValuesLength];
    for (int i = 0; i < arrayValuesLength; i += gap + 1){
        arrayValuesArray[i] = (rand()%(int)MAX);
    }

    if (DEBUG){
        cout << "Arreglo\n> ";
        printArray(arrayValuesArray, arrayValuesLength);
    }
    
    double t1 = omp_get_wtime();
    gap_sum(&arrayValuesArray, n, gap);
    double t2 = omp_get_wtime();
    double tiempo = t2 - t1;
    printf("> tiempo de suma = %f secs\n", tiempo);
    
    if (DEBUG){
        cout << "Resultado\n> ";
        printArray(arrayValuesArray, arrayValuesLength);
    }

    return 0;
}


void printArray(int *array, int n){
    cout << "[ ";
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << "]" << endl;
}


void gap_sum(int **Array, int n, int gap){
    int largo = n + ((n-1)*gap);
    int sum = 0;
    
    for (int i = largo - 1; i >= 0; i -= gap+1){
        sum += (*Array)[i];
        (*Array)[i] = sum;
    }
}