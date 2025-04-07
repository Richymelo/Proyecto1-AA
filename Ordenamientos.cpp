// Ordenamiento.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;



void exchangeSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void selectionSortMax(int arr[], int n) {
    int i, j, max_idx;

    for (i = n - 1; i > 0; i--) {
        max_idx = 0;

        for (j = 1; j <= i; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, j, temp;

    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

void merge(vector<int>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void selectionSortMax(int arr[], int n) {
    int i, j, max_idx;

    for (i = n - 1; i > 0; i--) {
        max_idx = 0;

        for (j = 1; j <= i; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }
}

void flip(int arr[], int i){
    int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

// Devuelve el �ndice del elemento m�ximo en arr[0..n-1]
int findMax(int arr[], int n){
    int mi, i;
    for (mi = 0, i = 0; i < n; ++i)
        if (arr[i] > arr[mi])
            mi = i;
    return mi;
}

// Funci�n principal que ordena el arreglo dado usando operaciones de volteo
void pancakeSort(int* arr, int n){
    // Comienza con el arreglo completo y reduce el tama�o actual uno por uno
    for (int curr_size = n; curr_size > 1;--curr_size)
    {
        // Encuentra el �ndice del elemento m�ximo en arr[0..curr_size-1]
        int mi = findMax(arr, curr_size);

        // Mueve el elemento m�ximo al final del arreglo actual si no est� ya al final
        if (mi != curr_size - 1)
        {
            // Para moverlo al final, primero lleva el n�mero m�ximo al inicio
            flip(arr, mi);

            // Ahora mueve el n�mero m�ximo al final invirtiendo el arreglo actual
            flip(arr, curr_size - 1);
        }
    }
}