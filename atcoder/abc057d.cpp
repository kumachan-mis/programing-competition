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

ll c[51][51];

void init() {
    REP(i, 51) {
        REP(j, 51) {
            c[i][j] = -1;
        }
    }
}

ll combi(ll n, ll r) {
    if (c[n][r] != -1) return c[n][r];
    if (r == 0 || r == n) return c[n][r] = 1;
    else return c[n][r] = combi(n-1, r) + combi(n-1, r-1);
}

int main() {
    init();
    ll n, a, b; cin >> n >> a >> b;
    vll v;
    REP(i, n) {
        ll e; cin >> e;
        v.push_back(e);
    }
    SORT(v);

    bool is_same = true;
    ll e = v[n-1];
    RFOR(i, n, n-a) {
        if (e != v[i]) {
            is_same = false;
            break;
        }
    }

    if (is_same) {
        e = v[n-1];
        ll border = n - 1;
        while (true) {
            if (border < 0 || e != v[border]) break;
            border--;
        }
        border = n - 1 - border;
        ll m = min({b, border});
        ll ans = 0;
        FOR(i, a, m + 1) {
            ans += combi(border, i);
        }
        cout << e << endl;
        cout << ans << endl;
    } else {
        e = v[n-a];
        ll l = n-a, r = n-a; 
        while(true) {
            if (l < 0 || v[l] != e) break;
            l--;
        }
        l++;
        while(true) {
            if (r >= n || v[r] != e) break;
            r++;
        }

        ll ans = combi(r - l, r - (n - a));
        long double e_d = 0.0;
        FOR(i, n - a, n) {
            e_d += v[i];
        }
        e_d /= a;
        cout.precision(20);
        cout << fixed << e_d << endl;
        cout << ans << endl;
    }
    return 0;
}