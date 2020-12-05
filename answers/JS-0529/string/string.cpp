#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
char str[1048579];
int cur[27];
ll hash[1048579];
ll sig[1048579]={};
int base;
ll ans;
int sa,sc;
int len;
int T;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
scanf("%d",&T);
for(;T;--T)
	{
	ans=0LL;
	memset(str,0,sizeof(str));
	memset(cur,0,sizeof(cur));
	memset(sig,0,sizeof(sig));
	memset(hash,0,sizeof(hash));
	scanf("%s",str+1);
	len=strlen(str+1);
	sig[0]=1;
	int flag=0;
	for(int i=1;i<=len;++i)
	if(!cur[str[i]-97])cur[str[i]-97]=1,base=str[i]-96,++flag;
	/*if(flag==1)flageuqaltoone();
	else*/
		{
		for(int i=1;i<=len;++i)
			{
			hash[i]=(hash[i-1]*base+str[i]-97) ;
			sig[i]=(sig[i-1]*base) ;
			}
			
		//for(int i=1;i<=len;++i)
		//printf("hash:%lld sig:%lld\n",hash[i],sig[i]);
		//cout<<hash[i]<<" "<<sig[i]<<endl;	
			
			
		for(int p=2;p<len;++p)//ABi+C
			{
			if(p>(len+1)/2)//AB+C
				{
				sc=0;
				memset(cur,0,sizeof(cur));
				for(int i=p+1;i<=len;++i)//C
				++cur[str[i]-97];
				for(int i='a'-97;i<='z'-97;++i)
				sc+=cur[i]&1;
				for(int p1=1;p1<p;++p1)//A
					{
					sa=0;
					memset(cur,0,sizeof(cur));
					for(int i=1;i<=p1;++i)
					++cur[str[i]-97];
					for(int i='a'-97;i<='z'-97;++i)
					sa+=cur[i]&1;
					//printf("%d %d sa:%d sc:%d\n",p1,p,sa,sc);
					if(sa<=sc){++ans;}
					}
				}
			else
			//if(p<=(len+1)/2)
				{
				
				
				sc=0;
				memset(cur,0,sizeof(cur));
				for(int i=p+1;i<=len;++i)//C
				++cur[str[i]-97];
				for(int i='a'-97;i<='z'-97;++i)
				sc+=cur[i]&1;
				for(int p1=1;p1<p;++p1)//A
					{
					sa=0;
					memset(cur,0,sizeof(cur));
					for(int i=1;i<=p1;++i)
					++cur[str[i]-97];
					for(int i='a'-97;i<='z'-97;++i)
					sa+=cur[i]&1;
					//printf("%d %d sa:%d sc:%d\n",p1,p,sa,sc);
					if(sa<=sc){++ans;}
					}
				
				
				
				
				
				int sp=1;
				for(int i=2;i<=(len-1)/p;++i)
				{
				//printf("p:%d hp:%lld hp*i:%lld i:%d\n",p,hash[p],hash[p*i]%sig[p*(i-1)]/sig[p*(i-2)],i);
				
					if((hash[p*i]%sig[p*(i-1)])/sig[p*(i-2)]==hash[p]){sp=i;}else break;
				}
				
			//	printf("sp:%d\n",sp);
				
				
				for(int num=2;num<=sp;++num)
					{
					sc=0;
					memset(cur,0,sizeof(cur));
					for(int i=p*num+1;i<=len;++i)//C
					++cur[str[i]-97];					
					for(int i='a'-97;i<='z'-97;++i)
					{
					//printf("%c %d\n",i+97,cur[i]);
					if(cur[i]%2!=0)++sc;
					}
					for(int p1=1;p1<p;++p1)//A
						{
						sa=0;
						memset(cur,0,sizeof(cur));
						for(int i=1;i<=p1;++i)
						++cur[str[i]-97];
						for(int i='a'-97;i<='z'-97;++i)
						if(cur[i]%2!=0)++sa;
						//printf("%d %d sa:%d sc:%d num:%d\n",p1,p*num,sa,sc,num);
						if(sa<=sc){	++ans;}
						}					
							
					}
				
				}
			
			}
		
		}
	cout<<ans<<endl;
	}
return 0;
}

