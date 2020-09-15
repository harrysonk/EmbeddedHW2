/*******************************************************************
 *  EECS3100HW2
 *  Problem 2
 *  Written by Harrison Kania
 *  Computes the factorial of 5
 * 
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
	//Loops through 5 times and multiplies the number by itself each time
	//This will result in the correct factorial of 5, 120
	for(i = 1; i <= 5; i++)
	{
		factorialOf5 *= i;
	}
	
  while(1)
	{
		
  }
}


