#include <stdio.h>
#include <math.h>

struct equation //���������, ���������� � ���� x1,x2 - �����, D - ������������, n - ���������� ������
{
	double D,x1,x2;
	int n;
};

struct equation function (double a, double b, double c) //�������, ��������� ���������� � �������� ������
{
    struct equation e;
    
    //������ �=0 (�������� ���������)
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
	
	//������, � ������� � �� ����� 0 (���������� ���������)
	    if (a!=0)
    {
    	e.D=(b*b)-(4*a*c); //������� �������������

        // ������ � ������������� ��������������
    	if (e.D < 0) e.n=0;
    	// ������ � ������� ��������������
    	if (e.D == 0)
    	{
    		e.n=1;
    		e.x1=(-b+sqrt(e.D))/(2*a);
    	}
    	// ������ � ������������� ��������������
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
	//���� ����������
	equation e;
	double a,b,c;
	scanf("%lg %lg %lg", &a,&b,&c);
    
    //������� ���������� � �������� ������
    e = function (a,b,c); // ��������� ��������� �, � ������� e.x1,e.x2 - �����, e.n - ���������� ������
    
    //����� ����������
    if (e.n==0) printf("No roots");
    if (e.n==1) printf("One root: %f \n", e.x1);
    if (e.n==2) printf("Two roots: %f and %f",e.x1,e.x2);
    if (e.n==3) printf("Any number from R is root");

	return 0;
}
