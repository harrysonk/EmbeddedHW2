/*******************************************************************
 *  EECS3100HW2
 *  Question 4
 *  Written by Harrison Kania
 *  Edits a persons credit score based on if they made a payment
 *  The list of payments is in an array
 *  If the credit score is at 800 for more than 2 months is returns
 *	a reward bit. If the credit score is at 800 for more than two
 *  months it returns a alarm bit of 0
 *******************************************************************/


// Called by startup assembly code, start of C code

/* Global variables here – avoid declaring too many globals unnecessarily as it is not considered a good
programming practice. */
int creditRatingAlice = 750;

// 0 represents “defaulted” and 1 represents “paid” for the payment history
int monthlyPaymentHistoryAlice[24] = {1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1};

//global credit status flag
volatile int creditStatus;
	
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

	//Loops endlessly based on the size of the array and goes around forever
	while(1)
	{
		//Get correct position in array starting at 0
		month = (month + 1) % 24;
		//If 1 increase credit score and return reward bit if criteria is met
		if(monthlyPaymentHistoryAlice[month] == 1)
		{
			if(creditRatingAlice == 800)
			{
				return 1;
			}
			updateCreditRatingAlice(1);
		}
		//If 0 decrease credit score and return alarm bit if criteria is met
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
  while(1)
	{
		creditStatus = rewardsOrAlarm();
  }
}



