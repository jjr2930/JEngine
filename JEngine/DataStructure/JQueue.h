#pragma once
#include "JList.h"
#include <mutex>

namespace JSample
{
	namespace DataStructure
	{ 
		template<class T>
		class JQueue
		{
		private:
			JList<T> _data;
			std::mutex mutex;

		public:
			void Enqueue(T value)
			{
				mutex.lock();
				{
					_data.Add(value);
				}
				mutex.unlock();
				//cout << "====enqueue_start=====" << endl;
				//Print();
				//cout << "====enqueue_end=====\n" << endl;
			}

			T Dequeue()
			{
				//cout << "====dequeue_start=====" << endl;
				T value = (T)0;
				mutex.lock();
				{
					if (_data.GetCount() <= 0)
					{
						mutex.unlock();
						{
							cout << "Out of range";
							throw;
						}
					}

					value = _data[0];
					_data.RemoveByIndex(0);
				}
				mutex.unlock();
				//Print();
				//cout << "====dequeue_end=====\n" << endl;
				return value;
			}

			uint32_t GetCount()
			{
				return _data.GetCount();
			}

			void Clear()
			{
				data.Clear();
			}

			void Print()
			{
				cout << "JQueue count : " << _data.GetCount() << endl;
				//cout << "JQueue count : " << _data.GetCount() << " , ";
				//for (size_t i = 0; i < _data.GetCount(); i++)
				//{
				//	cout << _data[i] << " , ";
				//}
				//cout << endl;
			}
		};
	}
}