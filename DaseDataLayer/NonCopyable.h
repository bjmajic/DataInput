#pragma once
/*
����һ�������࣬������Ϊ������Ļ���, ����������Ĳ��ɿ���������
*/
class NonCopyable
{
public:
	NonCopyable(){}
	~NonCopyable(){}
private:
	NonCopyable(const NonCopyable&);
	NonCopyable& operator = (const NonCopyable&);
};

