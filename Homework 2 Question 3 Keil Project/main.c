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

//Initialize global variables
volatile int maxValueArray[10] = {-1, 5, 3, 8, -10, 23, 6, 5, 2, 10};
volatile int arraySize = 10; 
int main(void)
{    
	//Maximum vlaue integer
	volatile int maximumValue = 0;
	//Iterator integer
	int i;
	
	//For loop to loop through array and compare elements to find the greatest value
	for(i = 0; i < arraySize; i++)
	{
		if(maximumValue < maxValueArray[i])
		{
			maximumValue = maxValueArray[i];
		}
	}
	
	
  while(1)
	{
		
  }
}


