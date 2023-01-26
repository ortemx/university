#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <queue>
#include <stack>

using namespace std;

struct Edge {
  int begin;
  int end;
};

void init(int **arr, int n)
{
    for (int i=0;i< n;i++)
        for (int j=0;j< n;j++)
            arr[i][j]=0;
}

void print(int **arr, int n)
{
    for (int i=0;i<n ;i++)
    {
        cout<<endl;
        for (int j=0;j< n;j++)
            cout<<setw(3)<<arr[i][j];
    }
    cout<<endl;
}
void add(int **arr, int n)
{
    int cs;//kol-vo sosedey
    int s;//sosedi
    cout<<"vvedite rebra dlya vershin:"<<endl;
    for (int i=0;i<n ;i++)
        {
            cout<<"skolko sosedey u versiny "<<i+1<<"?\n";
            cin>>cs;
            if ((cs!=0) && (cs<n))
            {
                cout<<"vvedite vseh sosedey :\n";
                while (cs!=0)
                {
                    s=0;
                    cs--;
                    cin>>s;
                    if (s!=0)
                        arr[i][s-1]=1;
                    else cout<<"ERROR\n";
    //                ((s!=0) && (s<cs))?
      //               arr[i][s-1]=1
        //             :cout <<"ERROR";
                }
            }
            else cout<<"ERROR\n";
        }
}
int main()
{
    queue<int> Queue;
    stack<Edge> Edges;
    int req;
    Edge e;

    int n;
    cout<<"vvedite kol-vo vershin\n"; cin>>n;

    int **graf = new int*[n];
    for (int i=0;i< n;i++)
        graf[i]=new int[n];

    init(graf, n);
    add(graf, n);
    print(graf, n);

    int *nodes = new int[n];
    for (int i = 0; i < n; i++) // исходно все вершины равны 0
    nodes[i] = 0;
    cout<<"vvedite #vershiny do kotoroy nayti put'\n";
    cout << "N = ";
    cin >> req;
    req--;
    Queue.push(0); // помещаем в очередь первую вершину
    while (!Queue.empty())
    {
        int node = Queue.front(); // извлекаем вершину
        Queue.pop();
        nodes[node] = 2; // отмечаем ее как посещенную
        for (int j = 0; j < n; j++)
        {
            if (graf[node][j] == 1 && nodes[j] == 0)
            { // если вершина смежная и не обнаружена
                Queue.push(j); // добавляем ее в очередь
                nodes[j] = 1; // отмечаем вершину как обнаруженную
                e.begin = node; e.end = j;
                Edges.push(e);
                if (node == req) break;
            }
        }
    cout << node + 1 << endl; // выводим номер вершины
    }
    cout << "TTyTb Do BepLLI|/|Hb| " << req + 1 << endl;
    cout << req + 1;
    while (!Edges.empty()) {
        e = Edges.top();
        Edges.pop();
        if (e.end == req) {
            req = e.begin;
            cout << " <- " << req + 1;
        }
    }


return 0;
}
