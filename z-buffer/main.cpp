#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

struct vertex{
    float x;
    float y;
    float z;
};

int nv = 5;
// no. of vertices
vertex poly[20] = {{0, 40, 0}, {-20, 0, -20}, {20, 0, -20}, {20, 0, 20}, {-20, 0, 20}};
//vertices, clockwise
int edgemat[20][20] = {{0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 0, 1, 0, 0}, {1, 1, 0, 1, 0}};
//lower triangular matrix, 1 = >edge
int ns = 5;
// no. of surfaces
int surfaces[10][10] = {{0, 1, 2, -1}, {0, 2, 3, -1}, {0, 3, 4, -1}, {0, 4, 1, -1}, {1, 2, 3, 4, -1}};
//names of vertices make a surface, -1 is delimiter
bool visible[10] = {true, true, true, true, true};
//for each surface
vertex temp[20];

draw_surfaces(vertex temp[], int surfaces[][10], int ns, bool visible[], int xc, int yc)
{
    int m, n, i, j;
    for (i=0;
         i < ns;
         i++)
    {
        if (visible[i] == true)
        {
            for (j=0;
                 surfaces[i][j+1] != -1;
                 j++)
            {
                m = surfaces[i][j];
                n = surfaces[i][j+1];
                line(temp[m].x+xc, temp[m].y+yc, temp[n].x+xc, temp[n].y+yc);
            }
            m = surfaces[i][j];
            n = surfaces[i][0];
            line(temp[m].x+xc, temp[m].y+yc, temp[n].x+xc, temp[n].y+yc);
        }
    }
}

void perspectiveview(int xc, int yc)
{
    // centre of projection
    vertex cop;
    cop.x = 10;
    cop.y = 10;
    cop.z = -10000000000;
    for (int i=0;
         i < nv;
         i++)
    {
        temp[i].x = (poly[i].x*(-cop.z)) / ((-cop.z) + poly[i].z);
        temp[i].y = (poly[i].y*(-cop.z)) / ((-cop.z) + poly[i].z);
    }

    draw_surfaces(temp, surfaces, ns, visible, xc, yc);
}

void hiddensurface()
{
    vertex centroid = {0, 0, 0};
    // centroid of 3d polygon
    for (int k=0;
         k < nv;
         k++)
    {
        centroid.x += poly[k].x;
        centroid.y += poly[k].y;
        centroid.z += poly[k].z;
    }
    centroid.x /= nv;
    centroid.y /= nv;
    centroid.z /= nv;

    vertex normals[10];
    vertex means[10];
    for (int i=0;
         i < ns;
         i++)
    {
        int v1 = surfaces[i][0];
        int v2 = surfaces[i][1];
        int v3 = surfaces[i][2];

        vertex v1v2 = {poly[v2].x-poly[v1].x, poly[v2].y-poly[v1].y, poly[v2].z-poly[v1].z};
        vertex v1v3 = {poly[v3].x-poly[v1].x, poly[v3].y-poly[v1].y, poly[v3].z-poly[v1].z};
        normals[i] = {v1v2.y*v1v3.z - v1v2.z*v1v3.y, v1v2.z*v1v3.x - v1v2.x*v1v3.z, v1v2.x*v1v3.y - v1v2.y*v1v3.x};

        vertex centroidv1 = {poly[v1].x-centroid.x, poly[v1].y-centroid.y, poly[v1].z-centroid.z};
        // take dot product with normal
        int dotprod = centroidv1.x*normals[i].x + centroidv1.y*normals[i].y + centroidv1.z*normals[i].z;
        if (dotprod < 0)
        {
            normals[i].x = -normals[i].x;
            normals[i].y = -normals[i].y;
            normals[i].z = -normals[i].z;
        }

        // for means
        means[i] = {0, 0, 0};
        int m = 0;
        for(;
            surfaces[i][m] != -1;
            m++)
        {
            means[i].x += poly[surfaces[i][m]].x;
            means[i].y += poly[surfaces[i][m]].y;
            means[i].z += poly[surfaces[i][m]].z;
        }
        means[i].x /= m;
        means[i].y /= m;
        means[i].z /= m;

        // for light vector
        vertex light = {0, 0, 100};
        vertex light_vector = {means[i].x-light.x, means[i].y-light.y, means[i].z-light.z};

        dotprod = light_vector.x*normals[i].x + light_vector.y*normals[i].y + light_vector.z*normals[i].z;
        if (dotprod >= 0)
        visible[i] = false;
        else
        visible[i] = true;
    }
}

int main()
{
    int gd = DETECT, gm = 0;
    initgraph( & gd, & gm, "C:\\TURBOC3\\BGI");

    hiddensurface();
    perspectiveview(250, 250);

    char ch;
    cout << "Enter any key to start rotation"<< endl;
    cin >> ch;
    // rotate
    float thrad = 5*3.14/180;
    // rotate by 5 degree anticlockwise each time
    while(true)
    {
        cleardevice();
        // rotating around y axis
        for (int i=0;
             i < nv;
             i++)
        {
            float x = poly[i].x;
            float y = poly[i].y;
            float z = poly[i].z;
            poly[i].x = cos(thrad)*x + sin(thrad)*z;
            poly[i].y = y;
            poly[i].z = -sin(thrad)*x + cos(thrad)*z;
        }

        hiddensurface();
        perspectiveview(250, 250);
        delay(70);
    }

    getch();
    closegraph();
    return 0;
}
