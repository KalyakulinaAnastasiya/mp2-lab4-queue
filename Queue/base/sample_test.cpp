#include <iostream>
#include <string>
#include "stack.h"
#include "procc.h"
#include <fstream>

using namespace std;

int main() {
	int size, timeTact, cores;
	double processorInt, intQueue;

	setlocale(LC_ALL, "Russian");
	cout << "Задайте размер очереди: ";
	cin >> size;
	cout << endl;
	cout << "Задайте количество тактов: ";
	cin >> timeTact;
	cout << endl;
	cout << "Задайте количество ядер процессора: ";
	cin >> cores;
	cout << endl;
	cout << "Задайте производительность процессора: ";
	cin >> processorInt;
	cout << endl;
	cout << "Задайте интенсивность потока задач: ";
	cin >> intQueue;
	cout << endl;
	Proceccor proc;
    proc.InPut(size, timeTact, cores, processorInt, intQueue);
	proc.Work(size, timeTact, cores, processorInt, intQueue);
	system("pause");
	cin >> size;
	return 0;
}
