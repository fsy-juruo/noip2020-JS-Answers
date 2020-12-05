#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define INF 2147483647
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=55;
const int Maxm=405;
int n,m;
struct Vector{
	int A[Maxm],sz;
	Vector(){
		sz=0;memset(A,0,sizeof(A));
	}
	int size(){
		return sz;
	}
	int back(){
		return A[sz-1];
	}
	int pb(int x){
		A[sz++]=x;
	}
	void pop_back(){
		sz--;
	}
	bool empty(){
		return sz==0;
	}
	int operator [](int x){
		return A[x];
	}
};
Vector V[Maxn];
vector<pair<int,int> > O;
int cnt[Maxn];
bool cmp(int x,int y){
	return cnt[x]<cnt[y];
}
void Throw(int x,int y){
//	assert(!V[x].empty() && V[y].size()!=m);
	int v=V[x].back();V[y].pb(v);V[x].pop_back();
	O.pb(mp(x,y));
}
int T=0;
void Solve(int x){
	if (x==n) return;
	vector<int> R;
	memset(cnt,0,sizeof(cnt));
	int Ept;
	for (int i=x;i<=n+1;i++){
		if (V[i].empty()){
			Ept=i;
			continue;
		}
		for (int j=0;j<V[i].size();j++){
			if (V[i][j]==x) cnt[i]++;
		}
		R.pb(i);
	}
	//sort(R.begin(),R.end(),cmp);
	for (int i=0;i+1<R.size();i+=2){
		int A=R[i],B=R[i+1];
		if (cnt[A]*3<=m && cnt[B]*3<=m){
			swap(A,B);
			for (int j=0;j<cnt[A];j++){
				Throw(B,Ept);
			}
			for (int j=0;j<m;j++){
				if (V[A].back()==x) Throw(A,B);
				else Throw(A,Ept);
			}
			int nc=0;
			for (int j=0;j<m;j++){
				if (V[B][j]==x) nc++;
			}
			for (int j=0;j<nc;j++){
				Throw(Ept,A);
			}
			for (int j=0;j<m;j++){
				if (V[B].back()==x){
					Throw(B,Ept);
				}
				else{
					Throw(B,A);
				}
			}
		//	cerr<<"FUCK1FF"<<endl;
			nc=0;
			for (int j=0;j<m;j++){
				if (V[Ept][j]==x) nc++;
			}
			
			for (int j=0;j<nc;j++){
				Throw(A,B);
			}
			for (int j=0;j<m;j++){
				if (V[Ept].back()==x){
					Throw(Ept,A);
				}
				else{
					Throw(Ept,B);
				}
			}
		//	cerr<<"FUCK1FFF"<<endl;
		}
		else{
		//	cerr<<"FUCK"<<endl;
			swap(A,B);
			for (int j=0;j<cnt[A];j++){
				Throw(B,Ept);
			}
			for (int j=0;j<m;j++){
				if (V[A].back()==x) Throw(A,B);
				else Throw(A,Ept);
			}
			int nC=0,nr=0;
			for (int j=0;j<m;j++){
				if (V[Ept][j]==x) nC++;
			}
			int nB=0;
			for (int j=0;j<m;j++){
				if (V[B][j]==x) nB++;
			}
			
			for (int j=0;j<nC;j++){
				Throw(B,A);
			}
			for (int j=0;j<m;j++){
				if (V[Ept].back()==x){
					Throw(Ept,B);
				}
				else{
					Throw(Ept,A);
				}
			}
			nC=0;
			for (int j=0;j<m;j++){
				if (V[B][j]==x){
					nC++;
				}
			}
			
			for (int j=0;j<m-nC;j++){
				Throw(A,Ept);
			}
			for (int j=0;j<m;j++){
				if (V[B].back()==x){
					Throw(B,Ept);
				}
				else{
					Throw(B,A);
				}
			}
			for (int j=0;j<m;j++){
				Throw(A,B);
			}
			Ept=A;
		}
	}
	for (int i=1;i<=n+1;i++){
		if (i!=Ept){
			while (!V[i].empty() && V[i].back()==x){
				Throw(i,Ept);T++;
			}
		}
	}
	//cerr<<"EEEE"<<endl;
	int X=-1;
	for (int i=1;i<=n+1;i++){
		if (i!=Ept) X=i;
	}
	if (R.size()&1){
		X=R.back();
	}
	int I=1;
	while (!V[X].empty()){
		if (V[X].back()==x){
			Throw(X,Ept);T++;
		}
		else{
			while (I<=n+1 && (I==X || I==Ept || V[I].size()==m)) I++;
			Throw(X,I);T++;
		}
	}
	//cerr<<"EEEEE"<<endl;
	
	
	int Ans=Ept;
	Ept=X;
	//cout<<"HH"<<' '<<Ans<<' '<<Ept<<endl;
	
	if (Ans!=x){
		if (Ept==x){
			for (int i=0;i<m;i++) Throw(Ans,x),T++;
			Ept=Ans;
		}
		else{
			for (int i=0;i<m;i++){
				Throw(x,Ept),T++;
			}
			for (int i=0;i<m;i++){
				Throw(Ans,x),T++;
			}
			Ept=Ans;
		}
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++){
		for (int j=0;j<m;j++){
			int x=read();V[i].pb(x);
		}
	}
	
	for (int i=1;i<=n;i++){
		Solve(i);
	}
	printf("%d\n",(int)O.size());
	
	for (int i=0;i<O.size();i++){
		printf("%d %d\n",O[i].first,O[i].second);
	}
	return 0;
}
/*
2 3
1 1 2
2 1 2
*/
