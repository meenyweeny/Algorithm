//
// Created by 이경민 on 2022/09/07.
//
#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> lhs;
priority_queue<int, vector<int>, greater<int>> rhs;

int n,x;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    --n;
    cin>>x;
    cout<<x<<"\n";
    lhs.push(x);

    int k;
    while(n--){
        cin>>x;
        if(lhs.size() > rhs.size()){
            k=lhs.top();
            lhs.pop();
            lhs.push(x < k ? x : k);
            rhs.push(x < k ? k : x);
        }
        else if(lhs.size() == rhs.size()){
            if(lhs.top()<x) rhs.push(x);
            else lhs.push(x);
        }
        else{
            k=rhs.top();
            rhs.pop();
            lhs.push(x < k ? x : k);
            rhs.push(x < k ? k : x);
        }

        if(lhs.size() >= rhs.size()) cout<<lhs.top();
        else cout<<rhs.top();
        cout<<"\n";
    }
}
