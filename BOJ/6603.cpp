//
// Created by 이경민 on 2023/02/02.
//
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int k;
bool visited[50];
vector<int> vec;

void lotto(int count, int idx, bool visit[]) {
    if(count == 6) {
        for(int i=1; i<50; i++) {
            if(visit[i]) {
                cout<<i<<' ';
            }
        }
        cout<<'\n';
        return;
    }
    if(idx>=k) {
        return;
    }
    for(int i=idx; i<k; i++) {
        if(!visit[vec[i]]) {
            visit[vec[i]] = true;
            lotto(count+1, i+1, visit);
            visit[vec[i]] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x;

    while(1) {
        cin>>k;
        if(k==0) {
            break;
        }

        vec.clear();
        memset(visited,false,sizeof(visited));

        for(int j=0; j<k; j++) {
            cin>>x;
            vec.push_back(x);
        }

        lotto(0, 0,visited);
        cout<<'\n';
    }

}
