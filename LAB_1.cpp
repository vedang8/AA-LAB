#include <bits/stdc++.h>
using namespace std;

int Partition(int A[], int p, int r){
    int x = A[r];
    int i = p-1;
    int j;
    //static int cnt = 0;
    for(j=p; j<=r-1; j++){
        if(A[j] <= x){
           i++;
           swap(A[j], A[i]);
        }
        //cnt++;
    }
    //cout << cnt << " ";
    swap(A[i+1], A[r]);
    return (i+1);
}

int Rpartition(int A[], int p, int r){
    int i = p + (rand()%(r-p+1));
    swap(A[i], A[r]);
    return (Partition(A, p, r));
}

void RandomizedQuickSort(int A[], int p, int r){
    if(p <= r){
        int q = Rpartition(A, p, r);
        RandomizedQuickSort(A, p, q-1);
        RandomizedQuickSort(A, q+1, r);
    }    
} 

int main() {
    srand(time(NULL));
    int n = 5;
    int A[] = {4, 1, 5, 2, 3};
    // for(int i=1; i<=n; i++){
    //     A[i] = i;
    // }
    
    RandomizedQuickSort(A, 0, 4);
    for(int i=0; i<5; i++){
        cout << A[i] << " ";
    }
    return 0;
}