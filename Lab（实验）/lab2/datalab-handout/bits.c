/* 
 * CS:APP Data Lab 
 * 
 * <李士贤-xian>
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
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  int bit_and=~((~x)|(~y));
  return bit_and;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  return x>>(n<<3)&0xff;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  int mask=(((~(1<<31))>>n)<<1)|1;//构造高n位为0，其余位为1的数
  //mask=(~(1<<31))>>(n+(~1+0x1))//参考后面的negate函数
  return (x>>n)&mask;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int t1=0x55,t2=0x33,t3=0x0f,t4=0xff,t5=0xff;
  //get0x55555555,to get 1 for every two bits
  t1=t1+(t1<<8);
  t1=t1+(t1<<16);
  //get0x33333333,to get 1 for every four bits
  t2=t2+(t2<<8);
  t2=t2+(t2<<16);
  //get0x0f0f0f0f
  t3=t3+(t3<<8);
  t3=t3+(t3<<16);
  //get0x00ff00ff
  t4=t4+(t4<<16);
  //get0x0000ffff
  t5=t5+(t5<<8);

  x=(x&t1)+((x>>1)&t1);
  x=(x&t2)+((x>>2)&t2);
  x=(x&t3)+((x>>4)&t3);
  x=(x&t4)+((x>>8)&t4);
  x=(x&t5)+((x>>16)&t5);
  return x;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  return ((x|(~x+0x1))>>31)+1;
}
/* 
 * tmin - return minimum two's complement integer 最小的二进制补码整数 100..00=-2^31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 0x1<<31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */

int fitsBits(int x, int n) {
  int mask=x>>(n+(~1+0x1));
  int sign=(x>>31)&1;
  return ((!sign)&(!mask))+((sign)&(!(mask+1)));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */

//正数向下舍入，负数向上舍入
int divpwr2(int x, int n) {
  int temp=((1<<n)+(~1+0x1))&(x>>31);//(2^n-1)&(0或1)负数才加偏置
  return (x+temp)>>n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ((~x)+0x1);
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  return !((x>>31)|(!x));   //!(x>>31)&(!(!x))
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int signx=(x>>31)&0x1;//x的符号位
  int signy=(y>>31)&0x1;//y的符号位
  int z=((y+((~x)+0x1))>>31)&0x1;//y-x的符号位
  return (!(signx^signy)&(!z))|((signx^signy)&signx);//(!((signx^signy)|z))|((signx^signy)&signx)
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  int sign;
  int shift,shift1,shift2,shift3,shift4,shift5;
  sign=!!(x>>16);
  shift1=sign<<4;
  x=x>>shift1;

  sign=!!(x>>8);
  shift2=sign<<3;
  x=x>>shift2;

  sign=!!(x>>4);
  shift3=sign<<2;
  x=x>>shift3;

  sign=!!(x>>2);
  shift4=sign<<1;
  x=x>>shift4;

  sign=!!(x>>1);
  shift5=sign;

  shift=shift1+shift2+shift3+shift4+shift5;
  return shift;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  unsigned e,m;
  m=uf<<9;
  e=uf>>23;
  /*if((!((e&0xff)^0xff))&(!!(m^0)))//是NaN的情况
  {
      return uf;
  }
  return (1<<31)^uf;
  */
  if((((e&0xff)^0xff))|(!(m^0))){
    uf=(1<<31)^uf;
  }
  return uf;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  unsigned sign,exp,frac;
  unsigned mask0=0x80000000;
  int num=0,E,bias;
  sign=x&0x80000000;//得到符号位
  if(sign) x=-x;
  if(!x) return 0;//0需要单独考虑
  while((x&mask0)==0){
    mask0=mask0>>1;
    num++;
  }//找出除符号位外，最高的1的位置，以便得出exp
  E=31-num;
  bias=E-23;
  exp=E+127;
  frac=((x<<num)>>8)&0x7fffff;
  if(E>23){
    int flag0,flag2;
    flag0=((x>>bias)&1);//判断第23位是0还是1
    flag2=((x<<(num+1))&0x1ff);//判断23位后的形式是大于等于小于1000
    if((flag2>0x100)|((flag2==0x100)&(flag0))){
    	frac++;
    	if(frac>0x7fffff){
    		exp++;
    		frac=0;
    	}//当尾码全为1，需要进位时，阶码加1，尾数变为0
    }
  }
  exp=exp<<23;
  return sign|exp|frac;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */

//分为NaN/+无穷大/-无穷大，非规格化，规格化
unsigned float_twice(unsigned uf) {
  unsigned e;
  unsigned t;
  int unStand=!(uf&0x7f800000);
  e=uf>>23;
  if(!((e&0xff)^0xff)){
    return uf;
  }
  //如果uf阶码全为0，那么unStand=1,表示是非规格化数
  if(unStand){
    t=(((uf&0x7fffff)<<1)|(uf&(1<<31)));
  }
  else{
    t=uf+0x800000;
  }
  return t;
}
