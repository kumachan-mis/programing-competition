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

int main() {
    int n, k; cin >> n >> k;
    vll v = cin_vector<ll>(n);
    SORT(v);
    if (k == n) {
        cout << v[k-1] << endl;
    } else if (k == 0) {
        if (v[0] <= 1) {
            cout << -1 << endl;
        } else {
            cout << (v[0] -  1) << endl;
        }
    } else if (v[k-1] != v[k]) {
        cout << v[k-1] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
