#include<bits/stdc++.h>
using namespace std;
bool t[300];
int s[(1<<20)+5],s2[(1<<20)+5],ans;
string a;
int c(int x){
	return s2[x];
}
void ad(int q,int x)
{
	for(int i=0;i<=q;++i) 
	if(s[i]<=c(x)&&x!=a.size()){
//	if(s[q]<=c(x)){
		++ans;
		
		/*for(int j=0;j<=i;++j) cout<<a[j];cout<<' ';
		for(int j=i+1;j<=q+1;++j) cout<<a[j];cout<<' ';
		for(int j=x;j<a.size();++j) cout<<a[j];cout<<endl;*/
//		cout<<i+1<<' '<<q-i+1<<' '<<a.size()-x<<endl;
	}
}
bool cp(int q,int r)
{
	if(r+q>=a.size()-1) return 0;
	for(int i=0;i<=q;++i)
	if(a[i]!=a[i+r]) return 0;
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	while(n--){
		cin>>a;
		memset(t,0,sizeof(t));
		ans=0;
		s[0]=1;t[a[0]]=1;
		for(int i=1;i!=a.size();++i)
		{
			if(t[a[i]]) s[i]=s[i-1]-1;
			else s[i]=s[i-1]+1;
			t[a[i]]^=1;
		}
		memset(t,0,sizeof(t));
		s2[a.size()-1]=1;t[a[a.size()-1]]=1;
		for(int i=a.size()-2;i>=0;--i)
		{
			if(t[a[i]]) s2[i]=s2[i+1]-1;
			else s2[i]=s2[i+1]+1;
			t[a[i]]^=1;
		}
		for(int i=1;i<a.size();++i)
		{
			ad(i-1,i+1);
			
			int r=i+1;
			while(cp(i,r)){
				r+=i;
				ad(i-1,r);
			}
			
		}
		printf("%d\n",ans);
	}
	return 0;
}

