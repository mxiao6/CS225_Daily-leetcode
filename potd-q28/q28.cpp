#include <iostream>
using namespace std;

struct node{
    int val;
    node * left;
    node * right;
};

void printTree(node * root){
    if(root == NULL){
        cout << "NULL ";
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

/*
 *Given a binary tree, flatten it to a linked list in-place
 *       1
        / \
       2   5
      / \   \
     3   4   6
 *
 * 1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
 * 
 * 1. move the root right branch to the end of root left branch;
 * 2. swap root right and left branch;
 * 3. keep doing it along the right branch.
 */

void smoosh(node * root){
    node * curr = root;
    while (curr) {
        if (curr -> left) { // if we have the left branch;
            node * left = curr -> left; // track the left branch;
            while (left -> right)
                left = left -> right; // go to the end of the left branch;
            left -> right = curr -> right; // move the root right branch to the end of root left branch;
            curr -> right = curr -> left; //swap root right and left branch;
            curr -> left = NULL; //clear pointer;
        }
        curr = curr -> right; //keep doing it along the right branch.
    }
}

int main(){
    node * root = new node;
    root->val = 1;
    node * temp = root;
    temp->left = new node;
    temp->left->val = 2;
    temp = temp->left;
    temp->left = new node;
    temp->left->val = 3;
    temp->left->left = NULL;
    temp->left->right = NULL;
    temp->right = new node;
    temp->right->val = 4;
    temp->right->left = NULL;
    temp->right->right = NULL;
    temp = root;
    temp->right = new node;
    temp->right->val = 5;
    temp->right->left = NULL;
    temp = temp->right;
    temp->right = new node;
    temp->right->val = 6;
    temp->right->left = NULL;
    temp->right->right = NULL;
    printTree(root);
    cout << endl;
    smoosh(root);
    printTree(root);
    cout << endl;

    return 0;
}
