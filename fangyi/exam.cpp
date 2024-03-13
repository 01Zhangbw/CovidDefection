#include"head.h"

vector<int> random(int n)//����һ����0 ~n-1��vector������������� 
{
	vector<int> temp;
	for (int i = 0; i < n; i++)
		temp.push_back(i);
	random_shuffle(temp.begin(), temp.end());
	return temp;
}

void exam(User user) {
	system("cls");//����
	ifstream ifs;//����һ��ifstream�Ķ���
	vector<string> vec;//
	vector<Info> info;//����һ���洢������Ϣ������

	readTest(ifs, vec, info);//��ȡ��������

	int key, num, a, b;
	int i = 0;
	float score = 0;//��ʼ��������ֵΪ0


	cout << "--------------------------Start------------------------------" << endl;//��ʼ����
	cout << "��������Ŀ����: ";//��ʾ�û������Լ���������������û��Զ��壬����ѡ��������Ŀ���������迼��һ�������ɶ�
	fflush(stdin);//���������
	cin >> num;//�û����������������

	vector<int> ii = random(37);//����һ��0 ~ n-1����������� ��nΪ�������Ŀ��������

	cout << "����������Կ�ʼ!" << endl;//��ʾ�û��������


	key = cin.get();//��ȡ���������ָ��
	if (key == 0 || key == 224 || key == -32)
		key = cin.get();
	//��ʼ
	while (i < num)
	{
		if (info[ii[i]].rightTime <= 5)//����ϵͳ�������ͣ����������Ŀ����ԵĴ���������Σ�����Ϊ����Ŀ�ѶȽ�С�����ٳ�
		{
			cout << "��" << i + 1 << "��";//i��ʾ��Ŀ��ż�1��ֵ

			cout << info[ii[i]].statement << endl;//������
			cout << info[ii[i]].optionsA << endl;//���A��
			cout << info[ii[i]].optionsB << endl;//���B��
			cout << info[ii[i]].optionsC << endl;//���C��
			cout << info[ii[i]].optionsD << endl;//���D��


			string answer;
			cout << "***������:";//��ʾ��������

			cin >> answer;//���������

			if (answer == info[ii[i]].rightAnswer) {
				score += (float)(100.0 / num);//������Ŀ����Ϊ�Զ��壬��˵�����������仯
				info[ii[i]].rightTime++;//����Ŀ����ԵĴ���++
				cout << "����ȷ!" << endl;
			}
			else {
				cout << "�𰸴���!" << endl;
			}
			cout << "---------��ǰ����:" << score << "��------" << endl;

			Sleep(1800);//ֹͣ1.8s
			i++;//��ת����һ��
		}
		else//����������ʱ
		{
			i++;
			num++;
		}
	}
	cout << "�������!" << endl;
	cout << "��ķ�����" << score << endl;

	char name[15] = "rankings.txt";//��ȡ���а��ļ�
	ofstream outfile(name, std::ios::app);//�������������ӵ��ļ���β


	if (!outfile.is_open()) {//�޷����ļ����쳣����
		cout << "cannot open";

		exit(0);
	}

	outfile << "ѧ�ţ�" << user.ID << " ";//д��txt�û���ѧ����Ϣ
	outfile << "���Գɼ���" << score << " ";//д��txt�û����Գɼ���Ϣ

	outfile.close();
	Sleep(1800);

	system("pause");
}