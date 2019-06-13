#include <stdio.h>
#include <memory>
#include "../TestApp/DataStructure/JList.h"
#include "../TestApp/DataStructure/JQueue.h"


using namespace JSample::DataStructure;

class TestClass
{
public : 
	int	hi = 0;
	void Print()
	{
		cout << "Hello world" << endl;
	}
};

void DequeueAndPrint(JQueue<TestClass*>* q)
{
	auto clss = q->Dequeue();
	clss->Print();
	delete clss;
}

int main(int argc, char* args)
{
	JQueue<TestClass*> queue;
	queue.Enqueue(new TestClass());
	DequeueAndPrint(&queue);
	queue.Enqueue(new TestClass());
	queue.Enqueue(new TestClass());
	queue.Enqueue(new TestClass());
	DequeueAndPrint(&queue);
	queue.Enqueue(new TestClass());
	queue.Enqueue(new TestClass());
	queue.Enqueue(new TestClass());
	queue.Enqueue(new TestClass());
	queue.Enqueue(new TestClass());
	queue.Enqueue(new TestClass());
	queue.Enqueue(new TestClass());
	DequeueAndPrint(&queue);
	queue.Enqueue(new TestClass());
	queue.Enqueue(new TestClass());
	queue.Enqueue(new TestClass());
	DequeueAndPrint(&queue);
	queue.Enqueue(new TestClass());
	queue.Enqueue(new TestClass());
	DequeueAndPrint(&queue);


	/*JList<TestClass*> list;]
	
	list.Add(new TestClass());
	list.RemoveByIndex(0);
	list.Add(new TestClass());
	list.RemoveByIndex(0);
	list.Add(new TestClass());
	list.RemoveByIndex(0);
	list.Add(new TestClass());
	list.Add(new TestClass());
	list.RemoveByIndex(0);
	list.Add(new TestClass());
	list.Add(new TestClass());
	list.Add(new TestClass());
	list.Add(new TestClass());
	list.RemoveByIndex(0);
	list.RemoveByIndex(0);
	list.RemoveByIndex(0);
	list.RemoveByIndex(0);
	list.Add(new TestClass());
	list.Add(new TestClass());
	list.Add(new TestClass());

	list.Add(new TestClass());
	list.RemoveByIndex(0);*/


	return 0;
}