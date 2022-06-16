//
// Created by 이경민 on 2022/06/16.
//
#include<iostream>
using namespace std;

int arr[100001];
int sum[100001];
int n,m,s,e;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>arr[i];
    sum[0]=arr[0];
    for(int i=1; i<n; i++) sum[i]=sum[i-1]+arr[i];
    while(m--){
        cin>>s>>e;
        cout<<sum[e-1]-sum[s-2]<<"\n";
    }
}
