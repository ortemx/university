#include <iostream>
#include <queue> // �������
#include <stack> // ����
using namespace std;
struct Edge {
  int begin;
  int end;
};
int main()
{
  queue<int> Queue;
  stack<Edge> Edges;
  int req;
  Edge e;
  int mas[7][7] = { { 0, 1, 1, 0, 0, 0, 1 },
  { 1, 0, 1, 1, 0, 0, 0 },
  { 1, 1, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 0, 1, 0 },
  { 0, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 1, 0 } };
  int nodes[7]; // ������� �����
  for (int i = 0; i < 7; i++) // ������� ��� ������� ����� 0
    nodes[i] = 0;
  cout << "N = "; cin >> req; req--;
  Queue.push(0); // �������� � ������� ������ �������
  while (!Queue.empty())
  {
    int node = Queue.front(); // ��������� �������
    Queue.pop();
    nodes[node] = 2; // �������� �� ��� ����������
    for (int j = 0; j < 7; j++)
    {
      if (mas[node][j] == 1 && nodes[j] == 0)
      { // ���� ������� ������� � �� ����������
        Queue.push(j); // ��������� �� � �������
        nodes[j] = 1; // �������� ������� ��� ������������
        e.begin = node; e.end = j;
        Edges.push(e);
        if (node == req) break;
      }
    }
    cout << node + 1 << endl; // ������� ����� �������
  }
  cout << "���� �� ������� " << req + 1 << endl;
  cout << req + 1;
  while (!Edges.empty()) {
    e = Edges.top();
    Edges.pop();
    if (e.end == req) {
      req = e.begin;
      cout << " <- " << req + 1;
    }
  }
  cin.get(); cin.get();
  return 0;
}
