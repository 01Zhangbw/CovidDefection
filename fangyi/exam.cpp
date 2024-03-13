#include"head.h"

vector<int> random(int n)//生成一个有0 ~n-1的vector容器随机数数组 
{
	vector<int> temp;
	for (int i = 0; i < n; i++)
		temp.push_back(i);
	random_shuffle(temp.begin(), temp.end());
	return temp;
}

void exam(User user) {
	system("cls");//清屏
	ifstream ifs;//创建一个ifstream的对象
	vector<string> vec;//
	vector<Info> info;//建立一个存储试题信息的容器

	readTest(ifs, vec, info);//读取试题的题库

	int key, num, a, b;
	int i = 0;
	float score = 0;//初始化分数的值为0


	cout << "--------------------------Start------------------------------" << endl;//开始答题
	cout << "请输入题目数量: ";//提示用户输入自己所答的题数。由用户自定义，自主选择所答题目数量，给予考生一定的自由度
	fflush(stdin);//清除缓冲区
	cin >> num;//用户输入所答题的数量

	vector<int> ii = random(37);//产生一个0 ~ n-1的随机数数组 （n为题库中题目的数量）

	cout << "按任意键考试开始!" << endl;//提示用户进入答题


	key = cin.get();//获取键盘输入的指令
	if (key == 0 || key == 224 || key == -32)
		key = cin.get();
	//开始
	while (i < num)
	{
		if (info[ii[i]].rightTime <= 5)//答题系统的智能型，当所答的题目被答对的次数超过五次，就认为此题目难度较小，不再出
		{
			cout << "第" << i + 1 << "题";//i表示题目编号减1的值

			cout << info[ii[i]].statement << endl;//输出题干
			cout << info[ii[i]].optionsA << endl;//输出A项
			cout << info[ii[i]].optionsB << endl;//输出B项
			cout << info[ii[i]].optionsC << endl;//输出C项
			cout << info[ii[i]].optionsD << endl;//输出D项


			string answer;
			cout << "***请作答:";//提示考生作答

			cin >> answer;//考生输入答案

			if (answer == info[ii[i]].rightAnswer) {
				score += (float)(100.0 / num);//由于题目数量为自定义，因此单题分数有所变化
				info[ii[i]].rightTime++;//该题目被答对的次数++
				cout << "答案正确!" << endl;
			}
			else {
				cout << "答案错误!" << endl;
			}
			cout << "---------当前分数:" << score << "分------" << endl;

			Sleep(1800);//停止1.8s
			i++;//跳转到下一题
		}
		else//当智能跳题时
		{
			i++;
			num++;
		}
	}
	cout << "考试完成!" << endl;
	cout << "你的分数是" << score << endl;

	char name[15] = "rankings.txt";//读取排行榜文件
	ofstream outfile(name, std::ios::app);//将输出的数据添加到文件结尾


	if (!outfile.is_open()) {//无法打开文件的异常处理
		cout << "cannot open";

		exit(0);
	}

	outfile << "学号：" << user.ID << " ";//写入txt用户的学号信息
	outfile << "考试成绩：" << score << " ";//写入txt用户考试成绩信息

	outfile.close();
	Sleep(1800);

	system("pause");
}