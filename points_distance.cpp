#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>


struct Point {
    double x, y, z;
};

double calculatePerpendicularDistance(const Point& A, const Point& B, const Point& C) {
    // Calculate vector AB
    Point AB = {B.x - A.x, B.y - A.y, B.z - A.z};
    // Calculate vector AC
    Point AC = {C.x - A.x, C.y - A.y, C.z - A.z};
    
    Point crossProduct = {
        AB.y * AC.z - AB.z * AC.y,
        AB.z * AC.x - AB.x * AC.z,
        AB.x * AC.y - AB.y * AC.x
    };
    
    // Magnitude of cross product
    double crossProductMagnitude = std::sqrt(
        crossProduct.x * crossProduct.x +
        crossProduct.y * crossProduct.y +
        crossProduct.z * crossProduct.z
    );
    
    // Magnitude of AB
    double AB_magnitude = std::sqrt(
        AB.x * AB.x + 
        AB.y * AB.y + 
        AB.z * AB.z
    );
    
    return crossProductMagnitude / AB_magnitude;
}

void processCSV(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);
    
    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(inputFile, line);   // input file se line me copy ho gaya
    outputFile << line << ",perpendicular_distance" << std::endl;  

    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string value;
        std::vector<double> coords;
        
        while (std::getline(ss, value, ',')) {
            coords.push_back(std::stod(value));
        }
        
        if (coords.size() == 9) {
            Point A = {coords[0], coords[1], coords[2]};
            Point B = {coords[3], coords[4], coords[5]};
            Point C = {coords[6], coords[7], coords[8]};
            
            double distance = calculatePerpendicularDistance(A, B, C);
            
            
            outputFile << line << "," << distance << std::endl;
        }
    }
    
    inputFile.close();
    outputFile.close();
}

int main() {
    std::string inputFilename = "points.csv";                     
    std::string outputFilename = "points_with_distances.csv";     
    processCSV(inputFilename, outputFilename);
    
    std::cout << "Perpendicular distances added to " << outputFilename << std::endl;
    return 0;
}
