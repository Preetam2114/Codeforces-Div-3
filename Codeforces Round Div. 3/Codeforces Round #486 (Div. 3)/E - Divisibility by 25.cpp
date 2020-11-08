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
int a[11];
string s;
int minMov(string x) {
    if (x[0] == '0' && a[0] < 2) {
        return -1;
    }
    if (x[0] != '0') {
        if (!a[x[0] - '0'] || !a[x[1] - '0']) 
            return -1;
    }
    string t = s;
    int r = t.size() - 1;
    while (t[r] != x[1]) {
        r--;
    }

    int cnt = t.size() - r - 1;

    for (int i = r; i < t.size() - 1; i++) 
        swap(t[i], t[i + 1]);
        r = t.size() - 2;
        while (t[r] != x[0]) {
            r--;
    }

    cnt += t.size() - r - 2;
    for (int i = r; i < t.size() - 2; i++) 
        swap(t[i], t[i + 1]);

    int count_0 = 0;
    while (t[count_0] == '0') 
        count_0++;

    if (count_0 + 2 > s.size()) 
        return -1;

    if (count_0) 
        return count_0 + cnt;

    return cnt;
}

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
    ll t=1;
    // cin>>t;
    while(t--){
        cin>>s;
        for (auto it : s){
            a[it - '0']++;
        }
        if ((a[0] > 1) || (a[2] && a[5]) || (a[0] && a[5]) || (a[7] && a[5])) {
            int res = 1e9;
            string s[4] = {"25", "50", "75", "00"};
            for (int i = 0; i < 4; i++) {
                int t = minMov(s[i]);
                if (t != -1) {
                    res = min(res, t);
                }
            }
            cout << res << endl;
        } 
        else cout<<-1<<endl;
    } 
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
