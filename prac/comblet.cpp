#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <array>

using namespace std;


#define MULTIPLIER 91
#define INITIAL_M 16
#define WORD_SIZE 64



template<typename K, typename V>
struct item{
    K key;
    V value;
};


//#define arsize 100
template <typename K, typename V>
class Dict{
private:
    array<item<K,V>, INITIAL_M> htable;
    int m;

public:
    Dict(void);
    int mhash(K key);
    void insert(item<K, V> a);
    item<K, V> search(K key);
    void printTable(void);
    int getCurrentSize(void);
    void display(item<K,V> a);
};


template <typename K, typename V>
Dict<K,V>::Dict(void){
    // initialize the table
    m = INITIAL_M; // set table size variable. the table array is already initialized
}


template <typename K, typename V>
int Dict<K, V>::getCurrentSize(){
    return sizeof(htable) / sizeof(htable[0]);
}


template <typename K>
int prehash(K key){
    //use hasher to prehash
    hash<K> hasher;
    return abs((int)hasher(key) << 5);
}

template <typename K, typename V>
int Dict<K, V>::mhash(K key){
    int k = prehash(key);
    int m = getCurrentSize();
    double a = 0.6180339887;
    // m (ka mod 1)
    double frac = k * a - floor(k*a);
    return floor(m * frac);
}


template <typename K, typename V>
void Dict<K, V>::insert(item<K, V> a){
    int h = mhash(a.key);
    htable[h] = a;
}

template <typename K, typename V>
item<K, V>Dict<K, V>::search(K key){
    int keyIndex = mhash(key);
    if(keyIndex < 0 || keyIndex >= getCurrentSize()){
        return item<K,V>();
    }

    item<K, V>a = htable[keyIndex];
    return a;

}

template <typename K, typename V>
void Dict<K, V>::display(item<K,V> a){
    cout << a.key << ": " << a.value << endl;
}




template <typename K, typename V>
void Dict<K,V>::printTable(void){
    for(int i = 0; i < getCurrentSize(); i++){
        cout << htable[i].key << ": " << htable[i].value << endl;
    }
}



vector<string> letterComb(string digits){
   

    Dict<char, string> map;

    item<char,string> a = {'1', ""};
    item<char,string> a1 = {'2', "abc"};
    item<char,string> a2 = {'3', "def"};
    item<char,string> a3 = {'4', "ghi"};
    item<char,string> a4 = {'5', "jkl"};
    item<char,string> a5 = {'6', "mno"};
    item<char,string> a6 = {'7', "pqrs"};
    item<char,string> a7 = {'8', "tuv"};
    item<char,string> a8 = {'9', "wxyz"};
    map.insert(a);
    map.insert(a1);
    map.insert(a2);
    map.insert(a3);
    map.insert(a4);
    map.insert(a5);
    map.insert(a6);
    map.insert(a7); 
    
    int s = 1;
    const int n = digits.size(); 
    for(int i = 0; i < n; i++){
        string e = map.search(digits[i]).value;
        s *= e.size();
    }  

    vector<string>ar;
    int i = 0;
   
    int ind[n];
    for(int z = 0; z < n; z++) ind[z] = 0;
    while(i < s){
        string str = "";
        for(int j = 0; j < n; ++j){ // for each digit
            str += map.search(digits[j]).value[ind[j]];
        }
        ar.push_back(str);
        for(int x = n-1; x >= 0; --x){
            int max = map.search(digits[x]).value.size() -1;
            if (ind[x] < max){
                ind[x] += 1;
                break;
            }
            else{
                ind[x] = 0;
            }
        }
        i++;
    }
    return ar;
}

int main(void){

  
    string d = "234";
    vector<string> x = letterComb(d);
    for(string s : x){
        cout << s << " , ";
    }

    cout << endl;
}
