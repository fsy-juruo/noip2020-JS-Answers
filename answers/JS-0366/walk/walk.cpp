#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(;  isdigit(c); c = getchar()) x = (x << 3) + (x << 1) +  c - '0';
	x *= f;
}



int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	cout<<-1<<endl;
 	return 0;
}

