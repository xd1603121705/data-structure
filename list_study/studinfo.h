#ifndef INCLUDE_STUDINFO_H
#define INCLUDE_STUDINFO_H
#include <string>
#include <fstream>

class StudentRecord
{
public:
	std::string name; // 这里不加std::会报错：error C4430：缺少类型说明符 - 假定为int
	float gpa;
public:
	// 输入输出运算符的重载最好定义为友元函数
	friend std::ifstream &operator >> (std::ifstream &fis, StudentRecord &item); // 格式化输出StudentRecord( name + GPA )
	friend std::ostream  &operator << (std::ostream & os, const StudentRecord item); // 从文件中读数据( name + GPA )到StudentRecord型变量中
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