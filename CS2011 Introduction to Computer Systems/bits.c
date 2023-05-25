/* 
 * CS2011 Lab1
 * 
 * Thavishka Gamage
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any o operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type o than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type o than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
 /* 
We must comprehend that the XOR operator returns 1 in order to emulate it.
When x and y are different, it returns 1, whereas when they are equal, it returns 0.
To achieve this, we must formulate two statements that denote the conditions of when x and y are 0 and when x and y are 1.
Through ~x&~y and x&y, respectively, this is possible. The two scenarios are then connected by an OR, followed by a negation.
Given that we are unable to use a or, we can mimic it by using ~ condition AND ~ condition.
*/ 
return (~(~x&~y) &~ (x&y));
  
  
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    // The lowest value is -1 * 2^31  because we are returning a two's complement, which can be calculated through 1 << 31.
    return 1 << 31;
  
}
//2
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    /*
      Create a binary number whose even bits are equal to 1.
      Then combine the binary number given with the one that calculated through the or.
      Afterwards negate it to see if it is equal to 0. If it is, we must return true. If not, we have to return false
    */
    int t = (0x55 << 24) + (0x55 << 16) + (0x55 << 8) + 0x55;
    int temp = ~(t|x);
    return !(temp);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    // negate(x) = ~ x + 1 since the negation of x is one less than x.
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    /*
     Calculating the lower and upper bounds will allow us to determine whether the number falls inside the range of 0x30 = x = 0x39.
     This may be done by using the formulas (x + ( 0x2f)) and (0x3a + ( x)).
     Since the most significant bit of negative numbers is 1, the MSB must be 1, if one of the values is negative, i.e., outside of the range.
     We obtain the most important bit using the shift, and then we use the exclamation point to return a bool in the form of an int.
     */
    return !(((x + (~ 0x2f)) | (0x3a + ( ~ x))) >> 31);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    /*
       The value of x is first transformed into a conditional value, where 0 is true and all other binary values are false.
       Then, by coupling a and a to z and y through &, we replicate the condition.
       Then we use | to link the if and else statements.
    */
    int a = ~(!x) + 1;
    return (a & z) | (~a & y);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int sign = !(x >> 31)^!(y>>31); // finding out if the symptoms are the same
    int SIGNX = sign & (x >> 31); //obtaining the x sign
    int diffSign = !sign & !((y+ (~x+1)) >> 31); //determining the sign of the y & x difference. If y-x is negative and they have the same sign, the diff sign = 1
    return SIGNX | diffSign;
    
  
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    /*
     The most important bit of the binary produced by the OR of the negation of x and x itself is given to us by the expression ((x+1)|x)>>31).
     Next, we determine the result's sign and, in essence, toggle it from false to true and from true to false.
     */
  return ((((~x+1)|x)>>31)&1)^1;
  
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /*
Split x into two and chck if the top half has some value other than 0. If so, we increase n << 4.
Then check the left 8 of the bottom half. If it has some value other than 0, we increase n by n <<3. 
The program will do this multiple times and finally increase it by 1 to account for the index issue. */

    int count = 0;
    x = x ^ (x >> 31); // 1 if msb is 0, 0 if msb is 1
    count += ((!!(x >> (count + 16))) << 4); // if shifting 
    count += ((!!(x >> (count + 8))) << 3);
    count += ((!!(x >> (count + 4))) << 2);
    count += ((!!(x >> (count + 2))) << 1);
    count += ((!!(x >> (count + 1))));
    count += (x >> count);
    return count + 1;

}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
/*
The first 2 bytes of the float are extracted as e, while the last 23 bits are extracted as the fractiontion.
The sign, which is the initial bit or the msb, is also extracted. By examining the denorm and e value, we first determine whether uf is equal to 0.
Since it already holds the value if it equals 0, we can return the uf in that case.
In order to return the value of uf, we also verify the scenario where the exponent is 255 or maxed out.
We must take into account the singular circumstance in which the denorm is maximal or equal to 0x007FFFFF.
In this instance, we can raise the exponent by 1 and lower the denorm by 1.
*/
  const unsigned FF = 0xFF;
  const unsigned first = 0x80000000;
  const unsigned second = 0x007fffff;
	unsigned e =((uf >> 23)&FF);
	unsigned sign=(uf & first);
	unsigned denorm=(uf & second);
	
	if(e == 255||(e == 0&& denorm == 0)){
		return uf;
	}
  else if(e){
		e = e + 1;
	}
  else if(denorm == second){
		denorm = denorm - 1;
		e = e + 1;
	}
  
  else{
		denorm = denorm << 1;
	}
	return sign|e << 23|denorm;
}

/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    /*
    In order to extract the fractional portion of uf, we must determine the sign of the float by examining the msb.
    The significand and exponent are then extracted.
    Since a value of 0 or the two's complement minimum is implied if the exponent is less than 0 or larger than 31.
    Since we must left shift the significand if the fractional component is bigger than 23, Otherwise, we must right shift it.
    If the signs concur, the significand is returned. If not, we give back the minimum two's complement.
     */
      int tMin = 0x1 << 31;
      int sign = uf >> 31;
      int fraction = uf & 0x007fffff;
      int e = ((uf >> 23) & 0xff) - 127;
      int m = fraction | (0x1 << 23);
      const int fraction_SIZE = 23;
      if(e < 0) {
        return 0;
      }
      if(e > fraction_SIZE) {
      return tMin;
      }
      else if(e > fraction_SIZE) {
        m = m << (e - fraction_SIZE);
      }
      else {
        m = m >> (fraction_SIZE-e);
      }

      if(!((m >> 31) ^ sign)) {
         return m;
      }
      else if(m >> 31) {
        return tMin;
      }
      else {
        return ~m + 1;
      }
}