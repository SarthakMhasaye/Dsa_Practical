#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

Node* createNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getHeight(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotation(Node* n) {
    Node* temp = n->left;
    n->left = temp->right;
    temp->right = n;
    n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
}

Node* leftRotation(Node* n) {
    Node* temp = n->right;
    n->right = temp->left;
    temp->left = n;
    n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
}

Node* insert(Node* node, int value) {
    if (node == NULL) return createNode(value);
    
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);
    if(balance > 1 && value < node->left->data){
        return rightRotation(node);
    }
    if(balance < -1 && value > node->right->data){
        return leftRotation(node);
    }
    if(balance > 1 && value > node->left->data){
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    if(balance < -1 && value < node->right->data){
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    return node;
}

void display(Node* node) {
    if (node == NULL) return;
    display(node->left);
    cout << node->data << " ";
    display(node->right);
}

int main() {
    Node* root = NULL;
    
    root = insert(root, 50);
    root = insert(root, 25);
    root = insert(root, 75);
    root = insert(root, 10);
    root = insert(root, 30);
    
    cout << "AVL Tree: ";
    display(root);
    cout << endl;
    
    return 0;
}
