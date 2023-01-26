#include <windows.h>
#include <GL/gl.h>
#include "glu.h"
#include "glut.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>
#define PI 3.1415926535898
#define u unsigned

using namespace std;

class Point {
public:
    double x;
    double y;
    Point() { x = 0; y = 0; };
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    Point operator- (Point const arg) {
        return Point(x - arg.x, y - arg.y);
    }
    void show() {
        //cout << this->x << "  " << this->y << "\n";
        glPointSize(6);
        glColor3f(0.9, 0.48, 0.26);
        glEnable(GL_POINT_SMOOTH);
        glBegin(GL_POINTS);
        glVertex2f(this->x, this->y);
        glEnd();
        glFinish();
    }
};
const int wight = 1000;
const int height = 1000;
const int x_min = -10;
const int x_max = 10;
const int y_min = -10;
const int y_max = 10;
const double shift = 0.3;
const double r = 0.2;



vector <Point> SetOfPoints;
vector <Point> shell;

Point convert(Point arg) {
    double scale_x = (x_max - x_min) / (double)wight;
    double scale_y = (y_max - y_min) / (double)height;
    return Point(arg.x * scale_x + x_min, -arg.y * scale_y + y_max);
}

double distance(Point A, Point B) { return pow(B.x - A.x, 2) + pow(B.y - A.y, 2); }

void drawGrid() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(x_min, x_max, y_min, y_max);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*glLineWidth(1.0);
    glColor3f(0.9, 0.48, 0.26);
    glLineStipple(1, 0x0101);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    for (int i = x_min; i < x_max; i++) {
        glVertex2f(i, y_min + shift);
        glVertex2f(i, y_max - shift);
    }
    for (int i = ceil(x_min + shift); i < x_max; i++) {
        glVertex2f(x_min + shift, i);
        glVertex2f(x_max - shift, i);
    }
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex2f(0, y_min + shift);
    glVertex2f(0, y_max - shift);
    glVertex2f(x_min + shift, 0);
    glVertex2f(x_max - shift, 0);
    glEnd();*/
    glFinish();
}

void drawCircle(Point arg, double r)
{
    int amountSegments = 100;
    double angle;
    glColor3f(0.77, 0.16, 0.16);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < amountSegments; i++)
    {
        angle = 2 * PI * i / amountSegments;
        glVertex2f(arg.x + r * cos(angle), arg.y + r * sin(angle));
    }
    glEnd();
    glFinish();
}

void DrawLine(Point a, Point b) { 
    glBegin(GL_LINES); 
    glVertex2f(a.x, a.y); 
    glVertex2f(b.x, b.y); 
    glEnd(); 
    glFinish();
}

void DrawLine(Point a, Point b, float red, float green, float blue) {
    glColor3f(red, green, blue);
    glBegin(GL_LINES); 
    glVertex2f(a.x, a.y); 
    glVertex2f(b.x, b.y); 
    glEnd(); glFinish();
}

double PSP(Point A, Point B, Point C) { return (B - A).x * (C - B).y - (B - A).y * (C - B).x; }

//скалярное произведение векторов AB AC
double SP(Point A, Point B, Point C) { return (B - A).x * (C - A).x + (B - A).y * (C - A).y; }

void DrawShell(vector <Point> &shell) {
    glLineWidth(1.0);
    glColor3f(0.34, 0.89, 0.39);
    glLineStipple(1, 0x0101);
    glBegin(GL_LINE_LOOP);
    for (u short i = 0; i < shell.size(); i++) {
        glVertex2f(shell[i].x, shell[i].y);
    }

    glEnd();
    glFinish();
    for (u short i = 0; i < shell.size(); i++) {
        shell[i].show();
    }
}

void DrawShell(vector <Point>& shell, float red, float green, float blue) {
    glLineWidth(1.0);
    glColor3f(red, green, blue);
    glLineStipple(1, 0x0101);
    glBegin(GL_LINE_LOOP);
    for (u short i = 0; i < shell.size(); i++) {
        //glVertex2f(shell[i].x, shell[i].y);
    }

    glEnd();
    glFinish();
    for (u short i = 0; i < shell.size(); i++) {
        shell[i].show();
    }
}

bool isBelong_angleMethod(Point A) {
    double angle = 0;
    int n = shell.size();
    double a;
    double b;
    bool sign;
    double arg;
    for (int i = 0; i < n - 1; i++) {
        a = sqrt(distance(A, shell[i]));
        b = sqrt(distance(A, shell[i + 1]));
        arg = SP(A, shell[i], shell[i + 1]) / (a * b);
        if (arg < -1) {
            arg = -1;
        }
        else if (arg > 1) {
            arg = 1;
        }
        if (PSP(A, shell[i], shell[i + 1]) <= 0) {

            angle -= acos(arg);
        }
        else {
            angle += acos(arg);
        }
    }
    a = sqrt(distance(A, shell[n - 1]));
    b = sqrt(distance(A, shell[0]));
    arg = SP(A, shell[n - 1], shell[0]) / (a * b);
    if (arg < -1) {
        arg = -1;
    }
    else if (arg > 1) {
        arg = 1;
    }
    if (PSP(A, shell[n - 1], shell[0]) <= 0) {
        angle -= acos(arg);
    }
    else {
        angle += acos(arg);
    }

    return (abs(angle) < 1) ? false : true;
}


