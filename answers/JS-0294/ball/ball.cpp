#include<bits/stdc++.h>
#define x0 pmtx0
#define x1 pmtx1
#define y0 pmty0
#define y1 pmty1
#define pb push_back
#define mp make_pair
#define DEBUG printf("Passing Line %d in function [%s].\n",__LINE__,__FUNCTION__)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int > vi;
typedef pair<int ,int > pii;

namespace FastIO{
	const int SIZE=(1<<20);
	char in[SIZE],*inS=in,*inT=in+SIZE;
	inline char Getchar(){
		if(inS==inT){
			inT=(inS=in)+fread(in,1,SIZE,stdin);
			if(inS==inT)return EOF;
		}
		return *inS++;
	}
	char out[SIZE],*outS=out,*outT=out+SIZE;
	inline void Flush(){
		fwrite(out,1,outS-out,stdout);
		outS=out;
	}
	inline void Putchar(char c){
		*outS++=c;
		if(outS==outT)Flush();
	}
	struct NTR{
		~NTR(){Flush();}
	}ZTR;
}
#ifndef LOCAL
	#define getchar FastIO::Getchar
	#define putchar FastIO::Putchar
#endif
template<typename T> inline void read(T &x){
	x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	x*=f;
}
template<typename T> inline void write(T x){
	if(!x){putchar('0');return ;}
	if(x<0){putchar('-');x=-x;}
	static int st[27];int tot=0;
	while(x){st[++tot]=x%10;x/=10;}
	while(tot)putchar(st[tot--]+'0');
}
const int maxn=407,INF=0x3f3f3f3f;
const int MOD=998244353;
const ll LINF=0x3f3f3f3f3f3f3f3fll;

template<typename T> inline void chkmin(T &x,T y){x=(x<y?x:y);}
template<typename T> inline void chkmax(T &x,T y){x=(x<y?y:x);}
template<typename T> inline T ABS(T x){return (x<0?-x:x);}
inline int mod1(int x){if(x>MOD)x-=MOD;return x;}
inline int mod2(int x){if(x<0)x+=MOD;return x;}
inline void add(int &x,int y){x=mod1(x+y);}
inline void sub(int &x,int y){x=mod2(x-y);}

int n,m;
int a[maxn][maxn];
int top[maxn];
int cnt[57][57];
vector<pii > v;
inline void move(int x,int y){
//	cout<<x<<' '<<y<<endl; 
	v.pb(mp(x,y));
	cnt[x][a[x][top[x]]]--;cnt[y][a[x][top[x]]]++;
	a[y][++top[y]]=a[x][top[x]--];
//	assert(top[y]<=m);
}
inline void empty(int x){
	for(int i=1;i<=x-1;i++){
		while(top[i]!=m)move(x,i);
	}
}
inline int find_somewhere_not_full(int l,int r,int k){
	for(int i=l;i<=r;i++){
		if(i!=k&&top[i]!=m)return i;
	}
	return -1;
}
vector<int > st;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			cnt[i][a[i][j]]++;
		}
		top[i]=m;
	}
	top[n+1]=0;
	for(int i=n;i>=2;i--){
		empty(i+1);
		int target=a[1][top[1]];
		move(1,i+1);
		for(int j=i;j>=1;j--){
			if(!cnt[j][target])continue;
//			tot=0;
//			ban[j]=true;
			for(int k=top[j];k>=1;k--){
//				cout<<i<<' '<<j<<' '<<k<<endl;
//				cout<<i<<' '<<j<<' '<<k<<endl;
//				cout<<top[j]<<endl;
//				system("pause"); 
				if(a[j][k]!=target){
//					int tmp=;
					move(j,find_somewhere_not_full(1,i+1,j));
				}else{
//					ban[i+1]=true;
					int tmp=find_somewhere_not_full(1,i,j);
					int pl=0;
					if(tmp==-1){
						j==1?pl=2:pl=1;
						move(j,i+1);
						move(pl,j);
						move(i+1,pl);
						tmp=pl;
					}else{
						move(j,tmp);
					}
//					cout<<tmp<<endl;
//					ban[tmp]=true;
					while(a[i+1][top[i+1]]!=target)move(i+1,j);
					move(tmp,i+1);
					k=top[j]+1;
				}
			}
		}
	}
	empty(2);
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++){
		printf("%d %d\n",v[i].first,v[i].second);
	}
//	for(int i=1;i<=n+1;i++){
//		for(int j=1;j<=top[i];j++){
////			cout<<top[i]<<endl;
//			cout<<a[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	return 0;
}
//THINGS TO REMEMBER
//1.LONG LONG !!!!
//2.FREOPEN!!!!(AND FILENAME)
//3.MAXN!!!!(AND MEMORY LIMIT)
//4.BORDER CASE!!!!!


