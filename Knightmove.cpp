#include <bits/stdc++.h>
using namespace std;
const int D=8;

bool canPlace(int board[D][D], int n, int r, int c ){
    return r>=0 && r<n && c>=0 && c<n && board[r][c]==0;
}
bool KnightMove(int board[D][D], int n, int move_no, int currRow, int currCol){
    if(move_no==n*n){
        return true;
    }
    int rowdir[]={2,1,-1,-2,-2,-1,1,2};
    int coldir[]={ 1, 2, 2, 1, -1, -2, -2, -1};
    for(int currdir=0;currdir<8;++currdir){
            int nextRow= currRow+ rowdir[currdir];
            int nextCol= currCol+ coldir[currdir];

            if(canPlace(board, n, nextRow, nextCol)==true){
                board[nextRow][nextCol]=move_no+1;
                bool Success=KnightMove(board, n, move_no+1, nextRow, nextCol);
                if(Success){
                    return true;
                }
                board[nextRow][nextCol]=0;
            
    }
}

return false;
}

void printboard(int board[D][D], int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<setw(3) <<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int board[D][D]={0};
    int n;
    cin>>n;
    int moves=1;
    bool isSuccessful= KnightMove(board, n, moves, 0, 0);

    if (isSuccessful){
        printboard(board, n);
    }
    return 0;
}
