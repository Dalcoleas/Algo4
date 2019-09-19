#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void heapify(int arr[], int n, int i) 
{ 
	int largest = i; 
	int l = 2*i + 1; 
	int r = 2*i + 2;

	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 
		heapify(arr, n, largest); 
	} 
} 

void heapSort(int arr[], int n) 
{ 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i); 

	for (int i=n-1; i>=0; i--) 
	{ 
		swap(arr[0], arr[i]); 
		heapify(arr, i, 0); 
	} 
} 

bool check(int numA, int numB){
    if(numA>=numB){
        return true;
    } else{
        return false;
    }
}
  
int main(){

    int casos,cantidad;
    cin >> casos;
    int arr[casos];

    for(int l = 0; l<casos;l++){
        cin >> cantidad;
        int a[cantidad];
        arr[l] = 2;
        int cont = 2;

        int size = sizeof(a) / sizeof(a[0]);

        for(int i=0;i<size;i++){
            cin >> a[i];
        }

        heapSort(a,cantidad);

        for(int i=0;i<cantidad;i++){
            if(check(a[i], arr[l])){
                arr[l] = cont * 2;
                cont++;
            }     
        }
    }

    for (int i = 0 ; i < casos; i++){
        cout << arr[i] << endl;
    }  
}