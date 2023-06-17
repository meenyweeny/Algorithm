#include<iostream>
using namespace std;

int n;
int answer;

void process(int count, int arr[16], bool visited[16]) {
    if(count>n) {
        ++answer;
        return;
    }

    for(int i=1; i<=n; i++) {
        if(visited[i]) {
            continue;
        }
        bool flag = true;
        for(int j=1; j<count; j++) {
            int bx,by;
            bx = j; by = arr[j];
            int nx,ny;
            nx = count; ny = i;
            if(abs(nx-bx)==abs(ny-by)) {
                flag = false;
                break;
            }
        }
        if(!flag) {
            continue;
        }
        visited[i] = true;
        arr[count] = i;
        process(count+1,arr,visited);
        visited[i] = false;
        arr[count] = 0;
    }
}

void solve() {
    cin>>n;
    bool visit[16] = {false,};
    int arr[16] = {false,};
    process(1,arr,visit);
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
