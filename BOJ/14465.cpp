//
// Created by 이경민 on 2022/06/16.
//
#include<iostream>
#include<algorithm>
using namespace std;

int n,k,b,x,ans;
int arr[100001];
bool broken[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k>>b;
    for(int i=1; i<=b; i++) {
        cin>>x;
        broken[x] = true;
    }
    arr[0]=0;
    for(int i=1; i<=n; i++){
        arr[i] = arr[i-1] + (broken[i] ? 0 : 1);
    }
    ans=n;
    for(int i=k; i<=n; i++){
        ans = min(ans,k-arr[i]+arr[i-k]); //순수 k개 내에서만 켜져있는 개수 확인하기 위함
    }
    cout<<ans;
}
