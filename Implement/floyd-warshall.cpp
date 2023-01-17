//
// Created by 이경민 on 2023/01/17.
//
#include<iostream>
#include<algorithm>
using namespace std;

int dist[101][101];
const int inf = 1e9;

void floyd(int n) {
    //i부터 j까지, 1~k 개의 정점을 이용하여 최단거리를 구한다
    //DP를 사용하는 문제!
    //n번 만큼의 단계를 반복하며 점화식에 맞게 2차원 리스트를 갱신하는 것

    //1.현재 단계를 k번째라고 할 때
    //현재 dist에는 1~k-1번째 정점을 사용해서 나올 수 있는 최단거리가 남아있음
    //1~k의 정점을 이용하여 도달 가능한 최다거리를 구함
    //DP이므로 과거의 값을 이용하여 다음 값을 구하는 방식!

    //2.점화식
    //두 정점 i,j에 대해 k번 정점을 지나가면서 가면 최단거리가 더 짧아지는가?
    //즉 기존 i->j보다 i->k->j가 더 짧은 최단거리를 가지는지 확인

    //3.위의 점화식을 모든 (i,j)에 적용함!
    //조건 => if(dist[i][j] > dist[i][k] + dist[k][j])
    //위 if문으로 판단하면서 기존보다 빨라지면 최단거리 갱신을 한다

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                //최단거리가 더 짧은걸 dist로 갱신
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n=5;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            dist[i][j] = i==j ? 0 : inf;
        }
    }
}
