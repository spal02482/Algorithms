//Read Binary File & Print in reverse Order
/*Name:Suraj Pal
  Roll No.:7656
  SE COMPS
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct record		
{
	int day;
	int shift;
	int prod;
	int def;
}RECORD;
int main()
{
	FILE *fp=fopen("weekrec.dat","wb+");	
	RECORD r[3];
	int day,shift,def,unitsp;
	for(day=1;day<3;day++)			
	{
		for(shift=0;shift<3;shift++)		
		{
			printf("Enter the total number of units produced and total number of defected units.\n");
			scanf("%d%d",&unitsp,&def);
			r[shift].day=day;
			r[shift].shift=shift+1;
			r[shift].prod=unitsp;
			r[shift].def=def;
		}
		fwrite(r,sizeof(RECORD),3,fp);	
	}
	for(day=1;day<3;day++)		
	{
		for(shift=0;shift<3;shift++)
		{
			fseek(fp,-sizeof(RECORD),1);			
			fread(&r[shift],sizeof(RECORD),1,fp);	
		}
		for(shift=0;shift<3;shift++)
			printf("%d %d %d %d\n",r[shift].day,r[shift].shift,r[shift].prod,r[shift].def);
	}
	fclose(fp);
}
