#pragma once
class Triangle
{
public:
    Triangle();
    Triangle(int , int , int );
    ~Triangle();

    int getVertex1();
    int getVertex2();
    int getVertex3();

    void setMvertex1(int);
    void setMvertex2(int);
    void setMvertex3(int);

private:
    int mVertex1;
    int mVertex2;
    int mVertex3;
};
