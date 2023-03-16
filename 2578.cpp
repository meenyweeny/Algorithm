#include<iostream>
using namespace std;

int map[5][5];

void input() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin>>map[i][j];
        }
    }
}

void checker(int num) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(map[i][j]==num) {
                map[i][j]=0;
            }
        }
    }
}

bool solution(int num) {
    checker(num);
    int sum = 0;
    bool check;
    check = (map[0][0]==0);
    for(int i=1; i<5; i++) {
        check = (map[i][i]==0) && check;
    }
    if(check) ++sum;
    check = map[0][4]==0;
    for(int i=1; i<5; i++) {
        check = (map[i][4-i]==0) && check;
    }
    if(check) ++sum;
    for(int i=0; i<5; i++) {
        check = map[i][0]==0;
        for(int j=1; j<5; j++) {
            check = (map[i][j]==0) && check;
        }
        if(check) ++sum;
    }
    for(int i=0; i<5; i++) {
        check = map[0][i]==0;
        for(int j=1; j<5; j++) {
            check = (map[j][i]==0) && check;
        }
        if(check) ++sum;
    }
    return sum>=3;
}

void solve() {
    input();
    int k;
    bool flag = true;
    for(int i=1; i<=25; i++) {
        cin>>k;
        if(!flag) {
            continue;
        }
        if(solution(k)) {
            cout<<i;
            flag = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
