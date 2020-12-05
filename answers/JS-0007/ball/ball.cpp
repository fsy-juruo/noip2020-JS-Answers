#include<bits/stdc++.h>
using namespace std;
int a[55][200010],tp[55],n,m;
stack<pair<int,int> >st;
//int zhishao()
//{
//	int ma[55]={0};
//	for(int i=1;i<=n+1;i++)
//		for(int j=1;j<=n;j++)
//			ma[j]=max(ma[j],b[i][j]);
//	int s=0;
//	for(int i=1;i<=n;i++)
//		s+=m-ma[i];
//	return s;
//}
//bool check()
//{
//	int s=0;
//	for(int i=1;i<=n+1;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			if(b[i][j]==m)
//				s++;
////	printf("%d %d\n",maxdep,b[i][j]);
//		}
//	}
//	return s==n;
//}
void prnt(int dep)
{
	if(st.empty())return;
	int t1=st.top().first,t2=st.top().second;
	st.pop();
	prnt(dep+1);
	cout<<t1<<' '<<t2<<endl;
}
//void dfs(int dep)
//{
//	if(check())
//	{
//		cout<<st.size()<<endl;
//		prnt(1);
//		exit(0);
//	}
////	prnt();
////cout<<dep<<endl;
////		for(int i=1;i<=n+1;i++)
////		{
////			for(int j=1;j<=tp[i];j++)
////				cout<<a[i][j]<<' ';
////			cout<<endl;
////		}
////	cout<<endl;
////	printf("%d\n",maxdep);
//	for(int i=1;i<=n+1;i++)
//	{
//		if(tp[i]!=0)
//		{
//			for(int j=1;j<=n+1;j++)
//			{
//				if(i==j)continue;
//				if(tp[j]>=m)continue;
//				int t=a[i][tp[i]];
//				b[i][t]--;
//				b[j][t]++;
//				tp[i]--;
//				a[j][++tp[j]]=t;
////				printf("%d\n",zhishao());
//				if(zhishao()+(int)st.size()+1<=maxdep)
//				{
//					st.push(make_pair(i,j));
//					dfs(dep+1);
//					st.pop();
//				}
//				tp[j]--;
//				a[i][++tp[i]]=t;
//				b[j][t]--;
//				b[i][t]++;
//			}
//		}
//	}
//}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][++tp[i]];
		}
	}
//	if(n==2)
//	{
//		while(tp[1])
//		{
//			if(a[1][tp[1]]==1)
//			{
//				a[2][++tp[2]]=1;
//				st.push(make_pair(1,2));
//			}
//			else
//			{
//				a[3][++tp[3]]=2;
//				st.push(make_pair(1,3));
//			}
//			tp[1]--;
//		}
//		while(tp[2])
//		{
//			if(a[2][tp[2]]==1)
//			{
//				a[1][++tp[1]]=1;
//				st.push(make_pair(2,1));
//			}
//			else
//			{
//				a[3][++tp[3]]=2;
//				st.push(make_pair(2,3));
//			}
//			tp[2]--;
//		}
//		cout<<st.size()<<endl;
//		prnt(1);
//		return 0;
//	}
	while(tp[1])
	{
		if(a[1][tp[1]]==1)
		{
			a[n+1][++tp[n+1]]=1;
			st.push(make_pair(1,n+1));
		}
		else
		{
			a[a[1][tp[1]]][++tp[a[1][tp[1]]]]=a[1][tp[1]];
			st.push(make_pair(1,a[1][tp[1]]));
		}
		tp[1]--;
	}
	for(int i=2;i<=n;i++)
	{
		while(tp[i])
		{
			if(a[i][tp[i]]==1)
			{
				a[n+1][++tp[n+1]]=1;
				st.push(make_pair(i,n+1));
			}
			else if(a[i][tp[i]]<=i)
			{
				a[a[i][tp[i]]-1][++tp[a[i][tp[i]]-1]]=a[i][tp[i]];
				st.push(make_pair(i,a[i][tp[i]]-1));
			}
			else
			{
				a[a[i][tp[i]]][++tp[a[i][tp[i]]-1]]=a[i][tp[i]];
				st.push(make_pair(i,a[i][tp[i]]));
			}
			tp[i]--;
		}
	}
	cout<<st.size()<<endl;
	prnt(1);
//	for(maxdep=1;maxdep<=820000;maxdep++)
//	{
//		dfs(1);
//	}
	return 0;
}

