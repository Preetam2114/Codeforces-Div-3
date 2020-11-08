/////////////////////// SET-UP ///////////////////////
#include<bits/stdc++.h>
#include <chrono> 
#include <unistd.h> 
#include <sys/resource.h>
#include <errno.h>
#include <unistd.h>

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
const ll mod = 1e9;
auto start = high_resolution_clock::now();  
///////////////////// CODE HERE ///////////////////////


//////////////////// ONLINE_JUDGE ////////////////////
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    struct rusage r_usage;
    int ret = getrusage(RUSAGE_SELF,&r_usage);
///////////////////// CODE HERE ///////////////////////
	int a, n, m;
	cin >> a >> n >> m;
	vector<int> rain(a + 1);
	vector<pair<int, int>> umb(a + 1, make_pair(mod, -1));
	vector<int> costs(m);
	
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		for (int j = l; j < r; ++j)
			rain[j] = 1;
	}
	
	for (int i = 0; i < m; ++i) {
		int x, p;
		cin >> x >> p;
		costs[i] = p;
		umb[x] = min(umb[x], make_pair(p, i));
	}
	
	vector<vector<int>> dp(a + 1, vector<int>(m + 1, mod));
	dp[0][m] = 0;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (dp[i][j] == mod)
				continue;
			if (rain[i] == 0)
				dp[i + 1][m] = min(dp[i + 1][m], dp[i][j]);
			if (j < m)
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + costs[j]);
			if (umb[i].first != mod)
				dp[i + 1][umb[i].second] = min(dp[i + 1][umb[i].second], dp[i][j] + umb[i].first);
		}
	}
	
	int ans = mod;
	for (int i = 0; i <= m; ++i)
		ans = min(ans, dp[a][i]);
	if (ans == mod)
		ans = -1;
	cout << ans << endl;
//////////////////// System log //////////////////////
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"----------------------------------------"<<endl;
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(4);
    cout << "Execution Time :  "<<float(duration.count()/1000000)
            << " (seconds)" << endl;
    cout<< "Process id     :  " 
             << getpid() << endl;
    cout<< "Memory usage   :  "<<r_usage.ru_maxrss<<endl;
    cout<<"----------------------------------------"<<endl;
//////////////////////////////////////////////////////
    return 0; 
} 
