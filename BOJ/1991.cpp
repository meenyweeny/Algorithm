//
// Created by 이경민 on 2023/01/14.
//
#include<iostream>
#include<vector>
using namespace std;

int n;
char tree[26][2];
bool visited[26];

void preorder(char parent) {
    cout<<parent;
    if(tree[parent-'A'][0]>='A' && tree[parent-'A'][0]<='Z') {
        preorder(tree[parent-'A'][0]);
    }
    if(tree[parent-'A'][1]>='A' && tree[parent-'A'][1]<='Z') {
        preorder(tree[parent-'A'][1]);
    }
}

void inorder(char parent) {
    if(tree[parent-'A'][0]>='A' && tree[parent-'A'][0]<='Z') {
        inorder(tree[parent-'A'][0]);
    }
    cout<<parent;
    if(tree[parent-'A'][1]>='A' && tree[parent-'A'][1]<='Z') {
        inorder(tree[parent-'A'][1]);
    }
}

void postorder(char parent) {
    if(tree[parent-'A'][0]>='A' && tree[parent-'A'][0]<='Z') {
        postorder(tree[parent-'A'][0]);
    }
    if(tree[parent-'A'][1]>='A' && tree[parent-'A'][1]<='Z') {
        postorder(tree[parent-'A'][1]);
    }
    cout<<parent;
}

void input() {
    cin>>n;
    char a,b;
    for(int i=0; i<n; i++) {
        cin>>a;
        for(int j=0; j<2; j++) {
            cin>>b;
            tree[a-'A'][j] = b;
        }
    }
}

void solution() {
    preorder('A');
    cout<<"\n";
    inorder('A');
    cout<<"\n";
    postorder('A');
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
