#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define REPA(i,n) for(int i=1;i<=n;i++)
#define FRN(i,l,r) for(int i=l;i<r;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii >
#define SZ(v) ((int)(v).size())
#define fill(v,a) memset((v),a,sizeof(v))
using namespace std;
/*
#check time limit
#check memory limit:about 6~8MB
#check bound in for
#check bound in arry
#check name name name name name name name name
#check long long limit
//
/*********************************************************/
//do remember, read all first then choose to program     //
//                     easy first                        //
//            write down on paper first                  //
//long long in read,long long in middle,long long at last//
/*********************************************************/
inline ll gcd(ll a,ll b){//a>b
	if(a<b)swap(a,b);
	if(b==0)return a;
	return gcd(b,a%b);
}
const int MAXN=1e5+10;
struct frac{
	ll son,mum;//son/mum
	void make_empty(){
		son=0;mum=0;
	}
	bool empty(){
		return mum==0;
	}
	void make_easy(){
		ll k=gcd(son,mum);
		son/=k;
		mum/=k;
	}
	void init(int a,int b){//a/b
		son=a,mum=b;
		make_easy();
	}
	void add(frac n){
		ll k=gcd(mum,n.mum);
		ll k1=n.mum/k,k2=mum/k;
		mum*=k1;
		son=son*k1+n.son*k2;
		make_easy();
	}
	void depart(int k){
		if(k==1){
			
		}
		else if(k==2){
			if(son%2==0)son/=2;
			else mum*=2;
		}
		else if(k==3){
			if(son%3==0)son/=3;
			else mum*=3;
		}
		else if(k==4){
			if(son%2==0)son/=2;
			else mum*=2;
			if(son%2==0)son/=2;
			else mum*=2;
		}
		else{
			if(son%5==0)son/=5;
			else mum*=5;
		}
	}
}ver[MAXN];
int n,m;
int in[MAXN],d[MAXN];
vi v[MAXN];
vi out;
queue<int>q;
int main(void){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	fill(in,0);
	int D,x;
	REPA(i,n){
		scanf("%d",&D);
		d[i]=D;
		if(D==0)out.pb(i);
		REP(j,D){
			scanf("%d",&x);
			in[x]++;
			v[i].pb(x);
		}
	}
	//REP(i,SZ(out))cout<<out[i]<<' ';
	//cout<<endl;
	REPA(i,n)ver[i].make_empty();
	REPA(i,n)if(in[i]==0){
		q.push(i);
		ver[i].init(1,1);
	}
	while(!q.empty()){
		int pos=q.front();q.pop();
		frac num=ver[pos];
		num.depart(d[pos]);
		REP(i,SZ(v[pos])){
			if(ver[v[pos][i]].empty()){
				ver[v[pos][i]]=num;
			}
			else{
				ver[v[pos][i]].add(num);
			}
			in[v[pos][i]]--;
		}
		REP(i,SZ(v[pos]))if(in[v[pos][i]]==0)q.push(v[pos][i]);
	}
	REP(i,SZ(out))printf("%lld %lld\n",ver[out[i]].son,ver[out[i]].mum);
	return 0;
}
