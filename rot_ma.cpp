#include<cstdio>
#include<iostream>
#include"rot_mat.hpp"
using namespace std;

int main()
{
    float U_mat[3],X_mat[3],T_mat[3][3];
    printf("Enter the uvw frame: ");        //taking UVW matrix
    for(int i=0;i<3;i++)
       scanf("%f",&U_mat[i]);

    
    for(int i=0;i<3;i++)                   //initializing rotational matrix as identity
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
                T_mat[i][j]=1.0;
            else
                T_mat[i][j]=0;
        }
    }

    //preparing final transformation matrix
    char flag;
    do
    {
        //taking input of new rorartional matrix T_new
        char axi;
        float ang,T_new[3][3];
        printf("Enter axis:");
        cin>>axi;
        printf("Enter angle:");
        scanf("%f",&ang);
        switch(axi)
        {
        case 'x':
        case 'X':
                xrot(T_new,ang);
                break;
        case 'y':
        case 'Y':
                yrot(T_new,ang);
                break;
        case 'z':
        case 'Z':
                zrot(T_new,ang);
                break;
        }

        //preparation of final transformation matrix
        float temp[3][3];       //for temporary storage of result of multiplication
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                float sum=0;
                for(int k=0;k<3;k++)
                {sum+=T_new[i][k]*T_mat[k][j];}
                temp[i][j]=sum;
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                T_mat[i][j]=temp[i][j];
        }
        cout<<"If you want have any more rotational matrix press y/y:";
        cin>>flag;    
    }while(flag=='y'||flag=='Y');
    
    
    cout<<"The final transformation matrix is:";
    for(int i=0;i<3;i++)
    {
        cout<<"\n";
        for(int j=0;j<3;j++)
            cout<<T_mat[i][j]<<"\t";
    }

    for(int i=0;i<3;i++)
    {
        float sum=0;
        for(int j=0;j<3;j++)
            sum+=(T_mat[i][j]*U_mat[j]);
        X_mat[i]=sum;
    }
    printf("\nThe X-matrix is:");
    for(int i=0;i<3;i++)
        printf("%f ",X_mat[i]);

    return 0;
}