#include<bits/stdc++.h>
using namespace std;
string st;
int i,t,j,p,k,num[100010],ans,a[100010][30];
int count(int x,int y)
{
  int sum[110],res=0;
  if(x==0)
  {
  	for(int i=1;i<=26;i++)
  	  if(a[y][i]%2==1)res++;
  	return res;
  }
  for(int i=1;i<=26;i++)
    if((a[y][i]-a[x-1][i])%2==1)res++;
  return res;
}
bool check(int x,int y)
{
  for(int i=0;i<=x;i++)
    if(st[i]!=st[y+i])return false;
  return true;
}
int main()
{
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  scanf("%d",&t);
  for(i=1;i<=t;i++)
  {
    char c=getchar();
    st.clear();
    while(!islower(c))c=getchar();
    while(islower(c)){st+=c;c=getchar();}
    //printf("%d\n",st.size());
    ans=0;
    memset(a,0,sizeof(a));
    for(j=0;j<st.size();j++)
      a[j][st[j]-'a'+1]=1;
    for(j=0;j<st.size();j++)
      for(k=1;k<=26;k++)
        a[j][k]+=a[j-1][k];
    for(k=1;k<st.size();k++)
      	num[k]=count(0,k-1);
    for(j=1;j<st.size()-1;j++)
    {
      p=i+1;
      //memset(num,0,sizeof(num));
      sort(num+1,num+j+1);
      //for(k=1;k<=j;k++)
      //  printf("%d ",num[k]);
      //printf("\n");
	  //printf("1\n");
      for(k=j+1;k<st.size();k=k+j+1)
      {
        int z=count(k,st.size()-1);
        //printf("%d\n",z);
        int l=0,r=j;
        while(l<r)
        {
          int mid=(l+r+1)/2;
          if(z>=num[mid])l=mid;else r=mid-1;
		}
		for(;l<j;l++)
		  if(num[l]!=num[l+1])break;
		if(num[1]>z)l=0;
		//printf("%d\n",l);
		ans+=l;
	    //printf("%d %d %d\n",j,k,l);
      	if(k+j+1>=st.size())break;
      	if(!check(j,k))break;
	  }
	}
	printf("%d\n",ans);
  }
  return 0;
}
