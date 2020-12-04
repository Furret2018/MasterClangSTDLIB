// Test Intel storage mode


//http://c.biancheng.net/view/161.html


#include <stdio.h>
#include <string.h>


char * message = "Input the password> ";
main()
{
	// Test the memory storage mode: BIG ending or small Ending?
	// a will be allocated on stack
	int a[] = {0x00AB, 0xCD00, 0x00EF, 0xAB00, 0x00CD};	
	printf("sizeof(int)   = 0x%x \n", sizeof(int));	
	printf("sizeof(a)     = 0x%x \n", sizeof(a));
	printf("sizeof(char)  = 0x%x \n", sizeof(char));
	printf("sizeof(short) = 0x%x \n", sizeof(short));
	printf("sizeof(long)  = 0x%x \n", sizeof(long));
	
	printf("Array address: %016X \n", a);
	printf("Array address: %p    \n", a);
	
	int *p = a;
	
	// Print array
	printf("Read int a[] as int: \n");
	for (int i = 0; i< sizeof(a)/sizeof(int); i++)
	{
		// a only can be a right value , cannot be changed.  a++ is allowed.
		printf("%2d : %08X : %08X \n", i, p, *p);
        p++;		
	}	
	
	
	char *pc = (char*)a;
	// 
	printf("Read the memory of int[] a as char \n");
	for (int i = 0; i< sizeof(a)/sizeof(char); i++)
	{
		// a only can be a right value , cannot be changed.  a++ is allowed.
		// printf("%08X: \n", *p++);
		printf("%2d : %08X : %02X \n", i, pc, *pc);
		pc++;
	}
	
	short *pshort = (short*)a;
	// 
	printf("Read the memory of int[] a as char \n");
	for (int i = 0; i< sizeof(a)/sizeof(short); i++)
	{
		// a only can be a right value , cannot be changed.  a++ is allowed.
		// printf("%08X: \n", *p++);
		printf("%2d : %08X : %04X \n", i, pshort, *pshort);
		pshort++;
	}
	
	
	// conclusion: the low byte in LOW memory
}

















