#pragma once
#include <stdint.h>
#include <iostream>

using namespace std;

namespace JSample
{
	namespace DataStructure
	{
		template<typename T>
		class JList
		{
		private:
			const uint32_t DEFAULT_INIT_SIZE = 4;

			T* _data = nullptr;
			uint32_t _size = 0;
			uint32_t _count = 0;
			//uint32_t _callCount= 0;

		public :
			JList()
			{
				_data = (T*)malloc(DEFAULT_INIT_SIZE * sizeof(T));
				_size = DEFAULT_INIT_SIZE;
				memset(_data, 0, _size * sizeof(T));
			}

			JList(uint32_t size)
			{
				_data = (T*)malloc(size * sizeof(T));
				_size = size;
				memset(_data, 0, _size * sizeof(T));
			}

			virtual ~JList() 
			{
				cout << "JList Destructor is called" << endl;
				free(_data);
			}

			void Add(T newItem)
			{
				if (_size == _count)
				{
					Resize();
				}

				_data[_count] = newItem;
				_count++;
				//Print();
			}

			void RemoveByIndex(uint32_t index)
			{
				if (index >= _count)
				{
					cout << "Out of range" << endl;
					throw;
				}
								
				//moved range
				for (size_t i = index + 1; i <= _count; i++)
				{
					_data[i - 1] = _data[i];
				}

				--_count;
				//Print();
			}

			void Resize()
			{
				//++_callCount;
				uint32_t nextSize = _size + 10;
				//cout << "size up : " << nextSize << endl;
				T* newArray = (T*)malloc(nextSize * sizeof(T));

				memset(newArray, 0, nextSize * sizeof(T));
				for (size_t i = 0; i < _size; i++)
				{
					newArray[i] = _data[i];
				}
			
				//cout << "call count : " << _callCount << endl;
				free(_data);
				_data = newArray;
				_size = nextSize;
			}

			void ResizeNonCopy(uint32_t nextSize)
			{
				//cout << "size up : " << nextSize << endl;
				T* newArray = (T*)malloc(nextSize * sizeof(T));

				memset(newArray, 0, nextSize * sizeof(T));

				//cout << "call count : " << _callCount << endl;
				free(_data);
				_data = newArray;
				_size = nextSize;
			}

			uint32_t GetCount()
			{
				return _count;
			}

			uint32_t GetSize()
			{
				return _size;
			}

			void Clear()
			{
				free(_data);
				_data = new T[DEFAULT_INIT_SIZE];
			}

			void Print()
			{
				cout << "Size : " << _size << " , ";
				for (size_t i = 0; i < _count; i++)
				{
					cout << _data[i] << " , ";
				}
				cout << endl;
			}

			void Copy(const JList<T>& source, bool cleared = false)
			{
				if (cleared)
				{
					Clear();
				}

				if (_size < source._count)
				{
					ResizeNonCopy(source._size);
				}

				for (size_t i = 0; i < source._count; i++)
				{
					_data[i] = source[i];
				}
			}

#pragma region Operator overloading

			T& operator[](uint32_t index)
			{
				if (index > _count)
				{
					cout << "JList=>Out of range" << endl;
					throw;
				}

				return _data[index];
			}
#pragma endregion
		};
	}
}
