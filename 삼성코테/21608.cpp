#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int n;
bool like[401][401];
int map[20][20];
int answer = 0;
vector<int> seat_sequence;

void input() {
    cin>>n;
    int k,s;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>k;
            seat_sequence.push_back(k);
            for(int q=0; q<4; q++) {
                cin>>s;
                like[k][s] = true;
            }
        }
    }
}

bool check_range(int x,int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

void find_seat(int now) {
    int x,y;
    x=-1;
    y=-1;
    int like_max = 0;
    int empty_max = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j]!=0) {
                continue;
            }
            if(x==-1 && y==-1) {
                x=i;
                y=j;
            }
            int like_count = 0;
            int empty_count = 0;
            for(int dir=0; dir<4; dir++) {
                int nx = i + "2011"[dir] - '1';
                int ny = j + "1120"[dir] - '1';
                if(!check_range(nx,ny)) {
                    continue;
                }
                if(map[nx][ny]==0) {
                    ++empty_count;
                } else if(like[now][map[nx][ny]]) {
                    ++like_count;
                }
            }
            if(like_max<like_count) {
                x = i;
                y = j;
                like_max = like_count;
                empty_max = empty_count;
            } else if(like_max==like_count) {
                if(empty_max<empty_count) {
                    empty_max = empty_count;
                    x = i;
                    y = j;
                }
            }
        }
    }
    map[x][y] = now;
}

void solution() {
    for(auto s:seat_sequence) {
        find_seat(s);
    }
}

void get_goodpoint() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int count = 0;
            int student = map[i][j];
            for(int dir=0; dir<4; dir++) {
                int nx = i + "2011"[dir] - '1';
                int ny = j + "1120"[dir] - '1';
                if(!check_range(nx,ny)) {
                    continue;
                }
                if(like[student][map[nx][ny]]) {
                    ++count;
                }
            }
            if(count!=0) {
                --count;
                answer += pow(10,count);
            }
        }
    }
}

void solve() {
    input();
    solution();
    get_goodpoint();
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
    return 0;
}
