#include <assert.h>
#include <iostream>


using namespace std;

#if 0
namespace work {
	//传统版string类实现
	class string {
	public:
		string(const char* str = "") 
		{
			if (str == nullptr) {
				assert(false);
				return;
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		string(const string& s)
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}
		string& operator=(const string& s)
		{
			if(this != &s) 
			{
				char* pstr = new char[strlen(s._str) + 1];
				strcpy(pstr, s._str);
				delete[] _str;
				_str = pstr;
			}
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};

}

//现代版string类实现
class String {
public:
	String(const char* str = "")
	{
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(nullptr)
	{
		String stmp(s._str);
		swap(_str, stmp);
	}
	///*String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		String stmp(s._str);
	//		swap(_str, stmp);
	//	}
	//	return *this;
	//}*/

	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
#endif


namespace wode
{
	class string {
	public:
		typedef char* iterator;
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";

			_size = strlen(str);
			_capacity = _size;
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			string tmp(s);
			this->Swap(tmp);
		}
		string& operator=(string s)
		{
			this->Swap(s);
			return *this;
		}
		~string() {
			if (_str) {
				delete[] _str;
				_str = nullptr;
			}
		}

		/////////////////////////////////////////////////////////////////
		// iterator
		
		iterator begin() {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
		
		/////////////////////////////////////////////////////////////////
		// modify
		void PushBack(char c)
		{
			if (_size == _capacity)
				reserve(_capacity * 2 + 3);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		string& operator+=(char c)
		{
			PushBack(c);
			return *this;
		}
		string& Append(const char* str)
		{
			strcat(this->_str, str);
			return *this;
		}

		string& operator+=(const char* str) 
		{
			strcat(this->_str, str);
			return *this;
		}
		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}


		void Swap(string& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		const char* c_str()const
		{
			return _str;
		}

		/////////////////////////////////////////////////////////////////
		// capacity
		size_t size() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}
		bool empty() const
		{
			return _size == 0;
		}

		void resize(size_t newsize, char ch = '\0')
		{
			if (newsize > _size)
			{
				if (newsize > _capacity)
				{
					reserve(newsize);
				}
				memset(_str + _size, ch, newsize - _size);
			}
			_size = newsize;
			_str[_size] = '\0';
		}

		void reserve(size_t newsize)
		{
			if (newsize > _capacity)
			{
				char* pstr = new char[newsize + 1];
				strcpy(pstr, _str);
				delete[] _str;
				_str = pstr;
				_capacity = newsize;
			}
		}

		////////////////////////////////////////////////////////////////////
		// access
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}

		const char& operator[](size_t index) const
		{
			assert(index < _size);
			return _str[index];
		}

		bool operator<(const string& s)
		{
			if (strcmp(_str, s._str) < 0)
				return true;
			else
				return false;
		}
		bool operator<=(const string& s)
		{
			if (strcmp(_str, s._str) <= 0)
				return true;
			else
				return false;
		}
		bool operator>(const string& s)
		{
			if (strcmp(_str, s._str) > 0)
				return true;
			else
				return false;
		}
		bool operator>=(const string& s)
		{
			if (strcmp(_str, s._str) >= 0)
				return true;
			else
				return false;
		}
		bool operator==(const string& s)
		{
			if (strcmp(_str, s._str) == 0)
				return true;
			else
				return false;
		}
		bool operator!=(const string& s)
		{
			if (strcmp(_str, s._str) != 0)
				return true;
			else
				return false;
		}

		// 返回c在string中第一次出现的位置
		size_t Find(char c, size_t pos = 0) const;
		// 返回子串s在string中第一次出现的位置
		size_t Find(const char* s, size_t pos = 0) const;
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& Insert(size_t pos, char c);
		string& Insert(size_t pos, const char* str);
		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& Erase(size_t pos, size_t len);
private:
	friend ostream& operator<<(ostream& _cout, const wode::string& s);



	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}

ostream& wode::operator<<(ostream& _cout, const wode::string& s)
{
	cout << s._str;
	return _cout;
}