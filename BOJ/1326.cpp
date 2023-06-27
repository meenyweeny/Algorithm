#include<iostream>
#include<queue>
using namespace std;

int n,a,b;
int arr[10002];
bool visited[10002];

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
    }
    cin>>a>>b;
}

void process() {
    queue<pair<int,int>> q;
    q.push({a,0});
    visited[a] = true;

    while(!q.empty()) {
        int front = q.front().first;
        int count = q.front().second;
        q.pop();

        if(front==b) {
            cout<<count;
            return;
        }

        for(int i=1; i<=10000; i++) {
            int nf = front + arr[front] * i;
            if(nf>n) {
                break;
            }
            if(visited[nf]) {
                continue;
            }
            q.push({nf,count+1});
            visited[nf] = true;
        }

        for(int i=1; i<=10000; i++) {
            int nb = front - arr[front] * i;
            if(nb<1) {
                break;
            }
            if(visited[nb]) {
                continue;
            }
            q.push({nb, count + 1});
            visited[nb] = true;
        }
    }

    cout<<-1;
}

void solve() {
    input();
    process();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
