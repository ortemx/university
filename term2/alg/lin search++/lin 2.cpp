#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  setlocale(LC_ALL, "rus");

  int ans[20]; // создали массив дл€ записи всех индексов
  int h = 0;
  int arr[20]; // создали массив на 20 элементов
  int key; // создали переменную в которой будет находитьс€ ключ

  srand ( time(NULL) );

  for (int i = 0; i < 20; i++) {
    arr[i] = 1 + rand() % 20; // заполн€ем случайными числами €чейки

    cout << arr[i] << " "; // выводим все €чейки массива

    if (i == 9) {
      cout << endl;
    }
  }

  cout << endl << endl << "¬ведите ключ : "; cin >> key; // считываем ключ

  for (int i = 0; i < 20; i++) {
    if (arr[i] == key) { // провер€ем равен ли arr[i] ключу
      ans[h++] = i;
    }
  }

  if (h != 0) { // провер€ем были ли совпадени€
    for (int i = 0; i < h; i++) {
      cout << " люч " << key << " находитс€ в €чейке " << ans[i] << endl; //выводим все индексы
    }
  }
  else {
    cout << "ћы не нашли ключ " << key << " в массиве";
  }
  return 0;
}
