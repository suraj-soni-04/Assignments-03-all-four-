#include <vector>
#include <..\headers\Triangle.h>
#include <..\headers\Triangulation.h>
#include <..\headers\Point3D.h>
#include <..\headers\STLWriter.h>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
void STLWriter::fileWriter(string filePath,vector<Point3D> &points,vector<Triangle> &triangles,unordered_map<int,Point3D> &mapping)
{

    ofstream outFile(filePath);
    if (!outFile.is_open())
    {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    for (Triangle &triangle : triangles)
    {
        auto i1=mapping[triangle.getVertex1()];
        auto i2=mapping[triangle.getVertex2()];
        auto i3=mapping[triangle.getVertex3()];
        outFile <<  i1.getMX() << " " << i1.getMY() << " " << i1.getMZ() << endl;
        outFile <<  i2.getMX() << " " << i2.getMY() << " " << i2.getMZ() << endl;
        outFile <<  i3.getMX() << " " << i3.getMY() << " " << i3.getMZ() << endl;
    }

    outFile.close();
}
