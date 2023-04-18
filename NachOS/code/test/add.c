/* add.c
 *	Simple program to test whether the systemcall interface works.
 *	
 *	Just do a add syscall that adds two values and returns the result.
 *
 */

#include "syscall.h"

int
main()
{
  int result;
  
  result = Add(42, 230);
  //PrintInt(result);
  //printf("result56566 is %d\n", result);
  Halt();
  /* not reached */
}
