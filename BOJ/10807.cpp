//
// Created by 이경민 on 2022/08/22.
//
#include<iostream>
using namespace std;

int n,x;
int pos[101];
int neg[101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    while(n--) {
        cin>>x;
        if(x<0) ++neg[x*-1];
        else ++pos[x];
    }
    cin>>x;
    x<0 ? cout<<neg[x*-1] : cout<<pos[x];
}
