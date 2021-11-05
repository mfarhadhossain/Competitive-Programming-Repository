#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ff first
#define ss second
#define m_p make_pair
typedef long long int ll;
#define pii pair<ll,ll>
int N,a[55];
void getCofactor(int mat[55][55],int temp[55][55],int p,int q, int n)
{
    int i = 0, j = 0;
 
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those
            //  element which are not in given row and
            //  column
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 
/* Recursive function for finding determinant of matrix.
   n is current dimension of mat[][]. */
int determinantOfMatrix(int mat[55][55],int n)
{
    int D = 0; // Initialize result
 
    //  Base case : if matrix contains single element
    if (n == 1)
        return mat[0][0];
 
    int temp[55][55]; // To store cofactors
 
    int sign = 1; // To store sign multiplier
 
    // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of mat[0][f]
        getCofactor(mat,temp, 0, f, n);
        D += sign * mat[0][f]
             * determinantOfMatrix(temp, n - 1);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}
void solve(){
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>a[i];



}
int main (){
	char ch,ch2,ch3,dummy=' ';
	int d2,d3;
	cin>>ch>>ch2>>d2>>ch3>>d3;
	cout<<ch<<dummy<<ch2<<d2<<dummy<<ch3<<d3<<endl;
	// //freopen("input.txt","r",stdin);
	// //freopen("output.txt","w",stdout);
	// ios_base::sync_with_stdio(false);cin.tie(0);
	
	// int t=1;cin>>t;
	// while(t--)solve();
	return 0;
}