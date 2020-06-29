#include <iostream>
#include <vector>
#include <cstdlib>


using namespace std;

typedef struct obj{
    int key;
    int val;
};

int maxCycleLength(int i, int j){
    vector<obj> prevals;
    int max;
    for(int x = i; x <= j; x++){
        int key = -1;
        if(){
            if(prevals)
        }
    }
    max = 0
}

int cycleLength(int n){

    int c = 1;
  
    while(n != 1){
        if(n % 2 != 0){
            n = 3*n + 1;
        }else{
            n /= 2;
        }
    }
    return c;
}

int main(int argc, char* argv[]){
    int i, j;
    if(argc != 3) return 1;

    i = atoi(argv[1]);
    j = atoi(argv[2]);
    
    int c = maxCycleLength(i, j);
        
    cout << "\n" << i << " " << j << " " << c;
}