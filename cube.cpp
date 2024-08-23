#include <iostream>
#include <fstream>
#include <cmath>

const int boxLength=5;

struct Vertex {
    double x, y, z;
};

Vertex findNormal(const Vertex& v1, const Vertex& v2, const Vertex& v3){
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

void writeSTL(int Triangle[][3], Vertex Node[8] ) {
    
    std::ofstream stlFile("cube.stl");

    stlFile << "solid cube\n";

    for(int i=0; i<12; ++i){
        int pos1=Triangle[i][0],pos2=Triangle[i][1],pos3=Triangle[i][2];
        Vertex v1=Node[pos1];
        Vertex v2=Node[pos2];
        Vertex v3=Node[pos3];

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

    stlFile << "endsolid cube\n";

    stlFile.close();

    std::cout << "cube.stl file has been generated." << std::endl;

}


int main() {

    Vertex Node[8]={
        {0,0,0},
        {0,boxLength,0},
        {boxLength,boxLength,0},
        {boxLength,0,0},
        {boxLength,0,boxLength},
        {boxLength,boxLength,boxLength},
        {0,boxLength,boxLength},
        {0,0,boxLength}
    };

    int Triangle[12][3]={
        {0,2,1},
        {0,3,2},
        {3,5,2},
        {3,4,5},
        {1,2,5},
        {1,5,6},
        {0,7,4},
        {0,4,3},
        {7,6,5},
        {7,5,4},
        {0,1,6},
        {0,6,7}
    };

    writeSTL(Triangle, Node);
    return 0;
}