#ifndef _Proccecor_
#define _Proceccor_
#include "stack.h"
#include <iostream>
#include <vector>

using namespace std;

struct Task
{
	int cores;           //требуемые  для выполнения задачи ядра
	int tacts;           //такты   
};

struct JobProcc 
{
	vector <Task> task;
	int PrCores;             //ядра процессора
};

class Proceccor {
private:
	int timeTact = 0;                  //время работы процессора в тактах
	int NumberOfCycle = 0;     //номер такта
	int completed = 0;         
	int size = 0;              
	double processorInt = 0;   //интенсивность процессора
	double intQueue = 0;       //интенсивность потока задач
	int stopQueue = 0;      //количество простоев(процессор занят)
	int renoun = 0;         //отказ процессора
	int stopProc = 0;       //количество простоев(нет задач)
	int amountTask = 0;       //количество прошедших задач

public:
	
	Task TaskGeneration();
	void InPut(int _size, int _timeTact, int _cores, double _processorInt, double _intQueue);
	void Out(int _amountTask, int _stopQueue, int _stopProc, int _Time, int _completed, int _NumberOfCycle);
	void Cycle(TStack<Task> &qu, JobProcc &proc, int time);
	void Work(int _queueSize, int _time, int _cores, double _processorInt, double _queueInt);

};

#endif


/*Proceccor(int timeTact = 0,                  //время работы процессора в тактах
	int NumberOfCycle = 0,     //номер такта
	int completed = 0,
	int size = 0,
	double processorInt = 0,   //интенсивность процессора
	double intQueue = 0,       //интенсивность потока задач
	int stopQueue = 0,      //количество простоев(процессор занят)
	int renoun = 0,         //отказ процессора
	int stopProc = 0,       //количество простоев(нет задач)
	int amountTask = 0){      //количество прошедших задач) {
		this->timeTact = 0;                 //время работы процессора в тактах
		this->NumberOfCycle = 0;     //номер такта
		this->completed = 0;
		this->size = 0;
		this->processorInt = 0;   //интенсивность процессора
		this->intQueue = 0;       //интенсивность потока задач
		this->stopQueue = 0;      //количество простоев(процессор занят)
		this->renoun = 0;         //отказ процессора
		this->stopProc = 0;       //количество простоев(нет задач)
		this->amountTask = 0;       //количество прошедших задач
	}*/