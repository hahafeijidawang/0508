#include <MyVect.h>
#include<iostream>
using namespace std;

MyVect::MyVect()
{
    date = nullptr;
    date_size = 0;
    date_capacity = 0;
}

MyVect::MyVect(int n)
{
    date_size = n;
    date_capacity = 2 * n + 1;
    date = new double[date_capacity];
}

double& MyVect::operator[](int n)
{
    return date[n];
}

const double& MyVect::operator[](int n) const //常成员函数供常对象调用
{
    return date[n];
}

MyVect& MyVect::operator=(const MyVect& rhs) //重载赋值符
{
    if (this == &rhs)
    {
        return *this;
    }
    date_capacity = rhs.date_capacity;
    date_size = rhs.date_size;
    if (date != nullptr)
    {
        delete[] date;
    }
    date = new double[date_capacity];
    for (int i = 0; i < rhs.date_size; i++)
    {
        date[i] = rhs.date[i];
    }
    return *this;
}

MyVect::MyVect(const MyVect& other)
{
    this->date_size = other.date_size;
    this->date_capacity = other.date_capacity;
    date = new double[date_capacity];
    for (int i = 0; i < date_size; i++)
    {
        date[i] = other.date[i];
    }
}
void MyVect::reallocate()  //重新分配内存
{
    if (date_size == date_capacity)
    {
        double* old = date;
        date_capacity = 2 * date_size + 1;
        date = new double[date_capacity];
        for (int i = 0; i < date_size; i++)
        {
            date[i] = old[i];
        }
        if (old != nullptr)
            delete[] old;
    }
}

void MyVect::push_back(double var)
{
    this->reallocate();
    date[date_size] = var;
    date_size++;
}

double MyVect::pop_back()
{
    double out = date[date_size-1];
    date_size--;
    return out;
}

void MyVect::insert(int n, double var)
{
    reallocate();
    for (int i = date_size; i >n; i--)
    {
        date[i] = date[i-1];
    }
    date[n] = var;
    date_size++;
}

void MyVect::erase(int n)
{
    for (int i = n; i < date_size; i++)
    {
        date[i] = date[i + 1];
    }
    date_size--;
}

void MyVect::clear()
{
    date_size = 0;
    date_capacity = 0;
    if (date != nullptr)
        delete [] date;
    date = nullptr; //此句不可忘，否则析构时删除野指针出现内存错误
}

void MyVect::print()
{
    for (int i = 0; i < date_size; i++)
        cout << date[i] << '\t';
    cout << endl;
}

MyVect::~MyVect()
{
    date_size = 0;
    date_capacity = 0;
    if (date!=nullptr)
    {
        delete[] date;
    }
    date = nullptr;
    //cout << "析构啦！" << endl;
}
