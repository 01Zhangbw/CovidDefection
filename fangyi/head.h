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
	string rightAnswer;//��ȷѡ��
	string optionsA;//ѡ��A
	string optionsB;//ѡ��B
	string optionsC;//ѡ��C
	string optionsD;//ѡ��D
	string statement;//��Ŀ����
	int rightTime;//��ԵĴ���

};

class User {
public:
	string ID;//�û�ѧ��
	string name;//�û���
	string password;//�û�����
	float m_score;
};

void printMenu1(int a);//��ӡ��ʼҳ��
int chooseOption(int num, void (*p)(int));//ѡ��
void moveCursor(int x, int y);//��궨λ
void printCursor(int x, int y);//��ʾ���
void inFile(char name[15]);

void read(ifstream& ifs, vector<string>& vec, vector<User>& user);
void user();//�û������û������������
void user_login(User user);//��¼
void printMenu2(int a);//��ӡ����ҳ��
void exam(User user);//����
void readTest(ifstream& ifs, vector<string>& vec, vector<Info>& info);

void _register();//�û�ע��
void write_user(User user);//д�û���Ϣ
void rankings();//���а�
vector<int> random(int n);//���������