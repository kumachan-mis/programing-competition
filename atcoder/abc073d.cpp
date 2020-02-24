#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <cmath>
 
using namespace std;
 
// typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
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
 
//constant
const double    EPS     = 1e-10;
const double    PI      = acos(-1.0);
const int       INFTY   = (1<<21);
const ll        INFTY_LL = (1LL<<60);
 
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

void solve_helper(
    const vector< vector<ll> >& wf,
    vector< pair<int, bool> >& v,
    int current,
    ll score,
    ll& ret
) {
    int cnt = 0;
    REP(i, SZ(v)) {
        if (v[i].second) {
            cnt++;
            continue;
        }
        v[i].second = true;
        int next = v[i].first;
        solve_helper(wf, v,  next, score + wf[current][next], ret);
        v[i].second = false;
    }
    if (cnt == SZ(v) && score < ret) ret = score;
}

ll solve(const vector< vector<ll> >& wf, vector< pair<int, bool> >& v) {
    ll ret = INFTY_LL;
    REP(i, SZ(v)) {
        v[i].second = true;
        solve_helper(wf, v, v[i].first, 0, ret);
        v[i].second = false;
    }
    return ret;
}

int main() {
    int n, m, r; cin >> n >> m >> r;
    vector< pair<int, bool> > v;
    REP(i, r) {
        int e; cin >> e;
        e--;
        v.emplace_back(e, false);
    }
    vector< vector<ll> > wf(n, vector<ll>(n, INFTY_LL));
    REP(i, n) {
        wf[i][i] = 0;
    }
    REP(i, m) {
        int a, b; ll c; cin >> a >> b >> c;
        a--; b--;
        wf[a][b] = c;
        wf[b][a] = c;
    }
    REP(k, n) {
        REP(i, n) {
            REP(j, n) {
                ll x = wf[i][k] + wf[k][j];
                if (wf[i][j] > x) wf[i][j] = x;
            }
        }
    }
    cout << solve(wf, v) << endl;
}
