#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f;
const int N=(1<<20)+10;

int T;
int n;
char str[N];int nxt[N];
bool cnt[26];
int sum[N],s[N];
int mins[N];
ull ans;

class BIT{
public:
	int t[30];
	void init(){for (int i=1;i<=27;i++)t[i]=0;}
	inline int lowbit(int x){return x&(-x);}
	void add(int x){for (;x<=30;x+=lowbit(x))t[x]++;}
	ll query(int x){
		int ret=0;
		for (;x;x-=lowbit(x))ret+=t[x];
		return ret;
	}
}t;

int read(){
	int f=1,x=0;char ch=getchar();
	while (ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

void getsum(){
	for (int i=0;i<26;i++)cnt[i]=0;
	for (int i=n-1;i>=0;i--){
		cnt[str[i]-'a']^=1;
		if (cnt[str[i]-'a'])sum[i]=sum[i+1]+1;
		else sum[i]=sum[i+1]-1;
	}
}

void getmins(){
	for (int x=0;x<n;x++){
		if ((x+1)%(x-nxt[x]+1)==0 && nxt[x]!=0)mins[x]=x-nxt[x]+1;
		else mins[x]=x+1;
	}
}

//int mins(int x){
//	if ((x+1)%(x-nxt[x]+1)==0 && nxt[x]!=0)return x-nxt[x]+1;
//	return x+1;
//}

void solve(){
	ans=0;
	scanf("%s",str);n=strlen(str);
	if (n<3){puts("0");return ;}
	nxt[0]=0;
	for (int i=1;i<n;i++){
		int j=nxt[i-1];
		while (j && str[i]!=str[j])j=nxt[j-1];
		if (str[i]==str[j])j++;
		nxt[i]=j;
	}
//	cerr<<n<<endl;
//	for (int i=0;i<n;i++)cerr<<nxt[i]<<' ';cerr<<endl;
//	for (int i=0;i<n;i++)cerr<<mins(i)<<' ';cerr<<endl;
	
	getsum();
	getmins();
	
	t.init();
	for (int i=0;i<26;i++)cnt[i]=0;
	int s=0;
	for (int i=1;i<n-1;i++){
//		cerr<<i<<endl;
		cnt[str[i-1]-'a']^=1;
		if (cnt[str[i-1]-'a'])s++;
		else s--;
		t.add(s+1);
//		cerr<<"add:"<<s<<endl;
		
		int len=i+1;
		for (int j=i;j<n-1 && mins[j]==mins[i];j+=len){
//			if (mins(j)==mins(i)){
				ans+=t.query(sum[j+1]+1);
//				cerr<<i<<' '<<j<<' '<<sum[j+1]<<' '<<t.query(sum[j+1]+1)<<endl;
//			}
//			else break;
		}
//		cerr<<"query"<<endl<<endl;
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read();
	while (T--)solve();
	
	return 0;
}


