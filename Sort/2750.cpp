//
// Created by 이경민 on 2022/06/17.
//
#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000];
int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];

    for(int i=0; i<n; i++){
        for(int k=0; k<i; k++){
            if(arr[k]>arr[i]) swap(arr[i],arr[k]);
        }
    }

    for(int i=0; i<n; i++) cout<<arr[i]<<"\n";
}
