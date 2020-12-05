#include<bits/stdc++.h>
using namespace std;
char chll;bool flagp=0;int n;
string s;int cnt[200],ct[200];
int ans=0;
void sc(int &axp)
{
	axp=0;
	flagp=0;chll=getchar();
	while(!isdigit(chll)){if(chll=='-')flagp=1;chll=getchar();}
	while(isdigit(chll)){axp=(axp<<1)+(axp<<3)+(chll-48);chll=getchar();}
	if(flagp)axp=-axp;
	return ;
}
void pr(int axp)
{
	if(axp==0) return ;
	if(axp<0){putchar('-');axp=-axp;}
	pr(axp/10);
	putchar(axp%10+'0');
	return ;
}
 void gt(string &str)
{
	str="";
	while(chll=getchar(),chll!='\n')str.push_back(chll);
	return ;
}

void work()
{
	memset(cnt,0,sizeof(cnt));
	ans=0;
	int l=s.size();
	int op1=0,op2=0;
	for(int i=0;i<l-2;i++)
	{
		if(cnt[s[i]]%2==0)op1++;
		else op1--;
		cnt[s[i]]++;
		for(int k=i+2;k<l;k++){
			op2=0;memset(ct,0,sizeof(ct));
			for(int j=k;j<l;j++){
			//	cout<<s[j]<<" ";
				if(ct[s[j]]%2==0)op2++;
				else op2--;
				ct[s[j]]++;
			}//cout<<endl;
			//cout<<i<<" "<<k<<" "<<op1<<" "<<op2<<endl;
			if(op2<op1)continue;
			ans++;	
		}
		
	}
	cout<<ans<<endl;
	return ;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
/*	int n=0;
	int x=17,y=9;
	for(int i=1;i<=18;i++)if(i%2==0)n+=x,x-=2;else n+=y,y-=2;
	cout<<n<<endl;*/
	sc(n);
	for(int i=1;i<=n;i++){
	gt(s);work();	
	}
	/*int ans=0;int k;
	while(sc(k),k!=100000)
	ans+=k;
	cout<<ans<<endl;*/
	return 0;
}
