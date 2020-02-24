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

void calc(vector< pair<ll,ll> >& a, vector< pair<ll,ll> >& b) {
    ll a_i = 0, b_i = 0, cnt = 0;
    while(b_i < b.size()) {
        if (a_i != a.size() && a[a_i].first < b[b_i].first) {
            cnt += a[a_i].second;
            a_i++;
        } else {
            b[b_i].second = cnt;
            b_i++;
        }
    }
}

int main() {
    int n;
    vector< pair<ll,ll> > a, b, c;
    cin >> n;
    REP(i, n) {
        ll e;
        cin >> e;
        a.emplace_back(e, 1);
    }
    SORT(a);
    REP(i, n) {
        ll e;
        cin >> e;
        b.emplace_back(e, 0);
    }
    SORT(b);
    REP(i, n) {
        ll e;
        cin >> e;
        c.emplace_back(e, 0);
    }
    SORT(c);
    calc(a, b);
    calc(b, c);
    ll res = 0;
    EACH(i, c) res += i->second;
    cout << res << endl;
    return 0;
}