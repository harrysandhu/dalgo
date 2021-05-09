#include <stdio.h>


void merge(int arr[], int l, int m, int r){
    
}


int* mergeSort(int a[], int s, int e){
    if (e > s){
        int mid = (s+e) / 2;
        int left[] = mergeSort(a, s, mid);
        int right[] = mergeSort(a, mid+1, e);
        return merge(left, right);
    }
    int x[s-(e+1)];
    for (int i = s, j = 0; i < e + 1; i++, j++){
        x[j] = a[i];
    }
    return x;
    
}

int main(void){
    int a[] = {4, 2, 5, 8, 7, 0, 1, 0, 1, 1, 1};
    int *x = mergeSort(a, 0, 10);

}

