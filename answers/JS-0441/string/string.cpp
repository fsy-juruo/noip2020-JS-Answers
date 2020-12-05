#include<bits/stdc++.h>
using namespace std;
int t;
int n;
string s;
int cnt[26];
int pre[(1<<20)+1];
int precnt[(1<<20)+1][26];
int f(int x,int y){
	int ccnt[26];
	int ans=0;
	for(int i=x;i<=y;i++){
		ccnt[i]=precnt[y][i]-precnt[x-1][i];
		if(ccnt[i]%2) ans++;
	}
	return ans;
}
void solve(){
	memset(cnt,0,sizeof(cnt));
	memset(pre,0,sizeof(pre));
	memset(precnt,0,sizeof(precnt));
	cin>>s;
	n=(int)s.length();
	for(int i=0;i<n;i++){
		for(int j=0;j<26;j++){
			precnt[i+1][j]=precnt[i][j];
		}
		if(cnt[s[i]-'a']%2==0){
			pre[i+1]=pre[i]+1;
		}
		else pre[i+1]=pre[i]-1;
		cnt[s[i]-'a']++;
		precnt[i+1][s[i]-'a']++;
	}
	memset(cnt,0,sizeof(cnt));
	int ans=0;
	int co=0;
	for(int i=n-1;i>=2;i--){
		if(cnt[s[i]-'a']%2==0){
			co++;
		}
		else co--;
		cnt[s[i]-'a']++;
		for(int j=1;j<=i-1;j++){
			if(pre[j]>co) continue;
			for(int k=1;k<=i/2;k++){
				if(i%k) continue;
				int b=i/k-j;
				if(b<=0) continue;
				bool flag2=true;
				for(int l=i/k;l<i;l+=i/k){
					bool flag=true;
					for(int m=l;m<l+j;m++){
						if(s[m]!=s[m-l]){
							flag=false;
							break;
						}
					}
					if(!flag){
						flag2=false;
						break;
					}
				}
				if(!flag2) continue;
				for(int l=i/k+j;l<i;l+=i/k){
					bool flag=true;
					for(int m=l;m<l+b;m++){
						if(s[m]!=s[m-l+j]){
							flag=false;
							break;
						}
					}
					if(!flag){
						flag2=false;
						break;
					}
				}
				if(flag2) ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--) solve();
}

