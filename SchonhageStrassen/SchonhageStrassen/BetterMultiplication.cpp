#include "BetterMultiplication.h"
int BetterMultiplication::countDigits(long a) 
{
	int count = 0;
	while (a > 0) 
	{ //check the number of digits at a certain point
		a /= 10; //reduce by factor of 10
		count++; //increment digit counter
	}
	return count; //return number of digits
}
void BetterMultiplication::schonhageStrassenMultiplication() {
	findLinear(); //perform all linear  multiplications on algorithm
	performCarry(); //perform the carry operation on linear multiplications
}
void BetterMultiplication::findLinear() 
{ //this essentially finds the products of all digits in the two numbers multiplied together (individually). i.e 4 multiplied by digits 1 8 1 and 2.
	int firstNumDigits = countDigits(x);
	int secondNumDigits = countDigits(y);
	long temp = x; //temporary variable to store the first number
	length = firstNumDigits + secondNumDigits - 1; //length for linear multiplications is 1 less than both digits added together
	linearConvulsion = new int[length]; //dynamic array to store the linear multiplications
	for (int i = 0; i < length; i++) {
		linearConvulsion[i] = 0;
	}
	for (int i = 0; i < firstNumDigits; i++, y /= 10) 
	{
		x = temp;
		for (int j = 0; j < secondNumDigits; j++, x /= 10) 
		{
			//multiplies current digit of a with current digit of b and stores in the array
			linearConvulsion[i + j] += (y % 10) * (x % 10); //i + j will refer to the respective digit column
		}
	}
	for (int i = length - 1; i >= 0; i--) 
	{
		std::cout << "The current linear convolution is: " << linearConvulsion[i] << std::endl;
	}
}
void BetterMultiplication::performCarry() {
	long product = 0;
	int carry = 0, base = 1;
	for (int i = 0; i < length; i++) 
	{
		linearConvulsion[i] += carry;
		product = product + (base * (linearConvulsion[i] % 10)); //product is equal to the base (power of 10) multiplied by the current unit in linearConvulsion
		carry = linearConvulsion[i] / 10; //amount to carry by in next iteration
		base *= 10;
	}
	std::cout << "The product is " << product << std::endl;
	delete[] linearConvulsion;
}
long BetterMultiplication::x = 2604;
long BetterMultiplication::y = 1812;
int BetterMultiplication::length = 0;
int* BetterMultiplication::linearConvulsion = nullptr;