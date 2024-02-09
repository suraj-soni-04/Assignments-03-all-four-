#include <..\headers\ObjReader.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
void ObjReader::fileReader(string filePath, vector<Point3D> &uniquePoints, vector<Triangle> &triangles)
{
    ifstream objFile(filePath);
    if (!objFile.is_open())
    {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(objFile, line))
    {
        istringstream iss(line);
        string type;
        iss >> type;

        if (type == "v")
        {
            string x, y, z;
            iss >> x >> y >> z;
            Point3D point3D(stod(x), stod(y), stod(z));
            uniquePoints.push_back(point3D);
        }
        else if (type == "f")
        {
            string vertexIndex;
            Triangle triangle(0, 0, 0);
            vector<string> tmp;
            for (int i = 0; i < 3; ++i)
            {
                iss >> vertexIndex;
                tmp.push_back(vertexIndex);
            }
            triangle.setMvertex1(stoi(tmp[tmp.size() - 3]));
            triangle.setMvertex2(stoi(tmp[tmp.size() - 2]));
            triangle.setMvertex3(stoi(tmp[tmp.size() - 1]));
            tmp.clear();
            triangles.push_back(triangle);
        }
    }
    objFile.close();
}
