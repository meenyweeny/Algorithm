//
// Created by 이경민 on 2022/06/01.
//
#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
string str;
set<string> s;
vector<string> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    while(n--){
        cin>>str;
        s.insert(str);
    }
    while(m--){
        cin>>str;
        if(s.contains(str)) v.push_back(str);
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<"\n";
    for(auto i:v){
        cout<<i<<"\n";
    }
}
