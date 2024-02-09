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

STLReader* STLReader::getInstance()
{
    if(stlReader==nullptr) stlReader=new STLReader();
    return stlReader;
}
STLReader *STLReader::stlReader=nullptr;

STLReader::STLReader()
{

}


void STLReader::fileReader(string &filePath, Triangulation *triangulation,unordered_map<int,Point3D> &mapping)
{

    cout<<"t : "<<unsigned(triangulation)<<"--"<<endl;
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
    vector<Vertex> vertex;
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
            
            vertexx.x=stod(x);
            vertexx.y=stod(y);
            vertexx.z=stod(z);

            vertex.push_back(vertexx);
            vertexCount++;
            

            point3D.setmX(stod(x));
            point3D.setmY(stod(y));
            point3D.setmZ(stod(z));

    
            //code to map
            if(mapping.size()<3)
            {
                mapping[position]=point3D;
                position++;
                cout<<"size  b : "<<triangulation->getPoints().size()<<endl;
                triangulation->getPoints().push_back(point3D);
                
                // points->push_back(point3D);
                // //(*points).push_back(point3D);
            
                // //triangulation->getPoints().push_back(point3D);
                // // auto ii=triangulation->getPoints();
                // // ii->push_back(point3D);
                
                // //triangulation->getPoints()->push_back(point3D);
                // // cout<<"Address : "<< addressof(*ii)<<endl;
                // // cout<<"-Address : "<< addressof(ii)<<endl;
                
                // //triangulation->getPoints().push_back(point3D);
                cout<<"size  a : "<<triangulation->getPoints().size()<<endl;
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
                    //triangulation->getPoints().push_back(point3D);
                }
            }
            
            
            if(vertexCount==3)
            {
                vector<int> tmpArr; 
                Comparator comparator;
                for(auto i:vertex)
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
                triangulation->getTriangles().push_back(triangle);            
                vertex.clear();
            }
        }
    }
    inputFile.close();
}
