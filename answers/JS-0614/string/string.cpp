#include<bits/stdc++.h>
using namespace std;
int T;
long long ans;
string s,a,b,c;
int num[30],num1,num3;
bool check1(int len1,int len2,int k){
	int i;
	for(i=0;i<len1+len2;i++)
		if(s[i]!=s[(len1+len2)*(k-1)+i])
			return 0;
	return 1;
}
bool check2(int len1,int len2,int k){
	int i;
	int n=s.size(),len3;
	len3=n-(len1+len2)*k;
	num1=num3=0;
	for(i=0;i<len1;i++)
		num[s[i]-'a']++;
	for(i=0;i<26;i++){
		if(num[i]%2==1)
			num1++;
		num[i]=0;
	}
	for(i=n-len3;i<n;i++)
		num[s[i]-'a']++;
	for(i=0;i<26;i++){
		if(num[i]%2==1)
			num3++;
		num[i]=0;
	}
	if(num1<=num3)
		return 1;
	return 0;
}
void solve1(){
	int n=s.size();
	int len1,len2,i;
	for(len1=1;len1<=n;len1++)
		for(len2=1;len2<=n;len2++)
			for(i=1;i*(len1+len2)<n;i++){
				if(!check1(len1,len2,i))
					break;
				if(check2(len1,len2,i))
					ans++;
			}
	printf("%lld\n",ans);
}
void init(){
	ans=0;
}
void solve2(){
	int n,m;
	register int i,len;
	n=s.size();
	for(len=1;len<=n-2;len++){
		m=n-len;
		if(len%2==1){
			ans+=m-1;
			for(i=2;i*i<=m;i++)
				if(m%i==0)
					if(i*i==m)
						ans+=i-1;
					else
						ans+=i+m/i-2;
		}
		else{
			ans+=(m-1)/2;
			for(i=2;i*i<=m;i++)
				if(m%i==0)
					if(i*i==m){
						if(i%2==0)
							ans+=i/2-1;
						else
							ans+=(i-1)/2;
					}
					else{
						if(i%2==0)
							ans+=i/2-1;
						else
							ans+=(i-1)/2;
						i=m/i;
						if(i%2==0)
							ans+=i/2-1;
						else
							ans+=(i-1)/2;
						i=m/i;
					}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	char c;
	bool flag=0;
	while(T--){
		init();
		cin>>s;
		c=s[0];
		for(int i=1;i<s.size();i++)
			if(s[i]!=c)
				flag=1;
		if(s.size()<=100||(s.size()<=1000&&flag)){
			solve1();
			continue;
		}
		if(!flag){
			solve2();
			continue;
		}
	}
	return 0;
}
