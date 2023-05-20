#include<iostream>
using namespace std;

const int inf = 1000001;
int a[inf];
int n,b,c;
unsigned long long answer;

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    cin>>b>>c;
}

void solution() {
    answer+=n;
    for(int i=0; i<n; i++) {
        a[i]-=b;
        if(a[i]<=0) {
            continue;
        }
        answer+=(a[i]/c);
        answer += (a[i]%c !=0);
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
