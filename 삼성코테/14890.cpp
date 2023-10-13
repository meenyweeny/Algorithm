#include<iostream>
#include<cmath>
using namespace std;

const int sz = 1e2;
int n,l,answer;
int map[sz][sz];
bool visited[sz];

void input() {
    cin>>n>>l;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
        }
    }
}

void judge_row() {
    for(int row=0; row<n; row++) { //한줄씩 반복

        bool flag = true; //가능한 줄인지 표시
        fill(visited,visited+sz,false);
        for(int i=1; i<n; i++) {
            int now = map[row][i];
            int before = map[row][i-1];
            if(before==now) { //둘이 같으면
                continue;
            }
            if(abs(before-now)>1) { //둘의 높이차이가 2이상이면 불가능
                flag = false;
                break;
            }
            if(before>now) { //앞이 더 높다 -> 나부터 뒤로 l칸 쌓기
                //나부터 map 끝까지 l칸 없으면 안된다
                if(i+l-1>=n) {
                    flag = false;
                    break;
                }
                //l칸 있으면 l칸이 다 같은 블록이어야 한다
                for(int j=1; j<l; j++) {
                    if(now!=map[row][i+j]) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) {
                    break;
                }
                //l칸을 visited로 만든다
                for(int j=0; j<l; j++) {
                    visited[i+j] = true;
                }

                //index를 넘긴다
                i += l;
                --i;
            } else { //뒤가 더 높다 -> 나부터 앞으로 l칸 쌓기
                //나의 앞에 l칸이 없으면 안된다
                if(i-l<0) {
                    flag = false;
                    break;
                }
                //l칸 있는데 이미 블록이 있다 - 안돼
                for(int j=1; j<=l; j++) {
                    if(visited[i-j]) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) {
                    break;
                }
                //l칸의 높이가 다르다 - 안돼
                for(int j=1; j<=l; j++) {
                    if(map[row][i-j]!=before) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) {
                    break;
                }
                //l칸 visited로 만들어준다
                for(int j=1; j<=l; j++ ){
                    visited[i-j] = true;
                }
            }
        }

        answer += flag;
    }
}

void judge_col() {
    for(int col=0; col<n; col++) {
        fill(visited,visited+sz,false);
        bool flag = true;
        for(int i=1; i<n; i++) {
            int before = map[i-1][col];
            int now = map[i][col];

            if(before==now) {
                continue;
            }
            if(abs(before-now)>1) {
                flag = false;
                break;
            }
            if(before>now) {
                if(i+l-1>=n) {
                    flag = false;
                    break;
                }
                //l칸 있으면 l칸이 다 같은 블록이어야 한다
                for(int j=1; j<l; j++) {
                    if(now!=map[i+j][col]) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) {
                    break;
                }
                //l칸을 visited로 만든다
                for(int j=0; j<l; j++) {
                    visited[i+j] = true;
                }
                //index를 넘긴다
                i += l;
                --i;
            } else { //뒤가 더 높아 -> 앞에 쌓기
                //나의 앞에 l칸이 없으면 안된다
                if(i-l<0) {
                    flag = false;
                    break;
                }
                //l칸 있는데 이미 블록이 있다 - 안돼
                for(int j=1; j<=l; j++) {
                    if(visited[i-j]) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) {
                    break;
                }
                //l칸의 높이가 다르다 - 안돼
                for(int j=1; j<=l; j++) {
                    if(map[i-j][col]!=before) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) {
                    break;
                }
                //l칸 visited로 만들어준다
                for(int j=1; j<=l; j++ ){
                    visited[i-j] = true;
                }
            }
        }

        answer+=flag;
    }
}

void solution() {
    judge_row();
    judge_col();
}

void solve() {
    input();
    solution();
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
