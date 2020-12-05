#include<bits/stdc++.h>
#define re register
using namespace std;
template<typename T> void fr(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+c-48;
	x*=f;
}
int t,ans;
string s;
inline int f(int x,int y)
{
	int a[30],result=0;
	for(int i=1;i<=30;i++)a[i]=0;
	for(int i=x;i<=y;i++)a[s[i]-'a'+1]++;
	for(int i=1;i<=28;i++)if(a[i]%2==1)result++;
	return result;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	fr(t);
	for(int i=1;i<=t;i++)
	{
		ans=0;
		cin>>s;
		for(re int j=0;j<s.length()-2;j++){
			for(re int k=j+1;k<s.length()-1;k++){
				for(re int l=k+1;l<s.length()-1;l++){
					if(s[l]!=s[l-k-1])break;
					if((l+1)%(k+1)==0&&f(0,j)<=f(l+1,s.length()-1)){
						ans++;;
					}
				}
				if(f(0,j)<=f(k+1,s.length()-1)){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

