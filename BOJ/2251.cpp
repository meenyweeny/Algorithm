#include<iostream>
#include<vector>
using namespace std;

int a,b,c;
vector<int> answer;
bool visited[201][201][201];

void input() {
    cin>>a>>b>>c;
}

void process(int x,int y,int z) {
    visited[x][y][z] = true;
    if(x==0) {
        answer.push_back(z);
    }
    int xmax = a-x;
    int ymax = b-y;
    int zmax = c-z;
    if(x!=0) {
        if(x>ymax) {
            int tmp = x-ymax;
            if(!visited[tmp][b][z]) {
                process(tmp,b,z);
            }
        } else {
            if(!visited[0][y+x][z]) {
                process(0,y+x,z);
            }
        }
        if(x>zmax) {
            int tmp = x-zmax;
            if(!visited[tmp][y][c]) {
                process(tmp,y,c);
            }
        } else {
            if(!visited[0][y][z+x]) {
                process(0,y,z+x);
            }
        }
    }
    if(y!=0) {
        if(y>xmax) {
            int tmp = y-xmax;
            if(!visited[a][tmp][z]) {
                process(a,tmp,z);
            }
        } else {
            if(!visited[x+y][0][z]) {
                process(x+y,0,z);
            }
        }
        if(y>zmax) {
            int tmp = x-zmax;
            if(!visited[x][tmp][c]) {
                process(x,tmp,c);
            }
        } else {
            if(!visited[x][0][z+y]) {
                process(x,0,z+y);
            }
        }
    }
    if(z!=0) {
        if(z>xmax) {
            int tmp = z-xmax;
            if(!visited[a][y][tmp]) {
                process(a,y,tmp);
            }
        } else {
            if(!visited[x+z][y][0]) {
                process(x+z,y,0);
            }
        }
        if(z>ymax) {
            int tmp = z-ymax;
            if(!visited[x][b][tmp]) {
                process(x,b,tmp);
            }
        } else {
            if(!visited[x][y+z][0]) {
                process(x,y+z,0);
            }
        }
    }
}

void solution() {
    process(0,0,c);

    sort(answer.begin(), answer.end());
    for(auto a:answer) {
        cout<<a<<' ';
    }
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
