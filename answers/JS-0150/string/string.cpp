#include <bits/stdc++.h>
#define rept(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,a) rept(i,0,a)
#define re return
#define sz(a) ((int)a.size())
#define fill(a,t) memset(a,t,sizeof a)
#define all(a) a.begin(),a.end()
#define erase_end(a) if(sz(a))a.erase(a.end()-1)
#define erase_str(a) if(sz(a))a.erase(a.begin())
#define pb push_back


using namespace std;
int read(){
	int f=1,cur=0;
	char ch=cin.get();
	while ((ch<'0' || ch>'9') && ch!='-')  ch=cin.get();
	if (ch=='-') f=-1;
	else cur=ch-'0';
	ch=cin.get();
	while (ch>='0' && ch<='9')  cur=10*cur+ch-'0',ch=cin.get();
	re f*cur;
}

int lf[2000000],rt[2000000];

void calc_first(string s){
	int n=sz(s);
	int t1[30]={},n1=0;
	rep(i,n){
		int l=(t1[s[i]-'a']^=1);
		n1+=(l)?1:-1;
		lf[i]=n1;
	}
	int t2[30]={},n2=0;
	for (int i=n-1;i>=0;i--){
		int l=(t2[s[i]-'a']^=1);
		n2+=(l)?1:-1;
		rt[i]=n2;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		string s;
		cin>>s;
		calc_first(s);
		int n=sz(s),ans=0;cout<<n<<'\n';
		rep(j,n){
			int fl=1;
			rept(k,1,n/(j+1)+1) {
				if (k-1) rep(l,j+1){
					if (s[k*(j+1)+l]!=s[(k-1)*(j+1)+l]){
						fl=0;
						break;
					}
				}
				if (!fl) break;
				rep(i,j) if (rt[k*(j+1)]>=lf[i]) ans++/*,cout<<'('<<i<<','<<j<<','<<k*(j+1)<<")\n"*/;
			}
		}
		cout<<ans<<'\n';
	}
	re 0;
}
/*

1
llllllllllllllllllll

*/

/****************** /
		1、检查附初值
		2、检查数组大小，绝对不MLE
		3、检查会不会爆int
		4、对拍查错
/ ******************/
