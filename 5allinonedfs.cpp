#include<bits/stdc++.h>
using namespace std;
//TC IS O(3n) and SC IS O(4n) 
struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

void preinpost(Node* root){
    stack<pair<Node*,int>>st;
    st.push({root,1});
    vector<int>pre,in,post;
    if(root==NULL) return ;
    while(!st.empty()){
        auto it=st.top();
        st.pop();

        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }
    int n=pre.size();
    cout<<"Preorder Traversal: ";
    for(int i=0;i<n;i++)  cout<<pre[i]<<" ";
    cout<<endl;
    cout<<"Inorder Traversal: ";
    for(int i=0;i<n;i++)  cout<<in[i]<<" ";
    cout<<endl;
    cout<<"Postorder Traversal: ";
    for(int i=0;i<n;i++)  cout<<post[i]<<" ";
}

int main(){
    Node* node=new Node(1);
    node->left=new Node(2);
    node->right=new Node(5);
    node->left->left=new Node(3);
    node->left->right=new Node(4);
    node->right->left=new Node(6);
    node->right->right=new Node(7);

    preinpost(node);

}