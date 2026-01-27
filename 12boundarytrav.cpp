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

bool isLeaf(Node* root){
    return root->left==NULL && root->right==NULL;
}

void addLeftbound(Node* root,vector<int>&res){
    Node* curr=root->left;
    while(curr!=NULL){
        if(!isLeaf(curr))res.push_back(curr->data);
        if(curr->left!=NULL) curr=curr->left;
        else curr=curr->right;
    }
}

void addRightbound(Node* root,vector<int>&res){
    Node* curr=root->right;
    vector<int>temp;
    while(curr!=NULL){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right!=NULL) curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}

//USES PREORDER TRAVERSAL
void addLeaves(Node* root,vector<int>&res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return ;
    }
    if(root->left!=NULL) addLeaves(root->left,res);
    if(root->right!=NULL) addLeaves(root->right,res);

}

vector<int>boundarytrav(Node* root){
    vector<int>ans;
    if(root==NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    addLeftbound(root,ans);
    addLeaves(root,ans);
    addRightbound(root,ans);
    return ans;
}

int main(){
    Node* root = new Node(1);
root->left = new Node(2);
root->left->left = new Node(4);
root->left->left->left = new Node(10);
root->left->left->right = new Node(11);
root->left->right = new Node(5);
root->left->right->left = new Node(12);
root->left->right->right = new Node(13);
root->right = new Node(3);
root->right->right = new Node(6);

vector<int> result = boundarytrav(root);
for (int val : result) cout << val << " ";



}