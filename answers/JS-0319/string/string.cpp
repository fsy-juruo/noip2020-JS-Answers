#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int sum=0,fh=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') fh=-1; ch=getchar();}
	while(isdigit(ch)){if(sum==214748364&&fh==-1&&ch=='8'){sum=-2147483638; fh=1;} else sum=sum*10+ch-'0'; ch=getchar();}
	return sum*fh;
}
inline void write(int x){
	if(x==0){putchar('0');return ;}stack<char>s;
	if(x==INT_MIN){s.push('8');x=-214748364;}
	if(x<0)putchar('-');x=abs(x);
	while(x){s.push(char(x%10+'0')); x/=10;}
	while(!s.empty()){putchar(s.top()); s.pop();}
}
int f(string st)
{
	bool h[100];
	memset(h,false,sizeof(h));
	for(int i=0;i<st.size();i++)
	{
		h[st[i]-96]=!h[st[i]-96];
	}
	int ans=0;
	for(int i=1;i<=26;i++)
	{
		if(h[i]==true)
		{
			ans++;
		}
	}
	return ans;
}
map<pair<string,pair<string,string> >,bool> h;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t=read();
	while(t)
	{
		h.clear();
		string st,st1="";
		cin>>st;
		int ans=0;
		st1=st[0];
		for(int i=1;i<st.size()-1;i++)
		{
			st1+=st[i];
			int wz=(st.size()-1)-((st.size()-1)%(i+1));
		//	cout<<i<<' '<<((st.size()-1)-((st.size()-1)%(i+1)))<<endl;
			for(int j=i+1;j<((st.size()-1)-((st.size()-1)%(i+1)));j++)
			{
				if(st[j]!=st[j%(i+1)])
				{
			//		cout<<j<<' '<<j%(i+1)<<endl;
					wz=j/(i+1)*(i+1);
					break;
				}
			}
	//		cout<<wz<<endl;
			for(int k=wz;k>=2;k-=(i+1))
			{
				string stc=st.substr(k,st.size()-k);
		//		cout<<'*'<<stc<<endl;
				for(int j=1;j<st1.size();j++)
				{
					string sta,stb;
					sta=st1.substr(0,j);
					stb=st1.substr(j,st1.size()-j);
					if(f(sta)<=f(stc)&&!h[make_pair(sta,make_pair(stb,stc))])
					{
				//		cout<<sta<<' '<<stb<<' '<<stc<<endl;
						h[make_pair(sta,make_pair(stb,stc))]=true;
						ans++;
					}
				}
			}
		}
		write(ans);
		putchar('\n');
		t--;
	}
	return 0;
}
