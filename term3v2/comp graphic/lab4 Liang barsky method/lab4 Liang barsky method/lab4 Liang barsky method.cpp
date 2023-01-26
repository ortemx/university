#include <windows.h>
#include <GL/gl.h>
#include "glu.h"
#include "glut.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>
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
		cout << this->x << "  " << this->y << "\n";
		glPointSize(6);
		glColor3f(0.9, 0.48, 0.26);
		glEnable(GL_POINT_SMOOTH);
		glBegin(GL_POINTS);
		glVertex2f(this->x, this->y);
		glEnd();
		glFinish();
	}
};

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int x_min = -10;
const int x_max = 10;
const int y_min = -10;
const int y_max = 10;
const double shift = 0.3;
const double r = 0.2;
int choose;
bool RectangleIsSet = false;
bool PointIsSet = false;
double WindowXmin, WindowXmax, WindowYmin, WindowYmax;



vector <Point> Rect;
pair <Point, Point> points;
vector <Point> intersections;

Point convert(Point arg) {
	double scale_x = (x_max - x_min) / (double)WIDTH;
	double scale_y = (y_max - y_min) / (double)HEIGHT;
	return Point(arg.x * scale_x + x_min, -arg.y * scale_y + y_max);
}

void drawGrid() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(x_min, x_max, y_min, y_max);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLineWidth(1.0);
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
	glEnd();
	glFinish();
}

