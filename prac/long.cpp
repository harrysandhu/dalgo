#include <iostream>
#include <string>
#include <vector>


using namespace std;


bool is_pal(string s){
    int n = s.size();
    for(int i = 0; i < n; i++)
        if(s[n-i-1] != s[i])
            return false;
    return true;

}

vector<int> str_contains(string s, char x){
    vector<int> data;
    int n = s.size();
    for(int i = n-1; i >= 0; --i){
        if(s[i] == x){
            data.push_back(i);
        }
    }

    return data;
}



void printv(vector<int> & data){
    for(int i : data){
        cout << i << ", ";
    }
    cout << endl;
}

string getSubStr(string s, int i, int index){
    string res = "";
    for(int x = i; x < index+1; x++){
        
    }
   cout << "Rs " << res << endl;
    return res;
    
}

string get_largest_palin_index(string s, int x){
     int n = s.size();
    string temp;
    for(int i = n-1; i > x; --i){
        temp = s.substr(x, i-x+1);
        if(is_pal(temp)){
            return temp;
        }
    }
    return string(1, s[x]);
}


string lp(string s){
    int n = s.size();
    int maxlen = 0;
    vector<int> data;
    string lp;
    int index = 0;
    for(int i = 0; i < n; i++){
        if ((n - i) > maxlen){
            string temp = get_largest_palin_index(s, i);
                if(temp.size() > maxlen){
                    lp = temp;
                     maxlen = temp.size();
                    
                }
            }
        
    }
    return lp;
}



int main(void){
    string s = "kyyrjtdplseovzwjkykrjwhxquwxsfsorjiumvxjhjmgeueafubtonhlerrgsgohfosqssmizcuqryqomsipovhhodpfyudtusjhonlqabhxfahfcjqxyckycstcqwxvicwkjeuboerkmjshfgiglceycmycadpnvoeaurqatesivajoqdilynbcihnidbizwkuaoegmytopzdmvvoewvhebqzskseeubnretjgnmyjwwgcooytfojeuzcuyhsznbcaiqpwcyusyyywqmmvqzvvceylnuwcbxybhqpvjumzomnabrjgcfaabqmiotlfojnyuolostmtacbwmwlqdfkbfikusuqtupdwdrjwqmuudbcvtpieiwteqbeyfyqejglmxofdjksqmzeugwvuniaxdrunyunnqpbnfbgqemvamaxuhjbyzqmhalrprhnindrkbopwbwsjeqrmyqipnqvjqzpjalqyfvaavyhytetllzupxjwozdfpmjhjlrnitnjgapzrakcqahaqetwllaaiadalmxgvpawqpgecojxfvcgxsbrldktufdrogkogbltcezflyctklpqrjymqzyzmtlssnavzcquytcskcnjzzrytsvawkavzboncxlhqfiofuohehaygxidxsofhmhzygklliovnwqbwwiiyarxtoihvjkdrzqsnmhdtdlpckuayhtfyirnhkrhbrwkdymjrjklonyggqnxhfvtkqxoicakzsxmgczpwhpkzcntkcwhkdkxvfnjbvjjoumczjyvdgkfukfuldolqnauvoyhoheoqvpwoisniv";
    // cout << s << endl;
    cout << "yoooo " << lp(s) << endl; 

}