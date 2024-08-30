// This file is creating a csv file. Reading that csv file creating an stl file to generate a cuboid.

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <sstream> // Required for std::stringstream
using namespace std;

struct Vertex
{
    double x, y, z;
};

Vertex findNormal(const Vertex &v1, const Vertex &v2, const Vertex &v3)
{
    // Calculate normal
    double normalX = (v2.y - v1.y) * (v3.z - v1.z) - (v2.z - v1.z) * (v3.y - v1.y);
    double normalY = (v2.z - v1.z) * (v3.x - v1.x) - (v2.x - v1.x) * (v3.z - v1.z);
    double normalZ = (v2.x - v1.x) * (v3.y - v1.y) - (v2.y - v1.y) * (v3.x - v1.x);

    // Normalize the normal
    double length = std::sqrt(normalX * normalX + normalY * normalY + normalZ * normalZ);
    normalX /= length;
    normalY /= length;
    normalZ /= length;

    Vertex normal = {normalX, normalY, normalZ};
    return normal;
}

void writeCSV(const vector<vector<double>> &Node, const vector<vector<int>> &Triangle)
{
    std::ofstream writeFile("write_cuboid.csv"); // creating file... write_cuboid.csv
    // writeFile << "x" << "," << "y" << "," <<"z";
    for (size_t i = 0; i < Node.size(); ++i)
    {
        writeFile << Node[i][0] << "," << Node[i][1] << "," << Node[i][2] << "\n";
    }
    // writeFile << "pos1" << "," << "pos2" << "," << "pos3\n";
    for (size_t i = 0; i < Triangle.size(); ++i)
    {
        writeFile << Triangle[i][0] << "," << Triangle[i][1] << "," << Triangle[i][2] << "\n";
    }
    writeFile.close();
}

void writeSTL(vector<vector<int>> Triangle)
{
    ifstream inputFile("write_cuboid.csv"); // input stream, reading now
    vector<vector<double>> Node;            // container

    if (inputFile.is_open())
    {
        std::string line;
        for (int i = 0; i < 8; ++i)
        {
            getline(inputFile, line);
            vector<double> temp;
            std::stringstream ss(line);
            string cell;

            while (getline(ss, cell, ','))
            {
                temp.push_back(stod(cell));
            }
            Node.push_back(temp);
        }
        inputFile.close();
    }
    else
    {
        std::cerr << "Error opening file: " << "write_cuboid.csv" << endl;
    }

    ofstream stlFile("cuboid.stl"); // out stream, writing .stl file now

    stlFile << "solid cuboid\n";

    for (int i = 0; i < 12; ++i)
    {
        int pos1 = Triangle[i][0], pos2 = Triangle[i][1], pos3 = Triangle[i][2];
        Vertex v1 = {Node[pos1][0], Node[pos1][1], Node[pos1][2]};
        Vertex v2 = {Node[pos2][0], Node[pos2][1], Node[pos2][2]};
        Vertex v3 = {Node[pos3][0], Node[pos3][1], Node[pos3][2]};

        Vertex normal = findNormal(v1, v2, v3);

        // Write the facet to the STL file
        stlFile << "  facet normal " << normal.x << " " << normal.y << " " << normal.z << "\n";
        stlFile << "    outer loop\n";

        stlFile << "      vertex " << v3.x << " " << v3.y << " " << v3.z << "\n";

        stlFile << "      vertex " << v2.x << " " << v2.y << " " << v2.z << "\n";

        stlFile << "      vertex " << v1.x << " " << v1.y << " " << v1.z << "\n";

        stlFile << "    endloop\n";
        stlFile << "  endfacet\n";
    }

    stlFile << "endsolid cuboid\n";

    stlFile.close();

    std::cout << "cuboid.stl file has been generated." << std::endl;
}

int main()
{
    double length = 1, width = 1, height = 1;
    cout << "Enter the cuboid length, width and height: \n";
    cin >> length >> width >> height;
    vector<vector<double>> Node = {
        {0, 0, 0},
        {0, width, 0},
        {length, width, 0},
        {length, 0, 0},
        {length, 0, height},
        {length, width, height},
        {0, width, height},
        {0, 0, height}};

    vector<vector<int>> Triangle = {
        {0, 2, 1},
        {0, 3, 2},
        {3, 5, 2},
        {3, 4, 5},
        {1, 2, 5},
        {1, 5, 6},
        {0, 7, 4},
        {0, 4, 3},
        {7, 6, 5},
        {7, 5, 4},
        {0, 1, 6},
        {0, 6, 7}};
    writeCSV(Node, Triangle);
    writeSTL(Triangle); // write .stl file by reading the write_cuboid.csv file
    return 0;
}