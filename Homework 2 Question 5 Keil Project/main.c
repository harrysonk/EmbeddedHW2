/*******************************************************************
 *  EECS3100HW2
 *  Question 5
 *  Written by Harrison Kania
 *  Creates two arrays and compares each element to another
 *  Each element in is equivilant to sum of each number in the array
 *  Compares the two methods and returns true or false based on the results
 *	
 *  
 *******************************************************************/




// Called by startup assembly code, start of C code

//Define constants
#define TRUE 1
#define FALSE 0
#define N 25 // array size

//Sum method populates the sum array with the correct values
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

//Fun method populates the fun array with the correct values
unsigned long fun(unsigned long n)
{
	return (n *(n+1))/2;
}

//Main method initializes arrays and populates them with values based on the sum and fun methods
int main(void)
{    
	
	volatile unsigned long num;
	volatile unsigned long sumBuf[N], funBuf[N]; // arrays to store computed values
	volatile int correctFlag = TRUE;
	
	//For loop to populate and compare arrays
	//Returns false if an element does not match
	for(num = 0; num < N; num++)
	{
		sumBuf[num] = sum(num);
		funBuf[num] = fun(num);
		if(sumBuf[num] != funBuf[num])
		{
			correctFlag = FALSE;
		}				
	}
	
	//Returns true is the arrays are the same
	return correctFlag;
	
  while(1)
	{
		
  }
}


