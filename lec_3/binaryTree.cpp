#include <iostream>
#include <cstdlib>
#include <array>

using namespace std;
#define arsize 7


typedef struct node{
	int n;
	struct node* right;
	struct node* left;
}node;


int left(int i){
	return 2*i +1;
}

int right(int i){
	return 2*i + 2;
}


int height(node *root){
	int h = 0;
	return h;
}

// void treeDelete(node* root, node* u, node* v){

// }

// void transplant(node* root, node* u, node* v){

// }

// z->left = null, z->right = null
void insert(node* root, node* z){
	node* x = root; //current node
	node* t = NULL; // trailing node

	while(x != NULL){
		//move thru the tree
		t = x;
		if(z->n < x->n){
			x = x->left;
		}else{
			x = x->right;
		}
	}
	if(x == NULL) x = z; // tree was empty
	if(t->n > z->n){ //
		t->left = z;
		cout << t->left->n  << ", " <<  t->n<< endl;
	}else{
		t->right = z;
		cout << t->n << ", " << t->right->n << endl;
	}
}	





void inorder(node *head){
	if(head != NULL){
		cout << head->n << ", ";
		inorder(head->left);

		inorder(head->right);
					
	
	}
}

node* create(int i){
	node* x = (node*) malloc(sizeof(node));
	x->n = i;
	return x;
}


// void createTr(array<int, arsize> &ar, int lo, int hi, node* cur, node* head){
	
// }


void createBin(array<int, arsize> &ar, int i, node* cur, node* head){
	if(i >= 0 && right(i) < arsize){
		cur->left = create(ar[left(i)]);
		cur->right = create(ar[right(i)]);
		createBin(ar, left(i), cur->left, head);
		createBin(ar, right(i), cur->right, head);
	}
}




int main(void){
	
	array<int, arsize>ar = {10, 9, 11, 8, 6, 12, 13};
	
	node* head = create(ar[0]);
	createBin(ar, 0, head, head);
	//  cout << head->right->left->n << endl;
	inorder(head);
	node* sev = create(7);
	insert(head, sev);
	inorder(head);
}	
