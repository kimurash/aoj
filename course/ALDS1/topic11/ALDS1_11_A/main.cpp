// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    i16 N;
    cin >> N;

    bool adj_mat[N + 1][N + 1];
    rep(i, 1, N){
        rep(j, 1, N){
            adj_mat[i][j] = false;
        }
    }

    rep(i, 1, N){
        i32 u, k, v;
        cin >> u >> k;
        rep(j, 1, k){
            cin >> v;
            adj_mat[i][v] = true;
        }
    }

    rep(i, 1, N){
        rep(j, 1, N){
            if(j != 1){
                cout << " ";
            }
            cout << adj_mat[i][j];
        }
        cout << endl;
    }

    return(0);
}
