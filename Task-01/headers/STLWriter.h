#pragma once
#include <string>
#include <vector>
#include <.\Triangle.h>
#include<string>
#include<unordered_map>
using namespace std;


class STLWriter
{
public:
    void fileWriter(string , Triangulation *, unordered_map<int, Point3D> &);
    static STLWriter* getInstance();
private:
    STLWriter();
    ~STLWriter();
    
    STLWriter(const STLWriter &other)=delete;
    STLWriter& operator=(const STLWriter&other)=delete;
    
    static STLWriter *stlWriter;
};
