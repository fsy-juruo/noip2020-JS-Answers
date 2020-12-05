#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
//rp++!
using namespace std;
int z[1050005];
char s[1050005];
int n,t;
void get_z(){
	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(i>r){
			l=r=i;
			while(r<n && s[r]==s[r-l]) r++;
			z[i]=r-l;
			r--;
		}
		else{
			int k=i-l;
			if(z[k]<r-i+1) z[i]=z[k];
			else{
				l=i;
				while(r<n && s[r]==s[r-l]) r++;
				z[i]=r-l;
				r--;
			}
		}
	}
}
int num[1050005][27];
int ncnt[1050005];
int x[30];
ll ans;
int main(){
	//remember to use freopen!
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		n=strlen(s);
		get_z();
		int ha=0;
		for(int i=0;i<n;i++) ha+=z[i];
		z[0]=n;
		memset(x,0,sizeof(x));
		memset(num,0,sizeof(num));
		memset(ncnt,0,sizeof(ncnt));
		ans=0;
		for(int i=0;i<n;i++){
			if(i!=0){
				for(int j=0;j<=26;j++)
					num[i][j]+=num[i-1][j];
			}
			x[s[i]-'a']++;
			int cnt=0;
			for(int j=0;j<26;j++)
				if(x[j]%2!=0)
					cnt++;
			num[i][cnt]++;
		}
		for(int i=0;i<n;i++)
			for(int j=1;j<=26;j++)
				num[i][j]+=num[i][j-1];
		memset(x,0,sizeof(x));
		for(int i=n-1;i>=0;i--){
			x[s[i]-'a']++;
			int cnt=0;
			for(int j=0;j<26;j++)
				if(x[j]%2!=0)
					cnt++;
			ncnt[i]=cnt;
		}
		for(int i=2;i<n;i++){
			if(z[i]<i)
				ans+=num[i-2][ncnt[i]];
			else{
				ans+=num[i-2][ncnt[i]];
				int mx=z[i]/i+1;
				for(int rep=2;rep<=mx && rep*i<n;rep++)
					ans+=num[i-2][ncnt[rep*i]];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//remember to use long long or unsigned long long
//remember to clear the...array?
//remember to read problems carefully
//think carefully before writing
