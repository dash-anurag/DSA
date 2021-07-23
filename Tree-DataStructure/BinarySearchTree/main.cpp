#include <bits/stdc++.h>
using namespace std;

class Node {
  public: 
  int data;
  Node* left;
  Node* right;
  Node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

class BinarySearchTree {
  Node* root;
  public:
  BinarySearchTree() {
    root = NULL;
  }

  void insertNode(int data) {
    auto newNode = new Node(data);
    auto temp = root;
    Node* x = NULL;

    while(temp == NULL) {
      x = temp;
      if(data < temp->data){
        temp = temp->left;
      } else {
        temp = temp->right;
      }
    }
    if(x == NULL){
      root = newNode;
    }

    else if( data < x->data) {
        x->left = newNode;
    } 
     else {
     x->right = newNode;
     }
  }

  

};

int main(void) {
  auto tree = new BinarySearchTree();
  tree;

  return 0;
}