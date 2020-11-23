

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>


void displayCursorPostion(COORD * pos);

int main(){
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;		// 控制台屏幕缓冲区信息, in wincon.h
	COORD curpos = {0, 0};					// 存储光标当前的位置
	
	
	
	
	
	// 获得输出设备句柄
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOut, &csbi);
	
	printf("SizeofWidnows: Width: %d, Height: %d \n", csbi.dwSize.X, csbi.dwSize.Y);
	printf("PositionofCursor: X: %d, Height: Y:%d \n", csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y);
	

	
	
	// 设置输出环境的背景色和前景色	
	SetConsoleTextAttribute(hOut, 0x70);						
	printf("Good day! \n");
	SetConsoleTextAttribute(hOut, 0x07);   // 黑底白字    
	printf("Good day! \n");
	
	// 
	int width = 120, height = 30;
	// 设置光标到控制台的中心
	curpos.X = width/2;
	curpos.Y = height /2;
	
	
	
	
	// 在中心位置输出一句话	
	char * message = "This is the center of the console!";
	int cnt = sizeof(message);      // 这句不对，因为message是指针，所以大小是4或8 
	printf("sizeof(message) : %d \n", cnt);
	cnt = strlen(message);
	printf("strlen(message) : %d \n", cnt); 
	
	
	// 计算字符串的长度，放到中心
	curpos.X = (width-cnt)/2;		// width/2 - cnt/2 = (width-cnt)/2	
	SetConsoleTextAttribute(hOut, 0xF0 | 0x04);		// C和C++都没有提供二进制数的表达方法
	//system("cls");				// 清屏
	SetConsoleCursorPosition(hOut, curpos);
	printf("%s", message);
	
	
	// 关闭句柄
	CloseHandle(hOut);	
	printf("end...................");	          // 这一句不会输出，因为输出设备已经关闭了。	
}


void displayCursorPostion(COORD * pos){
	printf("Cursor Postion: [X: %d, Y: %d] \n", pos->X, pos->Y);
}


	// 0x00 全黑
    // 0xFF 全白	
	// 前4位是背景色，后4位是前景色
	// 遵循光的合成 （0是无，即黑。全有就是白光，白色） 0xF0 白底黑字


