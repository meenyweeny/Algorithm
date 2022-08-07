//
// Created by 이경민 on 2022/08/08.
//
#include<iostream>
using namespace std;

bool check[10001];

void d(int x) {
    int ret = x;
    while(x!=0){
        ret += (x%10);
        x/=10;
    }
    if(ret>10000) return;
    check[ret]=true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=1; i<=10000; i++) d(i);
    for(int i=1; i<=10000; i++) {
        if(check[i]) continue;
        cout<<i<<"\n";
    }
}
