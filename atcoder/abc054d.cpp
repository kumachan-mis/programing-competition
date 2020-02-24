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
 
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

int main() {
    const int MAX = 400;
    int dp[MAX + 1][MAX + 1];
    REP(a, MAX + 1) {
        REP(b, MAX + 1) {
            dp[a][b] = -1;
        }
    }
    dp[0][0] = 0;
    int n, m_a, m_b;
    vi v_a, v_b, v_c;
    cin >> n >> m_a >> m_b;
    REP(i, n) {
        int e_a, e_b, e_c; cin >> e_a >> e_b >> e_c;
        v_a.push_back(e_a);
        v_b.push_back(e_b);
        v_c.push_back(e_c);
    }
    REP(k, n) {
        RFOR(a, MAX + 1, 0) {
            RFOR(b, MAX + 1, 0) {
                int c = dp[a][b];
                if (c == -1) continue;
                int a_nxt = a + v_a[k], b_nxt = b + v_b[k];
                if (a_nxt > MAX || b_nxt > MAX) continue;
                int c_nxt = dp[a_nxt][b_nxt];
                if (c_nxt == -1) dp[a_nxt][b_nxt] = c + v_c[k];
                else dp[a_nxt][b_nxt] = min({c_nxt, c + v_c[k]});
            }
        }
    }
    int ans = -1;
    int a = m_a, b = m_b;
    while (a <= MAX && b <= MAX) {
        if (dp[a][b] == -1) {
            a += m_a;
            b += m_b;
            continue;
        }
        if (ans == -1) ans = dp[a][b];
        else ans = min({ans, dp[a][b]});
        a += m_a;
        b += m_b;
    }
    cout << ans << endl;
}

// dp[a][b] = タイプAをちょうどaグラム，タイプBをちょうどbグラム買うのに必要な金額の最小値