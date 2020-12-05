//48
#include<bits/stdc++.h>
using namespace std;
const int N=1<<20,mod=19260817;
typedef unsigned long long ull;
typedef long long ll;
char s[N+10];
int t,num[28],pre[N+5],suf[N+5];
ull hash[N+10];
int check(int l1,int l2,int sz){
	for(int i=0;i<sz;i++)
	if(s[l1-1+i]!=s[l2-1+i]) return 0;
	return 1; 
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t){
		t--;
		memset(s,0,sizeof(s));
		memset(num,0,sizeof(num));
		scanf("%s",&s);
		int i=0,j,odd=0;
		while(s[i]>='a'&&s[i]<='z'){
			int p=s[i]-'a';
			num[p]++;
			if(num[p]%2){
				odd++;
				pre[i+1]=odd;
			}
			else {
				odd--;
				pre[i+1]=odd;
			}
			i++;
		}
		int len=i-1,ss=0;
		for(i=0;i<=25;i++)
		if(num[i]) ss++;
		if(ss==1){
			ll aaa=0;
			for(i=len-1;i>=0;i-=2) aaa+=i;
			for(i=2;i<=len-2;i+=2) aaa+=(len-i)/2;
			printf("%lld\n",aaa-1);
			continue;
		}
		odd=0;
		memset(num,0,sizeof(num));
		for(i=len;i>=0;i--){
			int p=s[i]-'a';
			num[p]++;
			if(num[p]%2){
				odd++;
				suf[i+1]=odd;
			}
			else {
				odd--;
				suf[i+1]=odd;
			}
		}
		for(i=1;i<=len+1;i++) hash[i]=hash[i-1]*mod+s[i-1];
		ll ans=0;
		for(i=2;i<=len+1;i++){
			bool flag=1;
			for(j=i;j<len+1;j+=i){
				if(!check(1,j-i+1,i)) {
					flag=0;
					break;
				}
			    int d=suf[j+1];
			    for(int k=1;k<i;k++)
			    if(pre[k]<=d) ans++;
			}
			//cout<<ans<<endl;
			/*if(!flag) continue;
			int d=suf[j-i+1];
			for(j=1;j<i;j++)
			if(pre[j]<=d) ans++;*/
		}
		printf("%lld\n",ans);
	}
	return 0;
}
