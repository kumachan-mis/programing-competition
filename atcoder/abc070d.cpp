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
    int n; cin >> n;
    unordered_map<int, vector< pair<int, ll> > > edges;
    REP(i, n-1) {
        int a, b; ll c; cin >> a >> b >> c;
        a--; b--;
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
    }
    int q, k; cin >> q >> k;
    k--;
    vector<ll> costs(n, -1); costs[k] = 0;
    unordered_set<int> open_set{k};
    while (!open_set.empty()) {
        unordered_set<int> new_open_set;
        for (const int node : open_set) {
            for (const pair<int, ll> neighborhood : edges[node]) {
                if (costs[neighborhood.first] != -1) continue;
                new_open_set.insert(neighborhood.first);
                costs[neighborhood.first] = neighborhood.second + costs[node];
            }
        }
        open_set = new_open_set;
    }
    REP(i, q) {
        ll x, y; cin >> x >> y;
        x--; y--;
        cout << (costs[x] + costs[y]) << endl;
    }
}
