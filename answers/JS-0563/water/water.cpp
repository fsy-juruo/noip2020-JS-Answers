#include<bits/stdc++.h>
using namespace std;

int n,m,d,a[100010],vh[100010];
struct nod{
	long long a,b;
}g[100010];
vector<int> v[100010];
queue<int> que;

int gcd(long long aa,long long bb){
	if(bb==0)return aa;
	long long temp=aa;
	aa=bb;
	bb=temp%bb;
	return gcd(aa,bb);
}

void readp(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		g[i].b=1;
	for(int i=1;i<=m;i++)
		g[i].a=1;
	for(int i=1;i<=n;i++){
		cin>>d;
		for(int j=1;j<=d;j++)
		{
			cin>>a[j];
			v[i].push_back(a[j]);
		}
	}
}

nod add(nod p,nod q){
	if(p.a==0)return q;
	if(q.a==0)return p;
	nod mni;
	mni.a=p.a*q.b+q.a*p.b;
	mni.b=p.b*q.b;
	long long gcdn=gcd(mni.a,mni.b);
	mni.a/=gcdn;
	mni.b/=gcdn;
	return mni;
}//可加约分

void bfs(){
	for(int i=1;i<=m;i++)
		que.push(i);
	while(!que.empty()){
		int temp=que.front();
		for(int i=0;i<v[temp].size();i++){
			nod mn;
			mn.a=g[temp].a;
			mn.b=g[temp].b*v[temp].size();
			g[v[temp][i]]=add(g[v[temp][i]],mn);
			if(!vh[v[temp][i]]){
				que.push(v[temp][i]);
				vh[v[temp][i]]=1;
			}
		}
		vh[temp]=0;
		que.pop();
		if(v[temp].size()){
			g[temp].a=0;
			g[temp].b=1;
		}
	}
}

void makesure(nod &mn){
	long long gcdn=gcd(mn.a,mn.b);
	mn.a/=gcdn;
	mn.b/=gcdn;
}

int main(){
        freopen("water.in","r",stdin);
        freopen("water.out","w",stdout);
	readp();
	bfs();
	for(int i=1;i<=n;i++)
		if(!v[i].size()){
			makesure(g[i]);
			cout<<g[i].a<<' '<<g[i].b<<endl;
		}
        return 0;
}

