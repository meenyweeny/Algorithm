#include<iostream>
#include<vector>
using namespace std;

int r,c,k;
int row,col;
int map[100][100];
int arr[101];

void input() {
    cin>>r>>c>>k;
    --r;
    --c;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cin>>map[i][j];
        }
    }
    row = col = 3;
}

void sort_row() {
    vector<pair<int,int>> v;
    for(int i=0; i<row; i++) {
        fill(arr,arr+101,0);
        v.clear();
        for(int j=0; j<col; j++) {
            ++arr[map[i][j]];
        }
        for(int i=1; i<101; i++) {
            if(arr[i]) {
                v.push_back({arr[i],i});
            }
        }
        sort(v.begin(),v.end());
        int index = 0;
        for(auto p:v) {
            map[i][index++] = p.second;
            map[i][index++] = p.first;
            if(index==100) {
                break;
            }
        }
        for(int j=index; j<row; j++) {
            map[i][j] = 0;
        }
        col = max(col,index);
    }
}

void sort_col() {
    vector<pair<int,int>> v;
    for(int i=0; i<col; i++) {
        fill(arr,arr+101,0);
        v.clear();
        for(int j=0; j<row; j++) {
            ++arr[map[j][i]];
        }
        for(int i=1; i<101; i++) {
            if(arr[i]) {
                v.push_back({arr[i],i});
            }
        }
        sort(v.begin(),v.end());
        int index = 0;
        for(auto p:v) {
            map[index++][i] = p.second;
            map[index++][i] = p.first;
            if(index==100) {
                break;
            }
        }
        for(int j=index; j<col; j++) {
            map[j][i] = 0;
        }
        row = max(row,index);
    }
}

void solution() {
    int time = 0;
    while(time<=100) {
        if(map[r][c]==k) {
            break;
        }
        row >= col ? sort_row() : sort_col();
        ++time;
    }
    cout<<((time>100) ? -1 : time);
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
