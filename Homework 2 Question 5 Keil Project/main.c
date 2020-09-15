/*******************************************************************
 *  main.c
 *  This is an embedded program template.
 *  
 *  Author: G. Serpen
 *  Date: Date: May 22, 2017
 *
 *  
 *******************************************************************/




// Called by startup assembly code, start of C code

#define TRUE 1
#define FALSE 0
#define N 25 // array size

unsigned long sum(unsigned long n)
{
	unsigned long partial = 0;
	while(n > 0)
	{
		partial += n;
		n--;
	}
	
	return partial;
}
unsigned long fun(unsigned long n)
{
	return (n *(n+1))/2;
}
int main(void)
{    
	
	volatile unsigned long num;
	volatile unsigned long sumBuf[N], funBuf[N]; // arrays to store computed values
	volatile int correctFlag = TRUE;
	
	for(num = 0; num < N; num++)
	{
		sumBuf[num] = sum(num);
		funBuf[num] = fun(num);
		if(sumBuf[num] != funBuf[num])
		{
			correctFlag = FALSE;
		}				
	}
	
	return correctFlag;
	
  while(1)
	{
		
  }
}


