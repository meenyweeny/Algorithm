#include<iostream>
using namespace std;

const int sz = 1e6;
int n;
unsigned long long answer;
int member[sz];
int b,c;

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>member[i];
    }
    cin>>b>>c;
}

void solution() {
    for(int i=0; i<n; i++) {
        member[i] -= b;
        ++answer;
        if(member[i]<0) {
            continue;
        }
        answer += (member[i]/c);
        member[i] %= c;
        answer += (member[i]!=0);
    }
    cout<<answer;
}

void solve() {
    input();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
