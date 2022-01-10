#include <iostream>
#include "View.h"
using namespace std;

bool View :: GetSubscripts(int &out_x, int &out_y, Point2D location)
{
    int sub_x = (location.x - origin.x) / scale;
    int sub_y = (location.y - origin.y) / scale;

    if ((sub_x <= view_maxsize) && (sub_y <= view_maxsize))
    {
        out_x = sub_x;
        out_y = sub_y;
        return true;
    }
    else
    {
        cout << "An object is outside the display." << endl;
        return false;
    }    
}

View :: View()
{
    size = 11;
    scale = 2.0;
    origin = Point2D(0,0);
}

void View :: Clear()
{
    for (int i = 0; i < view_maxsize; i++)
    {
        for (int j = 0; j < view_maxsize; j++)
        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

void View :: Plot(GameObject * ptr)
{
    int sub_x;
    int sub_y;
    bool valid;
    valid = GetSubscripts(sub_x, sub_y, (ptr -> GetLocation()));
    if ((valid) && (grid[sub_x][sub_y][0] == '.'))
    {
        ptr -> DrawSelf(grid[sub_x][sub_y]);
    }
    else if (valid)
    {
        grid[sub_x][sub_y][0] = '*';
        grid[sub_x][sub_y][1] = ' ';
    }
        /*
        if (grid[sub_x][sub_y][0] != '.')
		{
			grid[sub_x][sub_y][0] = '*';
			grid[sub_x][sub_y][1] = ' ';
		}
        else        
        {
            ptr -> DrawSelf(grid[sub_x][sub_y]);
        }
        */
}
//However, if there is already an object plotted in that cell of the grid, the characters are replaced with ‘*’ and ' ' to indicate that there is more than one object in that cell of the grid.

void View::Draw() {
    for (int j = size-1; j >= -1; j--) {
        for (int i = -1; i <= size-1; i++) {
            //grid axis
            if (i == -1 && j%2 == 0) {
                cout << j*2;
                if (j/5 == 0) {
                    cout << " ";
                }
            }
            else if (i == -1 && j%2 != 0) {
                cout << "  ";
            }
            else if (j == -1 && i%2 == 0) {
                cout << i*2;
                if (i/5 == 0) {
                    cout << " ";
                }
                cout << "  ";
            }
            //draw objects
            if (i >= 0 && j >=0) {
                cout << grid[i][j][0] << grid[i][j][1];
            }
        }
        cout << endl;
    }
}