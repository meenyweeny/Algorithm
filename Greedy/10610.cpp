//
//  10610.cpp
//  BOJ
//
//  Created by 이경민 on 2022/02/06.
//

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string str;
int mod;
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>str;
    for(int i=0; i<str.length(); i++){
        v.push_back(str[i]-'0');
        mod+=str[i]-'0';
    }
    
    sort(v.begin(),v.end());
    reverse(v.begin(), v.end());
    
    if(mod%3 != 0 || v[str.length()-1] != 0) {
        cout<<-1;
        return 0;
    }
    else {
        for(auto i:v){
            cout<<i;
        }
    }
}
