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

int solve() {
    // write your solution here
    
    int x;
    cin>>x;
    string s=to_string(x);
    int min=INT32_MAX;
    for (auto c : s) {
        if (c == '0') continue; // Skip '0' characters
        int digit = c - '0'; // Convert character to integer
        if (digit < min) {
            min = digit; // Update minimum digit found
        }
    }
  
    cout<<min<<endl; // Output the minimum digit found
    return min;
}

int32_t main() {
    fastIO();
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}