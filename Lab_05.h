#ifndef LAB_05
#define LAB_05

struct triples
{
	double sideA;
	double sideB;
	double sideHyp;
};
struct triples * inputOneSideAndHyp(struct triples *ms,double sideAIn,double hypIn,int index);
struct triples * inputTwoSides(struct triples *ms,double sideAIn,double sideBIn,int index);

#endif