void RebuildingShell(Point A) {
    // индексы "левой" и "правой" точек не определены
    int rightindex = -1;
    int leftindex = -1;

    bool direction = signbit(PSP(A, shell[0], shell[1]));
    bool IsIndexFinfed = true;

    int n = shell.size();
    for (u short j = 2; j < n; j++) {
        if (direction != signbit(PSP(A, shell[0], shell[j]))) {
            IsIndexFinfed = false;
            break;
        }
    }

    // в случае, если предыдущий цикл прошёл все итерации,
    // то нашлась либо(!) левая, либо(!) правая точка
    if (IsIndexFinfed) {

        // direction = 0, тогда поворот от AV[0] ко всем остальным AV[i] против часовой
        // direction = 1, тогда поворот от AV[0] ко всем остальным AV[i] по чавсовой
        // в первом случае означает что точка V[0] - левая точка 
        // (весь полигон расположен по левую сторону от вектора AV[0]
        // во втором случае означает что точка V[0] - правая точка 
        // (весь полигон расположен по правую сторону от вектора AV[0]
        if (direction) {
            rightindex = 0;
        } 
        else
        {
            leftindex = 0;
        }
    }

    for (u short i = 1; i < shell.size(); i++) {
        IsIndexFinfed = true;
        direction = signbit(PSP(A, shell[i], shell[0]));
        for (u short j = 0; j < shell.size(); j++) {
            if (i != j) {
                if (direction != signbit(PSP(A, shell[i], shell[j]))) {
                    IsIndexFinfed = false;
                    break;
                }
            }
        }

        if (IsIndexFinfed) {
            if (direction) {
                rightindex = i;
            }
            else
            {
                leftindex = i;
            }
        }

        // если индексы "левой" и "правой" точек определены,
        // то их дальнейшее нахождение не требуется
        if (rightindex != -1 && leftindex != -1) {
            break;
        }
    }

    // на этом этапе левая и правая точки определены
    // поворот оболочки так, что бы правая точка имела индекс 0

    vector <Point> shellcopy = shell;
    n = shellcopy.size();

    for (int i = 0; i < n; i++) {
        if (i + rightindex < n) {
            shell[i] = shellcopy[i + rightindex];
        }
        else {
            shell[i] = shellcopy[i - (n - rightindex)];
        }
    }

    cout << "\nrightindex = " << rightindex << " leftindex = " << leftindex;

    leftindex -= rightindex;
    if (leftindex < 0) {
        leftindex += n;
    }
    rightindex = 0;
    cout << "\nrightindex = " << rightindex << " leftindex = " << leftindex;

    shell.erase(shell.begin() + leftindex + 1, shell.end());
    shell.push_back(A);
    

    drawGrid();
    DrawShell(SetOfPoints, 0.5, 0.5, 0.5);
    DrawShell(shell);
    
}

void display(void)
{
    drawGrid();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        Point temp(x, y);
        temp = convert(temp);
        if (SetOfPoints.size() == 0) {
            SetOfPoints.push_back(temp);
            SetOfPoints[0].show();
        }
        else {
            if (distance(SetOfPoints[0], temp) > r * r) {
                if (SetOfPoints.size() == 1) {
                    SetOfPoints.push_back(temp);
                    DrawLine(SetOfPoints[0], SetOfPoints[1], 0.34, 0.89, 0.39);
                    SetOfPoints[0].show();
                    SetOfPoints[1].show();
                }
                else if (SetOfPoints.size() == 2){
                    SetOfPoints.push_back(temp);
                    if (PSP(SetOfPoints[0], SetOfPoints[1], SetOfPoints[2]) > 0) {
                        reverse(SetOfPoints.begin(), SetOfPoints.end());
                        
                        // на этом этапе обход по часовой
                    }

                    shell = SetOfPoints;
                    DrawLine(SetOfPoints[0], SetOfPoints[1], 0.34, 0.89, 0.39);
                    DrawLine(SetOfPoints[1], SetOfPoints[2], 0.34, 0.89, 0.39);
                    DrawLine(SetOfPoints[2], SetOfPoints[0], 0.34, 0.89, 0.39);
                    SetOfPoints[0].show();
                    SetOfPoints[1].show();
                    SetOfPoints[2].show();
                }

                // построение выпуклой оболочки

                // если размер оболочки >= 3
                else {

                    // если точка не пренадлежит оболочке
                    if (!isBelong_angleMethod(temp)) {
                        // перестроение ВО
                        RebuildingShell(temp);
                    }
                    else {
                        cout << "\npoint belong to hull";
                    }
                    SetOfPoints.push_back(temp);
                    temp.show();
                }
            }
        }
        }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        SetOfPoints.clear();
        display();
        system("cls");
    }
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(wight, height);
    glutInitWindowPosition(800, 50);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("RGB");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glClearColor(0.1, 0.1, 0.1, 0.0);
    glutMainLoop();
    system("pause");
    return 0;
}