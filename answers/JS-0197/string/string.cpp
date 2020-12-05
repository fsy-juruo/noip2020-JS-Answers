#include<bits/stdc++.h>
using namespace std;
char s[80000];
int jsqian[1015],jshou[1015],copyy[1015];
set<char>s1;
set<char>s2;
long long ans=0;
int T;
bool pd(int x,int y,int p,int q)
{
	if(q>=strlen(s)-1)return 0;
	int cha;cha=p-x;
	for(int i=x;i<=y;i++)if(s[i]!=s[i+cha])return 0;
	return 1;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	scanf("%d",&T);
	for(int xxx=1;xxx<=T;xxx++)
	{
		scanf("%s",s);
		int str=strlen(s);
		if(str<=1003)
		{
			jsqian[0]=1;s1.insert(s[0]);
			for(int i=1;i<str;i++)
			{
				char c;c=s[i];
				if(s1.find(c)!=s1.end()){s1.erase(c);jsqian[i]=jsqian[i-1]-1;}
				else{s1.insert(c);jsqian[i]=jsqian[i-1]+1;}
			}
			for(int i=str-1;i>=0;i--)
			{
				char c;c=s[i];
				if(s2.find(c)!=s2.end()){s2.erase(c);jshou[i]=jshou[i+1]-1;}
				else{s2.insert(c);jshou[i]=jshou[i+1]+1;}
			}
			for(int i=1;i<str;i++)
			{
				for(int j=1;;j++)
				{
					bool tf;tf=pd(0,i,(j-1)*(i+1),j*(i+1)-1);
					if(!tf)break;
					if(tf)copyy[i]++;
					//if()
				}
			}
///			for(int i=0;i<str;i++)printf("%d ",jsqian[i]);printf("\n");
//			for(int i=0;i<str;i++)printf("%d ",jshou[i]);printf("\n");
//			for(int i=0;i<str;i++)printf("%d ",copyy[i]);printf("\n");
			for(int i=0;i<str-2;i++)
			{
				for(int j=i+1;j<str-1;j++)
				{
                    for(int k=1;k<=copyy[j];k++)
                    {
                    	if(jsqian[i]>jshou[(1+j)*k])continue;
                    	ans++;
					}
//					for(int )
				}
			}
			printf("%lld\n",ans);
			for(int i=0;i<=str;i++)jsqian[i]=jshou[i]=copyy[i]=s[i]=0;
			ans=0;
			s1.clear();s2.clear();
//			    getchar();getchar();getchar();getchar();
		}
        if(str>1003)
        {
        	for(int i=0;i+2<=str-1;i++)
        	{
        		if((i+1)&1)ans+=(str-i-1)/2;
        		else ans+=(str-i-1);
			}
			printf("%lld\n",ans);
			for(int i=1;i<=str;i++)s[i]=0;
			ans=0;
		}
	}
}
/*
3
nnrnnr
zzzaab
mmlmmlo

5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
