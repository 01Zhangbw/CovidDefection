#include "head.h"


void _register() {//用户注册

	int i;
	User user;

	for (i = 0; i < 3; i++) {

		system("cls");
		char name[50] = { "registerMenu.txt" };//name的数组来存储后缀维持txt的文件名
		inFile(name);//读取registerMenu.txt里面的开始页面
		fflush(stdin);//清除缓冲区
		moveCursor(40, 14);//定位
		cin >> user.ID;//输入使用者的ID
		fflush(stdin);//清除缓冲区
		moveCursor(41, 16);//定位
		cin >> user.name;//输入使用者的名字
		moveCursor(45, 18);//定位
		cin >> user.password;//输入使用者的密码

		vector<User> user1;
		ifstream ifs;
		vector<string> vec;
		read(ifs, vec, user1);

		int boo = 0;//相当于bool变量，判断是否先前已注册
		int ii;
		for (ii = 0; ii < user1.size(); ii++) {
			if (user1[ii].ID == (user.ID)) {//用户名相同，即先前有其他用户已注册
				boo = 1;
				break;
			}
		}

		if (!boo) {
			moveCursor(40, 21);
			cout << "Success!";

			char name[15] = "userData.txt";
			ofstream outfile(name, std::ios::app);


			if (!outfile.is_open()) {
				cout << "canIDt open";
				exit(0);
			}
			outfile << user.ID << " ";//读入文件 ID
			outfile << user.name << " ";//读入文件 用户名
			outfile << user.password << endl;//读入文件 密码

			outfile.close();
			Sleep(1800);
			return;
		}
		else {
			moveCursor(13, 16);
			cout << "Failed! Please register again!" << endl;//请重新注册！
			moveCursor(13, 18);
			if (boo == 1)
				std::cout << "You have registered. Please log in!";//已注册，请登录！
			Sleep(2100);
		}
	}
}

void write_user(User user) {//写用户信息

	char name[15] = "user.txt";
	ofstream outfile(name);

	if (!outfile.is_open()) {
		printf("canIDt open %s\n", name);
		exit(0);
	}
	outfile << user.ID << " ";
	outfile << user.name << " ";
	outfile << user.password << endl;
	outfile.close();

}

void rankings() {//排名

	system("cls");

	ifstream readfile("rankings.txt");

	const int LINE_LENGTH = 200;
	char str[LINE_LENGTH];
	while (readfile.getline(str, LINE_LENGTH))
	{
		cout << str << endl;
	}
	readfile.close();
}