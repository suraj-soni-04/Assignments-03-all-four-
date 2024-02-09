#pragma once
#include <.\Triangle.h>
#include<.\Point3D.h>
#include<.\Triangulation.h>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class STLReader
{
public:
    void fileReader(string &, Triangulation *, unordered_map<int, Point3D> &);
    static STLReader* getInstance();
private:
    STLReader();
    ~STLReader();
    
    STLReader(const STLReader&other)=delete;
    STLReader& operator=(const STLReader&other)=delete;
    
    static STLReader *stlReader;
};
