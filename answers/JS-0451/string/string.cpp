#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
const int maxn=10001;
using namespace std;
int t,n,m;
map <char,int> v[maxn];
string stf(string x,int num) {
	string s;
	while(num--)
		s+=x;
	return s;
}
int arr[7]={0,1,3,5,7,9,11},tree[maxn*4];
void bt(int node,int l,int r){
	if(l==r){
		tree[node]=arr[l];
		return;
	}
	int mid=(l+r)>>1;
	int L=node*2,R=node*2+1;
	bt(L,l,mid),bt(R,mid+1,r);
	tree[node]=tree[L]+tree[R];
}

void data(int node,int acr,int vab,int l,int r){
	if(l==r){
		tree[node]=vab;
		return;
	}
	int mid=(l+r)>>1;
	int L=2*node,R=2*node+1;
	if(acr<=mid) data(L,acr,vab,l,mid);
	else data(R,acr,vab,mid+1,r);
	tree[node]=tree[L]+tree[R];
}

int add(int node,int st,int ed,int l,int r){
	if(st<=l&&ed>=r) return tree[node];
	if(l>ed||r<st) return 0;
	if(l==r) return tree[node];
	int mid=(l+r)>>1;
	int L=2*node,R=2*node+1;
	int addl=add(L,st,ed,l,mid),addr=add(R,st,ed,mid+1,r);
	return addl+addr;
}
//bool bt;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	memset(v,0,sizeof(v));
	for(int i(1); i<=t; ++i) {
		string s;
		cin>>s;
	}
	return 0;
}
//b k l;
