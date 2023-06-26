#include<iostream>
using namespace std;

struct Info {
    int team_num;
    int team_score;
    int last_submit;
    int submit_count;
    int score[101];
};

int k,n,t,m;
Info team[101];

bool comp(Info a, Info b) {
    if(a.team_score==b.team_score) {
        if(a.submit_count==b.submit_count) {
            return a.last_submit < b.last_submit;
        } else {
            return a.submit_count < b.submit_count;
        }
    } else {
        return a.team_score > b.team_score;
    }
}

void init() {
    Info tmp = {0,0,0};
    fill(tmp.score,tmp.score+101,0);
    fill(team,team+101,tmp);
    for(int i=1; i<=100; i++) {
        team[i].team_num = i;
    }
}

void input() {
    int i,j,s;
    int gap;
    for(int k=1; k<=m; k++) {
        cin>>i>>j>>s;
        ++team[i].submit_count;
        team[i].last_submit = k;
        gap = s - team[i].score[j];
        if(gap>0) {
            team[i].team_score += gap;
            team[i].score[j] = s;
        }
    }
}

void solution() {
    sort(team+1,team+n+1,comp);
    for(int i=1; i<=n; i++) {
        if(team[i].team_num==t) {
            cout<<i<<'\n';
            break;
        }
    }
}

void solve() {
    int tc;
    cin>>tc;
    while(tc--) {
        init();
        cin>>n>>k>>t>>m;
        input();
        solution();
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
