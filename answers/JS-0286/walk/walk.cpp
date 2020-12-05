#include<bits/stdc++.h>
using namespace std;

int c,d,way,maxw,minw,n,k,maxk,maxi,mini,ans;
int min_w[100010],max_w[100010],min_i[100010],max_i[100010],max_t,min_t;

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cout<<-1;
//	cin>>n>>k;
//	if(k == 1)
//	{
//		cin>>maxk;
//		for(int i = 1;i <= n;i++)
//		{
//			cin>>c>>d;
//			way += d;
//			if(maxw[max_t] < way)
//			{
//				max_t++;
//				max_w[max_t] = way;
//				max_i[max_t] = i;
//			}
//			if(minw[min_t] > way)
//			{
//				min_t++;
//				min_w[min_t] = way;
//				min_i[min_t] = i;
//			}
//		}
//		for(int i = 1;i <= k;i++)
//		{
//			if(way == 0)
//			{
//				cout<<-1;
//				break;
//			}
//			if(way > 0)
//			{
//				if(i + min_w[min_t] <= 0) re = mini;
//				else if(i + max_w[max_w] >= maxk) re = min(re,maxi);
//				else re = (maxk + 1 - maxw - i) / way + (bool)((maxk + 1 - maxw - i) % way != 0);
//			}
//			else
//			{
//				if(i + minw <= 0) ans += mini;
//				else if(i + maxi >= maxk) ans += maxi;
//				else ans += (0 - minw) / way + (bool)((0 - minw) % way != 0);
//			}
//			ans += re;
//			re = 0;
//		}
//	}
//	
	return 0;
}
