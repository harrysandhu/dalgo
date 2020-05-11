#include <iostream>
#include <vector>

using namespace std;


int left(int i){
	return 2*i +1; 
}

int right(int i){
	return 2*i + 2;
}


// void minheapify()


vector<int> findMedian(vector<int> &v1, vector<int> &v2){
		

	//v1 and v2 are two min heaps 
	//concat v1 and v2 and min-heapify v1.size() - 1
	v1.insert(v1.end(), v2.begin(), v2.end())
	return v1;
}


void printv(vector<int> &a){
	cout << "[ ";
	for(int i : a)
		cout << i << " ";
	cout << "]\n";
}

int main(void){
	vector<int>v1;
	v1.push_back(2);
	v1.push_back(6);
	v1.push_back(20);
	
	vector<int>v2;
	v2.push_back(4);
	v2.push_back(10);
	v2.push_back(15);

	vector<int>v3 = findMedian(v1);
	printv(v1);
	printv(v2);
	printv(v3);
}	
