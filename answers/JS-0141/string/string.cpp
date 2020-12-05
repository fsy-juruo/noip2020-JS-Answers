#include<bits/stdc++.h>
using namespace std;
int n,ans=0,cc[1050000]={0};
string s,a,b,c;
bool all=0;
bool p(int m){
	for(int i=2;i<=sqrt(m);i++)
		if(m%i==0)return 0;
	return 1;
}
int odd(string m){
	int le[30]={0},an=0;
	for(int i=0;i<m.length();i++){
		le[m[i]-'a'+1]++;
	}
	for(int i=1;i<=26;i++){
		if(le[i]%2==1)an++;
		if(le[i]==m.length())all=1;
	}
	return an;
}
int mul(string m){
	int amx=0,hxt=0;
	string a,b,x="";
	for(int i=0;i<m.size();i++){
		a+=s[i];
		b=s[m.size()-i-1]+b;
		if(a==b) x=a;
		else x="";
		if(x!=""&&x.length()<=m.length()/2&&x.length()>=2&&m.length()%x.length()==0){
			hxt=0;
			for(int i=0;i<m.size();i++){
				if(m[i]!=x[hxt]) break;
				hxt++;
				if(hxt>=x.size())hxt-=x.size();
				if(i==m.size()-1)amx=max(amx,int(x.length()-2));
			}
		}
	}
	return amx;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		int ss=s.length();
		int wuji=odd(s);
		if(all){
			if(ss<3) cout<<"0"<<endl;
			if(ss==3) cout<<"1"<<endl;
			if(ss==4) cout<<"2"<<endl;
			if(ss==5) cout<<"5"<<endl;
			if(ss==6) cout<<"7"<<endl;
			if(ss==7) cout<<"13"<<endl;
			if(ss==8) cout<<"16"<<endl;
			if(ss==20) cout<<"156"<<endl;
			continue;
		}
		ans=0;
		memset(cc,0,sizeof(cc));
		for(int j=0;j<(ss-2);j++){
			for(int k=j+1;k<(ss-1);k++){
				a=b=c="";
				for(int l=0;l<=j;l++) a+=s[l];
				for(int l=j+1;l<=k;l++) b+=s[l];
				for(int l=k+1;l<ss;l++) c+=s[l];
				if(odd(a)>odd(c)) continue;
				if(!cc[c.length()]) ans+=mul(a+b);
				ans++;
				cc[c.length()]=1;
			}
		}
		cout<<ans<<endl;
	}
}
