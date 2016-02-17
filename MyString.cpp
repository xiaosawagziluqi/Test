#include "stdafx.h"
#include <iostream>
using namespace std;

class MyString
{
public:
	MyString(const char *pData = NULL);
	MyString(const MyString &rhsStr);
	MyString & operator=(const MyString& rhsStr);
	~MyString();
private:
	char *m_pData;
};

MyString::MyString(const char *pData /*= NULL*/)
{
	if (NULL == pData)
	{
		m_pData = new char[1];
		*m_pData = '\0';
	}
	else
	{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

MyString::MyString(const MyString &rhsStr)
{
	int length = strlen(rhsStr.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, rhsStr.m_pData);

}

MyString & MyString::operator=(const MyString& rhsStr)
{
	if (this == &rhsStr)
	{
		return *this;
	}
	else
	{

		delete [] this->m_pData;
		int length = strlen(rhsStr.m_pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, rhsStr.m_pData);
		return *this;
	}
}

MyString::~MyString()
{
	delete[] m_pData;
	m_pData = NULL;
}
