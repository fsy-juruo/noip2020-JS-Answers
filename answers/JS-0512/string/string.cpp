#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
template <typename T>inline void read(T &x){
	x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
template <typename T>inline void write(T x){
	ull y=0;ull t=x;int l=0;
	if(x<0){putchar('-');x++;t=-x;t++;}
	if(!t){putchar('0');return;}
	while(t){y=y*10+t%10;t/=10;l++;}
	while(l){putchar(y%10+'0');y/=10;l--;}
}
template <typename T>inline void writes(T x){
	write(x);
	putchar(' ');
}
template <typename T>inline void writeln(T x){
	write(x);
	puts("");
}
const int MAXN=(1<<20)+10;
int a[27][MAXN];
int hz[MAXN];
bool sum[27];
char c[MAXN];
ull h1[MAXN],h2[MAXN],mod1[MAXN],mod2[MAXN];
ull p1=1007,p2=13331;
bool check(int x,int y,int xx,int yy){
	if(h1[y]-h1[x-1]*mod1[y-x+1]==h1[yy]-h1[xx-1]*mod1[yy-xx+1]&&h2[y]-h2[x-1]*mod2[y-x+1]==h2[yy]-h2[xx-1]*mod2[yy-xx+1])return true;
	return false;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T,x,xx;
	read(T);
	int tot=(1<<20);
	mod1[0]=1;mod2[0]=1;
	for(int i=1;i<=tot;i++){
		mod1[i]=mod1[i-1]*p1;
		mod2[i]=mod2[i-1]*p2;
	}
	while(T--){
		ll ans=0;
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		memset(c,0,sizeof(c));
		memset(hz,0,sizeof(hz));
		scanf("%s",c+1);
		int l=strlen(c+1);
		x=0;
		for(int i=1;i<=l;i++){
			h1[i]=h1[i-1]*p1+c[i]-'a'+1;
			h2[i]=h2[i-1]*p2+c[i]-'a'+1;
		}
		for(int i=1;i<=l;i++){
			if(sum[c[i]-'a'+1]){
				sum[c[i]-'a'+1]=false;
				x--;
				a[x][i]=1;
				for(int j=0;j<=26;j++){
					a[j][i]+=a[j][i-1];
				}
			}
			else{
				sum[c[i]-'a'+1]=true;
				x++;
				a[x][i]=1;
				for(int j=0;j<=26;j++){
					a[j][i]+=a[j][i-1];
				}
			}
		}
		for(int i=1;i<=l;i++){
			for(int j=1;j<=26;j++){
				a[j][i]+=a[j-1][i];
			}
		}
		memset(sum,0,sizeof(sum));
		x=0;
		for(int i=l;i>=1;i--){
			if(sum[c[i]-'a'+1]){
				sum[c[i]-'a'+1]=false;
				x--;
				hz[i]=x;
			}
			else{
				sum[c[i]-'a'+1]=true;
				x++;
				hz[i]=x;
			}
		}
		for(int i=2;i<=l-1;i++){
			int j=i;
			while(check(1,i,j-i+1,j)){
				ans+=a[hz[j+1]][i-1];
				j+=i;
				if(j>l-1)break;
			}
		}
		writeln(ans);
	}
	return 0;
}


