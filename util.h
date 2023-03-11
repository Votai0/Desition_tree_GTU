#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001



/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w);

char dt1a(float pl1a,float pw1a,float sl1a,float sw1a);
char dt1b(float pl1b,float pw1b,float sl1b,float sw1b);

double dt2a(float x1a,float x2a,float x3a,int x4a,int x5a);
double dt2b(float x1b,float x2b,float x3b,int x4b,int x5b);

/* Write the prototype of the functions implementing the decision trees for the third problem */
double dt3a(double aspeed ,double aweight ,double alength_of_driving ,int aroad_contition ,int anight_or_day);
double dt3b(double bspeed ,double bweight ,double blength_of_driving ,int broad_contition ,int bnight_or_day);

#endif /* _UTIL_H_ */
