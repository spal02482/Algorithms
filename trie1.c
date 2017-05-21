#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct trienode
{
	char key_char;
	int value;
	struct trienode *next,*children;
}trienode,*trienode_p;

typedef struct trie_t
{
	trienode *root;
}trie_t,*trie_p;

trienode_p create_node(char c,int value)
{
	trienode_p A = (trienode_p)malloc(sizeof(trienode));
	A->key_char=c;
	A->value=value;
	A->next=A->children=NULL;
	return A;
}

bool match_horizon(trienode_p *p,char c)
{
	while((*p)->key_char!=c)
	{
		if(!((*p)->next))
			return false;
		*p=(*p)->next;
	}
	return true;
}

int trie_match(trie_p trie,char *key)
{
	int key_len = strlen(key);
	bool found=true;
	trienode_p prev = trie->root,p=NULL;
	if(!prev || !key_len)
		return 0;
	for(int i=0;i<key_len;i++)
	{
		if(!prev)
			return 0;
		else if(match_horizon(&prev,key[i]))
		{
			printf("%c ",prev->key_char);
			p=prev;
			prev=prev->children;
		}
		else
		{
			found=false;
			break;
		}
	}
	if(found)
	{
		return p->value;
	}
	else
		return 0;
}

void trie_add(trie_p trie,char *key)
{

	int key_len=strlen(key);
	if(!key_len)
		return;
	else if(!trie->root)
	{
		trienode_p prev=NULL,A;
		A = create_node(key[0],1);
		trie->root=A;
		prev=trie->root;
		for(int i=1;i<key_len;i++)
		{
			A = create_node(key[i],1);
			prev->children=A;
			prev=A;
		}		
	}
	else
	{
		int i,j;
		trienode_p prev=trie->root,A,p=NULL;
		for(i=0;i<key_len;i++)
		{
			if(match_horizon(&prev,key[i]))
			{
				(prev->value)++;
				p=prev;
				prev=prev->children;
				if(!prev)
					break;
			}
			else
				break;
		}
		if(!prev)
		{
			i+=1;
			prev=p;
			A = create_node(key[i],1);
			prev->children=A;
			prev=A;
			i+=1;
		}
		else
		{
			A = create_node(key[i],1);
			prev->next=A;
			prev=A;
			i+=1;
		}
		for(j=i;j<key_len;j++)
		{
			A = create_node(key[j],1);
			prev->children=A;
			prev=A;
		}
	}		
}

int main()
{
	trie_t t;
	int n,value_retrieved;
	char key[100];
	t.root=NULL;
	printf("Enter the Number of Words:");
	scanf("%d",&n);
	printf("Enter Words..\n");
	for(int i=0;i<n;i++)
	{
		scanf("%s",key);
		trie_add(&t,key);
	}
	printf("Enter the Word to be Searched:");
	while(true)
	{
		scanf("%s",key);
		if(!strcmp(key,"quit"))
			break;
		value_retrieved = trie_match(&t,key);
		printf("%d\n",value_retrieved);
	}
	return 0;
}