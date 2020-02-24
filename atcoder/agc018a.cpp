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

ll gcd(ll a, ll b) {
    if (a < b) {
        ll temp = a;
        a = b;
        b = temp;
    }

    while(a % b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return b;
}

bool solve(const vll& a, ll g, ll k) {
    if (g > k || k % g != 0) return false;
    k /= g;
    return *max_element(ALL(a)) >= k;

}

int main() {
    ll n, k; cin >> n >> k;
    vll a;
    REP(i, n) {
        ll e; cin >> e;
        a.push_back(e);
    }
    ll g = a[0];
    FOR(i, 1, n) {
        g = gcd(a[i], g);
    }
    REP(i, n) a[i] /= g;
    cout << (solve(a, g, k)? "POSSIBLE" : "IMPOSSIBLE") << endl;
}