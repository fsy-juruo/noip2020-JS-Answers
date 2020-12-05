#include <bits/stdc++.h>
#define MAXS (1<<20|1)
#define P 131
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int t,len;
int Aodd[MAXS],Codd[MAXS],sum[MAXS][27];
ull p[MAXS],f[MAXS];
bool odd[26];
string str;

void Hash(){
	memset(p,0,sizeof(p));
	memset(f,0,sizeof(f));
	p[0]=1;
	for(int i=1;i<=len;++i)
		f[i]=f[i-1]*P+(str[i]-'a'+1),
		p[i]=p[i-1]*P;
}

void Odd(){
	memset(Aodd,0,sizeof(Aodd));
	memset(Codd,0,sizeof(Codd));
	memset(sum,0,sizeof(sum));
	memset(odd,0,sizeof(odd));
	for(int i=1;i<=len;++i){
		if(!odd[str[i]-'a']) Aodd[i]=Aodd[i-1]+1,odd[str[i]-'a']=1;
		else Aodd[i]=Aodd[i-1]-1,odd[str[i]-'a']=0;
	}
	memset(odd,0,sizeof(odd));
	for(int i=len;i>=1;--i){
		if(!odd[str[i]-'a']) Codd[i]=Codd[i+1]+1,odd[str[i]-'a']=1;
		else Codd[i]=Codd[i+1]-1,odd[str[i]-'a']=0;
	}
	for(int i=1;i<=len;++i)
		for(int j=0;j<=26;++j)
			sum[i][j]=sum[i-1][j]+(j>=Aodd[i]);
}

void calc(){
	ll ans=0;
	for(int b=2;b<=len-1;++b){
		for(int c=b+1;c<=len;c+=b){
			if((f[c-1]-f[c-b-1]*p[b])!=f[b]) break;
			ans+=sum[b-1][Codd[c]];
		}
	}
	cout<<ans<<endl;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>str;
		len=str.size();
		str=' '+str;
		Hash();
		Odd();
		calc();
	}
	return 0;
}
