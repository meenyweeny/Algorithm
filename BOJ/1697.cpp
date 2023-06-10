#include<iostream>
#include<queue>
using namespace std;

const int max_point = 100000;
int n,k;
int visited[max_point+1];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    queue<int> q;
    q.push(n);

    int cnt;
    while(!q.empty()) {
        int now = q.front();
        cnt = visited[now];
        q.pop();

        if(now == k) {
            cout << cnt;
            break;
        }

        ++cnt;
        if(now - 1 >= 0 && now - 1 <= max_point) {
            if(visited[now - 1] == 0) {
                q.push(now - 1);
                visited[now - 1]=cnt;
            }
        }
        if(now + 1 <= max_point) {
            if(visited[now + 1] == 0) {
                q.push(now + 1);
                visited[now + 1]=cnt;
            }
        }
        if(now * 2 <= max_point) {
            if(visited[now * 2] == 0) {
                q.push(now * 2);
                visited[now * 2]=cnt;
            }
        }
    }
}
