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
int main(void)
{    
	//Integer to represent factorialof5
	volatile int factorialOf5 = 1;
	//Count Integer
	int i;
	
	//For loop to calculate the factorial of 5
	for(i = 1; i <= 5; i++)
	{
		factorialOf5 *= i;
	}
	
  while(1)
	{
		
  }
}


