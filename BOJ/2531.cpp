#include<iostream>
using namespace std;

int n,d,k,c;
int visited[3001];
int arr[30001];

void input() {
    cin>>n>>d>>k>>c;

    for(int i=1; i<=n; i++) {
        cin>>arr[i];
    }
}

void solution() {
    int s,e;
    int answer = 0;
    int sum;
    for(int i=1; i<=k; i++) {
        if(visited[arr[i]]==0) {
            ++answer;
        }
        ++visited[arr[i]];
    }
    if(visited[c]==0) {
        ++answer;
    }
    sum = answer;
    s = 1;
    e = k;
    while(e!=k-1) {

        if(visited[c]==0) {
            --sum;
        }
        --visited[arr[s]];
        if(visited[arr[s]]==0) {
            --sum;
        }
        ++s;
        ++e;
        if(e>n) {
            e-=n;
        }
        if(visited[arr[e]]==0) {
            ++sum;
        }
        ++visited[arr[e]];
        if(visited[c]==0) {
            ++sum;
        }
        answer = max(sum, answer);
    }
    cout << answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}