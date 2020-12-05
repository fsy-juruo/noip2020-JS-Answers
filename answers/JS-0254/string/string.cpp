#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int toup(int x,int y){
	if(x%y==0)return x/y;
	else return x/y+1;
}
int alpa1[30],alpa2[30];
bool pd(int a,int b,int c,int k){
	memset(alpa1,0,sizeof(alpa1));
	memset(alpa2,0,sizeof(alpa2));
	int tot1=0;int tot2=0;
	for(int i=0;i+a+b<s.size()-c;i++){
		if(s[i]!=s[i+a+b])return 0;
	}
	for(int i=0;i<a;i++){
		alpa1[s[i]-'a']++;
	}
	for(int i=s.size()-1;i>=s.size()-c;i--){
		alpa2[s[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(alpa1[i]%2==1)tot1++;
	}
	for(int i=0;i<26;i++){
		if(alpa2[i]%2==1)tot2++;
	}
	return tot1<=tot2;
}
int work(int n){
	int ans=0;
	for(int k=1;k*3<=n;k++){
		int star=toup(n,k)-3;
		int en=1;
		if(star==0)continue;
		if(star%2==0)en=2;
		ans+=(star+en)*((star-en)/2+1)/2;
	}
	int star2=n-3;
	for(int k=1;k*3<n;k+=2){
		int gc=k*2;
		int en=star2;
		while(en-gc>0)en-=gc;
		int num=(star2-en)/gc+1;
		ans+=(num+1)*num/2;
		star2-=6;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;
		int n=s.size();
		bool flg=1;
		for(int i=1;i<s.size();i++){
			if(s[i]!=s[0])flg=0;
		}
		if(flg){
			cout<<work(n)<<endl;
			continue;
		}
		int ans=0;
		for(int k=1;k<=n;k++){//cishu
			for(int a=1;a<=n;a++){
				for(int b=1;b<=n;b++){
					int c=n-(a+b)*k;
					if(c<=0)break;
					if(pd(a,b,c,k)){
						ans++;	
					}			
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

