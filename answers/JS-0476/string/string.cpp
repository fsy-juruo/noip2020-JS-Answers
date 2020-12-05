#include<bits/stdc++.h>
using namespace std;
int t,cnt=1,cnt1=1,tmp;
string a;
//struct aaa
//{
//	int x,y,z;
//}temp[100000];
//bool cmp(aaa a,aaa b)
//{
//	if(a.x<=b.x)
//	{
//		if(a.x==b.x)
//		{
//			if(a.y<=b.y)
//			{
//				if(a.z<=b.y)
//				{
//					return 1;
//				}
//				return 1;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		return 1;
//	}
//	return 0;
//	
//}
int main()
{
	freopen("string.in","r",stdin);
	
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
////		a="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//		for(int i=1;i<=100;i++)
//		{
//			a.append("a");
//		}
		cin>>a;
//		for(int i=1;i<=a.length();i++)
//		{
//			printf("%c ",a[i]);
//		}
		int n=a.length();
//		printf("%d",n);
		printf("%d",n*(n-3)/2+2);
////		cout<<n;
//		for(int j=1;j<=n;j++)//c
//		{
//			for(int k=1;k<n-1;k++)
//			{
//				for(int m=1;m<n-1;m++)
//				{
//					if((k+m+j!=a.length())||(a.length()%(k+m+j)!=0)||(a.length()/(k+m+j)%2==0))
//					{
////						printf("fuck %d %d %d\n",j,k,m);
//						continue;
//					}
//					temp[cnt].x=j;
//					temp[cnt].y=k;
//					temp[cnt].z=m;
//					cnt++;
////					printf("%d %d %d\n",j,k,m);
//				}
//			}
//		}
//		sort(temp+1,temp+cnt+1,cmp);
//		for(int i=1;i<=cnt;i++)
//		{
//			if(temp[i].x>temp[i-1].x)
//			{
//				cout<<endl<<cnt1-tmp<<endl;
//				tmp=cnt1;
//			}
//			printf("%d %d %d\n",temp[i].x,temp[i].y,temp[i].z);
//			cnt1++;
//		}
//		printf("   %d",cnt);
//	}
	}
	return 0;
}
