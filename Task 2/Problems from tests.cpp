#include <stdio.h>

#ifdef MY_COMP
#define DBG printf("# "),
#else
#define DBG if(0)
#endif

// a2_08-------------------------------------------------- 2008-2
int a2_08();
// b2_08-------------------------------------------------- 2008-2
int b2_08();
void sort();
void printarr();
void scanarr();
void delextra();
// c2_08-------------------------------------------------- 2008-2
int c2_08();
// d1_08-------------------------------------------------- 2008-1
int d1_08();
int q2();
// c1_08 ------------------------------------------------- 2007-1
int c1_07();
int check();
//-----------------------------------------------------------


int main()
{
	DBG printf("Press 1 for A (2008, 2 variant)\n");
    DBG printf("Press 2 for B (2008, 2 variant)\n");
    DBG printf("Press 3 for C (2008, 2 variant)\n");
    DBG printf("Press 4 for D (2008, 1 variant)\n");
    DBG printf("Press 5 for C (2007, 1 variant)\n");
	
	int pr_number;
    scanf("%d", &pr_number);
    
    switch(pr_number)
    {
        case 1 : a2_08(); break;
        case 2 : b2_08(); break;
        case 3 : c2_08(); break;
        case 4 : d1_08(); break;
        case 5 : c1_07(); break;
    }
}

// a2_08--------------------------------------------------

int a2_08()
{
	int N,i;
	
	DBG printf("Enter N \n");
	
	scanf("%d", &N);
	
	for (i=N-1;i>=1;i--)
	{
		if (N%i==0) break;
	}
	printf("%d", i);
}

// b2_08--------------------------------------------------

void sort(int* arr, int size)
{
    int tmp, i, j;
 
    for(i = 0; i < size - 1; i++)
    {            
        for(j = 0; j < size - 1; j++)
        {     
            if (arr[j + 1] < arr[j]) 
            {
                tmp = arr[j + 1]; 
                arr[j + 1] = arr[j]; 
                arr[j] = tmp;
            }
        }
    }
}

void printarr(int* arr,int N)
{
	int i;
	for (i=0;i<=N-1;i++)
	{
		printf("%d ",arr[i]);
	}	
	printf("\n");
}

void scanarr(int *arr,int N)
{
	int i;
	for (i=0;i<=N-1;i++)
	{
		scanf("%d",&arr[i]);
	}
}

void delextra(int *arr,int N)
{
	int i,k;
	for (i=0;i<=N-1;i++)
    {
        while (arr[i] == arr[i+1])
      	{
      		for (k = i; k<=N; k++) 
      		{
      			arr[k]=arr[k+1];
      		}
      		N--;
//      		printf("N = %d \n", N);
      	}
      }
      arr[1001]=N;
}

int b2_08()
{
	int a[1001];
	int n,i,j,k;
	
	DBG printf("Enter n \n");
	
	scanf("%d",&n);
	
	scanarr(a,n);
	
	sort(a,n);

    delextra(a,n);
    
	printarr(a,a[1001]);
	
	
}

// c2_08--------------------------------------------------

int c2_08()
{
	
	int ch[100000];
	int i=1,j,k,n;
	
	DBG printf("Enter text \n");
	
	while ((ch[i] = getchar( ))!=EOF) i++;
	
	for (j=1;j<=i;j++)
	{
		while ((ch[j] == ' ') && (ch[j+1] == ' '))
		{
			for (k = j; k<=i; k++) 
			{
				ch[k]=ch[k+1];
			}
			i--;
		}
	}

	i--;
	
	n=1;
	
	while (n<=(i))
	{
    	putchar(ch[n]); n++;
	}

}
// d1_08--------------------------------------------------
int q2(int n,int k)
{
	if (n<0) return 0;
	if (n==0 && k>=0) return 1;
	if (n>0 && k==0) return 0;
	return (q2(n-2*k,k-1)+q2(n-k,k-1)+q2(n,k-1));
}

int d1_08()
{
	int a,b,Q2,N;
	
	DBG printf("Enter N \n");
	
	scanf("%d", &N);
	
	Q2=q2(N,N);
	printf("%d", Q2);
}
// c1_07--------------------------------------------------

int check(int n)
{
	if (n==0) return 1;
	if ((n-2)%4 == 0) return 0;
	if ((n+1)%4 == 0) n = (n+1)/4;
	if ((n-1)%4 == 0) n = (n-1)/4;
	if (n%4     == 0) n = n/4;
	if ((n==1) || (n==3) || (n==4)) return 1;
	check(n);
}

int c1_07()
{
	int N;
	
	DBG printf("Enter N \n");
	
	scanf ("%d",&N);

	if (check(N) == 0) printf("NO");
    if (check(N) == 1) printf("YES");
}
