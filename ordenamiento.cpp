// A tomar en cuenta, está hecho de tal forma que primero se recibe el m, osea 30 y luego n
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <fstream>

#include "ordenamiento.h"

using namespace std;
using namespace std::chrono;


duration<double> crear_arreglo(int *A, int TAM_ARREGLO, int RANGO_MAX) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    for (int i = 0; i < TAM_ARREGLO; i++) {
        int x = rand() % RANGO_MAX;
        A[i] = x;
    }
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_insertion_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    insertion_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_selection_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    selection_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_bubblesort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    bubblesort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}

duration<double> ordenar_merge_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    merge_sort(A, 0, TAM_ARREGLO-1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_quicksort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    quicksort(A, 0, TAM_ARREGLO-1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


int* copiar_arreglo(int A[], int n) {
    int *aux = new int[n];
    for (int i = 0; i < n; i++) {
        aux[i] = A[i];
    }
    return aux;
}


void mostrar_arreglo(int *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}


int main(int argc, char * argv[]) {
    // Se verifican que los argumentos sean correctos
    if (argc != 3) {
        cout << "\nSintaxis: ordenamiento <número_arreglos_a_generar_y_ordenar> <tamaño_arreglo>\n" << endl;
    } else {
        
        int NUM_ARREGLOS = atoi(argv[1]);
        int TAM_ARREGLO = atoi(argv[2]);
        int RANGO = 10 * TAM_ARREGLO;
        // Crea el archivo de salida 
        std::string titulo = "" + std::to_string(TAM_ARREGLO)+".txt";
        std::ofstream salida(titulo);
        // Imprime el número actual del arreglo 
        salida << "NÚMERO DE ARREGLO \t insertion sort \t selection sort \t bubblesort \t\t merge sort \t\t quicksort" << endl;

        cout << "\n\tTAMAÑO DE ARREGLOS: " << TAM_ARREGLO <<"\tNUMERO DE ARREGLOS: " << NUM_ARREGLOS << endl;

        for (int i = 0; i < NUM_ARREGLOS; i++)
        {
            int *A = new int[TAM_ARREGLO];
            int *B = new int[TAM_ARREGLO];
            salida << "\t" << i+1 << "\t""\t";

            duration<double> tiempo;
            cout << "\n** NUMERO DE ARREGLO: " << i + 1 << " **" << endl;
            cout << "\nCreando arreglo aleatorio de tamaño " << TAM_ARREGLO << "...";
            // Mide el tiempo de creacion del arreglo
            tiempo = crear_arreglo(A, TAM_ARREGLO, RANGO);
            cout << "\tCreado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl << "\n";
       
            // Realiza ordenamiento con insertion sort
            cout << "Iniciando ordenamiento con INSERTION SORT... ";
            B = copiar_arreglo(A, TAM_ARREGLO);
            tiempo = ordenar_insertion_sort(B, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            // Hace que la salida salga con 10 decimales, si hay más entonces se usa por defecto la notacion cientifica
            salida << std::fixed << std::setprecision(10) << tiempo.count() << "\t""\t";
            delete [] B;
            
            // Realiza ordenamiento con selection sort
            cout << "Iniciando ordenamiento con SELECTION SORT... ";
            B = copiar_arreglo(A, TAM_ARREGLO);
            tiempo = ordenar_selection_sort(B, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            // Hace que la salida salga con 10 decimales, si hay más entonces se usa por defecto la notacion cientifica
            salida << std::fixed << std::setprecision(10) << tiempo.count() << "\t""\t";
            delete [] B;
            
            // Realiza ordenamiento con bubblesort
            cout << "Iniciando ordenamiento con BUBBLESORT... ";
            B = copiar_arreglo(A, TAM_ARREGLO);
            tiempo = ordenar_bubblesort(B, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            salida << std::fixed << std::setprecision(10) << tiempo.count() << "\t""\t";
            delete [] B;
            
            // Realiza ordenamiento Merge sort
            cout << "Iniciando ordenamiento con MERGE SORT... " << flush;
            B = copiar_arreglo(A, TAM_ARREGLO);
            tiempo = ordenar_merge_sort(B, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            // Hace que la salida salga con 10 decimales, si hay más entonces se usa por defecto la notacion cientifica
            salida << std::fixed << std::setprecision(10) << tiempo.count() << "\t""\t";
            delete [] B;
            
            // Realiza ordenamiento con Quicksort
            cout << "Iniciando ordenamiento con QUICKSORT... " << flush;
            B = copiar_arreglo(A, TAM_ARREGLO);
            tiempo = ordenar_quicksort(B, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            // Hace que la salida salga con 10 decimales, si hay más entonces se usa por defecto la notacion cientifica
            salida << std::fixed << std::setprecision(10) << tiempo.count() << "\t""\t";
            delete [] B;

            cout << endl;
            salida << endl;
        }
    }
    return EXIT_SUCCESS;
}