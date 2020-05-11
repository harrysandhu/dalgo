#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <sstream>

using namespace std;


int parent(int i){
	return i/2;
}

int left(int i){
	return 2*(i) + 1;
}

int right(int i){
	return 2*(i) + 2;
}

void printHeap(vector<int> &xheap){
	int i = 0;
	while(i < parent(xheap.size())){
		cout << "node " << xheap[i] << "----" << endl;
		cout << "LEFT " << xheap[left(i)] << " -+-" << endl;
		cout << "RIGHT " << xheap[right(i)] << "//" << endl << endl;
		i++;
	}
}
	


void maxHeapify(vector<int> &a, int i){
	int l = left(i);
	int r = right(i);
	int largest = i;

	if(l < a.size() && a[l] > a[largest])
		largest = l;
	if(r < a.size() && a[r] > a[largest])
		largest = r;

	if(largest != i){
		//swap largest and i
		int temp = a[largest];
		a[largest] = a[i];
		a[i] = temp;
		maxHeapify(a, largest);
	}

}

void buildMaxHeap(vector<int> &a){
	//take the bottom up approach
	for(int i = (a.size() /2 ) +1; i >= 0; --i){
		cout << "testing:: " << a[i] << endl;
		cout << "LEFT " << a[left(i)] << " -+-" << endl;
		cout << "RIGHT " << a[right(i)] << "//" << endl << endl;
		maxHeapify(a, i);
	}
}


int main(void){

	vector<int> xheap;



	int c;
	size_t s = 0;
	while((c = cin.get()) != EOF){
		if(isdigit(c)){
			xheap.push_back(c - '0');
		}
	}

	for(int i = 0; i < s; i++){
		cout << xheap[i] << endl;
	}

	 printHeap(xheap);
	buildMaxHeap(xheap);
	cout << "built" << endl;
	printHeap(xheap);

	// cout << xheap[(xheap.size() / 2 )- 1];
}