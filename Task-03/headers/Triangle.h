#pragma once
class Triangle
{
public:
    Triangle();
    Triangle(int , int , int);
    ~Triangle();

    int getVertex1();
    int getVertex2();
    int getVertex3();
    int getNormalIndex();

    void setMvertex1(int);
    void setMvertex2(int);
    void setMvertex3(int);
    void setMnormalIndex(int);

private:
    int mVertex1;
    int mVertex2;
    int mVertex3;
    int mNormalIndex;
};
