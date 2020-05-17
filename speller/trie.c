// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <ctype.h>
// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#undef calculate
#undef getrusage

typedef struct trieNode{
    char str[45];
    struct trieNode* p[27];
}trieNode;

//global trieNode root
trieNode* root;
int size = 0;

bool trieInsert(char *s){
    int i = 0;
    int j = 0;
    trieNode *t = root;
    while(s[i] != '\0'){
        j = (isalpha(s[i])) ? s[i] - 97 : 26;
        if( t->p[j] == NULL){
            t->p[j] = malloc(sizeof(trieNode));     
        }
        t = t->p[j]; 
        i++;
    }
    strcpy(t->str, s);
    return true;
}

char* trieFind(char* s){
    int i = 0;
    int j = 0;
    trieNode *t = root;
    while(s[i] != '\0' && t != NULL){
        j = (isalpha(s[i])) ? s[i] - 97 : 26;
        if(t->p[j] == NULL){
            return NULL;
        }
        t = t->p[j];
        i++;
    }

    if(strcmp(t->str, s) != 0) {
        return NULL;
    }
    printf("here:: %s\n", t->str);
    return s;
}



// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    root = ( trieNode*)malloc(sizeof(trieNode));
	char str[LENGTH];
	char ch;
    // TODO
    FILE *fp = fopen(dictionary, "r");
    if(fp == NULL){
        printf("Error opening file.\n");
    	return false;
    }
    // trieInsert("hell's angles");
    // trieInsert("hello");

    while(fgets(str, LENGTH, fp) != NULL){
        str[strcspn(str, "\r\n")] = 0;
        trieInsert(str);
    }
    // char *s = trieFind("hell's angles");
     // char *x = trieFind("hello");

    fclose(fp);
    return true;
}

double calculate(const struct rusage *b, const struct rusage *a);

int main(void){
    
    struct rusage before, after;
    double time_load = 0.0;
    const char *dic = "dictionaries/large";
    
    getrusage(RUSAGE_SELF, &before);
    bool x = load(dic);
    getrusage(RUSAGE_SELF, &after);
    if(!x){
        printf("Could not load %s.\n", dic);
        return 1;
    }

    trieInsert("hello");
    char* z = trieFind("abidance");
        
    time_load = calculate(&before, &after);

    printf("TIME IN load:         %.2f\n", time_load);

}

// Returns number of seconds between b and a
double calculate(const struct rusage *b, const struct rusage *a)
{
    if (b == NULL || a == NULL)
    {
        return 0.0;
    }
    else
    {
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                  (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                 ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                  (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
    }
}



