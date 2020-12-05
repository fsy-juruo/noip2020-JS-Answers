#include<bits/stdc++.h>
using namespace std;
const int N=1048576;
const int M=1e5+5;
int ans;
int h[N],ha[N];
string s;
int lenth;
bool pd(string n) 
{
	for(int i=0;i<n.size();i++) 
		if(n[i]!=s[i]) return 0;
	return 1;
}
void check(string str) 
{
	string sum="";
	for(int i=1;i<=lenth;i++) 
	{
		sum=sum+str;
		memset(h,0,sizeof(h));
		memset(ha,0,sizeof(ha));
		if(pd(sum)) 
		{
			if(sum.size()<s.size()&&sum.size()>1)
			{
				string sc="";
				for(int j=sum.size();j<=s.size();j++) 
				{
					sc=sc+s[j];
					h[int(s[j]-'a')]++;	
				}
				int num=0;
				for(int j='a'-'a';j<='z'-'a';j++) if(h[j]%2==1) num++;
				int a=0;
	//			if(sum.size()==5) cout<<num<<endl;
				string sa="",sb=str;
				for(int j=0;j<str.size()-1;j++)
				{
					sa=sa+str[j];
					sb.erase(0,1);
					ha[int(str[j]-'a')]++;
					if(ha[int(str[j]-'a')]%2==1) a++;
					else a--;
//					cout<<sa<<" "<<sb<<" "<<sc<<endl;
//					if(sa==sb) f=false;
//					if(sa==sc) f=false;
//					if(sb==sc) f=false;
					if(a<=num) ans++;
				}
			}
		}	
		else break;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>s;
		ans=0;
		bool f=true;
		lenth=s.size();
		for(int i=0;i<lenth;i++) if(s[i]!=s[i-1]) f=false;
		if(f==true&&s.size()>5000) 
		{
			 
		}
		for(int i=0;i<lenth;i++)
		{
			str=str+s[i];
//			cout<<str.size()<<" "<<s.size()<<endl;
			check(str);
		}
		cout<<ans<<endl;
	}
	return 0;
}

