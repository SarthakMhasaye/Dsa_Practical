#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;  
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> list;
        for(int i = 0; i < size; i++){
            Node* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            list.push_back(node->data);
        }
        ans.push_back(list);
    }
    return ans;
}