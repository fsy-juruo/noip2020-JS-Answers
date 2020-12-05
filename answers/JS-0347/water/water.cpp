#include<bits/stdc++.h>
#define ll long long 
#define N 100010
using namespace std;
struct S{
	int b;int w;
	S(int B,int W){
		b=B;w=W;
	}
};
bool operator <(S x,S y){
	return x.w<y.w;
}
priority_queue<S> h;
vector<S> son[N];
ll n,m,Q;
ll g;
ll flag;
ll gcd(int a,int b){
	if(a<b) swap(a,b);
	if(a%b!=0) gcd(b,a%b);
	else if(a%b==0) return b;
}
ll q[N],p[N],ma[N],v[N],w[N],x,y,chu,b;
int cnt;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>Q;
		if(Q!=0){
			for(int j=1;j<=Q;j++){
				cin>>x;
				int dx=i;
				w[x]=w[dx]+1;
				son[dx].push_back(S(x,w[x]));
				
		//		cout<<"wrong  ";
			}
			}
		if(Q==0){
			cnt++;ma[cnt]=i;
		}
		}
		//	cout<<"cnt="<<cnt<<endl;
for(int i=1;i<=m;i++){

	q[m]=1;p[m]=1;
	h.push(S(m,0));}
	while(!h.empty()){
		ll a;
		 a=h.top().b;h.pop();
		//v[a]=1;
		flag=max(w[a],flag);
	//	cout<<"A="<<a<<endl;
		chu=son[a].size();
		
		for(int i=0;i<son[a].size();i++){
			b=son[a][i].b;
			int t=p[b];
			
		
			if(q[b]!=0){
	        p[b]=p[b]*chu*q[a]+p[a]*q[b];
			q[b]=q[b]*chu*q[a];
		//	cout<<"Aaa"<<endl;
		}
			if(q[b]==0) 
			p[b]=p[a],q[b]=q[a]*chu;
		//	cout<<"p["<<b<<"]="<<p[b]<<"q["<<b<<"]="<<q[b]<<endl;
			
			if(!v[b]&&flag<=w[b]){h.push(S(b,w[b]));
		//	cout<<"push"<<b<<endl;
		}
		}
	}
	if(cnt==2){
		g=gcd(p[ma[1]],q[ma[1]]);
		cout<<p[ma[1]]/g<<" "<<q[ma[1]]/g<<endl;
		cout<<q[ma[1]]/g-p[ma[1]]/g<<" "<<q[ma[1]]/g<<endl;
	}
	else for(int i=1;i<=cnt;i++){
	//	cout<<p[ma[i]]<<" "<<q[ma[i]]<<endl;
		g=gcd(p[ma[i]],q[ma[i]]);
		cout<<p[ma[i]]/g<<" "<<q[ma[i]]/g<<endl;
	} 
//	for(int i=1;i<=n;i++){
//		cout<<w[i]<<endl;
//	}
	return 0;
}

