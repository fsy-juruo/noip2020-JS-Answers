//I love Chiaki Nanami
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define fst first
#define snd second
#define lowbit(x) x&(-x)
const int inf=1e9+7;
//const int mod=;
const int maxn=(1<<20)+7;
inline int read(){
	int re=0;char c=getchar();
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9'){re=re*10+(c^48);c=getchar();}
	return re;
}
int n;
string s;
int nxt[maxn];
void build_nxt(string q){
	q+='$';
	nxt[0]=-1;
	int i=0,j=-1;
	while (i<q.size()-1){
		if (j==-1 || q[i]==q[j]){
			i++;j++;
			nxt[i]=j;
		}
		else j=nxt[j];
	}
}
int hve[27];
ll dp[maxn][27];
ll ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T_T=read();
	int sum=0; 
	while (T_T--){
		cin>>s;
		n=s.size();
		memset(nxt,0,sizeof(nxt));
		memset(hve,0,sizeof(hve));
		memset(dp,0,sizeof(dp));
		build_nxt(s);   // i+1-nxt[i+1]
//		for (int i=1;i<=s.size();i++) cout<<nxt[i]<<' ';puts("");
		int cnt=0;
		for (int i=0;i<n;i++){
			if (i!=0) dp[i][cnt]++;
			hve[s[i]-'a']++;
			if (hve[s[i]-'a']%2==0) cnt--;
			else cnt++;
			if (i!=0) for (int j=0;j<=26;j++) dp[i][j]+=dp[i-1][j];
		}
//		for (int i=0;i<n;i++){
//			cout<<i<<':';
//			for (int j=0;j<=3;j++){
//				cout<<dp[i][j]<<' ';
//			}
//			puts("");
//		} 
//		puts("--------------------------------");
		for (int i=0;i<n;i++){
			for (int j=1;j<=26;j++){
				dp[i][j]=dp[i][j-1]+dp[i][j];
			}
//			puts("");
		}
		memset(hve,0,sizeof(hve));
		cnt=1;hve[s[n-1]-'a']++;
		ans=0;
		for (int i=n-2;i>=1;i--){
			int xhj=i+1-nxt[i+1];
			int tans=ans;
			if ((i+1)%xhj!=0 || (i+1)==xhj) ans+=dp[i][cnt];
			else{
				int t=(i+1)/xhj;
				for (int j=2;j*j<=t;j++){
					if (t%j==0){
						ans+=dp[j*xhj-1][cnt];
						if (t/j!=j) ans+=dp[(t/j)*xhj-1][cnt];
					}
				}
				ans+=dp[i][cnt];
				if (xhj!=1) ans+=dp[xhj-1][cnt];
			}
//			cout<<i+1<<':'<<xhj<<' '<<cnt<<' '<<ans-tans<<endl;
			hve[s[i]-'a']++;
			if (hve[s[i]-'a']%2==0) cnt--;
			else cnt++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab

*/
