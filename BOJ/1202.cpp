//
// Created by 이경민 on 2023/01/12.
//
#include<iostream>
#include<queue>
using namespace std;

int n,k,m,v;
pair<int,int> jewel[300001];
int bag[300001];
priority_queue<int> pq;

void input() {
    cin>>n>>k;
    for(int i=1; i<=n; i++) {
        cin>>m>>v;
        jewel[i] = {m,v};
    }
    for(int i=1; i<=k; i++) {
        cin>>bag[i];
    }
}

void solution() {
    sort(jewel+1, jewel+n+1);
    sort(bag+1,bag+k+1);

    int index = 0;
    long long sum = 0;

    for(int i=1; i<=k; i++) {
        while(1) {
            if(index>n) {
                break;
            }
            if(bag[i]<jewel[index].first) {
                break;
            }
            pq.push(jewel[index].second);
            ++index;
        }
        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout<<sum;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
