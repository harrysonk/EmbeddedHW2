/*******************************************************************
 *  EECS3100HW2
 *  Question 1
 *  Written by Harrison Kania
 *  Four seperate C code snippets 
 *  All concern the topic of bit manipulation
 *
 *  
 *******************************************************************/

// Called by startup assembly code, start of C code
void Question1A()
{
	//Declare ch1, initialize it to 0x34
	volatile char ch1 = 0x34;
	//Declare ch2
	volatile char ch2;
	//Declare mask, initialize it to 0x20
	volatile char mask = 0x20;
	
	//If bit 5 in ch1 is 1 set ch2 to 1, otherwise set ch2 to 0
	ch2 = ((ch1 >> 5) & 1) ? 1 : 0;
}

void Question1B()
{
	//Declare ch1, initialize it to 0x34
	volatile char ch1 = 0x34;
	//Declare mask, initialize it to 1
	volatile char mask = 1;
	
	//Set bit 7 to be 1, result should be 0xB4
	ch1 = (ch1|(mask << 7));
}

void Question1C()
{
	//Declare ch1, initialize it to 0x34
	volatile char ch1 = 0x34;
	//Declare mask, initialize it to 1 
	volatile char mask = 1;
	
	//Clear bit 3 to 0, result should still be 0x34
	ch1 = (ch1&~(mask << 3));
}

void Question1D()
{
	//Declare ch1, initialize it to 0x34
	volatile char ch1 = 0x34;
	//Declare mask, initialize it to 1 
	volatile char mask = 1;
	
	//Toggle bit 4 to 1, result should be 0x24
	ch1 = (ch1^(mask << 4));
}
//Main method, calls parts A,B,C, and D of question.
int main(void)
{    
	Question1A();
	Question1B();
	Question1C();
	Question1D();
	
  while(1)
	{
		
  }
}


