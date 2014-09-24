#include <stdio.h>
#include <math.h>

struct roots //structure including x_1,x_2 - roots, D - discriminant, count - quantity of roots
{
	double D,x_1,x_2;
	int count;
};

struct roots function (double a, double b, double c) //function, counting quantity and values of roots
{
    struct roots r;
    
    //case à=0 (linear equation)
	if (a==0)
	{
		if (b==0)
		{
			if (c==0) r.count=3;
			if (c!=0) r.count=0;
		}			
	
		if (b!=0)
		{
		r.x_1=-c/b;
		r.count=1;
	    }
	}
	
	//case a is not equals 3 (quadratic equation)
	    if (a!=0)
    {
    	r.D=(b*b)-(4*a*c); //computing discrimninant

        // case of negative discriminant
    	if (r.D < 0) r.count=0;
    	// case of zero discriminant
    	if (r.D == 0)
    	{
    		r.count=1;
    		r.x_1=(-b+sqrt(r.D))/(2*a);
    	}
    	// case of positive discriminant
    	if (r.D > 0)
    	{
    		r.count=2;
    		r.x_1=(-b+sqrt(r.D))/(2*a);
    		r.x_2=(-b+sqrt(r.D))/(2*a);
    	}
    }
    return r;
}
	

int main()
{
	//INPUT OF VARIABLES
	roots r;
	double a,b,c;
	scanf("%lg %lg %lg", &a,&b,&c);
    
    //COUNTING QUANTITY AND VALUE OF ROOTS
    r = function (a,b,c); // outputting structure e where r.x1,r.x2 - roots, r.n - quantity of roots
    
    //OUTPUT OF RESULT
    if (r.count==0) printf("No roots");
    if (r.count==1) printf("One root: %f \n", r.x_1);
    if (r.count==2) printf("Two roots: %f and %f",r.x_1,r.x_2);
    if (r.count==3) printf("Any number from R is root");

	return 0;
}
