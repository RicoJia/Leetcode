#include <vector>
#include <iostream>
using std::cout; using std::endl; 
using std::vector;

void DFS_flip_island(vector<vector<char>>& grid, int r, int c){
    if (0 < r && r < grid.size() )
}

int numIslands(vector<vector<char>>& grid) {
   int row = grid.size(); 
   int cln = grid[0].size(); 
   int island_num = 0;
   std::cout<<grid[0][0]<<std::endl; 
   for (unsigned int r= 0;  r< row; ++r) {
       for (unsigned int c= 0;  c< cln; ++c) {
           if (grid[r][c] == 1)
           {
               DFS_flip_island(grid, r, c); 
                ++island_num;
           }
       }
   }
   return island_num; 
}

int main()
{
    std::vector<std::vector<char>> islands {
          {1,1,0,0,0},
          {1,1,0,0,0},
          {0,0,1,0,0},
          {0,0,0,1,1}
        };
   cout<<numIslands(islands)<<endl;  
}
