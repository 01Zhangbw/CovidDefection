#include "head.h"

void read(ifstream& ifs, vector<string>& vec, vector<User>& user)
{

	User user_1;
	ifs.open("userData.txt");//��userData.txt
	string str;
	char c;
	int i = 0;
	while (ifs.get(c))//��ԭ����testData.txt����
	{

		if (c != ' ' && c != ',' && c != '.' && c != '\n')
			str += c;
		else
		{
			if (str != "") {
				vec.push_back(str);//��str��ֵѹ��vec������vector��
				i += 1;
				if (i == 1) {

					user_1.ID = (str);//��i=1�� str��ֵΪ�û���ID

				}
				if (i == 2) {

					user_1.name = (str);//��i=2�� str��ֵΪ�û�������
				}
				if (i == 3) {
					user_1.password = str;//��i=3�� str��ֵΪ�û�������
					user.push_back(user_1);//��user_1 ����Ϣѹ��user����
				}
				if (i == 3) {

					i = 0;//��ʼ�µ��û���Ϣ��ȡ
				}
				str = "";//��str�ÿ�
			}
		}
	}

	if (ifs.is_open())
		ifs.close();//���ļ��ر�

}


void user() {

	while (1) {

		int i;

		string get_1, get_2;
		for (i = 0; i < 1; i++) {

			system("cls");//����
			char name[50] = { "loginMenu.txt" };//��һ��loginMenu.txt�����¼�����ͼ����������벻��Ҫ���߳�
			inFile(name);//��ȡ
			fflush(stdin);//���������������enter�Ȱ����Ĳ���ҪӰ��
			moveCursor(40, 20);//���궨λ
			fflush(stdin);//���������
			cin >> get_1;//�����û���
			fflush(stdin);//���������
			moveCursor(45, 22);//���궨λ
			cin >> get_2;//��������

		}

		system("cls");
		vector<User> user;
		ifstream ifs;
		vector<string> vec;
		read(ifs, vec, user);

		int ii;
		for (ii = 0; ii <= user.size(); ii++) {
			if (user[ii].ID == (get_1)) {//���������û�����userData.txt���ݿ��д洢����ͬ�������������ж�
				cout << "Loading...";
				break;
			}
		}
		if (user[ii].password == get_2) {//��������������userData.txt���ݿ��д洢��������ͬ
			system("cls");//����
			cout << "Success!";//��¼�ɹ���
			Sleep(800);//ͣ��8s��ʹ�û����ý������״̬

			user_login(user[ii]);
			break;
		}

		else {
			moveCursor(11, 17);
			cout << "Loading...";
			printf("Wrong password!");//�������
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
			exam(user);//���뿼�Խ���
			continue;
		case 2:
			system("cls");
			rankings();//��������ҳ��
			continue;
		default:break;
		}
		break;
	}

}


void printMenu2(int a) {


	system("cls");
	char name[50] = { "examMenu.txt" };//��examMenu.txt��ȡ���ԵĲ˵�ҳ��
	inFile(name);
	switch (a) {
		//��ʾ���
	case 1:printCursor(80, 25); break;
	case 2:printCursor(80, 31); break;
	default:break;
	}

}

void readTest(ifstream& ifs, vector<string>& vec, vector<Info>& info)
{

	Info info_1;//����һ��Info�Ķ���

	char c;
	string str;
	ifs.open("testData.txt");//��ȡtestData.txt
	int i = 0;
	while (!ifs.eof())//��txt��������ʱ��ֹͣ��ȡ����
	{
		getline(ifs, str);//��testData.txt�����ݵ�һ�и�ֵ��str

		if (str != "") {//��txt��������ʱ��ֹͣ��ȡ����

			vec.push_back(str);//��str������ѹջ��vec�����У�vector��
			i += 1;
			if (i == 1) {
				info_1.statement = str;//��iΪ1ʱ��str������Ϊ��Ŀ����ɣ���ֵ��info_1�� ��� ��һ���ݳ�Ա

			}
			if (i == 2) {
				info_1.optionsA = str;//��iΪ2ʱ��str������Ϊ��Ŀ��A���ֵ��info_1�� optionA ��һ���ݳ�Ա

			}
			if (i == 3) {
				info_1.optionsB = str;//��iΪ3ʱ��str������Ϊ��Ŀ��B���ֵ��info_1�� optionB ��һ���ݳ�Ա

			}
			if (i == 4) {
				info_1.optionsC = str;//��iΪ4ʱ��str������Ϊ��Ŀ��C���ֵ��info_1�� optionC ��һ���ݳ�Ա

			}
			if (i == 5) {
				info_1.optionsD = str;//��iΪ5ʱ��str������Ϊ��Ŀ��D���ֵ��info_1�� optionD ��һ���ݳ�Ա

			}
			if (i == 6) {
				info_1.rightAnswer = str;//��iΪ6ʱ������ȡ����ȷ����һ����
				info_1.rightTime = 0;//������е�һ����ı���Դ������г�ʼ��
			}
			if (i == 6) {
				info.push_back(info_1);//��info_1��һ����ѹ��info��
				i = 0;//���½�i��ֵ��Ϊ0������ʼ������һ����Ŀ�Ķ�ȡ
			}
			str = "";//��str�ÿ�
		}
	}
	if (ifs.is_open())
		ifs.close();//��ȡ�ļ����������󣬽���ر�
}