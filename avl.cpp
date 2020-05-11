#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height = -1;
};

node* insert(node *r, node* z){
    node* ptr = r;
    node *t;


    while(ptr != NULL){
        t = ptr;
        if(z->data > ptr->data){
            //go right
            ptr = ptr->right;
        }else if(z->data <= ptr->data){
            //go left
            ptr = ptr->right;
        }
    }
    if(ptr == NULL) return z;
    else{
        if(z->data <= t->data){
            t->left = t;
        }else{
            t->right = t;
        }
    }
    return r;

}


node* avlInsert(node* r, node* z){
    //insert the node
      node* ptr = r;
    node *t;

    while(ptr != NULL){
        t = ptr;
        if(z->data > ptr->data){
            //go right
            ptr = ptr->right;
        }else if(z->data <= ptr->data){
            //go left
            ptr = ptr->right;
        }
    }
    if(ptr == NULL) return z;
    else{
        if(z->data <= t->data){
            t->left = t;
        }else{
            t->right = t;
        }
    }

    

    //work your way up restoring avl property and 

    // updating heights, maintain avl property.
        // if a nhl - nhr >= 1, do rotation
        // heavy on left -> do right rotate vice versa
        t->height = 0;
        ptr = t;
    while(ptr != NULL){
        int hl, hr;
        if(ptr->left == NULL) 
            hl = -1;
        else
            hl = ptr->left->height;
        //for right
        if(ptr->right == NULL) 
            hr = -1; 
        else
            hr = ptr->right->height;
        
        ptr->height = max(hl, hr) + 1; // ptr height
        if(abs(hl - hr) > 1){
            //needs rotation
            if(hl > hr){
                //right rotation
                node* temp = ptr->parent;
                temp->left = ptr->left;
                ptr->parent = temp->left;
            }else{
                //left rotation
                node* temp = ptr->parent;
                temp->right = ptr->right;
                ptr->parent = temp->right;
            }
        }
        
        ptr = ptr->parent;
    }

    

     
}

int main(void){

    


} 