void drawCircle(Point arg, double r)
{
	int amountSegments = 20;
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

void drawLine(Point a, Point b) { glBegin(GL_LINES); glVertex2f(a.x, a.y); glVertex2f(b.x, b.y); glEnd(); glFinish(); }
void drawLine(Point a, Point b, float red, float green, float blue) {
	glColor3f(red, green, blue);
	glBegin(GL_LINES); glVertex2f(a.x, a.y); glVertex2f(b.x, b.y); glEnd(); glFinish();
}

double PSP(Point A, Point B, Point C) { return (B - A).x * (C - B).y - (B - A).y * (C - B).x; }

Point intersection(Point A, Point B, Point C, Point D) {
	float delta = (B.x - A.x) * (D.y - C.y) - (B.y - A.y) * (D.x - C.x);
	float delta1 = (C.x - A.x) * (D.y - C.y) - (C.y - A.y) * (D.x - C.x);
	float delta2 = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
	float s = delta1 / delta;
	float t = delta2 / delta;
	cout << "\n" << s << " " << t;
	return Point(A.x + s * (B.x - A.x), A.y + s * (B.y - A.y));
}

/// <summary>
/// Draw rectangle on window
/// </summary>
void drawRectangle() {
	Rect.clear();
	// A - left bottom corner of Rectangle
	// B - right top corner of Rectangle
	Point A, B;
	A = points.first;
	B = points.second;
	WindowXmin = min(points.first.x, points.second.x);
	WindowXmax = max(points.first.x, points.second.x);
	WindowYmin = min(points.first.y, points.second.y);
	WindowYmax = max(points.first.y, points.second.y);
	Rect.push_back(A);
	Rect.push_back(Point(A.x, B.y));
	Rect.push_back(B);
	Rect.push_back(Point(B.x, A.y));
	drawLine(Rect[0], Rect[1], 0.5, 0.71, 0.67);
	drawLine(Rect[1], Rect[2], 0.5, 0.71, 0.67);
	drawLine(Rect[2], Rect[3], 0.5, 0.71, 0.67);
	drawLine(Rect[3], Rect[0], 0.5, 0.71, 0.67);
	//cout << "\nRect: " << Rect[0].x << " " << Rect[0].y << " " << Rect[1].x << " " << Rect[1].y << " " << Rect[2].x << " " << Rect[2].y << " " << Rect[3].x << " " << Rect[3].y;
	cout << "\nXmin = " << WindowXmin << "\tXmax = " << WindowXmax << "\tYmin = " << WindowYmin << "\tYmax = " << WindowYmax;
}


void display(void) {
	drawGrid();

	/*
	//ручная проверка
	//cout << "enter left bottom corner: "; 
	
	// left top point of rectangle
	Point A(1, 6);
	// right bottom point of rectangle
	Point B(8, 1);
	WindowXmin = A.x;
	WindowXmax = B.x;
	WindowYmin = B.y;
	WindowYmax = A.y;
	points.first = A;
	points.second = B;
	drawRectangle();

	int x1(0), y1, x2, y2;
	bool flag;
	
	while (x1 != 100) {
		flag = false;
		cout << "\nenter x1: "; cin >> x1;
		cout << "enter y1: "; cin >> y1;
		cout << "enter x2: "; cin >> x2;
		cout << "enter y12: "; cin >> y2;

		points.first = Point(x1, y1);
		points.second = Point(x2, y2);

		points.first.show();
		points.second.show();

		float dx = x2 - x1;
		float dy = y2 - y1;

		float p[] = {-dx, dx, -dy, dy};
		float q[] = { points.first.x - WindowXmin, WindowXmax - points.first.x,points.first.y - WindowYmin,WindowYmax - points.first.y };
		
		cout << "dx = " << dx << "\ndy = " << dy;
		cout << "\np: " << p[0] << "\t" << p[1] << "\t" << p[2] << "\t" << p[3];
		cout << "\nq: " << q[0] << "\t" << q[1] << "\t" << q[2] << "\t" << q[3];

		float t0 = 0;
		float t1 = 1;
		// зеленый 0.41, 0.85, 0.5
		// красный 0.85, 0.46, 0.41
		for (int i = 0; i < 4; i++) {
			// паралеллен сторонам прямоугольника 
			if (p[i] == 0) {
				// полностью не виден
				if (q[i] < 0) {
					drawLine(points.first, points.second, 0.85, 0.46, 0.41);
					flag = true;
					break;
				}
			}
			else {
				if (p[i] > 0) {
					t1 = min(t1, q[i] / p[i]);
				} else{
					t0 = max(t0, q[i] / p[i]);
				}
			}
		}

		cout << "\nt0: " << t0;
		cout << "\nt1: " << t1;

		if (!flag) {			
			Point CrossPoint1(points.first.x + p[1] * t0, points.first.y + p[3] * t0);
			Point CrossPoint2(points.first.x + p[1] * t1, points.first.y + p[3] * t1);

			cout << "\nCP1: " << CrossPoint1.x << " " << CrossPoint1.y;
			cout << "\nCP2: " << CrossPoint2.x << " " << CrossPoint2.y;
			if (t0 < t1) {
				drawLine(points.first, points.second, 0.85, 0.46, 0.41);
				drawLine(CrossPoint1, CrossPoint2, 0.41, 0.85, 0.5);
			}
			else {
				drawLine(points.first, points.second, 0.85, 0.46, 0.41);
			}
		}
	}

	
	*/
	
}


void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		Point temp(x, y);
		temp = convert(temp);
		temp.show();
		if (!PointIsSet) {
			points.first = temp;
			PointIsSet = true;
		}
		else {
			if (!RectangleIsSet) {
				points.second = temp;
				RectangleIsSet = true;
				drawRectangle();
				PointIsSet = false;
				return;
			}
			else {
				points.second = temp;
			}
			// здесь код

			bool flag = false;

			//cout << "\np1: " << points.first.x << " " << points.first.y;
			//cout << "\np1: " << points.second.x << " " << points.second.y;
			float dx = (points.second - points.first).x;
			float dy = (points.second - points.first).y;
			float p[] = {-dx, dx,-dy,dy};
			float q[] = { points.first.x - WindowXmin, WindowXmax - points.first.x,points.first.y - WindowYmin,WindowYmax - points.first.y };

			//cout << "\ndx = " << dx << "\ndy = " << dy;
			//cout << "\np: " << p[0] << "\t" << p[1] << "\t" << p[2] << "\t" << p[3];
			//cout << "\nq: " << q[0] << "\t" << q[1] << "\t" << q[2] << "\t" << q[3];

			float t0 = 0, t1 = 1;
			for (int i = 0; i < 4; i++) {
				// паралеллен сторонам прямоугольника 
				if (p[i] == 0) {
					// полностью не виден
					if (q[i] < 0) {
						drawLine(points.first, points.second, 0.85, 0.46, 0.41);
						flag = true;
						break;
					}
				}
				else {
					if (p[i] > 0) {
						t1 = min(t1, q[i] / p[i]);
					}
					else {
						t0 = max(t0, q[i] / p[i]);
					}
				}
			}
			//cout << "\nt0: " << t0;
			//cout << "\nt1: " << t1;
			if (!flag) {

				if (t0 < t1) {
					Point CrossPoint1(points.first.x + p[1] * t0, points.first.y + p[3] * t0);
					Point CrossPoint2(points.first.x + p[1] * t1, points.first.y + p[3] * t1);
					//cout << "\nCP1: " << CrossPoint1.x << " " << CrossPoint1.y;
					//cout << "\nCP2: " << CrossPoint2.x << " " << CrossPoint2.y;
					drawLine(points.first, points.second, 0.85, 0.46, 0.41);
					drawLine(CrossPoint1, CrossPoint2, 0.41, 0.85, 0.5);
				}
				else {
					drawLine(points.first, points.second, 0.85, 0.46, 0.41);
				}
			}

			PointIsSet = false;
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		display();
		PointIsSet = false;
		RectangleIsSet = false;
		system("cls");
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(800, 50);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("RGB");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glClearColor(0.26, 0.26, 0.26, 0.0);
	glutMainLoop();
	system("pause");
	return 0;
}