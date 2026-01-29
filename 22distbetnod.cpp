#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

//TC IS O(n+n) and SC IS O(n+n+n)

void markparent(Node* root, unordered_map<Node*, Node*>& parent_track) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front(); q.pop();
        if (current->left) {
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if (current->right) {
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}

vector<int> distancek(Node* root, Node* target, int k) {
    unordered_map<Node*, Node*> parent_track;
    markparent(root, parent_track);

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;

    while (!q.empty()) {
        int size = q.size();
        if (curr_level == k) break;
        curr_level++;
        for (int i = 0; i < size; i++) {
            Node* current = q.front(); q.pop();
            if (current->left && !visited[current->left]) {
                q.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right]) {
                q.push(current->right);
                visited[current->right] = true;
            }
            if (parent_track[current] && !visited[parent_track[current]]) {
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }

    vector<int> result;
    while (!q.empty()) {
        Node* current = q.front(); q.pop();
        result.push_back(current->data);
    }
    return result;
}

int main() {
    Node* root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(20);
    Node* root2 = root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(30);
    root->right->right = new Node(40);

    vector<int> ans = distancek(root, root2, 2);

    for (int val : ans) {
        cout << val << " ";
    }
}
