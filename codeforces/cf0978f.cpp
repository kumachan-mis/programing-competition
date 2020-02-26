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
    vi original, sorted;
    int n, m; cin >> n >> m;
    vi mentor_ng(n, 0);
    REP(i, n) {
        int e; cin >> e;
        original.push_back(e);
        sorted.push_back(e);
    }
    SORT(sorted);
    REP(i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (original[a] > original[b]) mentor_ng[a]++;
        if (original[a] < original[b]) mentor_ng[b]++;
    }
    REP(i, n) {
        auto itr = lower_bound(ALL(sorted), original[i]);
        cout << (itr - sorted.begin()) - mentor_ng[i] << ' ';
    }
    cout << endl;
    return 0;
}
