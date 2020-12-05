#include <bits/stdc++.h>
#define nwah cout<<"fuck"<<endl;
using namespace std;
int kase;  //case数量 
string s;  //input string
string a,b,c,ab; //string a,b, and c
int len; //the lenth of s
int cnt[3][27]; //a counter to count the num of a...z appeared in sequence a,b and c
int ji[3];
int len_ab,len_c,len_a,len_b;

void init1(int op)
{
	ji[2]=0;
	for(int i=0;i<27;i++) cnt[2][i]=0;
	len_c=0;
	for(int i=op;i<=len-1;i++) c[len_c++]=s[i];
	for(int i=0;i<len_c;i++)
	{
		int num=c[i]-'a';
		cnt[2][num]++;
	}
	for(int i=0;i<26;i++) if(cnt[2][i]%2==1) ji[2]++;
	
}
void init2()
{
	
	ji[0]=0;
	for(int i=0;i<27;i++) cnt[0][i]=0;
	for(int i=0;i<len_a;i++) a[i]=s[i];
	for(int i=0;i<len_a;i++)
	{
		int num=a[i]-'a';
		cnt[0][num]++;
	}
	for(int i=0;i<26;i++) if(cnt[0][i]%2==1) ji[0]++;
//	nwah
	len_b=len_ab-len_a;
	int cnt=0;
	for(int i=len_a;i<=len_ab-1;i++) b[cnt++]=s[i];
}
bool cmp(string x,string y,int lenx,int leny)
{
	if(lenx!=leny) return false;
	for(int i=0;i<lenx;i++) if(x[i]!=y[i]) return false;
	return true;
}
bool is_same()
{
	if(cmp(a,b,len_a,len_b)&&cmp(a,c,len_a,len_c)) return true;
	return false; 
}
void print(int x)
{
	if(x==0)
	{
		for(int i=-0;i<len_a;i++) cout<<a[i];
		cout<<" ";
	}
	else if(x==1)
	{
		for(int i=0;i<len_b;i++) cout<<b[i];
		cout<<" ";
		
	}
	else 
	{
		for(int i=0;i<len_c;i++) cout<<c[i];
		cout<<endl;
	}
}
int solve()
{
	int ans=0; //ans
	for(len_ab=2;len_ab<len;len_ab++)
	{
//		for(int i=0;i<len_ab;i++) ab[i]=s[i];//copy string ab
		for(int i=1;i*len_ab<len;i++)
		{
//			nwah
//			cout<<len_ab<<endl;
			string nxt;
			int cnt=0;
			for(int j=(i-1)*len_ab;j<i*len_ab;j++) nxt[cnt++]=s[j];
			if(!cmp(ab,nxt,len_ab,len_ab)) break;
			init1(i*len_ab);
	//		nwah
			for(len_a=1;len_a<len_ab;len_a++)
			{
//				nwah
				init2();
				if(ji[0]>=ji[2]) continue;
				if(is_same()) continue; //a==b==c
				ans++;
/*				print(0);
				print(1);
				print(2);*/
			}
//			nwah
		}
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>kase;
	for(int i=0;i<kase;i++)
	{
		cin>>s;
		len=s.size();
		cout<<solve()<<endl;
	}
	return 0;
}

/*#include <bits/stdc++.h>
#define nwah cout<<"fuck"<<endl;
using namespace std;
int kase;  //case数量 
string s;  //input string
string a,b,c,ab; //string a,b, and c
int len; //the lenth of s
int cnt[3][27]; //a counter to count the num of a...z appeared in sequence a,b and c
int ji[3];
int len_ab,len_c,len_a,len_b;

bool cmp(string x,string y,int lenx,int leny)
{
	if(lenx!=leny) return false;
	for(int i=0;i<lenx;i++) if(x[i]!=y[i]) return false;
	return true;
}
bool is_same()
{
	if(cmp(a,b,len_a,len_b)&&cmp(a,c,len_a,len_c)) return true;
	return false; 
}



void init()
{
	ji[0]=ji[2]=0;
	for(int i=0;i<27;i++) cnt[0][i]=cnt[2][i]=0;
	for(int i=0;i<len_c;i++)
	{
		int num=c[i]-'a';
		cnt[2][num]++;
	}
	for(int i=0;i<26;i++) if(cnt[2][i]%2==1) ji[2]++;
	for(int i=0;i<len_a;i++)
	{
		int num=a[i]-'a';
		cnt[0][num]++;
	}
	for(int i=0;i<26;i++) if(cnt[0][i]%2==1) ji[0]++;
}

int solve()
{
	int ans=0;
	int i=1;
	for(len_a=1;(len_a+len_b)*i<len;len_a++)
	{
		for(len_b=1;(len_a+len_b)*i<len;len_b++)
		{
			for(i=1;(len_a+len_b)*i<len;i++)
			{
				len_c=len-i*(len_a+len_b);
				int cnt=0;
				for(int j=i*(len_a+len_b);j<len;j++) c[cnt++]=s[j];
				cnt=0;
				for(int j=0;j<len_a;j++) a[cnt++]=s[j];
				cnt=0;
				for(int j=len_a;j<(len_a+len_b);j++) b[cnt++]=s[j];
				init();
				if(ji[0]>=ji[2]) continue;
				if(is_same()) continue;
				ans++;
			}
		}
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>kase;
	for(int i=0;i<kase;i++)
	{
		cin>>s;
		len=s.size();
		cout<<solve()<<endl;
	}
	return 0;
}*/
