//
// Created by 이경민 on 2022/06/17.
//
#include<iostream>
using namespace std;

int a,b,v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>a>>b>>v;
    v-=a;
    a-=b;
    (v%a != 0) ? cout<< (v/a)+2 : cout<< (v/a)+1;
}
