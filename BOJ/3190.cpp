//
// Created by 이경민 on 2022/08/30.
//
#include<iostream>
#include<deque>
using namespace std;

#define apple 200000
#define snake 200001

#define right 100000
#define down 100001
#define left 100002
#define up 100003

int n,k,l,x;
char c;

int answer,direction;
int map[101][101];
deque<pair<int,int>> bam;
int nx = 1;
int ny = 1;

void convert_direction(char c){ //방향 변경
    if(direction==down) direction = (c=='D') ? left : right;
    else if(direction==up) direction = (c=='L') ? left : right;
    else if(direction==left) direction = (c=='D') ? up : down;
    else direction = (c=='L') ? up : down;
}

void check_end() { //이동을 했는데 벽에 닿아서 게임이 끝났는지 체크
    //끝났으면 출력하고 끝내고, 안끝났으면 무시
    if(map[nx][ny]==snake || nx<=0 || ny<=0 || nx>n || ny>n) {
        cout<<answer;
        exit(0);
    }
}

bool check_apple() { //움직인 머리 자리에 사과가 있었는지 판단함
    bool ret = (map[nx][ny] == apple);
    map[nx][ny]=snake; //사과가 있었든 없었든, 이제 뱀으로 만들어줌
    return ret;
}

void move() { //뱀을 움직이는 함수
    //현재 뱀의 머리의 좌표
    nx = bam.front().first;
    ny = bam.front().second;
    //뱀이 바라보는 방향에 따라서 새로운 머리의 좌푤르 설정
    if(direction == up) --nx;
    else if(direction == down) ++nx;
    else if(direction == left) --ny;
    else ++ny;
    bam.push_front({nx,ny}); //맨 앞에 머리 좌표를 넣어준다
    check_end(); //맨 앞에 넣어준 머리 좌표에 따라, 게임이 끝났는지 안끝났는지 확인 (만약 끝났다면 여기서 함수 종료)
    if(!check_apple()){ //움직인 머리 자리에 사과가 없었으면 꼬리를 한칸 땡겨야 함
        map[bam.back().first][bam.back().second] = 0; //뱀이었던 것을 없애준다
        bam.pop_back(); //덱에서도 꼬리를 빼준다
    }
}

void go() { //진행한 초수(몇초 진행했는지)를 하나씩 늘리면서 뱀을 조건에 맞게 이동시키는 함수
    ++answer;
    move();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    while(k--){
        cin>>l>>x;
        map[l][x] = apple;
    }

    //초기 상태 설정
    map[1][1] = snake;
    bam.push_back({1,1});
    direction = right;

    cin>>l;
    while(l--){
        cin>>x;
        cin>>c;
        while(answer!=x){
            go();
            if(answer==x){
                convert_direction(c);
            }
        }
    }

    while(1){
        go();
    }
}
