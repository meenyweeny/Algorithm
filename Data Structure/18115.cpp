//
// Created by 이경민 on 2022/08/30.
//
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int n,a;
deque<int> dq;
deque<int> tmp;
deque<pair<int,int>> answer;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1; i<=n; i++) {
        dq.push_back(i);
    }

    for(int i=0; i<n; i++){
        cin>>a;
        if(a==3){
            tmp.push_front(dq.back());
            dq.pop_back();
        }
        else if(a==1) {
            tmp.push_front(dq.front());
            dq.pop_front();
        }
        else {
            int temp = dq.front();
            dq.pop_front();
            tmp.push_front(dq.front());
            dq.pop_front();
            dq.push_front(temp);
        }
    }

    for(int i=0; i<n; i++) {
        answer.push_back({tmp[i],i+1});
    }

    sort(answer.begin(), answer.end());

    for(auto i:answer) cout<<i.second<<" ";
}
