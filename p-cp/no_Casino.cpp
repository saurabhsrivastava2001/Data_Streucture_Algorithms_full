#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define vi vector<int>
#define pii pair<int,int>

#define rep(i,a,b) for(int i=a;i<b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)

#define debug(x) cerr << #x << " = " << x << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int randInt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// const int MOD = 1e9+7;
// int modAdd(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
// int modMul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }

void solve() {
    // write your solution here
    int n;
}

int32_t main() {
    fastIO();
     cin >> t;
    while(t--) solve();
    return 0;
}