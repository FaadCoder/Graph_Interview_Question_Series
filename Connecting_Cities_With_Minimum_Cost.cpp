#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> par,size;

int getParent(int child)
{
    if(par[child]==child)
        return par[child];
    return par[child]=getParent(par[child]);
}

bool unionSet(int a,int b)
{
    a = getParent(a);
    b = getParent(b);
    if(a==b)
        return false;
    if(size[a]<size[b])
    	swap(a,b);
    par[b]=a;
    size[a]+=size[b];
    return true;
}

int getMinimumCost(int n, int m, vector<vector<int>> &graph)
{
	par.clear();
    size.clear();
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
        size[i]=1;
    }
	sort(graph.begin(),graph.end(),[&](vector<int> &a,vector<int> &b){
        return a[2]<b[2];
    });
	int minCost = 0;
    for(auto &node:graph)
    {
        if(unionSet(node[0],node[1]))
            minCost+=node[2];
    }
    unordered_set<int> vis;
    for(int i=1;i<=n;i++)
    {
        vis.insert(getParent(i));
    }
    if(vis.size()>1)
        return -1;
    return minCost;
}
