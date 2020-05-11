#include <iostream>
#include <array>
#include <cctype>
#include <queue>


using namespace std;
#define ARR_SIZE 10000

// 0 1 2 3 4

void merge(int a[], int s, int mid, int e){	
	size_t b1s = (mid - s + 1);
	size_t b2s = (e -(mid+1) +1 );
	int b1[b1s];
	int b2[b2s];

	for(int x = 0; x < b1s; x++){
		b1[x] = a[x + s];
	}
	
	for(int x = 0; x < b2s; x++){
		b2[x] = a[x+mid+1];
	}


	for(int x = 0; x < b1s; x++){
		cout << b1[x] << " ";
	}
	
	for(int x = 0; x < b2s; x++){
		cout << b2[x] << " "; 
	}

	cout << endl;
	int c = s;
	int i = 0, j = 0;

	while(i < b1s || j < b2s){
		if(i < b1s && j < b2s){
			if(b1[i] <= b2[j]){
				a[c] = b1[i];
				c++;
				i++;
			}else if(b1[i] >= b2[j]){
				a[c] = b2[j];
				c++;
				j++;
			}
		}else if(i >= b1s && j < b2s){
			a[c] = b2[j];
			c++;
			j++;
		}else if(j >= b2s && i < b1s){
			a[c] = b1[i];
			c++;
			i++;
		}
	}

}

void mergeSort(int a[], int s, int e){
	if(s < e){
		int mid = (s+e) /2;
		mergeSort(a, s, mid);
		mergeSort(a, mid+1, e);
		merge(a, s, mid, e);
	}
}





int main(void){

	int a[ARR_SIZE] = {0};
	char c;
	size_t s = 0;
	while((c = cin.get()) != EOF){
		if(isdigit(c)){
			a[s] = c - '0';
			s++;
		}
	}

 	 mergeSort(a, 0, s-1);
 	//merge(a, 0, (s/2), s-1);

	for(int i = 0; i < s; i++){
		cout << a[i] << endl;
	}
}

