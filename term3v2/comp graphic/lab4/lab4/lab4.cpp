// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
//#include <GL/gl.h>
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

const int wight = 1000;
const int height = 1000;
const int x_min = -10;
const int x_max = 10;
const int y_min = -10;
const int y_max = 10;
const double shift = 0.3;
const double r = 0.2;
int choose;
bool isSet = false;

vector <Point> Rect;
pair <Point, Point> points;
vector <Point> intersections;

Point convert(Point arg) {
	double scale_x = (x_max - x_min) / (double)wight;
	double scale_y = (y_max - y_min) / (double)height;
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

double PSB(Point A, Point B, Point C) { return (B - A).x * (C - B).y - (B - A).y * (C - B).x; }

Point intersection(Point A, Point B, Point C, Point D) {
	float delta = (B.x - A.x) * (D.y - C.y) - (B.y - A.y) * (D.x - C.x);
	float delta1 = (C.x - A.x) * (D.y - C.y) - (C.y - A.y) * (D.x - C.x);
	float delta2 = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
	float s = delta1 / delta;
	float t = delta2 / delta;
	cout << "\n" << s << " " << t;
	return Point(A.x + s*(B.x - A.x), A.y + s * (B.y - A.y));
}
/// <summary>
/// 
/// </summary>
/// <param name="A">First point of first segment</param>
/// <param name="B">Second point of first segment</param>
/// <param name="C">First point of second segment</param>
/// <param name="D">Second point of second segment</param>
/// <returns></returns>
bool isCrossed(Point A, Point B, Point C, Point D) {
	bool sign = signbit(PSB(A, B, C));
	if (signbit(PSB(A, B, D)) == sign) {
		return 0;
	}
	else {
		sign = signbit(PSB(C, D, A));
		if (signbit(PSB(C, D, B)) == sign) {
			return 0;
		}
		else {			
			return 1;
		}
	}
}
/// <summary>
/// Draw rectangle on window
/// </summary>
void drawRectangle() {
	// A - left bottom corner of Rectangle
	// B - right top corner of Rectangle
	Point A, B;
	A = Point(-4, -4);
	B = Point(5, 3);
	Rect.push_back(A);
	Rect.push_back(Point(A.x, B.y));
	Rect.push_back(B);
	Rect.push_back(Point(B.x, A.y));
	drawLine(Rect[0], Rect[1], 0.5, 0.71, 0.67);
	drawLine(Rect[1], Rect[2], 0.5, 0.71, 0.67);	
	drawLine(Rect[2], Rect[3], 0.5, 0.71, 0.67);	
	drawLine(Rect[3], Rect[0], 0.5, 0.71, 0.67);
}

void display(void){
	drawGrid();
	drawRectangle();
}

int ToBit(Point P) {
	int bit = 0;
	if (P.x < Rect[0].x) {
		bit += 8;
		cout << "8";
	}
	if (P.x > Rect[2].x) {
		bit += 2;
		cout << "2";
	}
	if (P.y < Rect[0].y) {
		bit += 1;
		cout << "1";
	}
	if (P.y > Rect[2].y) {
		bit += 4;
		cout << "4";
	}
	return bit;
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		Point temp(x, y);
		temp = convert(temp);

		if (!isSet) {
			points.first = temp;
			isSet = true;
		} 
		else {
			points.second = temp;
			isSet = false;
			int A_code = ToBit(points.first);
			int B_code = ToBit(points.second);
			cout << "\n A code: " << A_code << "\n B code: " << B_code;
			if (A_code == 0 && B_code == 0) {
				drawLine(points.first, points.second, 0.41, 0.85, 0.5);
			}
			else if ((A_code & B_code) != 0) {
				drawLine(points.first, points.second, 0.85, 0.46, 0.41);
			}
			else {
				if (isCrossed(Rect[0], Rect[1], points.first, points.second)) {
					intersections.push_back(intersection(Rect[0], Rect[1], points.first, points.second));
				}
				if (isCrossed(Rect[1], Rect[2], points.first, points.second)) {
					intersections.push_back(intersection(Rect[1], Rect[2], points.first, points.second));
				}
				if (isCrossed(Rect[2], Rect[3], points.first, points.second)) {
					intersections.push_back(intersection(Rect[2], Rect[3], points.first, points.second));
				}
				if (isCrossed(Rect[3], Rect[0], points.first, points.second)) {
					intersections.push_back(intersection(Rect[3], Rect[0], points.first, points.second));
				}
				cout << "\nintersections.sise() = " << intersections.size();
				if (intersections.size() == 0) {
					drawLine(points.first, points.second, 0.85, 0.46, 0.41);
				}
				else if (intersections.size() == 1) {
					if (A_code == 0) {
						drawLine(points.first, intersections[0], 0.41, 0.85, 0.5);
						drawLine(intersections[0], points.second, 0.85, 0.46, 0.41);
					}
					else {
						drawLine(points.first, intersections[0], 0.85, 0.46, 0.41);
						drawLine(intersections[0], points.second, 0.41, 0.85, 0.5);
					}
				}
				else {
					drawLine(points.first, points.second, 0.85, 0.46, 0.41);
					drawLine(intersections[0], intersections[1], 0.41, 0.85, 0.5);
				}
				intersections.clear();
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		display();
		intersections.clear();
		isSet = false;
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
