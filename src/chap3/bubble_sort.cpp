#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

void bubbleSort(int arr[], int n){
    int i, j;
    rep(i, n-1){
        rep(j, n-i-1){
            if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void printArray(int arr[], int size){
    int i;
    rep(i, size) cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array" << endl;
    printArray(arr, n);
    return 0;
}