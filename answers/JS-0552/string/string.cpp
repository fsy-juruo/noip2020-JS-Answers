#include<bits/stdc++.h>

using namespace std;

#define ll long long;
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define mp make_pair
#define pii pair<int,int>

const int INF=1e9+7;
int tot;
int cnt[27];
int rec[100000001];
int recc[100000001];
int z[100000001];
int ans;
string s;
void zfuc(){
	int l=1;
	int r=1;
	rep(i,s.size()-1){
		if(i<=r){
			if(z[i-l]+i<r)z[i]=z[i-l];
			else{
				while(r<s.size()&&s[r]==s[r-l])r++;
				l=i;
				z[i]=r-l;
				r--;
			}
		}
		else{
			l=r=i;
			while(r<s.size()&&s[r]==s[r-l])r++;
			z[i]=r-l;
			r--;
		}
//		cout<<i<<' '<<l<<' '<<r<<endl;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>tot;
	while(tot--){
		cin>>s;
		ans=0;
		memset(z,0,sizeof z);
		zfuc();
		memset(cnt,0,sizeof cnt);
		rec[s.size()]=0;
		for(int i=s.size()-1;i>=0;i--){
			cnt[s[i]-'a']++;
			if(cnt[s[i]-'a']%2==0)rec[i]=rec[i+1]-1;
			else rec[i]=rec[i+1]+1;
		}
		memset(cnt,0,sizeof cnt);
		recc[0]=0;
		for(int i=0;i<s.size();i++){
			cnt[s[i]-'a']++;
			if(cnt[s[i]-'a']%2==0)recc[i+1]=recc[i]-1;
			else recc[i+1]=recc[i]+1;
		}
		rep0(i,s.size())recc[i]=recc[i+1];
		rep(d,s.size()-1){
			int maxsiz=0;
			for(int i=d;i<s.size();i+=d){
				if(z[i]<d||i+d>=s.size())break;
				maxsiz=i;
			}
			int maxn=maxsiz/d+1;
			if(maxn==1){
				rep0(i,d-1){
					if(recc[i]<=rec[d])ans++;
				}
			}
			else{
				rep0(i,d-1){
					if(recc[i]<=rec[maxsiz-d])ans+=(maxn+1)/2;
					if(recc[i]<=rec[maxsiz])ans+=(maxn+1)/2;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
