#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#define EPS 1e-7
int main()
{
	double a, b, c, x1, x2;
	scanf("%lf %lf %lf", &a, &b, &c);
	double delta;
	if (fabs(a) <= EPS) 
	{	
		return 0;   
	}
	else 
	{
		delta = (b * b - 4 * a * c) * 1.0;
		x1 = (-b - sqrt(delta)) / (2.0 * a);  
		x2 = (-b + sqrt(delta)) / (2.0 * a);
		if (fabs(delta) <= EPS)
		{           
			printf("x1=x2=%.5lf", x1);
			return 0;
		}
		else if (delta > EPS) 
		{
			if (x1 < x2) 
			{      
				printf("x1=%.5lf;x2=%.5lf", x1, x2);
			}
			else 
			{
				printf("x1=%.5lf;x2=%.5lf", x2, x1);
			}
			return 0;
		}
		else 
		{
			printf("No answer!");
			return 0;
		}
	}
	return 0;
}