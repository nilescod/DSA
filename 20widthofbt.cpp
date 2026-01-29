#include <bits/stdc++.h>
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

//TC IS O(n) and SC IS O(h) and O(n) in worst case of skew trees

int widthofbt(Node* root){
    if(root==NULL) return 0;
    int ans=0;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        int mini=q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            int cur_id=q.front().second-mini;
            Node* node=q.front().first;
            q.pop();

            if(i==0) first=cur_id;
            if(i==size-1) last=cur_id;

            if(node->left) q.push({node->left,(2*cur_id)+1});
            if(node->right) q.push({node->right,(2*cur_id)+2});
        }
        ans=max(ans,last-first+1);
    }
    return ans;

}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->right->right->left = new Node(7);

    cout<<widthofbt(root);
    
}