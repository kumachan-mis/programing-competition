#include <bits/stdc++.h>
 
using namespace std;
 
// typedef
typedef long long ll;
typedef long double ldbl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
 
// container util
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
// repetition
#define FOR(i,m,n) for (ll (i) = ((ll) m); (i) < ((ll) n); ++(i))
#define RFOR(i,m,n) for (ll (i) = ((ll) (m)-1); (i) >= ((ll) n); --(i))
#define REP(i,n) FOR(i,0,n)
 
// i/o
#define TFOUT(b,t,f) cout << ((b)? (t) : (f)) << endl
 
// constant
const double PI  = acos(-1.0);
const int    MOD = (int)(1e9 + 7);
// DO NOT set INFTY_XXXs constants. They may bring some BUG! Use MAX_XXXs in climit instead.
 
// clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
// debug
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

int main() {
    int n, m, q; cin >> n >> m >> q;
    vvi dp(n, vi(n, 0));
    REP (i, m) {
        int l, r; cin >> l >> r;
        dp[l-1][r-1]++;
    }
    FOR (d, 1, n) {
        FOR (p, 0, n-d) {
            int q = p + d;
            dp[p][q] += dp[p][q-1] + dp[p+1][q] - (d >= 2? dp[p+1][q-1] : 0);
        }
    }
    REP (i, q) {
        int a, b; cin >> a >> b;
        cout << dp[a-1][b-1] << endl;
    }
    return 0;
}
