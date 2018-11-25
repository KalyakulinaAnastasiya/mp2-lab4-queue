#ifndef __STACK_H__
#define __STACK_H__
const int MaxStackSize = 100;

template <class T>
class TStack
{
  T *pMem;
  int size;               //размер pMem (до 100)
  int li, hi;            //индекс первого и последнего элемента в pMem
  int dataCount;        //количество элементов в очереди 

public:
  TStack(int _size)
  {
	size = _size;
	if ((size < 1) || (size > MaxStackSize))
		throw "error";
	else {
		li = 0;
		hi = 0;                               //??????
		dataCount = 0;
		pMem = new T[size];
	}
  }

  ~TStack()
  {
    delete [] pMem;
  }

  bool IsEmpty() {                            //проверить стек на пустоту
	  if (dataCount == 0)
		  return true;
	  else
		  return false;
  }

  bool IsFull() {                             //проверить стек на полноту
	  if (dataCount == MaxStackSize)
		  return true;
	  else
		  return false;
  }

  int GetNextIndex() {                        //получить следующий индекс
	  return dataCount;
  }

  T Push(T elem) {                            //добавить элемент
	  if (!IsFull())
	  {
		  pMem[hi++] = elem;
		  dataCount++;
		  if (hi > size - 1)
			  hi = 0;
	  }
	  else
	  {
		  throw "error";
	  }
  }

  T Back()                                       //взять элемент из стека      
  {
	  if (IsEmpty())
		  throw "error";
	  T tmp = pMem[li];
	  li = li + 1;
	  if (li > size - 1)
		  li = 0;
	  dataCount = dataCount - 1;
	  return tmp;
  }

  T Check(){
	  if (!IsEmpty())
	  {
		  return pMem[li];
	  }
	  else
		  throw "error";
  }
};

#endif


/* TStack GetElement()                        //посмотреть элемент
  {
	  return pMem[top];
  }*/
  /* int GetLenght()                                 //количество элементов в стеке
   {
	   return top + 1;
   }
   void Remove()                                 //удалить последний
   {
	   if (!IsEmpty())
		   top--;
   }*/

   /* double Pop() {                                   //взять из стека(элемент пропадает)
		 if (!IsEmpty())
			 return pMem[top--];
	 }*/