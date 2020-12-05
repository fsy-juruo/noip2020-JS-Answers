// NOIP 2020
// lycLTb
// 每题保证 20min 的有效思考时间 
// 题目难度和题目编号成正比,部分分难度和题目难度不成正比
// 希望单 hash 没事（合掌 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug puts("QwQ")
inline int read(){
	int f=1,x=0;
	char ch;
	while (ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

const int MAXN=1500000;
const int MOD=998244853;
int n;
char a[MAXN];
int cnt1[30][MAXN],cnt2[30][MAXN];
int ans;

int hash[MAXN];
int fac[MAXN],inv[MAXN];
int base=26;

inline int ksm(int x,int y){
	int ans=1;
	while (y){
		if (y&1) ans=ans*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return ans;
}

void init(){
	ans=n=0;
	char ch=getchar();
	while (ch<'a' || ch>'z') ch=getchar();
	while (ch>='a' && ch<='z'){
		a[++n]=ch;
		ch=getchar();
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=26;j++){
			cnt1[j][i]=cnt1[j][i-1]+(a[i]==(j+'a'-1));
		}
	}
	
	for (int j=1;j<=26;j++)
		cnt2[j][n+1]=0;
	
	for (int i=n;i>=1;i--){
		for (int j=1;j<=26;j++){
			cnt2[j][i]=cnt2[j][i+1]+(a[i]==(j+'a'-1));
		}
	}
	
	// hash
	srand(time(NULL));
	base+=rand()%4;
	
	fac[0]=inv[0]=1;
	for (int i=1;i<=n;i++){
		fac[i]=inv[i]=hash[i]=0;
		fac[i]=fac[i-1]*base%MOD;
		inv[i]=ksm(fac[i],MOD-2);
		hash[i]=(hash[i-1]*base%MOD)+a[i]-'a'+1;
		hash[i]%=MOD;
	}
}

inline int gethash(int l,int r){
	return (hash[r]-hash[l-1]*fac[r-l+1]%MOD+MOD)%MOD;
}

int kel[MAXN];

signed main()

{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int TestCase=read();
	while (TestCase--){
		init();
		cout<<n<<endl;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++)
				kel[j]=0;
				
			for (int j=i+1;j<=n;j++){
				kel[j]++;
				int tmp=gethash(1,j),stp=j;
				int cur=j+stp; 
				while (cur<=n){
					int le=cur-stp+1;
					if (gethash(le,cur)==tmp) kel[cur]++;
					else break;
					cur+=stp;
				}
			}
			
			for (int j=n;j>i+1;j--){
				int qwq=0,qaq=0;
				for (int k=1;k<=26;k++){
					qwq+=cnt1[k][i]&1;
					qaq+=cnt2[k][j]&1;
				}
				
				if (qwq<=qaq) ans+=kel[j-1];
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}

