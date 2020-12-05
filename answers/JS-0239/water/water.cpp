#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long gcd(long long a,long long b){
	if(!a)
		return b;
	return gcd(b%a,a);
}
long long lcm(long long a,long long b){
	return a*b/gcd(a,b);
}
struct frac{
	long long zi,mu;
	void out(){
		cout<<zi<<' '<<mu<<endl;
	}
}node[100010];
frac yue(long long a,long long b){
	long long div=gcd(a,b);
	frac res;
	res.zi=a/div;
	res.mu=b/div;
	return res;
}
frac operator + (frac a,frac b){
	long long zi,mu;
	mu=lcm(a.mu,b.mu);
	zi=a.zi*(mu/a.mu)+b.zi*(mu/b.mu);
	return yue(zi,mu);
}
frac operator / (frac a,long long b){
	a.mu*=b;
	return yue(a.zi,a.mu);
}
frac make(long long a,long long b){
	frac res;
	res.zi=a;
	res.mu=b;
	return res;
}
queue<long long>q;
vector<long long>to[100010];
long long cnt[100010];
bool last[100010];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		if(!k)
			last[i]=1;
		for(int j=0;j<k;j++){
			int y;
			cin>>y;
			to[i].push_back(y);
			cnt[y]++;
		}
	}
	for(int i=1;i<=n;i++)
		if(!cnt[i])
			node[i]=make(1,1),q.push(i);
		else
			node[i]=make(0,1);
	while(!q.empty()){
		if(to[q.front()].empty()){
			q.pop();continue;			
		}
		frac give=node[q.front()]/to[q.front()].size();
		for(int i=0;i<to[q.front()].size();i++){
			node[to[q.front()][i]]=node[to[q.front()][i]]+give;
			if(!--cnt[to[q.front()][i]])
				q.push(to[q.front()][i]);			
		}
		q.pop();		
	}
	for(int i=1;i<=n;i++)
		if(last[i])
			node[i].out();
	return 0;
}


