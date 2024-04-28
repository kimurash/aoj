// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAXNODE 100'009

using namespace std;

typedef string str;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;


vi32 G[MAXNODE];

i32 total_label;
i32 label[MAXNODE];

void dfs(int32_t now);

int main(){
    i32 N, M;
    cin >> N >> M;

    i32 s, t;
    rep(m, 1, M){
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    total_label = 0;
    rep(n, 1, N){
        if(!label[n]){
            total_label++;
            dfs(n);
        }
    }

    i32 Q;
    cin >> Q;

    rep(q, 1, Q){
        cin >> s >> t;
        cout << (label[s] == label[t] ? "yes" : "no") << endl;
    }

    return(0);
}

void dfs(int32_t now){
    if(label[now]){
        return;
    }
    label[now] = total_label;

    for(int32_t adj: G[now]){
        if(!label[adj]){
            dfs(adj);
        }
    }

    return;
}
