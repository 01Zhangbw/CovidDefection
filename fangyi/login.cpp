#include "head.h"

void read(ifstream& ifs, vector<string>& vec, vector<User>& user)
{

	User user_1;
	ifs.open("userData.txt");//打开userData.txt
	string str;
	char c;
	int i = 0;
	while (ifs.get(c))//其原理与testData.txt类似
	{

		if (c != ' ' && c != ',' && c != '.' && c != '\n')
			str += c;
		else
		{
			if (str != "") {
				vec.push_back(str);//将str的值压入vec容器（vector）
				i += 1;
				if (i == 1) {

					user_1.ID = (str);//当i=1， str赋值为用户的ID

				}
				if (i == 2) {

					user_1.name = (str);//当i=2， str赋值为用户的名字
				}
				if (i == 3) {
					user_1.password = str;//当i=3， str赋值为用户的密码
					user.push_back(user_1);//将user_1 的信息压入user容器
				}
				if (i == 3) {

					i = 0;//开始新的用户信息读取
				}
				str = "";//将str置空
			}
		}
	}

	if (ifs.is_open())
		ifs.close();//将文件关闭

}


void user() {

	while (1) {

		int i;

		string get_1, get_2;
		for (i = 0; i < 1; i++) {

			system("cls");//清屏
			char name[50] = { "loginMenu.txt" };//用一个loginMenu.txt保存登录界面的图案，避免代码不必要的冗长
			inFile(name);//读取
			fflush(stdin);//清除缓冲区，避免enter等按键的不必要影响
			moveCursor(40, 20);//坐标定位
			fflush(stdin);//清除缓冲区
			cin >> get_1;//输入用户名
			fflush(stdin);//清除缓冲区
			moveCursor(45, 22);//坐标定位
			cin >> get_2;//输入密码

		}

		system("cls");
		vector<User> user;
		ifstream ifs;
		vector<string> vec;
		read(ifs, vec, user);

		int ii;
		for (ii = 0; ii <= user.size(); ii++) {
			if (user[ii].ID == (get_1)) {//如果输入的用户名与userData.txt数据库中存储的相同，则进入密码的判断
				cout << "Loading...";
				break;
			}
		}
		if (user[ii].password == get_2) {//如果输入的密码与userData.txt数据库中存储的密码相同
			system("cls");//清屏
			cout << "Success!";//登录成功！
			Sleep(800);//停留8s，使用户更好进入答题状态

			user_login(user[ii]);
			break;
		}

		else {
			moveCursor(11, 17);
			cout << "Loading...";
			printf("Wrong password!");//密码错误
			Sleep(1300);
		}
	}
}

void user_login(User user) {

	int a;
	while (1) {
		a = chooseOption(3, printMenu2);
		switch (a) {
		case 1:
			exam(user);//进入考试界面
			continue;
		case 2:
			system("cls");
			rankings();//进入排名页面
			continue;
		default:break;
		}
		break;
	}

}


void printMenu2(int a) {


	system("cls");
	char name[50] = { "examMenu.txt" };//用examMenu.txt存取考试的菜单页面
	inFile(name);
	switch (a) {
		//显示光标
	case 1:printCursor(80, 25); break;
	case 2:printCursor(80, 31); break;
	default:break;
	}

}

void readTest(ifstream& ifs, vector<string>& vec, vector<Info>& info)
{

	Info info_1;//创建一个Info的对象

	char c;
	string str;
	ifs.open("testData.txt");//读取testData.txt
	int i = 0;
	while (!ifs.eof())//当txt中无内容时，停止读取操作
	{
		getline(ifs, str);//将testData.txt的内容的一行赋值到str

		if (str != "") {//当txt中无内容时，停止读取操作

			vec.push_back(str);//将str的内容压栈到vec容器中（vector）
			i += 1;
			if (i == 1) {
				info_1.statement = str;//当i为1时，str的内容为题目的题干，赋值到info_1的 题干 这一数据成员

			}
			if (i == 2) {
				info_1.optionsA = str;//当i为2时，str的内容为题目的A项，赋值到info_1的 optionA 这一数据成员

			}
			if (i == 3) {
				info_1.optionsB = str;//当i为3时，str的内容为题目的B项，赋值到info_1的 optionB 这一数据成员

			}
			if (i == 4) {
				info_1.optionsC = str;//当i为4时，str的内容为题目的C项，赋值到info_1的 optionC 这一数据成员

			}
			if (i == 5) {
				info_1.optionsD = str;//当i为5时，str的内容为题目的D项，赋值到info_1的 optionD 这一数据成员

			}
			if (i == 6) {
				info_1.rightAnswer = str;//当i为6时，即读取到正确答案这一内容
				info_1.rightTime = 0;//对题库中的一道题的被答对次数进行初始化
			}
			if (i == 6) {
				info.push_back(info_1);//将info_1这一对象压入info中
				i = 0;//重新将i的值赋为0，即开始进行下一道题目的读取
			}
			str = "";//将str置空
		}
	}
	if (ifs.is_open())
		ifs.close();//读取文件操作结束后，将其关闭
}