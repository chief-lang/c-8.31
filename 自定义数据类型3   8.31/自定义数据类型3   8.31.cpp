// 自定义数据类型3   8.31.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//结构体的内存计算方法    注意：一个基本数据应保持完整
struct One
{
	int a;//int占4个字节
	int b;
	char c;//char占1个字节
};
//内存对齐标准：以该结构体中最大的基本数据类型所占的内存进行对齐（因为最大字节为四个字节，所以char也分配四个字节，但自己只占一个字节，空三个字节）
struct Two
{
	int a;
	char b[10];//此时char有10个一个字节的，最大字节仍为4，分为4 4 2，而根据内存对齐标准：2变为4
	float c;//float占4个字节
};
struct Three
{
	double a;//double分配8个字节
	int b;//b对齐配8个字节
	char c[10];//此时10个字节分4个字节到b的空位，还剩6个字节占剩下的8个字节位
};
struct Four
{
	int a;//a占四个字节，剩下四个b来补
	char b[10];//此时b剩6个占到下一个8个字节位，c补一个。
	char c;//最后8个字节位由d占规划 
	double d;
};

//特殊
struct Five
{
	char a;
	int b;//先按照4个字节
	char c[10];
	double d;//然后按照8个字节
};
int main()
{
	printf("One的字节数为%d\n", sizeof(One));//sizeof是求字节数的
	printf("Two的字节数为%d\n", sizeof(Two));
	printf("Three的字节数为%d\n", sizeof(Three));
	printf("Four的字节数为%d\n", sizeof(Four));
	printf("Five的字节数为%d\n", sizeof(Five));
}
