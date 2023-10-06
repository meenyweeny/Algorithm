#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct SeatInfo {
    int x,y,like,empty;
};

int n,s;
int map[20][20];
bool like_info[401][401];

bool comp(SeatInfo a, SeatInfo b) {
    if(a.like == b.like) {
        if(a.empty == b.empty) {
            return a.x == b.x ? a.y < b.y : a.x < b.x;
        } else {
            return a.empty > b.empty;
        }
    } else {
        return a.like > b.like;
    }
}

bool check_range(int x,int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

int get_satisfied_point() {
    int ret = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int up = 0;
            int now_student = map[i][j];
            for(int k=0; k<4; k++) {
                int nx = i + "2011"[k] - '1';
                int ny = j + "1120"[k] - '1';
                if(!check_range(nx,ny)) {
                    continue;
                }
                if(like_info[now_student][map[nx][ny]]) {
                    ++up;
                }
            }
            if(up!=0) {
                --up;
                ret += pow(10,up);
            }
        }
    }
    return ret;
}

void make_seat() {
    vector<SeatInfo> seats;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j]) {
                continue;
            }
            int empty = 0;
            int likes = 0;
            for(int k=0; k<4; k++) {
                int nx = i + "2011"[k] - '1';
                int ny = j + "1120"[k] - '1';
                if(!check_range(nx,ny)) {
                    continue;
                }
                if(map[nx][ny]==0) {
                    ++empty;
                } else {
                    likes += like_info[s][map[nx][ny]];
                }
            }
            seats.push_back({i,j,likes,empty});
        }
    }
    sort(seats.begin(), seats.end(), comp);
    SeatInfo next = seats[0];
    map[next.x][next.y] = s;
}

void solve() {
    cin>>n;
    int a;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>s;
            for(int k=0; k<4; k++) {
                cin>>a;
                like_info[s][a] = true;
            }
            make_seat();
        }
    }
    cout<<get_satisfied_point();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
