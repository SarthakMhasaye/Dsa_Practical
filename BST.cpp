#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* node, int value) {
    if (node == NULL) {
        return createNode(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return node;
}

bool search(Node* node, int value) {
    if (node == NULL) return false;
    if (value == node->data) return true;
    if (value < node->data) return search(node->left, value);
    return search(node->right, value);
}

Node* deleteNode(Node* node, int value) {
    if (node == NULL) return NULL;
    
    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    } else {
        if (node->left == NULL) return node->right;
        if (node->right == NULL) return node->left;
        
        Node* temp = node->right;
        while (temp->left != NULL) temp = temp->left;
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

void inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    Node* root = NULL;
    
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    
    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (search(root, 100) ? "Found" : "Not Found") << endl;
    
    root = deleteNode(root, 20);
    cout << "After deleting 20: ";
    inorder(root);
    cout << endl;
    
    return 0;
}
