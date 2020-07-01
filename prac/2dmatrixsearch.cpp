#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



bool binsearch(vector<int> &m, int target, int lo, int hi){

    int mid = (lo + hi) +1/ 2;
    int t = m[mid];
    cout << "target" << target << "sf" << t;
    if(target - t == 0){
        return true;    
    }
    else if(lo >= hi) return false;
    else if(target < t){
        binsearch(m, target, lo, mid-1);
    }else if(target > t){
        binsearch(m, target, mid+1, hi);
    }
    
   
}

bool compfunc(int i, int j) {return (i < j);}

bool searchMatrix(vector< vector<int> >& matrix, int target) {
    if(matrix.size() == 0) return false;
    else if (matrix[0].size() == 0) return false;
    int row = 0;
    for(int i = 0; i < matrix.size(); i++){
        if(matrix[0][0] == target) return true;
        if(target <= matrix[i][matrix[i].size()-1]){
            row = i;
            break;
        }   
    }
    if(binary_search(matrix[row].begin(), matrix[row].end(), target, compfunc)) return true;

    return false;
}


int main(void){
    vector< vector<int> > m;
    vector<int> r1;
    r1.push_back(1);
    r1.push_back(3);
    r1.push_back(5);
    r1.push_back(7);

     vector<int> r2;
    r2.push_back(10);
    r2.push_back(11);
    r2.push_back(16);
    r2.push_back(20);

     vector<int> r3;
    r3.push_back(23);
    r3.push_back(30);
    r3.push_back(34);
    r3.push_back(50);
    
    m.push_back(r1);
    m.push_back(r2);
    m.push_back(r3);
vector< vector<int> > a;
vector <int>s;
s.push_back(1);
s.push_back(3);
a.push_back(s);
    bool x = searchMatrix(m, 5);
    if(x) cout << "true\n";
    else cout << "false\n";
}