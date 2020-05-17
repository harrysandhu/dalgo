// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include "dictionary.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>


typedef struct trieNode{
    char str[45];
    struct trieNode* p[40];
}trieNode;

//global trieNode root
trieNode* root;

size_t SIZE = 0;

bool trieInsert(const char *s){
    int i = 0;
    int j = 0;
    trieNode *t = root;
     char x[strlen(s)];
    strcpy(x, s);
    while(s[i] != '\0'){
    	if(isupper(x[i])){
    		x[i] = tolower(x[i]);
    	}
        j = (isalpha(x[i])) ? x[i] - 97 : 26;
        if( t->p[j] == NULL){
            t->p[j] = malloc(sizeof(trieNode));     
        }
        t = t->p[j]; 
        i++;
    }
    strcpy(t->str, x);
    SIZE++;
    return true;
}

const char* trieFind(const char* s){
    int i = 0;
    int j = 0;
    trieNode *t = root;
    char x[strlen(s)];
    strcpy(x, s);
    while(s[i] != '\0' && t != NULL){
    	if(isupper(x[i])){
    		x[i] = tolower(x[i]);
    	}
        j = (isalpha(x[i])) ? x[i] - 97 : 26;
        if(t->p[j] == NULL){
            return NULL;
        }
        t = t->p[j];
        i++;
    }
    if(strcmp(t->str, x) != 0) {
        return NULL;
    }
    return s;
}




// Returns true if word is in dictionary else false
bool check(const char *word)
{	
	const char* s = trieFind(word);
	if(s == NULL)
    	return false;
    return true;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
	 root = ( trieNode*)malloc(sizeof(trieNode));
	 SIZE = 0;
	char str[LENGTH];
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

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
	return SIZE;
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    free(root);
    return true;
}
