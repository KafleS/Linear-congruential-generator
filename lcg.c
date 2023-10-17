/*Name: Suman Kafle
Class cs241
Lab -06
*/

/* Project description: All the method as declared in the header file are implemented as instructed and testfiles are complied successfully*/

#include <stdio.h>
#include "lcg.h"


unsigned long productOfUniquePrimeFactors( unsigned long n)
{
  unsigned long testDiviser = 2;
  unsigned long product = 1;

  /* If n is 1 or less, return 1 as the product of unique prime factors*/
  if (n <= 1)
    {
      return 1;
    }

  /* testdiviser square is less than or eqaul to n*/
  while (testDiviser*testDiviser <= n)
    {
      if (n % testDiviser == 0)
	{
	  /*If testDiviser is a prime factor of n, add it to the product */
	  product *= testDiviser;

	  /*Divide n by the prime factor */
	  while (n % testDiviser == 0)
	    {
	      n /= testDiviser;
	    }
	}
      /* to increment the testDiviser to check the next number*/
      testDiviser++;
    }

  /*If n is still greater than 1, it must be a prime number itself, so add it to the product*/
  if (n > 1)
    {
      product *= n;
    }

  return product;
}

struct LinearCongruentialGenerator makeLCG(unsigned long m, unsigned long c)
{
  struct LinearCongruentialGenerator lcg0;
  lcg0.m = m;
  lcg0.c = c;
  lcg0.x = lcg0.c;

  /* check if m is diviser of 4 */
  if ( lcg0.m % 4 ==0 )
    {
      lcg0.a = 1+2*productOfUniquePrimeFactors(lcg0.m);
    }

  /*  if not go to this condition */
  else
    {
      lcg0.a = 1+productOfUniquePrimeFactors(lcg0.m);
    }

  if (lcg0.a<=0 || lcg0.a>=lcg0.m)
    {
      /* check if a is greater than 0 and smaller than m */
      lcg0.m = 0;
      lcg0.a = 0;
      lcg0.c = 0;
      lcg0.x = 0;

    }

  if ( lcg0.m<= 0)
    {/* check if m is 0*/
      lcg0.m = 0;
      lcg0.a = 0;
      lcg0.c = 0;
      lcg0.x = 0;
    }

  if ( lcg0.c<0 || lcg0.c>= m)
    {
      /* check if c is greater than 0 and smaller than m */
      lcg0.m = 0;
      lcg0.a = 0;
      lcg0.c = 0;
      lcg0.x = 0;
    }

  return lcg0;
}

/* Update lcg and return next value in the sequence. */
unsigned long getNextRandomValue(struct LinearCongruentialGenerator *lcg)
{
  /* to return the random values changing the value of x it its address*/
  unsigned long x1 = lcg->x;
  lcg->x = ((lcg->a*lcg->x)+lcg->c) % lcg->m;
  return x1;
}


