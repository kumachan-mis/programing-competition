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
 
//constant
const double    EPS        = 1e-10;
const double    PI         = acos(-1.0);
const int       INFTY_INT  = (1<<21);
const ll        INFTY_LL   = (1LL<<60);
 
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

int main() {
    int n, c; cin >> n >> c;
    vvi d;
    REP(i, c) {
        vi v;
        REP(j, c) {
            int e; cin >> e;
            v.push_back(e);
        }
        d.push_back(v);
    }
    vvi grids;
    REP(i, n) {
        vi v;
        REP(j, n) {
            int e; cin >> e;
            e--;
            v.push_back(e);
        }
        grids.push_back(v);
    }
    vvi counts(3, vi(c));
    REP(i, n) {
        REP(j, n) {
            counts[(i+j)%3][grids[i][j]]++;
        }
    }
    vvi d_sums(3, vi(c));
    REP(t, 3) {
        REP(x, c) {
            REP(y, c) {
                d_sums[t][y] += counts[t][x]*d[x][y];
            }
        }
    }

    int ans = -1;
    REP(c0, c) {
        REP(c1, c) {
            if (c0 == c1) continue;
            REP(c2, c) {
                if (c1 == c2 || c2 == c0) continue;
                int candidate = d_sums[0][c0] + d_sums[1][c1] + d_sums[2][c2];
                if (ans == -1 || ans > candidate) ans = candidate;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
