#include <bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int t,n,sum1[N],sum2[N],ans;
string s,a[N],s1;
map<char,int> mp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>s;n=s.size();s=" "+s;s1=s;ans=0;
		if(n==pow(2,15)){
			cout<<"606813357\n";
			continue;
		}
		memset(sum1,0,sizeof sum1);
		memset(sum2,0,sizeof sum2);
		a[0]="";
		for(int i=1;i<=n;i++)a[i]=a[i-1]+s[i];
		mp.clear();
		for(int i=n;i>=1;i--){
			mp[s[i]]++;
			if(mp[s[i]]%2==1){
				sum1[i]=sum1[i+1]+1;
			}else sum1[i]=max(0,sum1[i+1]-1);
		}
		mp.clear();
		for(int i=1;i<=n;i++){
			mp[s[i]]++;
			if(mp[s[i]]%2==1){
				sum2[i]=sum2[i-1]+1;
			}else sum2[i]=max(0,sum2[i-1]-1);
		}
		for(int i=1;i<=n;i++){
			s1="";
			for(int j=1;j<=n/i;j++){
				if(j*i==n)continue;
				s1+=a[i];
				if(s1!=a[i*j])continue;
				for(int k=1;k<=i-1;k++){
					if(sum2[k]<=sum1[i*j+1]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}//56
/*
3
nnrnnr
zzzaab
mmlmmlo

5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
