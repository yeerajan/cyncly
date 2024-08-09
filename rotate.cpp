#include <iostream>
#include <cmath>
using namespace std;

void rotateZ(float pi, float unit[3]){
    float rotVect[3][3];
    rotVect[0][0]=cos(pi);
    rotVect[0][1]=(-sin(pi));
    rotVect[0][2]=0;
    rotVect[1][0]=sin(pi);
    rotVect[1][1]=cos(pi);
    rotVect[1][2]=0;
    rotVect[2][0]=0;
    rotVect[2][1]=0;
    rotVect[2][2]=1;

    float result[3];
    for(int i=0; i<3; i++){
        float temp=0;
        for(int j=0; j<3; j++){
            temp+=(rotVect[i][j]*unit[j]);
        }
        result[i]=temp;
    }

    cout<<result[0]<<"i "<<result[1]<<"j "<<result[2]<<'k';

}

void rotateY(float pi, float unit[3]){
    float rotVect[3][3];
    rotVect[0][0]=cos(pi);
    rotVect[0][1]=0;
    rotVect[0][2]=sin(pi);
    rotVect[1][0]=0;
    rotVect[1][1]=1;
    rotVect[1][2]=0;
    rotVect[2][0]=(-sin(pi));
    rotVect[2][1]=0;
    rotVect[2][2]=cos(pi);

    float result[3];
    for(int i=0; i<3; i++){
        float temp=0;
        for(int j=0; j<3; j++){
            temp+=(rotVect[i][j]*unit[j]);
        }
        result[i]=temp;
    }

    cout<<result[0]<<"i "<<result[1]<<"j "<<result[2]<<'k';

}

void rotateX(float pi, float unit[3]){
    float rotVect[3][3];
    rotVect[0][0]=1;
    rotVect[0][1]=0;
    rotVect[0][2]=0;
    rotVect[1][0]=0;
    rotVect[1][1]=cos(pi);
    rotVect[1][2]=(-sin(pi));
    rotVect[2][0]=0;
    rotVect[2][1]=sin(pi);
    rotVect[2][2]=cos(pi);

    float result[3];
    for(int i=0; i<3; i++){
        float temp=0;
        for(int j=0; j<3; j++){
            temp+=(rotVect[i][j]*unit[j]);
        }
        result[i]=temp;
    }

    cout<<result[0]<<"i "<<result[1]<<"j "<<result[2]<<'k';

}
int main()
{
    cout<<"Enter the unit vector: ";
    float unit[3];
    for (int i = 0; i < 3; i++)
    cin>>unit[i];

    cout<<"Enter rotation angle in degree: ";
    float theta;
    cin>>theta;
    float pi=(theta*3.14159/180);
    char ch='X';
    cout<<"Rotation about which axis(X/Y/Z)? ";
    cin>>ch;

    switch(ch){
        case 'X':
            rotateX(pi,unit);
            break;
        case 'Y':
            rotateY(pi,unit);
            break;
        case 'Z':
            rotateZ(pi,unit);
            break;
        default:
            cout<<"Please enter the right choice";
    }
    
    return 0;
}