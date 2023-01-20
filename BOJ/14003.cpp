#include<iostream>
#include<vector>
using namespace std;

int n;
int arr[1000001];
int idx[1000001];
vector<int> lis;

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
    }
}

void solution() {
    lis.push_back(-2000000000);
    lis.push_back(arr[1]);
    idx[1] = 1;

    for(int i=2; i<=n; i++) {
        if(arr[i] > lis.back()) {
            lis.push_back(arr[i]);
            idx[i] = lis.size() - 1;
        } else {
            int backidx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            idx[i] = backidx;
            lis[backidx] = arr[i];
        }
    }

    cout<<lis.size() - 1<<'\n';

    vector<int> path;

    int len = lis.size() - 1;
    for(int i=n; i>0; i--) {
        if(idx[i]==len) {
            path.push_back(arr[i]);
            --len;
        }
    }

    reverse(path.begin(), path.end());
    for(int i=0; i<path.size(); i++) {
        cout<<path[i]<<' ';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
