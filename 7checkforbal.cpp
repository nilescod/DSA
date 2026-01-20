#include<bits/stdc++.h>
using namespace std;
//check for balanced tree

struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};
//NAIVE SOLUTION 
//TC IS O(n*n) and SC IS O(n)
int findh(Node* root){
    if(root==NULL) return 0;
    int lh=findh(root->left); 
    int rh=findh(root->right);
    return 1+max(lh,rh);
}
bool check(Node* node){
    if (node==NULL) return true;
    int lh=findh(node->left);
    int rh=findh(node->right);
    if(abs(lh-rh)>1) return false;

    bool left=check(node->left);
    bool right=check(node->right);

    if(!left||!right) return false;
    return true;
}

//OPTIMAL SOLUTION
//TC IS O(n)
int check2(Node* root){
    if(root==NULL) return 0;
    int lh=check2(root->left);
    if(lh==-1) return -1;
    int rh=check2(root->right);
    if(rh==-1) return -1;
    
    if(abs(lh-rh)>1) return -1;
    
    return 1+max(lh,rh);
}

int main(){
    Node* root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->right->left = new Node(6);

    cout<<check2(root);
}
