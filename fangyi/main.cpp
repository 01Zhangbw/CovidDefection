#include "head.h"

int main()
{
	system("title ����������");//С���������
	system("mode con cols=100 lines=38");

	while (1) {
		int a = chooseOption(4, printMenu1);
		switch (a) {
		case 1:
			user();//�û���¼
			continue;
		case 2:
			_register();//�û�ע��
			continue;
		default:break;
		}
	}
	system("pause");
	return 0;
}


