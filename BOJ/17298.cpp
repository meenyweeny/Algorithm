//
// Created by 이경민 on 2022/08/20.
//
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

#define MAX 1000000 + 1

int n,x;
int arr[MAX];
stack<pair<int,int>> st;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    memset(arr,-1,sizeof(arr));
    for(int i=1; i<=n; i++) {
        cin>>x;
        while(!st.empty()) {
            if(st.top().first < x) {
                arr[st.top().second] = x;
                st.pop();
            }
            else break;
        }
        st.push({x,i});
    }
    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }
}