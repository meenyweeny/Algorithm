//
// Created by 이경민 on 2023/02/13.
//
#include<iostream>
#include<queue>
#include<deque>
using namespace std;

struct lecture {
    int start;
    int end;

    bool operator<(const lecture & b) const {
        if(start == b.start) {
            return end > b.end;
        } else {
            return start > b.start;
        }
    }
};

int n;
priority_queue<lecture> pq;

void input() {
    cin>>n;
    int s,t;
    for(int i=0; i<n; i++) {
        cin>>s>>t;
        pq.push({s,t});
    }
}

void solution() {
    lecture top = pq.top();
    pq.pop();
    priority_queue<int, vector<int>, greater<int>> endtime;
    endtime.push(top.end);

    while(!pq.empty()) {
        top = pq.top();
        pq.pop();

        if(endtime.top() > top.start) {
            endtime.push(top.end);
        } else {
            endtime.pop();
            endtime.push(top.end);
        }
    }

    cout<<endtime.size();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
