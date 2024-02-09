#include <..\headers\ObjWriter.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
void ObjWriter::fileWriter(string filePath,vector<Point3D> &uniquePoints, vector<Triangle> &triangles)
{

    ofstream outFile(filePath);
    if (!outFile.is_open())
    {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }
    int index;
    for(int i=0;i<triangles.size();i++)
    {
        Triangle triangle=triangles[i];
        Point3D p1=uniquePoints[triangle.getVertex1()-1];
        Point3D p2=uniquePoints[triangle.getVertex2()-1];
        Point3D p3=uniquePoints[triangle.getVertex3()-1];
        outFile  << p1.getMX() << " " << p1.getMY() << " " << p1.getMZ() << endl;
        outFile  << p2.getMX() << " " << p2.getMY() << " " << p2.getMZ() << endl;
        outFile  << p3.getMX() << " " << p3.getMY() << " " << p3.getMZ() << endl;
    }
    outFile.close();
}