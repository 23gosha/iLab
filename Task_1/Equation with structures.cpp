#include <stdio.h>
#include <math.h>

struct equation //структура, включающая в себя x1,x2 - корни, D - дискриминант, n - количество корней
{
	double D,x1,x2;
	int n;
};

struct equation function (double a, double b, double c) //функция, считающая количество и значение корней
{
    struct equation e;
    
    //случай а=0 (линейное уравнение)
	if (a==0)
	{
		if (b==0)
		{
			if (c==0) e.n=3;
			if (c!=0) e.n=0;
		}			
	
		if (b!=0)
		{
		e.x1=-c/b;
		e.n=1;
	    }
	}
	
	//случай, в котором а не равно 0 (квадратное уравнение)
	    if (a!=0)
    {
    	e.D=(b*b)-(4*a*c); //подсчет дискриминанта

        // случай с отрицательным дискриминантом
    	if (e.D < 0) e.n=0;
    	// случай с нулевым дискриминантом
    	if (e.D == 0)
    	{
    		e.n=1;
    		e.x1=(-b+sqrt(e.D))/(2*a);
    	}
    	// случай с положительным дискриминантом
    	if (e.D > 0)
    	{
    		e.n=2;
    		e.x1=(-b+sqrt(e.D))/(2*a);
    		e.x2=(-b+sqrt(e.D))/(2*a);
    	}
    }
    return e;
}
	

int main()
{
	//ВВОД ПЕРЕМЕННЫХ
	equation e;
	double a,b,c;
	scanf("%lg %lg %lg", &a,&b,&c);
    
    //ПОДСЧЕТ КОЛИЧЕСТВА И ЗНАЧЕНИЯ КОРНЕЙ
    e = function (a,b,c); // выводится структура е, в которой e.x1,e.x2 - корни, e.n - количество корней
    
    //ВЫВОД РЕЗУЛЬТАТА
    if (e.n==0) printf("No roots");
    if (e.n==1) printf("One root: %f \n", e.x1);
    if (e.n==2) printf("Two roots: %f and %f",e.x1,e.x2);
    if (e.n==3) printf("Any number from R is root");

	return 0;
}
