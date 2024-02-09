#pragma once
#include <.\Triangle.h>
#include<.\Point3D.h>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class STLReader
{
public:
    void fileReader(const string &filePath, vector<Point3D> &points, vector<Triangle> &triangles, unordered_map<int, Point3D> &mapping);
};