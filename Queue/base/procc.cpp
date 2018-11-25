#include"procc.h"
#include <ctime>

Task Proceccor::TaskGeneration()                //генератор задач
{
	srand((unsigned int)time(NULL));
	int pr1 = rand() % 9 + 1;
	if (pr1 < (intQueue * 10))         
	{
		srand((unsigned int)time(NULL));
		int pr2 = rand() % 9 + 1;
		Task task;
		task.cores = pr2;
		return task;
	}
	else
	{
		Task task = {};
		task.cores = 0;
		return task;
	}
}

void Proceccor::InPut(int _size, int _timeTact, int _cores, double _processorInt, double _intQueue){
		cout << "Задайте размер очереди: ";
		cin >> size;
		cout << endl;
		cout << "Задайте количество тактов: ";
		cin >> _timeTact;
		cout << endl;
		cout << "Задайте количество ядер процессора: ";
		cin >> _cores;
		cout << endl; 
		cout << "Задайте производительность процессора: ";
		cin >> _processorInt;
		cout << endl;
		cout << "Задайте интенсивность потока задач: ";
		cin >> _intQueue;
		cout << endl;
}

void Proceccor::Out(int at, int sq, int sp, int tm, int cm, int nc)                           //вывод
	{
		cout << "Количество прошедших задач: " << amountTask << endl;
		if (amountTask != 0)
			cout << "Количество простоев очереди: " << (stopQueue * 100 / amountTask) << "%" << endl;
		else
			cout << "Количество простоев очереди: " << 0 << endl;
		cout << "Количество простоев процессора: " << (stopProc * 100 / timeTact) << "%" << endl;
		if (completed != 0)
			cout << "Время выполнения задачи: " << (double(timeTact - stopProc) / double(completed)) << endl;
		else
			cout << "Время выполнения задачи: " << 0 << endl;
		cout << "Завершенных задач: " << completed << endl;
		cout << "Количество циклов: " << NumberOfCycle << endl;
}

void Proceccor::Cycle(TStack<Task> &qu, JobProcc &proc, int Time)              //основной цикл
{
	for (int i = 0; i < Time; i++)
	{
		if (!qu.IsFull())
		{
			Task task1;
			task1 = TaskGeneration();
			if (task1.cores != 0)
			{
				qu.Push(task1);
			}
		}
		if (qu.IsEmpty())
		{
			stopQueue++;
		}
		else
		{
			for (int i = 0; i < qu.GetNextIndex(); i++)
			{
				Task task2;
				task2 = qu.Check();
				if (task2.cores <= proc.PrCores)
				{
					proc.PrCores = proc.PrCores - task2.cores;
					proc.task.push_back(task2);
					amountTask++;
					qu.Back();
					continue;
				}
				else
				{
					if (task2.cores > proc.PrCores)
					{
						renoun++;
						qu.Back();
					}
					else
						break;
				}
			}
		}
		if (proc.task.size() != 0)
		{
			int i = 0;
			for (i; i < proc.task.size(); i++)
			{
				proc.task[i].tacts++;
				srand((unsigned int)time(NULL));
				int pr = rand() % 9 + 1;
				if ((double)pr / 10 < processorInt)
				{
					Task task2;
					task2 = proc.task[i];
					if (task2.tacts == 1)
					{
						continue;
					}
					completed++;
					proc.task.erase(proc.task.begin() + i);
					proc.PrCores = proc.PrCores + task2.cores;
					NumberOfCycle = NumberOfCycle + task2.tacts;
				}
			}
		}
		else
		{
			stopProc++;
		}
	}
	Out(amountTask, stopQueue, stopProc, Time, completed, NumberOfCycle);
}

void Proceccor::Work(int _size, int _time, int _cores, double _processorInt, double _intQueue)
{
	JobProcc proc;
	proc.PrCores = _cores;
	timeTact = _time;
	size = _size;
	processorInt = _processorInt;
	intQueue = _intQueue;
	TStack<Task> qu(size);
	Cycle(qu, proc, timeTact);
}