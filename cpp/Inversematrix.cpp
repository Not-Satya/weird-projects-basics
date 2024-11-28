//calculate the Inverse of a matrix

#include <iostream>
using namespace std;

//determinant
int determinant(int A[3][3])
{
    int D=0;
    for (int j=0;j<3;j++)
    {
        int subarrr[2][2];
        int subi=0;
        for (int mi=1;mi<3;mi++)
        {
            int subj=0;

            for (int mj=0;mj<3;mj++)
            {
                if (mj==j)
                {
                    continue;
                }
                subarrr[subi][subj] = A[mi][mj];
                subj++;
            }
            subi++;

            int subset = (subarrr[0][0]*subarrr[1][1]-subarrr[0][1]*subarrr[1][0]);
            if (mi==2)
            {                
                D += A[0][j]*(j%2==0? 1:-1)*subset;
            }
        }
    }
    return D;
}

//minor, cofactor, adjoint
void adjoint(int A[3][3],int adj[3][3])
{
    int cofac[3][3];
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            int subarr[2][2];
            int subi=0;

            //minor
            for (int mi=0;mi<3;mi++)
            {
                if (i==mi)
                {
                    continue;
                }
                int subj=0;

                for (int mj=0;mj<3;mj++)
                {
                    if (mj==j)
                    {
                        continue;
                    }
                    subarr[subi][subj] = A[mi][mj];
                    subj++;
                }
                subi++;
            }

            //cofactor
            cofac[i][j] = ((i+j)%2==0? 1:-1)*(subarr[0][0]*subarr[1][1] - subarr[0][1]*subarr[1][0]);

            //adjoint
            adj[j][i]=cofac[i][j];
        }
    }
}

//inverse
bool inverse(int A[3][3], int inverse[3][3], bool intiger[3][3])
{
//determinant failsafe exit
    int D=determinant(A);
    if (D==0)
    {
        cout<<"The determinant of this matrix is 0 hence inverse can't be calculated.\n";
        return false;
    }

//inverse
    int adj[3][3];
    adjoint(A,adj);
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            inverse[i][j] = adj[i][j];

            if (adj[i][j]%D==0)
            {
                intiger[i][j] = true;
            }
            else
            {
                intiger[i][j] = false;
            }
        }
    }
 
    return true;
}

//hcf
int highestcf(int a, int b)
{
    int k=1;
    int hcf=1;

    if (a<0)
    {
        a *= -1;
    }
    if (b<0)
    {
        b *= -1;
    }
    if (a==1 || b==1)
    {
        return 1;
    }
    while (k<=min(a,b))
    {
        if (a%k==0 && b%k==0)
        {
            hcf *= k;
        }
        k++;
    }
    return hcf;
}

void inversematrix(int A[3][3])
{
    int inv[3][3];
    int d = determinant(A);

    cout<<"The determinant is: "<<d<<endl;
    bool intiger[3][3];

    if (inverse(A,inv,intiger)==true)
    {
        cout<<"The inverse of this matrix is: \n";
        for (int i=0;i<3;i++)
        {
            cout<<"   ";
            for (int j=0;j<3;j++)
            {
                if (inv[i][j]==0)
                {
                    cout<<"0  ";
                }
                else if (intiger[i][j]==true)
                {
                    cout<<inv[i][j]/d<<"  ";
                }
                else 
                {
                    int hcf = highestcf(inv[i][j], d);

                    if (inv[i][j]<0 && d<0)
                    {
                        cout<<-1*(inv[i][j]/hcf)<<"/"<<-1*(d/hcf)<<"  ";
                    }
                    else if (inv[i][j]<0 && d>0)
                    {
                        cout<<inv[i][j]/hcf<<"/"<<d/hcf<<"  ";
                    }
                    else if (inv[i][j]>0 && d<0)
                    {
                        cout<<-1*(inv[i][j]/hcf)<<"/"<<-1*(d/hcf)<<"  ";
                    }
                    else 
                    {
                        cout<<inv[i][j]/hcf<<"/"<<d/hcf<<"  ";
                    }
                }
            }
            cout<<endl;
        }
    }
}

//will have to change this to another format so that we can have the outputs in the from of p/q
void mproduct(int A[3][3], int B[3][3]) {
    int P[3][3];
    int prod = 0;
    int sum = 0;

    for (int j=0;j<3;j++) {
        for (int x=0;x<3;x++) {
            prod = 1;
            sum = 0;
            for (int i=0;i<3;i++) {
                prod = A[j][i] * B[i][j];
                sum += prod;
            }
            P[j][x] = sum;
        }
    }

    cout<<"The product of the two provided matrices is: "<<endl;
    for (int j=0;j<3;j++) {
        for (int i=0;i<3;i++) {
            cout<<P[j][i]<<"  ";
        }
        cout<<endl;
    }
}

int main() {
        int A[3][3] =
    {
        {11, -5, 0},
        {-5, 27, -4},
        {0, -4, 8}
    };

    int B[3][3] = 
    {
        {1, 2, 3},
        {5, 1, 4},
        {4, 6, 7}
    };

    inversematrix(B);


    return 0;
}
