#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
struct p{
	int pi,at,bt,ct;
}ps[20];
struct comp{
	bool operator()(p a,p b)
	{
		if(a.bt!=b.bt){
			return a.bt > b.bt;
		}
		return a.pi >  b.pi;
	}
};
int main()
{
	int n;
	p rs[20];
	scanf("%d",&n);
	priority_queue<p,vector<p>,comp> pq;
	for(int i=1;i<=n;i++){
		ps[i].pi = i;
		scanf("%d%d",&ps[i].at,&ps[i].bt);
	}
	bool visited[20] = {false};
	pq.push(ps[1]);
	int prev = ps[1].at;
	visited[1] = true;
	while(!pq.empty()){
		p w = pq.top();
		printf("print1    %d\t%d\t%d\t%d\n",w.pi,w.at,w.bt,w.ct);
		pq.pop();
		w.ct = prev + w.bt;
		rs[w.pi]=w;
		for(int i=1;i<=n;i++){
			if(ps[i].at <= w.ct && visited[i]!=true){
				pq.push(ps[i]);
				visited[i]=true;
			}
		}
		prev = w.ct;
		printf("print2    %d\t%d\t%d\t%d\n",w.pi,w.at,w.bt,w.ct);
	}
	for(int i=1;i<=n;i++){
		printf("%d\t%d\t%d\t%d\n",rs[i].pi,rs[i].at,rs[i].bt,rs[i].ct);
	}
	return 0;
}
