#include <..\headers\STLReader.h>
#include <..\headers\Triangulation.h>
#include <..\headers\Triangle.h>
#include <..\headers\Point3D.h>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


struct Vertex {
    int x, y, z;
};
class Comparator
{
    public:
        bool operator()(Point3D &p1, Point3D &p2)
        {
            if (p1.getMX() != p2.getMX())  return p1.getMX() < p2.getMX();
            if (p1.getMY() != p2.getMY())  return p1.getMY() < p2.getMY();
            return p1.getMZ() < p2.getMZ();
        }
};

void STLReader::fileReader(const string &filePath, vector<Point3D> &points,vector<Triangle> &triangles,unordered_map<int,Point3D> &mapping)
{

    int size=0;
    int vertexCount=0;
    int position=0;
    vector<int> lastThreeKeys;
    ifstream inputFile(filePath);
    if (!inputFile.is_open())
    {
        cerr << "Error opening file." << endl;
        return;
    }

    string line;
    vector<Point3D> vertices;
    vector<Vertex> vvv;
    while (getline(inputFile, line))
    {
        if (line.find("vertex") != string::npos)
        {
            Point3D point3D;
            string x, y, z;
            Vertex vertexx;
            istringstream iss(line);
            string discard;

            iss >> discard >> x >> y >> z;
            
            vertexx.x=stof(x);
            vertexx.y=stof(y);
            vertexx.z=stof(z);

            vvv.push_back(vertexx);
            vertexCount++;
            

            point3D.setmX(stod(x));
            point3D.setmY(stod(y));
            point3D.setmZ(stod(z));

            //code to map
            if(mapping.size()<3)
            {
                mapping[position]=point3D;
                position++;
                points.push_back(point3D);
            }
            else
            {
                //code to compare the point3D object in the map
                Comparator comparator;
                auto it = find_if(mapping.begin(), mapping.end(), [&](auto &pair) {
                    return !comparator(point3D, pair.second) && !comparator(pair.second, point3D);
                });

                //Point3D not found in the map, do something
                if (it == mapping.end())
                {
                    mapping[position]=point3D;
                    position++;
                    points.push_back(point3D);
                }
            }
            
            
            if(vertexCount==3)
            {
                vector<int> tmpArr; 
                Comparator comparator;
                for(auto i:vvv)
                {
                    Point3D tmpPoint(i.x,i.y,i.z);
                    //code to search the tmpPoint object values in the map an return its key from the map
                    Comparator comparator;
                    auto it = find_if(mapping.begin(), mapping.end(), [&](auto &pair) {
                    return !comparator(tmpPoint, pair.second) && !comparator(pair.second, tmpPoint);
                    });

                    // Check if the point is found in the map
                    if (it != mapping.end())
                    {
                        tmpArr.push_back(it->first); // Add the key to tmpArr
                    }
                
                }
                vertexCount=0;
                Triangle triangle(tmpArr[0],tmpArr[1],tmpArr[2]);
                triangles.push_back(triangle);            
                vvv.clear();
            }
        }
    }
    inputFile.close();
}
