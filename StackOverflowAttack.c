// Stack overflow Attack


// strcmp
// https://baike.baidu.com/item/strcmp/5495571?fr=aladdin
// http://c.biancheng.net/c/strcmp.html

// http://www.cplusplus.com/reference/cstring/strcmp/
// https://en.cppreference.com/w/cpp/string/byte/strcmp



#include <stdio.h>
#include <string.h>

#define PASSWORD "12345"

void print()
{
	printf("..........................Athorization OK! \n");
}


int verifyPassword(char *password)
{
	char buffer[8];
	int flag = strcmp(password, PASSWORD);
	strcpy(buffer, password);
	return flag;
}




main()
{
	printf("Function print addr: %p \n", print);
	
	
	char password[88];
	int flag;
	
	while(1)
	{
		printf("Input the password>");
		scanf("%s", password);
		flag = verifyPassword(password);
		if(flag)
		{
			printf("Password failed! \n");
		}
		else{
			printf("Password get. \n");
		}
	}
		
	
	return 0;
}


// https://blog.csdn.net/yan_star/article/details/88937283
// EBP = 0012FF80
// EIP = 004010E5



