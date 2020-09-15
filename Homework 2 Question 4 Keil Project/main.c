/*******************************************************************
 *  main.c
 *  This is an embedded program template.
 *  
 *  Author: G. Serpen
 *  Date: Date: May 22, 2017
 *
 *  
 *******************************************************************/



/* Global variables here – avoid declaring too many globals unnecessarily as it is not considered a good
programming practice. */
int creditRatingAlice = 750;
// 0 represents “defaulted” and 1 represents “paid” for the payment history
int monthlyPaymentHistoryAlice[24] = {1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1};

//global credit status flag
volatile int creditStatus;
// Called by startup assembly code, start of C code
	
volatile int month = 23;
/* Function called when Alice makes a monthly payment or defaults on the monthly payment.
* Returns nothing, updates global variable creditRatingAlice. */
void updateCreditRatingAlice (int opcode) 
{
	
// each monthly payment increments rating by 10 points all the way up to 800
// every default decrements rating by 10 points down to 700.
	if(opcode == 1 && creditRatingAlice != 800)
	{
		creditRatingAlice += 10;
	}
	else if(opcode == 0 && creditRatingAlice != 700)
	{
		creditRatingAlice -= 10;
	}
}
/* Function that raises an alarm when Alice's rating is 700 for 2 consecutive months,
* or rewards her if she has maintained a rating of 800 for 2 consecutive months.
* Reads montlyPaymentHistoryAlice for input.
* Returns 0 if alarm, 1 if reward. */
int rewardsOrAlarm () 
{
 // Read next value in monthlyPaymentHistoryAlice. Note that this function needs to keep track of the
 // last array element accessed so that when it reaches the last it can rewind to the first in a round
 // robin fashion to read a value from the monthlyPaymentHistoryAlice array forever.
// Pass the read value in monthlyPaymentHistoryAlice to function updateCreditRatingAlice(int x).
// Return reward/alarm value.

	while(1)
	{
		month = (month + 1) % 24;
		if(monthlyPaymentHistoryAlice[month] == 1)
		{
			if(creditRatingAlice == 800)
			{
				return 1;
			}
			updateCreditRatingAlice(1);
		}
		else
		{
			if(creditRatingAlice == 700)
			{
				return 0;
			}
			updateCreditRatingAlice(0);
		}
		
		
	}
	return 1;
}
int main(void)
{    
	
	// main(), while looping endlessly, sets a global flag creditStatus to the value returned by the function
// rewardsOrAlarm(). 
  while(1)
	{
		creditStatus = rewardsOrAlarm();
  }
}



