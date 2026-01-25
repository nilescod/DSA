#include<bits/stdc++.h>
using namespace std;
//VERTICAL ORDER TRAVERSAL
//TC IS O(n*logn) SC IS O(n) 
struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

vector<vector<int>>verticalordertra(Node* root){
    map<int,map<int,multiset<int>>>nodes;
    //here first int is vertical order according to which the map is sorted 
    queue<pair<Node*,pair<int,int>>>todo;
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        Node* node=p.first;
        int x=p.second.first,y=p.second.second;
        nodes[x][y].insert(node->data);
        if(node->left!=NULL){
            todo.push({node->left,{x-1,y+1}});
        }
        if(node->right!=NULL){
            todo.push({node->right,{x+1,y+1}});
        }
    }
    vector<vector<int>>ans;
    for(auto p:nodes){
        vector<int>col;
        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
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

    vector<vector<int>>ans;
    
    ans=verticalordertra(root);
    
    for(const auto &row: ans){
        for(int it:row){
            cout<<it<<" ";
        }
    }




}