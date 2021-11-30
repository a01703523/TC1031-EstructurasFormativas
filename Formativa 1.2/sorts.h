/*  
Salvador Santana Blanco
A01703523
*/

#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <iostream>
using namespace std;

template <class T>
class Sorts{
    public:
        void ordenaSeleccion(vector<T>&);
        void ordenaBurbuja(vector<T>&);
        void ordenaMerge(vector<T>&);
        int busqSecuencial(vector<T>&, int val);
        int busqBinaria(vector<T>&, int val);

    private:
        void swap(vector<T>&, int, int);

		void copyArray(vector<T>&, vector<T>&, int, int);
		void mergeArray(vector<T>&, vector<T>&, int, int, int);
		void mergeSplit(vector<T>&, vector<T>&, int, int);
};

template <class T>
void Sorts<T>::swap(vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

//O(n^2), son dos ciclos.
template <class T>
void Sorts<T>::ordenaSeleccion(vector<T> &source) {
	for(int i=source.size()-1; i>0; i--){
		int pos=0;//max
		for(int j=1; j<=i; j++){
			int min=source[0];
			if(source[j] > source[pos]){
				pos = j;
			}
		}
		if(pos != i){
			swap(source, i, pos);
		}
	}
}

//O(n^2), son dos ciclos.
template <class T>
void Sorts<T>::ordenaBurbuja(vector<T> &source) {
	for (int i=source.size()-1; i>0; i--) {
		for (int j=0; j<i; j++) {
			if (source[j] > source[j+1]) {
				swap(source, j, j+1);
			}
		}
	}
}


//MERGE SORT
template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {
	int i, j, k;
	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high) {
	int mid;
	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

template <class T>
void Sorts<T>::ordenaMerge(vector<T> &source) {
	vector<T> tmp(source.size());
	mergeSplit(source, tmp, 0, source.size() - 1);
}
//END MERGE SORT


template <class T>
int Sorts<T>::busqSecuencial(vector<T> &source, int val){
	for (int i=0; i < source.size(); i++) {
        if (source[i] == val) {
            return i;
        }
    }
    return -1;
}

template <class T>
int Sorts<T>::busqBinaria(vector<T>&source, int val) {
    ordenaBurbuja(source);
    int low = 0;
    int high = source.size()-1;
    while (low <= high) {
        int mid = (low+high)/2;
        if (source[mid] == val) {
            return mid;
        }
        else if (val > source[mid]) {
            low = mid+1;
        }
        else if (val < source[mid]) {
        	high = mid-1;
        }
    }
    return -1;
}


#endif