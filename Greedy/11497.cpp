//
// Created by 이경민 on 2022/09/11.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t;
int n,l,answer;
vector<int> tree;
vector<int> sorted_tree;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>l;
            tree.push_back(l);
        }
        sort(tree.begin(),tree.end());

        for(int i=0; i<n; i++) {
            if(i%2!=0) continue;
            sorted_tree.push_back(tree[i]);
        }

        for(int i=n-1; i>0; i--){
            if(i%2==0) continue;
            sorted_tree.push_back(tree[i]);
        }

        answer=-1;

        for(int i=1; i<n; i++){
            answer = max(answer, abs(sorted_tree[i]-sorted_tree[i-1]));
        }
        cout<<answer<<"\n";
        tree.clear();
        sorted_tree.clear();
    }
}