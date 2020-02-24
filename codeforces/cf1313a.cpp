#include <bits/stdc++.h>
 
using namespace std;
 
// typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
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
 
// clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
// debug
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

void solve() {
    int a, b, c; cin >> a >> b >> c;
    vector<int> v({a, b, c});
    SORT(v); a = v[2], b = v[1], c = v[0];
    vector<int> serves({1, 2, 4, 3, 5, 6, 7});
    int ans = 0;
    for(const int s : serves) {
        if (
            ((s & 1) != 0 && a == 0) ||
            ((s & 2) != 0 && b == 0) ||
            ((s & 4) != 0 && c == 0)
        )
        continue;
        ans++;
        if ((s & 1) != 0) a--;
        if ((s & 2) != 0) b--;
        if ((s & 4) != 0) c--;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    REP(i, t) solve();
    return 0;
}
