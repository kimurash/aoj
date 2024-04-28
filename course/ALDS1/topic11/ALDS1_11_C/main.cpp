// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 109

using namespace std;

typedef string str;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

i32 dist[MAX];
vector<i32> G[MAX];

int main(){
    i32 N;
    cin >> N;

    rep(i, 1, N){
        i32 u, k, v;
        cin >> u >> k;
        rep(j, 1, k){
            cin >> v;
            G[u].push_back(v);
        }
    }

    rep(i, 1, N){
        dist[i] = -1;
    }

    queue<int32_t> yet;
    
    yet.push(1);
    dist[1] = 0;
    
    while(!yet.empty()){
        int32_t now = yet.front();
        yet.pop();
    
        for(int32_t adj: G[now]){
            if(dist[adj] == -1){
                dist[adj] = dist[now] + 1;
                yet.push(adj);
            }
        }
    }

    rep(i, 1, N){
        printf("%d %d\n", i, dist[i]);
    }

    return(0);
}
