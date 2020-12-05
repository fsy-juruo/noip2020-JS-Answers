#include<bits/stdc++.h>
using namespace std;
int ans;
int ai[26];
int si[27][27];
int f(string a){
	int s=0;
	for(int i=0;i<a.length();i++)
		ai[a[i]-'a']++;
	for(int i=0;i<26;i++)
		if(ai[i]%2==1) s++;
	memset(ai,0,sizeof(ai));
	return s;
}
void che(string s,int ia,int ib){
	int k=0;
	string a,b,c,d;
	for(int i=0;i<=ia;i++)
		a+=s[i];
	for(int i=ia+1;i<=ib;i++)
		b+=s[i];
	for(int i=ib+1;i<=ib*2+1;i++)
		d+=s[i];
	string e;
	e=a+b;
	int cj;
	for(int i=ib+1;i<s.length();i++)
		cj+=s[i];
	c=cj;
	if(f(c)>=f(a))
			k++;
	if(d==e){
		int kb=ib*2+1;
		while(e==d&&kb+1<s.length()){
			string di,ci;
			for(int i=kb+1;i<s.length();i++)
				ci+=s[i];
			c=ci;
			if(f(c)>=f(a))
				k++;
			kb+=ib+1;
			for(int i=kb+1;i<=kb+ib;i++)
				di+=s[i];
			d=di;
		}
	}
	ans+=k;
	if(ib+1<s.length()){
		if(!si[ia+1][ib+1]) {che(s,ia+1,ib+1);si[ia+1][ib+1]=1;}
		if(!si[ia][ib+1]){che(s,ia,ib+1);si[ia][ib+1]=1;}
	}
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		che(s,0,1);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
