#include <windows.h>
#include <GL/gl.h>
#include "glu.h"
#include "glut.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
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
		cout << "\n" << this->x << "  " << this->y;
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
const int XMIN = -10;
const int XMAX = 10;
const int YMIN = -10;
const int YMAX = 10;
const double SHIFT = 0.3;
const double RADIUS = 0.2;
bool isOpen = true;
bool PointIsSet = false;
bool goNext = false;
vector <Point> v;
pair <Point, Point> points;


Point convert(Point arg) {
	double scale_x = (XMAX - XMIN) / (double)WIDTH;
	double scale_y = (YMAX - YMIN) / (double)HEIGHT;
	return Point(arg.x * scale_x + XMIN, -arg.y * scale_y + YMAX);
}

float distance(Point A, Point B) { return pow(B.x - A.x, 2) + pow(B.y - A.y, 2); }

void drawGrid() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(XMIN, XMAX, YMIN, YMAX);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLineWidth(1.0);
	glColor3f(0.9, 0.48, 0.26);
	glLineStipple(1, 0x0101);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	for (int i = XMIN; i < XMAX; i++) {
		glVertex2f(i, YMIN + SHIFT);
		glVertex2f(i, YMAX - SHIFT);
	}
	for (int i = ceil(XMIN + SHIFT); i < XMAX; i++) {
		glVertex2f(XMIN + SHIFT, i);
		glVertex2f(XMAX - SHIFT, i);
	}
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex2f(0, YMIN + SHIFT);
	glVertex2f(0, YMAX - SHIFT);
	glVertex2f(XMIN + SHIFT, 0);
	glVertex2f(XMAX - SHIFT, 0);
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

void drawPoligon() {
	glLineWidth(1.0);
	glColor3f(0.34, 0.89, 0.39);
	glLineStipple(1, 0x0101);
	glBegin(GL_LINE_LOOP);
	for (u short i = 0; i < v.size(); i++) {
		glVertex2f(v[i].x, v[i].y);
	}

	glEnd();
	glFinish();
	for (u short i = 0; i < v.size(); i++) {
		v[i].show();
	}
}

double PSP(Point A, Point B, Point C) { return (B - A).x * (C - B).y - (B - A).y * (C - B).x; }

double SP(Point A, Point B, Point C, Point D) {
	return (B - A).x * (D - C).x + (B - A).y * (D - C).y;
}

double SP(Point A, Point B) {
	return A.x * B.x + A.y * B.y;
}

float isSelfcrosed() {
	int i = 0;
	bool sign;
	int n = v.size();
	for (int j = i + 2; j < n - 1; j++) {
		sign = signbit(PSP(v[i], v[i + 1], v[j]));
		if (sign != signbit(PSP(v[i], v[i + 1], v[j + 1]))) {
			sign = signbit(PSP(v[j], v[j + 1], v[i]));
			if (sign != signbit(PSP(v[j], v[j + 1], v[i + 1]))) {
				return 1;
			}
		}
	}
	for (i = 1; i < n - 2; i++) {
		for (int j = i + 2; j < n - 1; j++) {
			sign = signbit(PSP(v[i], v[i + 1], v[j]));
			if (sign != signbit(PSP(v[i], v[i + 1], v[j + 1]))) {
				sign = signbit(PSP(v[j], v[j + 1], v[i]));
				if (sign != signbit(PSP(v[j], v[j + 1], v[i + 1]))) {
					return 1;
				}
			}
		}
		sign = signbit(PSP(v[i], v[i + 1], v[n - 1]));
		if (sign != signbit(PSP(v[i], v[i + 1], v[0]))) {
			sign = signbit(PSP(v[n - 1], v[0], v[i]));
			if (sign != signbit(PSP(v[n - 1], v[0], v[i + 1]))) {
				return 1;
			}
		}
	}
	return 0;
}

bool isConvex() {
	bool sign = signbit(PSP(v[0], v[1], v[2]));
	int n = v.size();
	for (int i = 2; i < n - 1; i++) {
		if (signbit(PSP(v[(i - 1)], v[i], v[i + 1])) != sign) {
			return 0;
		}
	}
	return (signbit(PSP(v[n - 2], v[n - 1], v[0])) != sign) ? 0 : (signbit(PSP(v[n - 1], v[0], v[1])) != sign) ? 0 : 1;
}

void CyrusBeckAlgorithm(Point point) {
	//если точка ещё не поставлена
	if (!PointIsSet) {
		points.first = point;
		points.first.show();
		cout << "\n\nA: " << points.first.x << " " << points.first.y;
		PointIsSet = true;
	} 
	//если точка поставлена
	else {
		points.second = point;
		points.second.show();
		cout << "\nB: " << points.second.x << " " << points.second.y;

		double t0 = 0, t1 = 1;
		int n = v.size();
		Point direcrion(points.second.x - points.first.x, points.second.y - points.first.y);
		for (int i = 0; i < v.size() - 1; i++) {			
			Point normal((v[i].y - v[i + 1].y), -(v[i].x - v[i + 1].x));
			Point w(points.first.x - v[i].x, points.first.y - v[i].y);
			if (SP(direcrion, normal) > 0) {
				t0 = max(t0, -SP(normal, w) / SP(direcrion, normal));
			}
			else if (SP(direcrion, normal) < 0) {
				t1 = min(t1, -SP(normal, w) / SP(direcrion, normal));
			}
		}
		Point normal((v[n-1].y - v[0].y), -(v[n-1].x - v[0].x));
		Point w(points.first.x - v[n-1].x, points.first.y - v[n-1].y);
		if (SP(direcrion, normal) > 0) {
			t0 = max(t0, -SP(normal, w) / SP(direcrion, normal));
		}
		else if (SP(direcrion, normal) < 0) {
			t1 = min(t1, -SP(normal, w) / SP(direcrion, normal));
		}

		if (t0 < t1) {
			Point CrossPoint1(points.first.x + direcrion.x * t0, points.first.y + direcrion.y * t0);
			Point CrossPoint2(points.first.x + direcrion.x * t1, points.first.y + direcrion.y * t1);
			drawLine(points.first, points.second, 0.85, 0.46, 0.41);
			drawLine(CrossPoint1, CrossPoint2, 0.41, 0.85, 0.5);
		}
		else {
			drawLine(points.first, points.second, 0.85, 0.46, 0.41);
		}
		cout << "\nt0 = " << t0 << " t1= " << t1;
		PointIsSet = false;
	}
}

