#include<bits/stdc++.h>
using namespace std;
int n,m,num,val,id[100100],u,v;
queue<int> q;
vector<int> ga[100100];
struct fract{
	long long fm,fz;
	fract(int x=0){
		fz=x;
		fm=1;
	}
};
long long gcd(long long aa,long long bb){
	if(bb==0) return aa;
	return gcd(bb,aa%bb);
}
long long x;
fract operator +(fract a,fract b){
	fract c;
	c.fm=a.fm*b.fm;
	c.fz=a.fz*b.fm+b.fz*a.fm;
	x=gcd(c.fm,c.fz);
	c.fm/=x;
	c.fz/=x;
	return c;
}
fract operator /(fract a,long long b){
	a.fm*=b;
	x=gcd(a.fm,a.fz);
	a.fm/=x;
	a.fz/=x;
	return a;
}
fract res[100100];
int main(){
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>num;
    	while(num--){
    		 cin>>val;
    		 ga[i].push_back(val);
    		 id[val]++;
		}
	}
	for(int i=1;i<=n;i++) if(id[i]==0) q.push(i),res[i]=1;
	while(q.size()){
		u=q.front();
		q.pop();
		for(int i=0;i<ga[u].size();i++){
			v=ga[u][i];
			res[v]=res[v]+res[u]/ga[u].size();
			id[v]--;
			if(id[v]==0) q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
		if(ga[i].size()==0)
			cout<<res[i].fz<<' '<<res[i].fm<<endl;
    return 0;
}
/*
  REMEMBER to init vals
  REMEMBER to check IO
  REMEMBER to compile before submitting
*/
