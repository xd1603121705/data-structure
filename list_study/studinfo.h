#ifndef INCLUDE_STUDINFO_H
#define INCLUDE_STUDINFO_H
#include <string>
#include <fstream>

class StudentRecord
{
public:
	std::string name; // ���ﲻ��std::�ᱨ��error C4430��ȱ������˵���� - �ٶ�Ϊint
	float gpa;
public:
	// ��������������������ö���Ϊ��Ԫ����
	friend std::ifstream &operator >> (std::ifstream &fis, StudentRecord &item); // ��ʽ�����StudentRecord( name + GPA )
	friend std::ostream  &operator << (std::ostream & os, const StudentRecord item); // ���ļ��ж�����( name + GPA )��StudentRecord�ͱ�����
};

std::ifstream& operator >>(std::ifstream & fis, StudentRecord &item)
{
	std::string name;
	float gpa;
	fis >> name >> gpa;
	item.gpa = gpa;
	item.name = name;
	return fis;
}

std::ostream  &operator << (std::ostream & os, const StudentRecord item)
{
	os << "name: " << item.name << " GPA: " << item.gpa;
	return os;
}

#endif