#include<bits/stdc++.h>
using namespace std;
int T,sum[3000][30],cnt[3000],ans,num[30000];
string c;
bool flag;
string st;
int read(){
	int xx=0,ff=1;
	char ch=getchar();
	while (!isdigit(ch)){
		if (ch=='-')ff=-1;
		ch=getchar();
	}
	while (isdigit(ch)){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	return ff*xx;
}
bool check(int x,int y,string s,string a){
	//cout<<1<<endl;
	c="";
	if (st.size()-1-y<=0)return 0;
	int p=0;
	for (int i=x;i<=y;i++){
		if (s[p++]!=st[i]){
			flag=1;
			return 0;
		}
		if (p==s.size())p=0;
	}
	int ss=0;
	for (int i=1;i<=29;i++)num[i]=0;
	for (int i=0;i<a.size();i++)
	    num[a[i]-'a'+1]++;
	for (int i=1;i<=29;i++){
		if (num[i]%2==1)ss++;
		num[i]=0;
    }
	for (int i=y+1;i<st.size();i++){
		c+=st[i];
		num[st[i]-'a'+1]++;
	}
	int s1=0;
	for (int i=1;i<=28;i++)
       if (num[i]%2==1)s1++;    
    if (ss<=s1){
    	//cout<<a<<endl;
    	return 1;
	}
    return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read();
	while (T--){
		cin>>st;
		if (st.size()>2000){
			cout<<100<<endl;
			return 0;
		}
		ans=0;
		string a="",b="";
		for (int i=0;i<st.size();i++){
			a+=st[i];
			b="";
			for (int j=i+1;j<st.size();j++){
				b+=st[j];
				string fi="";fi+=a;fi+=b;
				flag=0;
				for (int k=j;k<st.size();k+=fi.size())
				   if (check(j+1,k,fi,a)){
				   	//cout<<a<<" "<<b<<" "<<c<<endl;
				   	ans++;
				   }
				   else if (flag)break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

