#include<bits/stdc++.h>
#include<queue>
using namespace std;
long long gcd(long long n,long long m){
	if(m==0){
		return n;
	}
	return gcd(m,n%m);
}
struct fs{
	long long fz,fm;
	fs operator + (fs& x){
		fs ans;
		ans.fz=x.fz*this->fm+x.fm*this->fz;
		ans.fm=x.fm*this->fm;
		long long y=gcd(ans.fm,ans.fz);
		ans.fm/=y;
		ans.fz/=y;
		return ans;
	}
	fs operator = (fs& x){
		this->fm=x.fm;
		this->fz=x.fz;
		return *this;
	}
	fs operator += (fs x){
		this->fz=x.fz*this->fm+x.fm*this->fz;
		this->fm*=x.fm;
		long long y=gcd(this->fm,this->fz);
		this->fm/=y;
		this->fz/=y;
		return *this;
	}
	fs operator / (long long x){
		fs ans;
		ans.fm=this->fm*x;
		ans.fz=this->fz;
		long long y=gcd(ans.fm,ans.fz);
		ans.fm/=y;
		ans.fz/=y;
		return ans;
	}
	void print(){
		printf("%lld %lld\n",this->fz,this->fm);
	}
}ans[100005];
int rd[100005];
int n,m,d;
long long tmp;
vector<int>ansn;
vector<int>mp[100005];
priority_queue<int>q;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		ans[i].fm=1,ans[i].fz=0;
		scanf("%d",&d);
		if(d==0){
			ansn.push_back(i);
		}
		for(int j=0;j<d;j++){
			scanf("%lld",&tmp);
			mp[i].push_back(--tmp);
			rd[tmp]++;
		}
	}
	for(int i=0;i<n;i++){
		if(!rd[i])
			ans[i].fz=1,q.push(i);
	}
	while(!q.empty()){
		int x=q.top();
		q.pop();
		tmp=mp[x].size();
		for(int i=0;i<tmp;i++){
			ans[mp[x][i]]+=(ans[x]/tmp);
			fs u=ans[x]/tmp;
			if(!--rd[mp[x][i]]){
				q.push(mp[x][i]);
			}
		}
	}
	for(int i=0;i<ansn.size();i++){
		ans[ansn[i]].print();
	}
	return 0;
}
