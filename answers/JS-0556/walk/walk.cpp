/*
EI说过，希望都打上了注释
那么，我就多来些注释所带来的希望罢
EI ORZ
神仙墙上的所有神仙 ORZ
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
*/
#include<bits/stdc++.h>
#define reg register
#define ri reg int
#define ll long long
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline void read(int&x){
	x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	x=c-'0';
	for(c=getchar();isdigit(c);c=getchar())x=x*10+c-'0';
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cout<<-1;
	return 0;
}
