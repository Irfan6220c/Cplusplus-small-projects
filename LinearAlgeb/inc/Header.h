#pragma once
#include <iostream>
#include <assert.h>
#include <initializer_list>


namespace OIRFAN {
	template <typename T>
	class Matrix_Base_Class
	{
	public:
		//Implementing the Default constructor
		Matrix_Base_Class();
		~Matrix_Base_Class();
		Matrix_Base_Class(int rows); //Rows and equal number of columns
		Matrix_Base_Class(int rows, int columns); //Difffernt number of rows and columns
		//Copy constructor
		Matrix_Base_Class<T>(Matrix_Base_Class<T>& ClassObject);
		T& operator() (int rows, int columns);
		T& operator() (int rows, int columns) const;
		Matrix_Base_Class& Preallocate();
		Matrix_Base_Class<T>& operator=(Matrix_Base_Class<T> &ClassObject);
		void GetDimensions();


		void Reset();
		void Erase();
		void Resize(int rows);
		void Resize(int rows,int columns);

		template <typename T> 
		friend std::ostream& operator<< (std::ostream& out, Matrix_Base_Class<T>& ClassObject);
	public:

		int   m_Rows{};
		int   m_Columns{};
		T** m_Data{};

	};


	template<typename T>
	std::ostream& operator<<(std::ostream& out, Matrix_Base_Class<T>& ClassObject)
	{
		// TODO: insert return statement here
		for (int i = 0; i < ClassObject.m_Rows; ++i)
		{
			for (int j = 0; j < ClassObject.m_Columns; ++j)
			{

				out << ClassObject.m_Data[i][j];
				out << " ";

			}

			out << " \n";
		}
		return out;
	}
	

	template<typename T>
	inline Matrix_Base_Class<T>::Matrix_Base_Class(Matrix_Base_Class<T>& ClassObject)
	{

		this->m_Data = new T * [ClassObject.m_Rows];
		for (int i = 0; i < ClassObject.m_Rows; ++i)
		{
			this->m_Data[i] = new T[ClassObject.m_Columns];
		}


		for (int i = 0; i < ClassObject.m_Rows; ++i)
		{
			for (int j = 0; j < ClassObject.m_Columns; ++j)
			{
				this->m_Data[i][j] = ClassObject.m_Data[i][j];
			}

		}
	}

}