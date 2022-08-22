//
// Created by 이경민 on 2022/08/22.
//
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int t,n,m,x,answer;
vector<int> v;
queue<pair<int,int>> q;

void clear() {
    v.clear();
    while(!q.empty()) q.pop();
    answer = 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>t;

    while(t--) {
        cin>>n>>m;
        for(int i=0; i<n; i++) {
            cin>>x;
            v.push_back(x);
            q.push({i,x});
        }
        sort(v.begin(), v.end());
        while(!q.empty()) {
            if (q.front().second == v.back()) {
                ++answer;
                if (q.front().first == m) {
                    cout<<answer<<"\n";
                    break;
                }
                v.pop_back();
                q.pop();
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }
        clear();
    }
}
