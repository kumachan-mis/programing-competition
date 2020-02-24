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
    int n, m; cin >> n >> m;
    map<pair<int, int>, int> edges;
    vector< vector<int> > wf(n, vector<int>(n, INFTY));
    REP(i, n) {
        wf[i][i] = 0;
    }
    REP(i, m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        wf[a][b] = c;
        wf[b][a] = c;
        edges[MP(a, b)] = c;
    }
    REP(k, n) {
        REP(i, n) {
            REP(j, n) {
                if (wf[i][j] > wf[i][k] + wf[k][j]) {
                    wf[i][j] = wf[i][k] + wf[k][j];
                }
            }
        }
    }
    int ans = 0;
    EACH(i, edges) {
        auto p = i->first;
        int c = i->second;
        if (wf[p.first][p.second] < c) ans++;
    }
    cout << ans << endl;
    return 0;
}

// あらゆる2頂点を結ぶ最短距離について考えているから，ワーシャルフロイドが使えそうだ．
// ワーシャルフロイド wf[i][j] = min {c[i][j], wf[i][k] + wf[k][j] (for all k)}
// wf[i][j] を求める過程で c[i][j] > wf[i][k] + wf[k][j]なるkがあるなら．c[i][j]はどの最短経路にも含まれない.
// かってな頂点 a, bをとり，その最短経路において a ->* i ->* j ->* b とする必要があるとすれば，
// i ->1 j よりも i ->{2..} j とした方がコストが必ず小さいからである．

