#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int inf = 500000 + 1;
int n,k,answer;
int location[inf][2];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(location,-1,sizeof(location));
    answer=-1;
    cin>>n>>k;
    queue<pair<int,int>> q;
    q.push({n,0});

    while(!q.empty()) {
        int front = q.front().first;
        int count = q.front().second;
        q.pop();

        if(front<0 || front>=inf) {
            continue;
        }
        if(location[front][count%2]!=-1) {
            continue;
        }
        location[front][count%2]=count;

        ++count;
        q.push({front-1,count});
        q.push({front+1,count});
        q.push({front*2,count});
    }

    int next = k;
    for(int i=0; i<inf; i++) {
        next += i;
        if(next>=inf) {
            break;
        }
        if(location[next][i%2]!=-1 && location[next][i%2]<=i) {
            answer=i;
            break;
        }
    }
    cout<<answer;
}
