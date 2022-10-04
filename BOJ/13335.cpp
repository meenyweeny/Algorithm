//
// Created by 이경민 on 2022/08/24.
//
#include<iostream>
#include<deque>
#include<queue>
using namespace std;

#define weight first
#define distance second

int n,w,L,a;
int now_weight,answer;
queue<int> bus;
deque<pair<int,int>> bridge; //무게, 위치

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> w >> L;
    for(int i=0; i<n; i++) {
        cin>>a;
        bus.push(a);
    }

    while(!((bridge.empty() && bus.empty()))){
        ++answer;

        for(int i=0; i<bridge.size(); i++) {
            ++bridge[i].distance;
        }

        if(!bridge.empty()) {
            if(bridge[0].distance == w) {
                now_weight -= bridge[0].weight;
                bridge.pop_front();
            }
        }
        if(!bus.empty()){
            if(bus.front() + now_weight <= L) {
                now_weight += bus.front();
                bridge.push_back({bus.front(), 0});
                bus.pop();
            }
        }
    }

    cout<<answer;
}
