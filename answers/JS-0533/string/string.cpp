//give me two bottle of water and a hard question
#include<iostream>
#include<fstream>
#include<cstring>
#define F(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,r,l) for(int i = r; i >= l; --i)
#define LL long long
using namespace std;
const int N = 1e5 + 10;
int T;
string s;
int pre[N],suf[N],len;
LL ans = 0;
void setup_ps() {
	bool bottle[26];
	len = s.size() - 1;
	memset(bottle,0,sizeof(bottle));
	F(i,1,len) {
		int now = (int)(s[i] - 'a');
		bottle[now] = !bottle[now];
		pre[i] = pre[i - 1];
		if(bottle[now]) pre[i] ++;
		else pre[i] --;
	}
	memset(bottle,0,sizeof(bottle));
	REP(i,len,1) {
		int now = (int)(s[i] - 'a');
		bottle[now] = !bottle[now];
		suf[i] = suf[i + 1];
		if(bottle[now]) suf[i] ++;
		else suf[i] --;
	}
	return;
}
bool com(int a,int b,int len) {
	return s.substr(a,len) == s.substr(b,len);
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	F(t,1,T) {
		ans = 0;
		cin >> s;
		s = " " + s;
		setup_ps();
		F(a,1,len) {
			int fa = pre[a];
			F(b,a + 1,len - 1) {
				for(int c = b + 1; c <= len; c += b) {
					int fc = suf[c];
					if(com(1,c - b,b) == 0) {
						break;
					}
					if(fa > fc) continue;
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//all goes well
//$hanker_007$