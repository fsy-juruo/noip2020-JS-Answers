#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k,x;
int p[3005][3005];
int d[3005];
struct node
{
	int l,p,q;
}s[3005];
struct c
{
	int pp,qq;
}ans[3005];
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0

10 1
5 2 3 4 5 6
2 7 8
2 8 10
2 9 7
1 9
3 7 8 9
1 10
0
1 10
0
*/
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		for(j=1;j<=d[i];j++)
		{
			scanf("%d",&x);
			p[i][x]=1;
		}
	}
	i=j=1;
	s[i].l=1;
	s[i].p=1;
	s[i].q=1;
	while(i<=j)
	{
		
		for(k=1;k<=n;k++)
		{

			if(p[i][k])
			{
				j++;
				s[j].l=k;

				s[j].p=s[i].p;
				s[j].q=s[i].q*d[i];
			//cout<<s[j].q<<endl;
				int a=s[j].p;
				int b=s[j].q;
				//cout<<b<<endl;
				
				if(ans[k].qq==0)
				{
					ans[k].pp=a;
					ans[k].qq=b;	
				}
				else
				{
					//if(k==10)
					//cout<<a<<" "<<b<<endl;
					ans[k].pp=ans[k].pp*b+ans[k].qq*a;
					ans[k].qq=ans[k].qq*b;
					
					a=ans[k].pp;
					b=ans[k].qq;
					//if(k==10)
					//cout<<endl<<a<<" "<<b<<endl;
					int ll=(__gcd(a,b));
					a=a/ll;
					b=b/ll;
					ans[k].pp=a;
					ans[k].qq=b;
					s[j].p=a;
					s[j].q=b;
					s[s[j].l].p=a;
					s[s[j].l].q=b;
				}
			}
		}
		i++;
	}
	
	for(k=1;k<=n;k++)
	if(d[k]==0)
	{
		int a=ans[k].pp;
		int b=ans[k].qq;
		printf("%d %d\n",a,b);
	}
	return 0;
}
