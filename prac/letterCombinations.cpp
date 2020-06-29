#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<string> lc(string digits){
    vector<string> ar;
    map<char, string> xmap;
    xmap.insert(pair<char, string>('1', ""));
    xmap.insert(pair<char, string>('2', "abc"));
    xmap.insert(pair<char, string>('3', "def"));
    xmap.insert(pair<char, string>('4', "ghi"));
    xmap.insert(pair<char, string>('5', "jkl"));
    xmap.insert(pair<char, string>('6', "mno"));
    xmap.insert(pair<char, string>('7', "pqrs"));
    xmap.insert(pair<char, string>('8', "tuv"));
    xmap.insert(pair<char, string>('9', "wxyz"));

    int s = 1; 
    const int n = digits.size();
    for(int i= 0; i < n; i++){
        s *= xmap[digits[i]].size();
    }
    int i = 0;
    int ind[n];
    for(int z = 0; z < n; z++) ind[z] = 0;

    while(i < s){
        string str = "";
        for(int j = 0; j < n; j++){
            if(xmap[digits[j]][ind[j]].size()) == 0) continue;
            str += xmap[digits[j]][ind[j]];
        }

        ar.push_back(str);
        for(int x = n-1; x >= 0; x--){
            int max = map[digits[x]].size();
            if(ind[x] < max){
                ind[x] += 1;
                break;
            }else{
                ind[x] = 0;
            }
        }
        i++
    }

    return ar;
}

int main(void){
    string digits = "23";
    vector<string> x = lc(digits);
}   