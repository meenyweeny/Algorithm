//
// Created by 이경민 on 2022/06/06.
//
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

set<string> answer;
int n,k,x;
vector<int> v;
bool check[10];

void permutation(string s, int count) {
    if(count == k) {
        answer.insert(s);
        return;
    }
    for(int i=0; i<v.size(); i++) {
        if(check[i]) continue;
        check[i] = true;
        permutation(s+to_string(v[i]),count+1);
        check[i] = false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    while(n--){
        cin>>x;
        v.push_back(x);
    }
    permutation("",0);
    cout<<answer.size();
}
