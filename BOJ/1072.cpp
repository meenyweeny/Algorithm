//
// Created by 이경민 on 2023/01/11.
//
#include<iostream>
using namespace std;

unsigned long long x,y;
int z;
int answer;

int get_point(long long x,long long y) {
    return ((y*100)/x);
}
void input() {
    cin>>x>>y;
}

void solution() {
    z = get_point(x,y);

    if(z>=99) {
        cout<<-1;
        return;
    }

    int start = 0;
    int end = 1000000000;

    while(start<=end) {
        int mid = (start + end) / 2;
        int point = get_point(x + mid,y + mid);
        if(point <= z) {
            answer = start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
