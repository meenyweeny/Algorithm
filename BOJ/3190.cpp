#include<iostream>
#include<vector>
#include<deque>
using namespace std;

const char apple = 'a';
const char snake = 's';
int n,direction,answer;
char map[102][102];
deque<pair<int,int>> snake_point;
vector<pair<int,char>> info;

bool is_in_range(int x,int y) {
    return x>0 && x<=n && y>0 && y<=n;
}

void input() {
    cin>>n;
    int k,a,b;
    char c;
    cin>>k;
    while(k--) {
        cin>>a>>b;
        map[a][b] = apple;
    }
    cin>>k;
    while(k--) {
        cin>>a>>c;
        info.push_back({a,c});
    }
}

void convert_direction(char dir) {
    if(dir=='L') {
        --direction;
        if(direction<0) {
            direction = 3;
        }
    } else {
        ++direction;
        if(direction>3) {
            direction = 0;
        }
    }
}

void move_snake(int nx,int ny) {
    if(map[nx][ny]!=apple) {
        map[snake_point.back().first][snake_point.back().second] = '0';
        snake_point.pop_back();
    }
    snake_point.push_front({nx,ny});
    map[nx][ny]=snake;
}

void solution() {
    reverse(info.begin(), info.end());
    map[1][1] = snake;
    snake_point.push_back({1,1});
    int nx,ny;
    nx=ny=1;
    while(1) {
        ++answer;
        nx += "1210"[direction] - '1';
        ny += "2101"[direction] - '1';
        if(!is_in_range(nx,ny) || map[nx][ny]==snake) {
            break;
        }
        move_snake(nx,ny);
        if(!info.empty() && info.back().first==answer) {
            convert_direction(info.back().second);
            info.pop_back();
        }
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
