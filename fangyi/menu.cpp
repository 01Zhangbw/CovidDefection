#include "head.h"


void printMenu1(int a) {

	system("cls");
	char name[50] = { "mainMenu.txt" };//mainMenu.txt存取的开始界面
	inFile(name);

	switch (a) {
	case 1:printCursor(80, 25); break;//显示光标
	case 2:printCursor(80, 31); break;
	default:break;
	}
}

int chooseOption(int num, void (*p)(int)) {

	int a = 1;
	int key = 1;

	while (1) {

		(*p)(a);
		fflush(stdin);//清除缓冲区
		key = _getch();//获取按键，但是只进入缓冲区而不输出的函数_getch
		if (key == 244 || key == 0)
			key = _getch();
		if (key == 72)
			a--;//up
		else if (key == 80)
			a++;
		else if (key >= 48 && key <= 57)
			return key - 48;//由字符转化为数字（ 0的ASCⅡ为48 ）
		else if (key == 27)
			return 0;//Esc
		else if (key == 13)
			return a;
		else;
		if (a == num)
			a = 0;
		if (a == -1)
			a = num - 1;
	}
}

void moveCursor(int x, int y) {//光标定位
	//(列,行)
	COORD coord = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void printCursor(int x, int y) {//显示光标

	moveCursor(x, y);
	cout << "<<--";
	moveCursor(x + 3, y);

}


void inFile(char name[15]) {
	system("cls");

	ifstream readfile(name);

	if (!readfile.is_open()) {//无法打开文件的异常处理
		printf("cannot open %s\n", name);
		exit(0);
	}

	const int LINE_LENGTH = 200;
	char str[LINE_LENGTH];
	while (readfile.getline(str, LINE_LENGTH))//将LINE_LENGTH的长度的txt的一行内容赋值给str
	{
		cout << str << endl;//输出
	}
	readfile.close();

}
