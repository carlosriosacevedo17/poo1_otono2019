#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
/*
 * Copyright (C) 2009 Ronny Yabar Aizcorbe <ronnycontacto@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * unright the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 */

// Función para dividir el array y hacer los intercambios
int divide(int *array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;

    pivot = array[start];
    left = start;
    right = end;

    // Mientras no se cruzen los índices
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }

        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }

        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }

    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;

    // La nueva posición del pivot
    return right;
}

// Función recursiva para hacer el ordenamiento
void quicksort(int *array, int start, int end)
{
    int pivot;

    if (start < end) {
        pivot = divide(array, start, end);

        // Ordeno la lista de los menores
        quicksort(array, start, pivot - 1);

        // Ordeno la lista de los mayores
        quicksort(array, pivot + 1, end);
    }
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int const MAX = 100;
    int arraySize;

    clock_t start_time;
    clock_t final_time;
    double total_time;
    start_time = clock();

    cout << "Ingresa tamanyo: " << endl;
    cin >> arraySize;

    int a[arraySize];

    // Para que el rand no genere siempre los mismos números, utilizando la hora del sistema
    srand(time(0));

    // Para generar enteros aleatorios usamos rand()
    for (int i = 0; i < arraySize; i++) {
        a[i] = rand() % MAX;
    }

   /* cout << "Array antes de ordenarse: " << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << a[i] << " ";
    }

    cout << endl << endl;*/

    quicksort(a, 0, arraySize - 1);

    final_time = clock();
    total_time = ((double)(final_time - start_time)) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución : %lf segundos \n", total_time);

    /*cout << "Array ordenado " << endl;
    for (int i = 0; i < arraySize; i++ ){
        cout << a[i] << "-";
    }

    cout << endl << endl;*/

    return 0;
}
