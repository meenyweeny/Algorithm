//
// Created by 이경민 on 2022/08/31.
//
#include<iostream>
#include<deque>
using namespace std;

int n,m,k;
int answer;
deque<int> dq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=1; i<=n; i++) dq.push_back(i);

    while(m--){
        cin>>k;
        if(dq.front()==k) dq.pop_front();
        else if(dq.back()==k) {
            dq.pop_back();
            ++answer;
        }
        else {
            for(int i=0; i<dq.size(); i++){
                if(dq[i]!=k) continue;
                if(i<=(dq.size()/2)) {
                    for(int j=0; j<i; j++) {
                        dq.push_back(dq.front());
                        dq.pop_front();
                        ++answer;
                    }
                    dq.pop_front();
                }
                else {
                    for(int j=0; j<dq.size()-i; j++){
                        dq.push_front(dq.back());
                        dq.pop_back();
                        ++answer;
                    }
                    dq.pop_front();
                }
            }
        }
    }
    cout<<answer;
}
