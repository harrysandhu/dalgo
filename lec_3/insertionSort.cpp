#include <iostream>
#include <array>
#include <cctype>

using namespace std;
#define ARR_SIZE 10000


void insertionSort(array<int, ARR_SIZE> & a, size_t n){
	int j = 0, temp = 0;
	a[-1] = 10;
	for(int i = 0; i < n; i++){
		j = i-1;
		temp = a[i];
		while(j >= 0 && a[j] >= temp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}






int main(void){

	array<int, ARR_SIZE> a = {0};
	char c;
	size_t s = 0;
	while((c = cin.get()) != EOF){
		if(isdigit(c)){
			a[s] = c - '0';
			s++;
		}
	}

 	insertionSort(a, s);
	for(int i = 0; i < s; i++){
		cout << a[i] << endl;
	}
}

