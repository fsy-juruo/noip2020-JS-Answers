#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007ll;
int n,k;
int w[15];
int c[500005],d[500005];
int h;
pair<long long,int> all[10000005];
int l[15];
int calc(int x){
	int maxv=INT_MIN,minv=INT_MAX,maxs,mins,res=0;
	vector<pair<int,int> > mv;
	for(int i=1;i<=n;++i){
		if(c[i]!=x){
			continue;
		}
		mv.push_back(make_pair(d[i],i));
		res+=d[i];
		if(maxv<res){
			maxv=res;
			maxs=i;
		}
		if(minv>res){
			minv=res;
			mins=i;
		}
	}
	if(mv.empty()){
		return -1;
	}
	bool zero=0,escape=0;
	if(res==0){
		zero=1;
	}
	for(int i=1;i<=w[x];++i){
		int mx=maxv+i,mn=minv+i;
		if(mx>w[x]||mn<1){
			escape=1;
		}
	}
	if(zero&&(!escape)){
		return -1;
	}
	for(int i=1;i<=w[x];++i){
		long long now=0ll;
		int pos=i;
		for(int j=0;j<mv.size();++j){
			pos+=mv[j].first;
			if(pos>w[x]||pos<1){
				now=(long long)mv[j].second;
				break;
			}
		}
		if(now==0ll){
			if(res<0){
				int pre=0-minv;
				int dis=max(0,i-pre);
				int div=dis/(-res);
				int pos=i+res*div;
				if(pos+minv>=1){
					pos+=res;
					div++;
				}
				for(int j=0;j<mv.size();++j){
					pos+=mv[j].first;
					if(pos<1){
						 now=(long long)mv[j].second;
						 break;
					}
				}
				now+=(long long)div*n;
				now%=mod;
			}
			else{
				int pre=w[x]+1-maxv;
				int dis=max(0,pre-i);
				int div=dis/res;
				int pos=i+res*div;
				if(pos+maxv<=w[x]){
					pos+=res;
					div++;
				}
				for(int j=0;j<mv.size();++j){
					pos+=mv[j].first;
					if(pos>w[x]){
						now=(long long)mv[j].second;
						break;
					}
				}
				now+=(long long)div*n;
				now%=mod;
			}
		}
		h++;
		all[h]=make_pair(now,x);
	}
	return 0;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	int maxv=INT_MIN;
	for(int i=1;i<=k;++i){
		scanf("%d",w+i);
		maxv=max(maxv,w[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%d%d",c+i,d+i);
	}
	if(maxv>1000000){
		puts("-1");
		return 0;
	}
	bool doom=1;
	for(int i=1;i<=k;++i){
		if(calc(i)!=-1){
			doom=0;
		}
	}
	if(doom){
		puts("-1");
		return 0;
	}
	sort(all+1,all+1+h);
	long long ans=0ll;
	for(int i=1;i<=k;++i){
		l[i]=w[i];
	}
	for(int i=1;i<=h;++i){
		long long val=all[i].first;
		for(int j=1;j<=k;++j){
			if(j==all[i].second){
				continue;
			}
			val=(val*(long long)l[j])%mod;
		}
		l[all[i].second]--;
		ans+=val;
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}

