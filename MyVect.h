#ifndef MYVECT_H
#define MYVECT_H
#pragma once
class MyVect
{
public:
    MyVect();
    MyVect(int n);
    MyVect(const MyVect& other);            //拷贝构造函数
    MyVect& operator = (const MyVect& rhs); //重载赋值符
    void push_back(double var);
    double pop_back();
    void insert(int n, double var);
    void erase(int n);
    void reallocate();                      //重新分配内存
    void clear();
    void print();
    double& operator[](int n);              //重载[]符
    const double& operator[](int n)const;   //const成员函数，返回值是const
    virtual ~MyVect();
private:
    double* date;      //数组指针
    int date_size;     //数组实际大小
    int date_capacity; //数组容量
};
#endif // MYVECT_H
