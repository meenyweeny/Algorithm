//
//  10807.cpp
//  BOJ
//
//  Created by 이경민 on 2022/05/11.
//

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
using namespace std;

int n,v,k;
int neg[101];
int pos[101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>n;
    while(n--){
        cin>>k;
        if (k<0) ++neg[k*-1];
        else ++pos[k];
    }
    cin>>v;
    if(v<0) cout<<neg[v*-1];
    else cout<<pos[v];
}
