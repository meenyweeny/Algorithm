//
// Created by 이경민 on 2022/08/30.
//
#include<iostream>
#include<deque>
using namespace std;

deque<int> dq;
int n,k,m;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k>>m;
    for(int i=1; i<=n; i++) dq.push_back(i);

    bool flag = true;
    int count = 0;
    while(!dq.empty()) {
        if(flag) {
            for(int i=1; i<k; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            cout<<dq.front()<<"\n";
            dq.pop_front();
        }
        else {
            for(int i=1; i<k; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cout<<dq.back()<<"\n";
            dq.pop_back();
        }
        ++count;
        if(count == m) {
            count = 0;
            flag = !flag;
        }
    }
}
