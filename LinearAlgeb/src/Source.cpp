
#include <iostream>
#include <assert.h>
#include <initializer_list>
#include "Header.h"
#include <stdexcept>
//Implementing a Matrix class//

using namespace OIRFAN;

//Implementation outside



	template <typename T>
	OIRFAN::Matrix_Base_Class<T>::Matrix_Base_Class()
	{
		m_Rows = 0;
		m_Columns = 0;
		m_Data = nullptr;
	}
	template <typename T>
	OIRFAN::Matrix_Base_Class<T>::Matrix_Base_Class(int rows) : m_Rows(rows), m_Columns(rows)
	{
		m_Data = new T * [m_Rows];
		for (int i = 0; i < m_Rows; ++i)
		{
			m_Data[i] = new T[m_Columns];
		}

	}
	template <typename T>
	OIRFAN::Matrix_Base_Class<T>::~Matrix_Base_Class()
	{
		if (m_Rows > 0)
		{
			for (int i = 0; i < m_Rows; ++i)
			{
				delete[] m_Data[i];
			}
			delete[] m_Data;
		}
	}

	template <typename T>
	OIRFAN::Matrix_Base_Class<T>::Matrix_Base_Class(int rows, int columns) : m_Rows(rows), m_Columns(columns)
	{
		m_Data = new T * [m_Rows];
		for (int i = 0; i < m_Rows; ++i)
		{
			m_Data[i] = new T[m_Columns];
		}
	}

	template <typename T>
	inline T& OIRFAN::Matrix_Base_Class<T>::operator()(int rows, int columns)
	{
		// TODO: insert return statement here

		return m_Data[rows][columns];
	}
	template <typename T>
	inline T& OIRFAN::Matrix_Base_Class<T>::operator()(int rows, int columns) const
	{
		// TODO: insert return statement here
		return m_Data[rows][columns];
	}

	template<typename T>
	Matrix_Base_Class<T>& OIRFAN::Matrix_Base_Class<T>::Preallocate()
	{
		// TODO: insert return statement here
		for (int i = 0; i < m_Rows; ++i)
		{
			for (int j = 0; j < m_Columns; ++j)
			{
				m_Data[i][j] = 0.0;
			}
		}
		return *this;
	}






	template<typename T>
	Matrix_Base_Class<T>& OIRFAN::Matrix_Base_Class<T>::operator=(Matrix_Base_Class<T>& ClassObject)
	{
		// TODO: insert return statement here
		for (int i = 0; i < ClassObject.m_Rows; i++)
		{
			for (int j = 0; j < ClassObject.m_Columns; j++)
			{
				m_Data[i][j] = ClassObject.m_Data[i][j];

			}

		}

		return *this;
	}



	//Reset the data in matrix to zero// Not deleting it
	template<typename T>
	inline void OIRFAN::Matrix_Base_Class<T>::Reset()
	{
		if (m_Rows > 0)
		{


			for (int i = 0; i < m_Rows; ++i)
			{
				for (int j = 0; j < m_Columns; ++j)
				{
					m_Data[i][j] = 0.0;
				}
			}
		}
		else
		{
			throw std::runtime_error("Trying to Reset an a matrix whhich was not created or allocated");
		}

	}

	template<typename T>
	void OIRFAN::Matrix_Base_Class<T>::Erase()
	{
		if (m_Rows > 0)
		{

			for (int i = 0; i < m_Rows; ++i)
			{
				delete[] m_Data[i];
			}
			delete[] m_Data;
			m_Data = nullptr;
			m_Rows = 0;
			m_Columns = 0;
		}
		else
		{
			throw std::runtime_error ("Trying to erase an a matrix whhich was not created or allocated");
		}
	}



	//for resizing the number of rows of matrix.. First will delete and then create new ones
	template<typename T>
	void OIRFAN::Matrix_Base_Class<T>::Resize(int rows)
	{
		Erase();

		m_Data = new T * [rows];
		for (int i = 0; i < rows; ++i)
		{
			m_Data[i] = new T[rows];
		}
	}

	template<typename T>
	void OIRFAN::Matrix_Base_Class<T>::Resize(int rows, int columns)
	{
		Erase();

		m_Data = new T * [rows];
		for (int i = 0; i < rows; ++i)
		{
			m_Data[i] = new T[columns];
		}
	}








int main()
{
	using namespace OIRFAN;
	return 0;
}