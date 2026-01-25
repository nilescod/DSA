#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

int height(Node* root,int &maxi){
    if(root==NULL) return 0;
    int lsum=height(root->left,maxi);
    int rsum=height(root->right,maxi);
    maxi=max(maxi,lsum+rsum+root->data);

    return root->data+max(lsum,rsum);
}
int maxsum(Node* root){
    int maxi=0;
    height(root,maxi);
    return maxi;
}

int main(){
    Node* root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout<<maxsum(root);
}