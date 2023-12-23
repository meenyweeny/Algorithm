#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node * parent;
    Node * left;
    Node * right;

    Node(int d) {
        data = d;
        parent = left = right = NULL;
    }
};

const int nodesize = 1e5 + 1;
int n;
vector<int> v;
Node* info[nodesize];
bool visited[nodesize];
int endpoint;
bool flag;
int answer;

void init() {
    for(int i=1; i<=n; i++) {
        info[i] = new Node(i);
    }
}

void input() {
    cin>>n;
    init();
    int p,l,r;
    for(int i=0; i<n; i++) {
        cin>>p>>l>>r;
        if(l!=-1) {
            info[p]->left = info[l];
            info[l]->parent = info[p];
        }
        if(r!=-1) {
            info[p]->right = info[r];
            info[r]->parent = info[p];
        }
    }
}

void inorder(int n) {
    if(info[n]->left!=NULL) {
        inorder(info[n]->left->data);
    }
    v.push_back(n);
    if(info[n]->right!=NULL) {
        inorder(info[n]->right->data);
    }
}

void similarinorder(int n) {
    visited[n] = true;
    if(flag) {
        return;
    }
    if(info[n]->left!=NULL && !visited[info[n]->left->data]) {
        ++answer;
        similarinorder(info[n]->left->data);
    } else if(info[n]->right!=NULL && !visited[info[n]->right->data]) {
        ++answer;
        similarinorder(info[n]->right->data);
    } else if(n==endpoint) {
        flag = true;
        return;
    } else if(info[n]->parent!=NULL) {
        ++answer;
        similarinorder(info[n]->parent->data);
    }
}

void solve() {
    input();
    inorder(1);
    endpoint = v.back();
    similarinorder(1);
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
    return 0;
}
