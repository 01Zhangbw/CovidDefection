#pragma once

#include <iostream>
#include<string>
#include<cstring>
#include <Windows.h>
#include<stdio.h>
#include<vector>
#include<ctime>
#include <fstream>
#include<algorithm>
#include<conio.h>
using namespace std;

class Info {
public:
	string rightAnswer;//正确选项
	string optionsA;//选项A
	string optionsB;//选项B
	string optionsC;//选项C
	string optionsD;//选项D
	string statement;//题目描述
	int rightTime;//答对的次数

};

class User {
public:
	string ID;//用户学号
	string name;//用户名
	string password;//用户密码
	float m_score;
};

void printMenu1(int a);//打印开始页面
int chooseOption(int num, void (*p)(int));//选择
void moveCursor(int x, int y);//光标定位
void printCursor(int x, int y);//显示光标
void inFile(char name[15]);

void read(ifstream& ifs, vector<string>& vec, vector<User>& user);
void user();//用户输入用户名及密码界面
void user_login(User user);//登录
void printMenu2(int a);//打印考试页面
void exam(User user);//考试
void readTest(ifstream& ifs, vector<string>& vec, vector<Info>& info);

void _register();//用户注册
void write_user(User user);//写用户信息
void rankings();//排行榜
vector<int> random(int n);//随机数出题