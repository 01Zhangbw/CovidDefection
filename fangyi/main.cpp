#include "head.h"

int main()
{
	system("title 防疫我争先");//小程序的主题
	system("mode con cols=100 lines=38");

	while (1) {
		int a = chooseOption(4, printMenu1);
		switch (a) {
		case 1:
			user();//用户登录
			continue;
		case 2:
			_register();//用户注册
			continue;
		default:break;
		}
	}
	system("pause");
	return 0;
}


