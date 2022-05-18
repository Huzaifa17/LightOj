#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[100005];
ll tree[400505];

void init(ll node,ll left,ll right)
{
	if(left==right)
	{
		tree[node]=arr[left];
		return ;
	}
	ll mid=(left+right)/2;
	init(2*node,left,mid);
	init(2*node+1,mid+1,right);
	tree[node]=tree[2*node]+tree[2*node+1];
	return ;
}


ll query(ll node,ll i,ll j,ll left,ll right)
{
	if(left>j||right<i)
	{
		return 0;
	}
	if(left>=i&&right<=j)
	{
		return tree[node];
	}
	ll mid=(left+right)/2;
	ll sl=query(2*node,i,j,left,mid);
	ll sr=query(2*node+1,i,j,mid+1,right);
	return sl+sr;
}

void update(ll node,ll left,ll right,ll idx,ll val)
{
	if(left>idx||right<idx)//idx > right || idx < left
	{
		return ;
	}
	if(left==right)
	{
		//cout<<"range: "<<left<<endl;
		//cout<<"node: "<<node<<endl;
		//cout<<"p1: "<<tree[node]<<endl;
		tree[node]=val;
		//cout<<"p2: "<<tree[node]<<endl;
		return ;
	}
	ll mid=(left+right)/2;
	update(2*node,left,mid,idx,val);
	update(2*node+1,mid+1,right,idx,val);
	tree[node]=tree[2*node]+tree[2*node+1];
	return ;
}

void update2(ll node,ll left,ll right,ll idx,ll val)
{
	if(left>idx||right<idx)
	{
		return ;
	}
	if(left==right)
	{
		//cout<<tree[node]<<endl;
		tree[node]=0;
		return ;
	}
	ll mid=(left+right)/2;
	update2(2*node,left,mid,idx,val);
	update2(2*node+1,mid+1,right,idx,val);
	tree[node]=tree[2*node]+tree[2*node+1];
	return ;
}

void solve()
{
	ll i,j,k,n,m,t,l;
	// here write the code
	cin>>n>>t;
	tree[4*n+50]={0};
	arr[n+1]={0};
	for(i=1;i<=n;++i)
	{
		cin>>arr[i];
	}
	init(1,1,n);
	/*for(i=1;i<=15;++i)
	{
		cout<<"i: "<<i<<"val: "<<tree[i]<<endl;
	}*/
	for(i=0;i<t;++i)
	{
		cin>>m;
		if(m==1)
		{
			cin>>k;
			k++;
			l=query(1,k,k,1,n);
			cout<<l<<endl;
			arr[k]=0;
			update2(1,1,n,k,0);
		}
		else if(m==2)
		{
			cin>>k>>l;
			k++;
			arr[k]+=l;
			//cout<<"arr: "<<arr[k]<<endl;
			update(1,1,n,k,arr[k]);
		}
		else
		{
			cin>>k>>l;
			k++;
			l++;
			ll val=query(1,k,l,1,n);
			cout<<val<<endl;
		}
	}
	return ;
}

int main()
{
	//freopen("Test_input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ll n,i,j,k,m,t;
	cin>>t;
	for(i=0;i<t;++i)
	{
		cout<<"Case "<<i+1<<":"<<endl;
		solve();
	}
	return 0;
}
