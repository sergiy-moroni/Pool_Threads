#include "simple_thread.h"
#include <iostream>
// функция, выполняющая задачу

using namespace std;

mutex coutLocker;

void taskFunc(int id, int delay) {
    // имитируем время выполнения задачи
    this_thread::sleep_for(chrono::seconds(delay));
    // выводим информацию о завершении
    unique_lock<mutex> l(coutLocker);
    cout << "task " << id << " made by thread_id " << this_thread::get_id() << endl;
}

int main()
{
    srand(0);
    RequestHandler rh;
    for (int i = 0; i < 20; i++)
        rh.pushRequest(taskFunc, i, 1 + rand() % 4);
    return 0;
}
