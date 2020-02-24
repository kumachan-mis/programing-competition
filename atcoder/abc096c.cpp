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

inline bool is_ok(int i, int j, const vector<string>& grid, int h, int w) {
    if (grid[i][j] != '#') return true;
    vector<int> di = {1, 0, -1, 0}, dj = {0, 1, 0, -1};
    bool ret = false;
    REP(t, 4) {
        int i_n = i + di[t], j_n = j + dj[t];
        if (
            0 <= i_n && i_n < h &&
            0 <= j_n && j_n < w &&
            grid[i_n][j_n] == '#'
        ) {
            ret = true;
            break;
        }
    }
    return ret;
}

int main() {
    vector<string> grid;
    int h, w; cin >> h >> w;
    REP(i, h) {
        string s; cin >> s;
        grid.push_back(s);
    }

    bool ans = true;
    REP(i, h) {
        REP(j, w) {
            if (!is_ok(i, j, grid, h, w)) {
                ans = false;
                break;
            }
        }
    }

    TFOUT(ans, "Yes", "No");
}
