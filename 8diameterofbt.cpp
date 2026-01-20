#include<bits/stdc++.h>
using namespace std;
//DIAMETER IS THE LONGEST PATH BETWEEN TWO NODES
//PATH DOES NOT NEED TO PASS VIA ROOT NODE
struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

//NAIVE SOLUTION TAKES TC OF O(n*n)
int findh(Node* root){
    if(root==NULL) return 0;
    int lh=findh(root->left); 
    int rh=findh(root->right);
    return 1+max(lh,rh);
}

int diameterofbt(Node* root){
    if(root==NULL) return 0;
    int lh=findh(root->left);
    int rh=findh(root->right);

    int maxi=INT_MIN;
    maxi=max(maxi,lh+rh);

    diameterofbt(root->left);
    diameterofbt(root->right);
    return maxi;
}


//OPTIMAL SOLUTION
//TC OF O(n)
int height(Node* root,int &dia){
    if(root==NULL) return 0;
    int lh=height(root->left,dia); 
    int rh=height(root->right,dia);
    dia=max(dia,lh+rh);
    return 1+max(lh,rh);
}

int diametre(Node* root){
    int dia=0;
    height(root,dia);
    return dia;
}


int main(){
    Node* root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout<<diameterofbt(root)<<" "<<diametre(root);
}