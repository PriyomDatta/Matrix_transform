#define _USE_MATH_DEFINES
#include<cmath>


//defining rotational matrix rotating about x-axis at angle ang
void xrot(float A[3][3],float ang)
{
    ang*=(M_PI/180);
    A[0][0]=1.0; 
    A[0][1]=0; 
    A[0][2]=0;
    A[1][0]=0; 
    A[1][1]=cos(ang); 
    A[1][2]=sin(ang)*(-1);
    A[2][0]=0; 
    A[2][1]=sin(ang); 
    A[2][2]=cos(ang); 
}


//defining rotational matrix rotating about y-axis at angle ang
void yrot(float A[3][3],float ang)
{
    ang*=(M_PI/180);
    A[0][0]=cos(ang); 
    A[0][1]=0; 
    A[0][2]=sin(ang);
    A[1][0]=0; 
    A[1][1]=1.0;
    A[1][2]=0;
    A[2][0]=sin(ang)*(-1); 
    A[2][1]=0; 
    A[2][2]=cos(ang); 
}


//defining rotational matrix rotating about y-axis at angle ang
void zrot(float A[3][3],float ang)
{
    ang*=(M_PI/180);
    A[0][0]=cos(ang); 
    A[0][1]=sin(ang)*(-1); 
    A[0][2]=0;
    A[1][0]=sin(ang); 
    A[1][1]=cos(ang); 
    A[1][2]=0;
    A[2][0]=0; 
    A[2][1]=0; 
    A[2][2]=1.0; 
}