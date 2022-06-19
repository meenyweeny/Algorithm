//
// Created by 이경민 on 2022/06/19.
//
#include<iostream>
using namespace std;

int k;
int a[46], b[46];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    a[0]=b[1]=1;

    cin>>k;

    for(int i=2; i<=k; i++){
        a[i] = a[i-2]+a[i-1];
        b[i] = b[i-2]+b[i-1];
    }
    cout<<a[k]<<" "<<b[k];
}
