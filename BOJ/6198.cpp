//
// Created by 이경민 on 2022/08/21.
//
#include<iostream>
#include<stack>
using namespace std;

int n;
long long answer;
int arr[80001];
stack<int> st;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        while(!st.empty() && st.top() <= arr[i]) st.pop();
        answer += (long long)st.size();
        st.push(arr[i]);
    }
    cout<<answer;
}