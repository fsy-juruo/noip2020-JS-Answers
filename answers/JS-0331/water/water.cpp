#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100010;
const int MAXM=1000010;
int n,m;
struct nde {
	int c,nxt;
}e[MAXM];
int head[MAXN],cnt=0;
int inp[MAXN],outp[MAXN];
long long fz[MAXN],fm[MAXN];
queue<int>q;
void read(int x,int y) {
	e[++cnt].c=y;
	e[cnt].nxt=head[x];
	head[x]=cnt;
}
long long gcd(long long a,long long b) {
	if(!b) return a;
	return gcd(b,a%b);
}
int Add(int st,int ch) {
	long long nowfm=fm[st]*fm[ch];
	long long fzst=fz[st]*fm[ch];
	long long fzch=fz[ch]*fm[st];
	long long nowfz=fzst+fzch;
	long long g=gcd(nowfz,nowfm);
	//cout<<"origin"<<nowfz<<" "<<nowfm<<" gcd "<<g<<endl;
	nowfz/=g;nowfm/=g;
	fz[ch]=nowfz;
	fm[ch]=nowfm;
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int targ;
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;i++) {
		scanf("%d",&outp[i]);
		for(register int j=1;j<=outp[i];j++) {
			scanf("%d",&targ);
			read(i,targ);
			inp[targ]++;
		}
	}
	for(register int i=1;i<=n;i++) {
		fm[i]=1;
		if(inp[i]==0) {
			//cout<<"mark";
			fz[i]=1;
			q.push(i);
		}
	}
	while(q.size()) {
		int st=q.front();
		//cout<<st<<"asyi";
		q.pop();
		//cout<<"check";
		long long nowfz=fz[st],nowfm=fm[st];
		if(outp[st]) {
			nowfm=nowfm*outp[st];
			long long g=gcd(nowfz,nowfm);
			nowfz=nowfz/g;nowfm=nowfm/g;
			fz[st]=nowfz;fm[st]=nowfm;
		}
		for(register int i=head[st];i;i=e[i].nxt) {
			
			int ch=e[i].c;
			inp[ch]--;
			if(!inp[ch]) {
				q.push(ch);
			}
			//cout<<"checkbefore"<<fz[st]<<" "<<fm[st]<<" ";
			Add(st,ch);
			//cout<<"checkadd"<<st<<" "<<ch<<" "<<fz[ch]<<" "<<fm[ch]<<endl;
		}
	}
	for(register int i=1;i<=n;i++) {
		if(outp[i]==0) {
			printf("%lld %lld\n",fz[i],fm[i]);
		}
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
