#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 단절점
// DFS 사용

#define MAX_N 10001
const int NO_VISITED = 0;

vector<vector<int>> adj;

bool isVisited[MAX_N];  // dfs 동작시 정점 방문확인용

int dfsOrder[MAX_N];    // dfs 방문순서 저장
int nowDfsOrder;        // 현재 방문순서값의 기록을 위해 사용하는 변수

bool isCut[MAX_N];      // 단절점 여부 확인 (단절점 : true)

// dfs이기 때문에, 그래프 끝부분(방문순서 끝부분)까지 간 뒤 다시 돌아오면서 연산이 진행되게 된다
// 인접 정점 중 가장 방문순서가 빠른 노드를 찾고
// 그걸 DFS들을 통해 해당 정점으로 접근이 가능한 노드들에 넘겨주는것
int dfs(int nowNode, bool isRoot)
{
    // 방문했으므로 방문순서를 1 늘리고, 현재 정점의 방문순서를 기록함
    nowDfsOrder++;
    dfsOrder[nowNode] = nowDfsOrder;

    // 인접한 정점 중 가장 방문순서가 빠른 노드를 저장
    // low : 현재 정점 이후에 방문하는 정점들 중 
    //       현재 정점을 거치지 않고 방문 가능한 정점들의 order(방문순서) 중 가장 빠른 순서
    // 한마디로 본인이 접근 가능한 가장 빠른 방문 순서를 생각하면 된다
    int nowLow = dfsOrder[nowNode];   

    // 루트 노드에서 계산하기 위해 child(자식 노드) 계산
    int child = 0;

    int len = adj[nowNode].size();
    for (int i = 0; i < len; i++) {
        int nextNode = adj[nowNode][i];

        // 다음에 갈 점이 방문한 적 없는 곳이라면 (방문 순서가 아직 기록되지 않았다면)
        // 그러면 다시 DFS를 돌아, 자식 노드들에 대해 추가적으로 방문을 한다
        if (dfsOrder[nextNode] == NO_VISITED) {
            child++;

            // 인접한 정점들에 대해 접근(DFS)하여, 방문순서를 기록하고 해당 노드의 Low를 가져온다
            // 즉 내 인접한 노드들 중(내가 실제 갈 수 있는 노드) 가장 빠른 방문순서를 가지고온다
            //
            // 전에 방문하였다면 아래 else문으로 빠지면서 
            // DFS 없이 현재의 순서와, 자신의 인접한 노드들 중 가장 작은 방문순서(Low) 두개 중 더 작은거를 반환하게 될것
            int nearLow = dfs(nextNode, false);

            // 처음 방문했다면, 현재 순서 or 자식노드에서 접근가능한 노드 중 방문순서가 가장 빠른 순서 중 더 빠른 쪽으로
            nowLow = min(nowLow, nearLow);

            // 루트가 아니면서 dfs를 돌려 나온 인접한 위치의 가장 작은 방문순서 >= 현재 방문순서 라면 단절점
            // dfs를 자식노드에 대해 돌리고 있는 중!
            // 자식노드에서 접근 가능한 노드가 현재노드의 방문순서보다 빠르다면
            // 현재노드가 없어도, 자식노드는 우회경로를 가지고 있다는 뜻이 된다
            if (isRoot == false && nearLow >= dfsOrder[nowNode])
                isCut[nowNode] = true;
        }
        else {
            // 방문한 점이라면, 현재 순서 or 인접한 노드의 순서중 더 빠른 쪽으로
            // 참고로 현재의 low와, 기존의 방문순서는 별개이다! 방문순서는 dfsOrder[nextNode]에 최초 작성된 이후 변경되지 않음
            // 기존의 방문순서는 그대로 유지되고 low를 통해서만 계산한다
            nowLow = min(nowLow, dfsOrder[nextNode]);
        }
    }

    // 루트에서 자식이 2이상 -> 단절점
    if (isRoot == true && child >= 2)
        isCut[nowNode] = true;

    return nowLow;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    adj.resize(V + 1);

    // 간선 정보 저장
    // 무향 그래프이므로 양쪽으로 저장 필요
    for (int i = 0; i < E; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    // 전체 정점에 대해 DFS를 돌리기 위해 순회한다
    // 현재 정점에 한번도 접근한적 없다면
    // 해당 점을 시작점(root)로 잡고 DFS를 돌린다
    // 이렇게 하는 이유는 그래프가 분리되어있을수 있기때문 
    // ("입력으로 주어지는 그래프는 연결 그래프가 아닐 수도 있다" 부분!)
    for (int i = 1; i <= V; i++)
    {
        if (dfsOrder[i] == NO_VISITED)
            dfs(i, true);
    }

    // 단절점 출력
    vector<int> vecAns;
    int cutCount = 0;
    for (int i = 1; i <= V; i++)
    {
        if (isCut[i] == true)
        {
            vecAns.push_back(i);
            cutCount++;
        }
    }

    printf("%d\n", cutCount);

    for (int i = 0; i < vecAns.size(); i++)
        printf("%d ", vecAns[i]);
}
