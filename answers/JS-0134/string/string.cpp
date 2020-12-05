#include<bits/stdc++.h>
using namespace std;

bool Ad[27],Cd[27];   //true %2==1
int con_c=0,con_a=0;
char s[1048576+10];
long long ans=0;
int cnt;

inline void start(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}

inline int read(){

	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) 
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

inline void pre(){
	for(int i=0;i<=26;i++) Ad[i]=Cd[i]=0;
	con_c=0;
	con_a=0;
	ans=0;
}

inline bool check(int l,int len){
	char t[1048576+10];
	for(int i=1;i<=l;i++) t[i]=s[i];
	int base=l;
	while(base!=len)
	{
		for(int i=1;i<=l;i++) if(t[i]!=s[i+base]) return false;
		base+=l;
	}
	return true;
}

inline void work(int l,int x){

	//cout<<endl;
	bool flag1=false,flag2=false,flag3=false;
	con_a=0;
	for(int i=0;i<=26;i++) Ad[i]=0;
	for(int i=1;i<l;i++)
	{
		Ad[s[i]-'a'+1]=!Ad[s[i]-'a'+1];
		if(Ad[s[i]-'a'+1]) con_a++;
		else con_a--;
		
		//cout<<i<<" "<<l-i<<" "<<x<<endl;
		//cout<<i<<" "<<con_a<<endl;
		
		/*if(i==l-i) 
		{
			flag1=true;
			for(int j=1;j<=i;j++) 
			{
				if(s[j]!=s[i+j])
				{
					flag1=false;
					break;
				}
				
			}
			if(flag1) cout<<"Delete1:"<<i<<endl;
		}//1--2
		
		if(i==x)
		{
			flag2=true;
			for(int j=1;j<=i;j++)
			{
				if(s[j]!=s[cnt-x+j])
				{
					flag2=false;
					break;
				}
			}	
			if(flag2) cout<<"Delete2:"<<i<<endl;
		}//1--3
		
		if(l-i==x)
		{
			flag3=true;
			for(int j=1;j<=l-i;j++)
			{
				if(s[i+j]!=s[cnt-x+j])
				{
					flag3=false;
					break;
				}
			}	
			if(flag3) cout<<"Delete3:"<<i<<endl;
		}
		
		
		
		if(flag1||flag2||flag3) continue;*/
		
		
		
		if(con_a<=con_c) ans++;
	}
	//cout<<ans<<endl;
}

int main()
{
	start();
	int T;
	T=read();
	for(int z=1;z<=T;z++)
	{
		pre();
		cnt=0;
		char c;
		while(c=getchar())
		{
			if(c=='\n') break;
			s[++cnt]=c;
		}
		for(int x=cnt;x>2;x--)
		{
			Cd[s[x]-'a'+1]=!Cd[s[x]-'a'+1];
			if(Cd[s[x]-'a'+1]) con_c++;
			else con_c--;
			//cout<<x<<" "<<con_c<<"|";
			for(int i=1;i<x;i++) if((x-1)%i==0) if((x-1)/i>=2) if(check((x-1)/i,x-1)) work((x-1)/i,cnt-x+1);
			//cout<<endl;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
