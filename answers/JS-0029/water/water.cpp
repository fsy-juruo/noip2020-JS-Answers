#include<bits/stdc++.h>
using namespace std;
#define SZ(v) ((int)(v).size())
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
int n,m;
const int Maxn=1e5+5;
vector<int>from[Maxn];
int in[Maxn],out[Maxn];
pii val[Maxn];//val是分数,保存污水的值 
int Gcd(int a,int b){
	if(a<b)swap(a,b);
	if(a%b==0)return b;
	return Gcd(b,a%b);
}
void change(pii &A){
	int mul=Gcd(A.first,A.second);
	A.first/=mul;
	A.second/=mul;
}
pii add(pii A,pii B){
	if(A.first==-1&&B.first==-1)return make_pair(-1,-1);
	if(A.first==-1)return B;
	if(B.first==-1)return A;
//	cout<<B.second<<endl;
	int mul=Gcd(A.second,B.second);
	int a=A.second/mul;
	int b=B.second/mul;
//	cout<<B.second<<endl;
	A.first*=b;
	A.second*=b;
	B.first*=a;
	B.second*=a;
//	cout<<mul<<' '<<a<<' '<<b<<endl;
	
	pii C=make_pair(A.first+B.first,A.second);
	change(C);
	return C;
}
void topo(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(SZ(from[u])==0)continue;
		
		pii to_add=make_pair(-1,-1);
		
		if(val[u].first!=-1){
			to_add.first=val[u].first;
			to_add.second=val[u].second*SZ(from[u]);
			change(to_add);
		}
//		cout<<u<<' '<<to_add.first<<' '<<to_add.second<<endl;
		rep(i,SZ(from[u])){
			int to=from[u][i];
//			cout<<to<<' ';
			val[to]=add(val[to],to_add);
			in[to]--;
			if(in[to]==0){
				q.push(to);
			}
		}
//		cout<<endl;
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
//	pii a=make_pair(5,11);
//	pii b=make_pair(6,13);
//	pii c=add(a,b);
//	cout<<c.first<<' '<<c.second<<endl;
	scanf("%d%d",&n,&m);
	vector<int>cand;
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		if(k==0)cand.push_back(i);
		for(int j=1;j<=k;j++){
			int x;scanf("%d",&x);
			from[i].push_back(x);
			out[i]++;
			in[x]++;
		}
	}
	memset(val,-1,sizeof(val));
	for(int i=1;i<=m;i++){
		val[i]=make_pair(1,1);
	}
	topo();
//	for(int i=1;i<=n;i++){
//		printf("vertex%d:%d %d\n",i,val[i].first,val[i].second);
//	}
	rep(i,SZ(cand)){
		printf("%d %d\n",val[cand[i]].first,val[cand[i]].second);
	}
	return 0;
}
