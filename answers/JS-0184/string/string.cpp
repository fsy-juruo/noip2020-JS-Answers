#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,ans,a[150][10005],sum[1005][1005];
string s;
bool check(){
	for(int i=1;i<s.size();i++)
		if(s[i]!=s[i-1])return false;
	return true;
}
void gao(int x,int y){
	if(y==1)return ;
	int z=(s.size()-1-x)%2;
	if(z==0)ans+=(ll)(y-1);
	else ans+=(ll)(y-1)/2;
}
bool fuckccf(int x,int y){
	if(y%x!=0)return false;
	if(x==y)return true;
	for(int i=1;(i+1)*x<=y;i++)
		for(int j=0;j<x;j++)
			if(s[j]!=s[j+x*i])return false;
	return true;
}
int su(int l,int r){
	int res=0;
	for(int i='a';i<='z';i++){
		int x=0;
		for(int j=l;j<=r;j++)
			if(s[j]==i)x++;
		res+=x%2;
	}
	return res;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> T;
	while(T--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		cin >> s;
		if(check()){
			for(int i=2;i<s.size();i++){
				for(int j=1;j*j<=i;j++){
					if(i%j!=0)continue;
					gao(i,j);
					if(j*j!=i)gao(i,i/j);
				}
			}
			cout << ans;
			continue;
		}
		for(int i=0;i<s.size();i++)
			a[s[i]][i]++;
		for(int i='a';i<='z';i++)
			for(int j=1;j<s.size();j++)
				a[i][j]+=a[i][j-1];
		for(int i=0;i<s.size();i++)
			for(int j=i;j<s.size();j++){
				for(int k='a';k<='z';k++){
					int u=0;
					if(i>0)u=a[k][i-1];
					sum[i][j]+=(a[k][j]-u)%2;
				}
			}
		for(int i=1;i<s.size()-1;i++){
			for(int j=1;j<=i;j++)
				if(i==j){
					for(int k=0;k<j;k++)
						if(su(0,k)<=su(i+1,s.size()-1))
							ans++;
				}
/*			for(int j=1;j<=i;j++){
				if(sum[0][j]>sum[i+1][s.size()-1])continue;
				vector<int> v;
				for(int k=1;k*k<=i;k++){
					if(i%k!=0)continue;
					if(k>j)v.push_back(k);
					if(k*k!=i and i/k>j)
						v.push_back(i/k);
				}
				for(int k=0;k<v.size();k++)
					if(fuckccf(v[k],i))ans++;
			}*/
		}
		cout << ans << endl;
	}
	return 0;
}
//I AK IOI
