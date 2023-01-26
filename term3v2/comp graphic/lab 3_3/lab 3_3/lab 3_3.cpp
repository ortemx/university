//#include "stdafx.h"
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

const int wight = 1000;
const int height = 1000;
const int x_min = -10;
const int x_max = 10;
const int y_min = -10;
const int y_max = 10;
const double shift = 0.3;
const double r = 0.2;
int choose;
bool isOpen = true;
//ifstream file("Z:\\2.1 сем\\compgraphic\\lab_3\\Debug\\points.txt", ios_base::in);

ifstream file("poligon.txt", ios_base::in);
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

vector <Point> v;

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

void drawLine(Point a, Point b) { glBegin(GL_LINES); glVertex2f(a.x, a.y); glVertex2f(b.x, b.y); glEnd(); glFinish(); }

double PSP(Point A, Point B, Point C) { 
	double PseudoScalarProduct = (B - A).x * (C - B).y - (B - A).y * (C - B).x;
	if ((signbit(PseudoScalarProduct) == 1) && (PseudoScalarProduct == 0)) {
		return 0;
	}
	else {
		return (B - A).x * (C - B).y - (B - A).y * (C - B).x;
	}
}

//скалярное произведение векторов AB AC
double SP(Point A, Point B, Point C) {
	return (B - A).x * (C - A).x + (B - A).y * (C - A).y;
}
//скалярное произведение векторов AB AC
double SP(double Ax, double Ay, double Bx, double By, double Cx, double Cy) {
	return (Bx - Ax) * (Cx - Ax) + (By - Ay) * (Cy - Ay);
}

double isSelfcrosed() {
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
		if (signbit(PSP(v[(int)(i - 1)], v[i], v[i + 1])) != sign) {
			return 0;
		}
	}
	return (signbit(PSP(v[n - 2], v[n - 1], v[0])) != sign) ? 0 : (signbit(PSP(v[n - 1], v[0], v[1])) != sign) ? 0 : 1;
}

void description() {
	if (isSelfcrosed()) {
		cout << "\nselfcrossed";
	}
	else {
		cout << "\nno selfcrossed";
		if (isConvex()) {
			cout << "\nis convex";
			if (PSP(v[0], v[1], v[2]) < 0) {
				cout << "\nclockwise";
			}
			else {
				cout << "\ncounterclockwise";
			}
		}
		else {
			cout << "\nis no convex";
		}
	}
}

void drawPoligon(vector <Point>& vertex) {
	glLineWidth(1.0);
	glColor3f(0.34, 0.89, 0.39);
	glLineStipple(1, 0x0101);
	glBegin(GL_LINE_LOOP);
	for (u short i = 0; i < vertex.size(); i++) {
		glVertex2f(vertex[i].x, vertex[i].y);
	}

	glEnd();
	glFinish();
	for (u short i = 0; i < vertex.size(); i++) {
		vertex[i].show();
	}
}

bool isBelong(Point A) {
	int count = 0;
	Point B(x_max, A.y);
	bool sign;
	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		sign = signbit(PSP(A, B, v[i]));
		if (sign != signbit(PSP(A, B, v[i + 1]))) {
			sign = signbit(PSP(v[i], v[i + 1], A));
			if (sign != signbit(PSP(v[i], v[i + 1], B))) {
				count++;
			}
		}
	}
	sign = signbit(PSP(A, B, v[n - 1]));
	if (sign != signbit(PSP(A, B, v[0]))) {
		sign = signbit(PSP(v[n - 1], v[0], A));
		if (sign != signbit(PSP(v[n - 1], v[0], B))) {
			count++;
		}
	}
	return (count % 2) ? 1 : 0;
}

