#include<bits/stdc++.h>
using namespace std;
inline int read(){
	   int x=0,f=1;char ch=getchar();
	   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	   while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	   return x*f;
}
string s;
int w[1100000][27];
int getf1(int x){
	int cnt=0;
	for(int i=1;i<=26;i++){
		if(w[x][i]%2==1){
			cnt++;
		}
	}
	return cnt;
}
int getf2(int x){
	int cnt=0;
	for(int i=1;i<=26;i++){
		if((w[s.size()][i]-w[x-1][i])%2==1){
			cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T,cnt,flag,cb;
	long long ans;
	T=read();
	while(T--){
		cin>>s;
		for(int i=1;i<=26;i++){
			w[0][i]=0;
		}
		for(int i=0;i<s.size();i++){
			for(int j=1;j<=26;j++){
				w[i+1][j]=w[i][j];
			}
			w[i+1][s[i]-'a'+1]++;
		}
		ans=0;
		for(int i=1;i<=s.size()-2;i++){
			for(int j=i+1;j<=s.size()-1;j++){
				cnt=0;
				while(1){
					cb=(cnt+1)*j+1;
					if(cb>s.size()){
						break;
					}
					if(getf1(i)<=getf2(cb)){
						ans++;
					}
					flag=1;
					for(int k=cb;k<=cb+j-1;k++){
						if(s[k-1]!=s[k-cb]){
							flag=0;
							break;
						}
					}
					if(flag==0){
						break;
					}
					cnt++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