bool fillVertex(vector <Point>& vertex) {
	//file.open("Z:\\2.1 сем\\compgraphic\\ConsoleApplication2\\Debug\\points.txt", ios_base::in);
	ifstream file("D:\\aaa\\универ\\3 new\\comp graphic\\lab 5\\Debug\\points.txt", ios_base::in);
	int size;
	int x, y;
	if (file.is_open()) {
		file >> size;
		for (int i = 0; i < size; i++) {
			file >> x;
			file >> y;
			Point temp(x, y);
			vertex.push_back(temp);
		}
		return 1;
	}
	else {
		cout << "\nERROR can't open file";
		return 0;
	}
}

void display(void)
{
	drawGrid();
	fillVertex(v);
	drawPoligon();
	while (true) {
		int x, y;
		cout << "\nenter x1: "; cin >> x;
		cout << "enter y1: "; cin >> y;
		points.first = Point(x, y);
		points.first.show();
		cout << "enter x2: "; cin >> x;
		cout << "enter y2: "; cin >> y;
		points.second = Point(x, y);		
		points.second.show();

		double t0 = 0, t1 = 1;
		int n = v.size();
		Point direcrion(points.second.x - points.first.x, points.second.y - points.first.y);
		for (int i = 0; i < v.size() - 1; i++) {
			Point normal((v[i].y - v[i + 1].y), -(v[i].x - v[i + 1].x));
			Point w(points.first.x - v[i].x, points.first.y - v[i].y);
			if (SP(direcrion, normal) > 0) {
				t0 = max(t0, -SP(normal, w) / SP(direcrion, normal));
			}
			else if (SP(direcrion, normal) < 0) {
				t1 = min(t1, -SP(normal, w) / SP(direcrion, normal));
			}
		}
		Point normal((v[n - 1].y - v[0].y), -(v[n - 1].x - v[0].x));
		Point w(points.first.x - v[n - 1].x, points.first.y - v[n - 1].y);
		if (SP(direcrion, normal) > 0) {
			t0 = max(t0, -SP(normal, w) / SP(direcrion, normal));
		}
		else if (SP(direcrion, normal) < 0) {
			t1 = min(t1, -SP(normal, w) / SP(direcrion, normal));
		}

		if (t0 < t1) {
			Point CrossPoint1(points.first.x + direcrion.x * t0, points.first.y + direcrion.y * t0);
			Point CrossPoint2(points.first.x + direcrion.x * t1, points.first.y + direcrion.y * t1);
			drawLine(points.first, points.second, 0.85, 0.46, 0.41);
			drawLine(CrossPoint1, CrossPoint2, 0.41, 0.85, 0.5);
		}
		else {
			drawLine(points.first, points.second, 0.85, 0.46, 0.41);
		}
		cout << "\nt0 = " << t0 << " t1= " << t1;
	}
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		Point temp(x, y);
		temp = convert(temp);
		// если полигон не замкнут
		if (isOpen) {
			if (v.size() == 0) {
				v.push_back(temp);
				v[0].show();
				drawCircle(v[0], RADIUS);
			}
			else {
				if (distance(v[0], temp) > RADIUS * RADIUS) {
					v.push_back(temp);
					v[v.size() - 1].show();
					drawLine(v[v.size() - 2], v[v.size() - 1]);
				}
				else {
					if (v.size() >= 3) {
						drawLine(v[v.size() - 1], v[0]);
						if (isSelfcrosed()) {
							MessageBoxA(GetActiveWindow(), (LPCSTR)"POLYGON INTERSECT ITSELF", (LPCSTR)"ERROR", MB_ICONERROR);
						}
						else {
							if (!isConvex()) {
								MessageBoxA(GetActiveWindow(), (LPCSTR)"POLYGON IS NOT CONVEX", (LPCSTR)"ERROR", MB_ICONERROR);
							}
							else {
								if (PSP(v[0], v[1], v[2]) < 0) {
									cout << "\nclockwise";
									reverse(v.begin(), v.end());
								}
								goNext = true;
							}
						}
						isOpen = false;
					}
				}
			}
		}
		// если полигон замкнут
		else {
			if (goNext) {
				CyrusBeckAlgorithm(temp);
			}
		}		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		isOpen = true;
		PointIsSet = false;
		goNext = false;
		v.clear();
		display();
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
	//glutMouseFunc(mouse);
	glClearColor(0.26, 0.26, 0.26, 0.0);
	glutMainLoop();
	system("pause");
	return 0;
}
