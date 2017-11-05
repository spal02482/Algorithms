#include <iostream>
#include <list>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	list<int> l;
	vector<int> v;
	int n,x,f,ph=0,pm=0;
	bool flag;
	scanf("%d%d",&n,&f);
	list<int> :: iterator it;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		v.push_back(x);
	}
	for(int i=0;i<f;i++) l.push_front(v[i]);
	for(int i=f;i<n;i++){
		flag=false;
		int x = v[i];
		printf("%d\n",x);
		for(it=l.begin();it!=l.end();++it){
			if(x==*it){
				l.erase(it);
				l.push_front(x);
				ph+=1;
				flag=true;
			}
		}
		if(!flag){
			l.pop_back();
			l.push_front(x);
			pm+=1;
		}
		for(it=l.begin();it!=l.end();++it){
			printf("%d ",*it);
		}
		printf("\n");
	}
	printf("%d %d\n",ph,pm+f);
	return 0;
}
