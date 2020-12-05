#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline void file(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
inline void read(string &x){
	x="";
	char c=getchar();
	for(;!('a'<=c&&c<='z');c=getchar());
	for(;('a'<=c&&c<='z');c=getchar())x=x+c;
}
const int maxn=(1<<20)+5;
int border[maxn];
string s;
int n,ans;
queue<int>q[maxn];
char ch[305];
int fsy[maxn];
int tr[4*maxn+5],tg[8*maxn+5];
void insert(int x,int l,int r,int ll){
	if(tg[x]){
		tr[x]+=tg[x];
		tg[x*2]+=tg[x];
		tg[x*2+1]+=tg[x];
		tg[x]=0;
	}
	if(ll<=l){
		tr[x]++;
		tg[x*2]++;
		tg[x*2+1]++;
		return ;
	}
	int mid=(l+r)/2;
	if(ll<=mid)
		insert(x*2,l,mid,ll);
	insert(x*2+1,mid+1,r,ll);
}
int asks(int x,int l,int r,int p){
	if(tg[x]){
		tr[x]+=tg[x];
		tg[x*2]+=tg[x];
		tg[x*2+1]+=tg[x];
		tg[x]=0;
	}
	if(l==r){
		return tr[x];
	}
	int mid=(l+r)/2;
	if(p<=mid)
		return asks(x*2,l,mid,p);
	if(mid+1<=p)
		return asks(x*2+1,mid+1,r,p);
}
void make_border(){
	int len=0;
	border[1]=0;
	for(int i=2;i<=n;i++){
		if(s[len]==s[i-1])len++;
		else{
			while(len!=0&&s[len]!=s[i-1]){
				len=border[len];
			}
			if(s[len]==s[i-1])len++;
		}
		border[i]=len;
	}
}

void solve(){
	ans=0;
	for(int i=1;i<=maxn;i++){
		fsy[i]=0;
	}
	for(int i=1;i<=maxn*4;i++){
		tr[i]=0;
	}
	for(int i=1;i<=maxn*8;i++){
		tg[i]=0;
	}
	n=s.size();
	make_border();
	for(int i=2;i<=n/2;i++){
		q[i].push(i);
		for(int j=i<<1;j<=n;j+=i){
			if(border[j]>=i){
				q[j].push(i);
			}
			else break;
		}
	}
	for(int i=1;i<=300;i++){
		ch[i]=0;
	}
	int fsyac=0;
	for(int i=n;i>=3;i--){
		ch[s[i-1]]++;
		if(ch[s[i-1]]%2==1)fsyac++;
		else fsyac--;
		while(q[i-1].size()){
			fsy[q[i-1].front()]++;
			q[i-1].pop();
		}
	}
	for(int i=1;i<=300;i++){
		ch[i]=0;
	}
	int f=0;
	for(int i=1;i<=n;i++){
		ch[s[i-1]]++;
		if(ch[s[i-1]]%2==1)f++;
		else f--;
//		if(f!=0)
			insert(1,0,maxn,f);
		ans+=fsy[i]*asks(1,0,maxn,i);
	}
}

int main(){
	file("string");
	int t;
	cin>>t;
	for(int l=1;l<=t;l++){
		read(s);
		solve();
		cout<<ans<<endl;
	}
	return 0;
}

