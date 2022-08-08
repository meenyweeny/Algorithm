//
// Created by 이경민 on 2022/08/09.
//
#include<iostream>
using namespace std;

int n,tmp,sum;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1; i<n; i++) {
        sum=tmp=i;
        while(tmp!=0){
            sum+=(tmp%10);
            tmp/=10;
        }
        if(sum==n) {
            cout<<i;
            return 0;
        }
    }
    cout<<0;
}