bool isBelong_angleMethod(Point A) {
	double angle = 0;
	int n = v.size();
	double a;
	double b;
	bool sign;
	double argument;
	cout <<	"+---+-------+-------+-------+-------+-------+---------+-------+" << endl;
	cout << "| i |  psb  |   a   |   b   |   sp  |  arg  |acos(arg)| angle |" << endl;
	for (int i = 0; i < n - 1; i++) {
		a = sqrt(distance(A, v[i]));
		b = sqrt(distance(A, v[i + 1]));
		if (a == 0 || b == 0) {
			return true;
		}
		else {
			argument = SP(A, v[i], v[i + 1]) / (a * b);
		}		
		if (argument < -1) {
			argument = -1;
		}
		else if (argument > 1) {
			argument = 1;
		}
		if (PSP(A, v[i], v[i + 1]) <= 0) {
			angle -= acos(argument);
		}
		else {
			angle += acos(argument);
		}
		printf("|%2i |%7.3f|%7.3f|%7.3f|%7.3f|%7.3f|%7.3f|%7.3f|\n", i, PSP(A, v[i], v[i + 1]), a, b, SP(A, v[i], v[i + 1]), argument, acos(argument), angle);
	}
	a = sqrt(distance(A, v[n - 1]));
	b = sqrt(distance(A, v[0]));
	if (a == 0 || b == 0) {
		return true;
	}
	else {
		argument = SP(A, v[n - 1], v[0]) / (a * b);
	}
	if (argument < -1) {
		argument = -1;
	}
	else if (argument > 1) {
		argument = 1;
	}
	if (PSP(A, v[n - 1], v[0]) <= 0) {
		angle -= acos(argument);
	}
	else {
		angle += acos(argument);
	}
	printf("|%2i |%7.3f|%7.3f|%7.3f|%7.3f|%7.3f|%7.3f|%7.3f|\n", n-1, PSP(A, v[n - 1], v[0]), a, b, SP(A, v[n - 1], v[0]), argument, acos(argument), angle);
	return (abs(angle) < 1) ? false : true;
}

bool fillVertex(vector <Point>& vertex) {

	int size;
	double x, y;
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

//заполнение поля точками
void putPoints() {
	for (double i = x_min + 0.4; i < x_max - 0.4; i += 0.2) {
		for (double j = y_max - 0.4; j > y_min + 0.4; j -= 0.2) {
			Point temp(i, j);
			glPointSize(4);
			glEnable(GL_POINT_SMOOTH);
			glBegin(GL_POINTS);
			if (isBelong(temp)) {
				cout << "\n" << i << " " << j;
				glColor3f(0.41, 0.68, 0.37);
			}
			else {
				glColor3f(0.7, 0.25, 0.25);
			}
			glVertex2f(i, j);
			glEnd();
			glFinish();
		}
	}
}

//рисование 1 точки
void putPoints(Point A) {
	glPointSize(6);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	if (isBelong_angleMethod(A)) {
		glColor3f(0.41, 0.68, 0.37);
	}
	else {
		glColor3f(0.7, 0.25, 0.25);
	}
	glVertex2f(A.x, A.y);
	glEnd();
	glFinish();
}

void display(void)
{
	drawGrid();
	if (choose == 1) {
		if (fillVertex(v)) {
			drawPoligon(v);
			//description();

			// из файла 			
			//double x, y;
			//while (!file.eof()) {
			//	file >> x;
			//	file >> y;
			//	cout << "\nx = " << x << " y = " << y;
			//	Point A(x, y);
			//	putPoints(A);
			//} 
			// авторасстановка
			//putPoints();

			//с клавиатуры
			
			double x(1);
			double y;
			while (x != -100) {
				cout << "\nEnter x: "; cin >> x;
				cout << "Enter y: "; cin >> y;
				Point temp(x, y);
				putPoints(temp);
			}
		};
	}
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		Point temp(x, y);
		temp = convert(temp);
		if (isOpen) {
			if (v.size() == 0) {
				v.push_back(temp);
				v[0].show();
				drawCircle(v[0], r);
			}
			else {
				if (distance(v[0], temp) > r * r) {
					v.push_back(temp);
					v[v.size() - 1].show();
					drawLine(v[v.size() - 2], v[v.size() - 1]);
				}
				else {
					if (v.size() >= 3) {
						drawLine(v[v.size() - 1], v[0]);
						isOpen = false;
						description();
					}
				}
			}
		}
		else {
			//putPoints(temp);
			putPoints();
		}

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP && isOpen == false) {
		isOpen = true;
		v.clear();
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
	cout << "select method: \n1 - file 2 - hand\n";
	glutDisplayFunc(display);
	cin >> choose;
	if (choose == 2) {
		glutMouseFunc(mouse);
	}
	glClearColor(0.26, 0.26, 0.26, 0.0);
	glutMainLoop();
	system("pause");
	return 0;
}