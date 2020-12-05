#include<bits/stdc++.h>
using namespace std;
int n,sum[110000][26],a[110000],c[110000];
char s[110000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	for(int p=1;p<=t;p++){
	for(int i=0;i<=25;i++){
		sum[0][i]=0;
	}
	a[0]=0;
	string uuz;
	char s[110000];
	cin>>uuz;
	int n=uuz.size();
	for(int i=n;i>=1;i--){
		s[i]=uuz[i-1];
	}
	for(int i=1;i<=n;i++){
		c[i]=0;
		for(int j=0;j<26;j++)sum[i][j]=sum[i-1][j];
		sum[i][s[i]-'a']++;
		if(sum[i][s[i]-'a']%2)a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
	}
	c[n+1]=0;
	for(int i=n;i>=1;i--){
		for(int j=0;j<26;j++){
			if((sum[n][j]-sum[i-1][j])%2)c[i]++;
		}
	}

	
	int ans=0;
	for(int i=2;i<n;i++){
		int l=i+1;
		while(s[(l-1)%i+1]==s[l]&&l<n){
			l++;
		}
		l--;
		l/=i;
		l*=i;
		int sum1=0,sum2=0;
		int o=l+1;
		for(int j=1;j<i;j++){
			if(a[j]<=c[o])sum1++;
		}
		if(l/i>1){
			o-=i;
			for(int j=1;j<i;j++){
			if(a[j]<=c[o])sum2++;
		}
		}
		ans+=(l/i)/2*(sum1+sum2)+sum1*((l/i)%2);
		
	}
	cout<<ans<<endl;
	}
	
	return 0;
}

