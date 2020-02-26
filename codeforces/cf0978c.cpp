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

int main() {
    int n, m; cin >> n >> m;
    vll a{0}, b;
    REP(i, n) {
        ll e; cin >> e;
        a.push_back(a[i] + e);
    }
    REP(i, m) {
        ll b; cin >> b;
        auto lb = lower_bound(ALL(a), b);
        cout << (lb - a.begin()) << ' ' << (b - *(lb - 1)) << endl;

    }
    return 0;
}
