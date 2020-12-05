#include <bits/stdc++.h>
#define ll long long
#define N 1<<15
using namespace std;

int T,n,xlen,xnum,numx,len,ans,numc;
int numm[30][N],nna[N];
char s[N];
string a,b,c,x;

bool check(string minn,int len){
	int i=0,lenx=minn.size();
	if(len%lenx!=0)
		return false;
	while(i<len){
		if(s[i+1]!=minn[i%lenx]) return false;
		++i;
	}
	return true;
}

void find(int e){
	string minn;
	for(int i=1;i<=e;++i){
		minn+=s[i];
		if(check(minn,e)){
			x=minn;
			xlen=minn.size();
			xnum=e/xlen;
			return;
		}
	}
}

int work(int num)
{
	if(num%2==0 && num!=0)
		ans+=work(num/2);
	int nm=0,numss=0;
	for(int i=0;i<num;++i){
		for(int k=0;k<xlen;++k){
			if(!i && !k) continue;
			numss=0;
			for(int ss='a'-'a';ss<='z'-'a';++ss){
				if(i%2 && (numm[ss][k]+numm[ss][xlen])%2) numss++;
				if(!i%2 && (numm[ss][k])%2) numss++;
			}
			if(numss<=numc) nm++;
		}
	}
	return nm;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d\n",&T);
	while(T--){
		a=b=c=x="";
		n=ans=len=0;
		memset(s,0,sizeof(s));
		memset(numm,0,sizeof(numm));
		char cc;
		for(int i=0;i<='z'-'a';++i) numm[i][0]=0;
		while(scanf("%c",&cc)){
			if(cc=='\n') break;
			s[++len]+=cc;
			numm[cc-'a'][len]++;
			for(int i=0;i<='z'-'a';++i) numm[i][len]+=numm[i][len-1];
		}
		for(int k=len;k>2;--k){
			numc=0;
			c+=s[k];
			for(int i='a'-'a';i<='z'-'a';++i){
				if((numm[i][len]-numm[i][k-1])%2) numc++;
			}
			find(k-1);
			ans+=work(xnum);
		}
		printf("%d\n",ans);
	}
	return 0;
}
