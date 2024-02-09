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
    void fileWriter(string filePath,vector<Point3D> &points,vector<Triangle> &triangles,unordered_map<int,Point3D> &mapping);
};
