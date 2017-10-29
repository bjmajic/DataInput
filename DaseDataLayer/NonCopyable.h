#pragma once
/*
这是一个基本类，仅仅作为其他类的基类, 用来控制类的不可拷贝、复制
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

