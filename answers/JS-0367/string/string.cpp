#include<bits/stdc++.h>
#define N 100
#define ll long long
using namespace std;
int T,cnt[30],maxn,js[30],g[1010][1010];
ll ans;
string st[N];

int num(int l,int r,string s){
	memset(cnt,0,sizeof(cnt));
	int len=s.size(),sum=0;
	for(int i=l;i<=r;i++)
		cnt[s[i]-'a']++;
	for(int i=0;i<26;i++)
		if(cnt[i]%2==1)sum++;
	return sum;
}

bool check(int la,int ra,int lc,int rc,string s){
	int na=num(la,ra,s),nc=num(lc,rc,s);
	if(na<=nc)return true;
	return false;
}

void init(string s){
	int len=s.size();
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++){
			if(check(0,i,j,len-1,s))g[i][j]=1;
		}
	}
}

void work(string s){
	int len=s.size();
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++){
			string ab=s.substr(0,j+1);
			for(int k=0;k<len-j-1&&ab==s.substr(k,j+1);k+=(j+1)){
				if(g[i][k+j+1]) ans++;
			}
		}
	}
	printf("%lld\n",ans);
}

void task1(){
	for(int i=1;i<=T;i++){
		ans=0;
		memset(g,0,sizeof(g));
		init(st[i]);
		work(st[i]);
	}
}
bool flag1=true;

void work2(string s){
	int len=s.size();
	for(int i=0;i<len-1;i++){
		if((len-1-i)%2==0){
			for(int j=1;j<=sqrt(i+1);j++){
				if((i+1)%j!=0)continue;
				if(j&1)ans=(ans+j/2-1+1);
				else ans=(ans+j/2-1);
			}
			if((i+1)%2==0)ans=(ans+i-1);
		}
		else {
			ans=(ans+i-1);
		}
	}
	printf("%lld\n",ans);
}

void task2(){
	for(int i=1;i<=T;i++){
		ans=0;
		work2(st[i]);
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	int jjs=0;
	for(int i=1;i<=T;i++){
		cin>>st[i];
		int len=st[i].size();
		maxn=max(maxn,len);
		memset(js,0,sizeof(js));
		jjs=0;
		for(int j=0;j<len;j++)
			js[st[i][j]-'a']++;
		for(int j=0;j<26;j++)
			if(js[j])jjs++;
		if(jjs>1)flag1=false;
	}	
	if(maxn<=1000)task1();
	else task2();
	return 0;
}
