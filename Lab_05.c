#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Lab_05.h"

int index_m = 0;
struct triples * inputOneSideAndHyp(struct triples *ms,double sideAIn,double hypIn,int index)
{
	struct triples *cur_triples = ms;
	cur_triples = ms + index;
	cur_triples->sideA = sideAIn;
	cur_triples->sideB = sqrt(pow(hypIn,2)- pow(sideAIn,2));
	cur_triples->sideHyp = hypIn;
	return ms;
}
struct triples * inputTwoSides(struct triples *ms,double sideAIn,double sideBIn,int index)
{
	struct triples *cur_triples = ms;
	cur_triples = ms + index;
	cur_triples->sideA = sideAIn;
	cur_triples->sideB = sideBIn;
	cur_triples->sideHyp = sqrt(pow(sideAIn,2) + pow(sideBIn,2));
	return ms;	
}
void printArray(struct triples *ms)
{
	struct triples	*last = ms + (index_m - 1);
	do{
		printf("Side A: %lf Side B: %lf Side Hyp: %lf\n",ms->sideA,ms->sideB,ms->sideHyp);
		ms++;
	}while(ms <= last);
}

int main(int argc, char **argv)
{
	struct triples *ms = (struct triples *) malloc(1000 * sizeof(struct triples));
	int option;
	do
	{
		
		puts("Please enter the option (1: OneSideAndHyp, 2: TwoSides, 3: exit ");
		scanf("%d",&option);
		if(option == 1)
		{
			double sideA;
			puts("Enter Side A: ");
			scanf("%lf",&sideA);
			double sideHyp;
			puts("Enter Side Hyp: ");
			scanf("%lf",&sideHyp);
			ms = inputOneSideAndHyp(ms,sideA,sideHyp,index_m);
			index_m++;
		}
		else if(option == 2)
		{
			double sideA;
			puts("Enter Side A: ");
			scanf("%lf",&sideA);
			double sideB;
			puts("Enter Side B: ");
			scanf("%lf",&sideB);
			ms = inputTwoSides(ms,sideA,sideB,index_m);
			index_m++;
		}
	}while((option == 1 || option == 2) && index_m < 1000);
	printArray(ms);
}
