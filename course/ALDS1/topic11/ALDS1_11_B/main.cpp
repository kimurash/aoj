// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 109

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

i32 cnt;
i32 discov[MAX];
i32 finish[MAX];
vector<i32> G[MAX];

void dfs(i32 now);

int main(){
    int N;
    cin >> N;

    rep(i, 1, N){
        int u, k, v;
        cin >> u >> k;
        rep(j, 1, k){
            cin >> v;
            G[u].push_back(v);
        }
    }

    cnt = 1;
    rep(i, 1, N){
        if(!discov[i]){
            dfs(i);
        }
    }

    rep(i, 1, N){
        printf("%d %d %d\n", i, discov[i], finish[i]);
    }

    return(0);
}


void dfs(int now){
    discov[now] = cnt++;

    for(i32 adj : G[now]){
        if(!discov[adj]){
            dfs(adj);
        }
    }

    finish[now] = cnt++;
    return;
}

