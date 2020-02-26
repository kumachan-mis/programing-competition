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

template<typename T>
inline std::vector<T> cin_vector(const size_t n) {
     std::vector<T> vec;
    vec.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        T element; std::cin >> element;
        vec.push_back(element);
    }
    return vec;
}

ll solve(const vector<ll>& v, ll first, ll last) {
    ll n = SZ(v);
    if (n <= 2) return 0;
    ll d = (v[n-1] + last) - (v[0] + first);
    if (d % (n-1) != 0) return -1;
    d /= n-1;

    vector<ll> diff(n, 0);
    diff[0] = first;
    diff[n-1] = last;

    for (ll i = 1; i < n-1; ++i) {
        if (v[i] - (v[i-1] + diff[i-1]) == d) {
            diff[i] = 0;
        } else if (v[i] + 1 - (v[i-1] + diff[i-1]) == d) {
            diff[i] = 1;
        } else if (v[i] - 1 - (v[i-1] + diff[i-1]) == d) {
            diff[i] = -1;
        } else {
            return -1;
        }
    }
    if ((v[n-1] + diff[n-1]) - (v[n-2] + diff[n-2]) != d) return -1;

    int ret = 0;
    REP(i, n) {
        if (diff[i] != 0) ret++;
    }
    return ret;
}

int main() {
    ll n; cin >> n;
    vll v = cin_vector<ll>(n);
    ll ans = -1;
    for (ll first = -1; first <= 1; first++) {
        for (ll last = -1; last <= 1; last++) {
            ll ret = solve(v, first, last);
            if (ret != -1 && (ans == -1 || ans > ret)) ans = ret;
        }
    }

    cout << ans << endl;
    return 0;
}
