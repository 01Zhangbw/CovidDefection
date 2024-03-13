#include "head.h"


void printMenu1(int a) {

	system("cls");
	char name[50] = { "mainMenu.txt" };//mainMenu.txt��ȡ�Ŀ�ʼ����
	inFile(name);

	switch (a) {
	case 1:printCursor(80, 25); break;//��ʾ���
	case 2:printCursor(80, 31); break;
	default:break;
	}
}

int chooseOption(int num, void (*p)(int)) {

	int a = 1;
	int key = 1;

	while (1) {

		(*p)(a);
		fflush(stdin);//���������
		key = _getch();//��ȡ����������ֻ���뻺������������ĺ���_getch
		if (key == 244 || key == 0)
			key = _getch();
		if (key == 72)
			a--;//up
		else if (key == 80)
			a++;
		else if (key >= 48 && key <= 57)
			return key - 48;//���ַ�ת��Ϊ���֣� 0��ASC��Ϊ48 ��
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

void moveCursor(int x, int y) {//��궨λ
	//(��,��)
	COORD coord = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void printCursor(int x, int y) {//��ʾ���

	moveCursor(x, y);
	cout << "<<--";
	moveCursor(x + 3, y);

}


void inFile(char name[15]) {
	system("cls");

	ifstream readfile(name);

	if (!readfile.is_open()) {//�޷����ļ����쳣����
		printf("cannot open %s\n", name);
		exit(0);
	}

	const int LINE_LENGTH = 200;
	char str[LINE_LENGTH];
	while (readfile.getline(str, LINE_LENGTH))//��LINE_LENGTH�ĳ��ȵ�txt��һ�����ݸ�ֵ��str
	{
		cout << str << endl;//���
	}
	readfile.close();

}
