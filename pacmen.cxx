#include <iostream>
using namespace std; 
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
enum TYPES { INT, FL, D, CH, B };
//----------------------------------------------------
class MAINARRAY
{
	private:
	template <class T> TYPES form_of (int, T);
	TYPES  OF_COUNT;
	void* COUNT;
	
	public:
	MAINARRAY ()	{}
	MAINARRAY (void* CO, TYPES O_CO) : COUNT(CO), OF_COUNT(O_CO) {}
	template <class T> MAINARRAY (T);
	~MAINARRAY ()	{}
	friend ostream& operator<< (ostream&, MAINARRAY&);
	MAINARRAY operator= (MAINARRAY&);
//	MAINARRAY operator[] (MAINARRAY&);
};
//-------‐--------------‐---------------
	template <class T>
	MAINARRAY::MAINARRAY (T count)
	{
		COUNT = new T (count);
		OF_COUNT = form_of(sizeof(T), count);
	}
//--------------------------------------------
	MAINARRAY MAINARRAY::operator= (MAINARRAY& ob)
	{
		OF_COUNT = ob.OF_COUNT;
		switch (OF_COUNT)
	{
		case INT: 
		COUNT = new int (*(static_cast <int*> (ob.COUNT)));
			break;
		case FL: 
		COUNT = new float (*(static_cast <float*> (ob.COUNT)));
			break;
		case D: 
		COUNT = new double (*(static_cast <double*> (ob.COUNT)));
			break;
		case CH: 
		COUNT = new char (*(static_cast <unsigned char*> (ob.COUNT)));
			break;
		case B: 
		COUNT = new bool (*(static_cast <bool*> (ob.COUNT)));
			break;
	}
	return MAINARRAY (COUNT, OF_COUNT);
	}
	
//---------------------------------------------
//---------------------------------------------
	template <class T>
	TYPES MAINARRAY::form_of(int memspace, T count)
	{
		switch (memspace)
		{
		case sizeof(int):
		if (*(static_cast <int*> (COUNT)) == count)
		return INT;
		else
		if (*(static_cast <float*> (COUNT)) == count)
		return FL;
			break;
		case sizeof(double): 
		if (*(static_cast <double*> (COUNT)) == count)
		return D;
			break;
		case sizeof(unsigned char):
		if (count != true && count != false) return CH;
		else return B;
			break;
		}
	}
//---------------------------------------------------
ostream& operator<< (ostream& s, MAINARRAY& ob)
{
	switch (ob.OF_COUNT)
	{
		case INT:
		cout << (*(static_cast <int*> (ob.COUNT)));
			break;
		case FL: 
		cout << (*(static_cast <float*> (ob.COUNT)));
			break;
		case D: 
		cout << (*(static_cast <double*> (ob.COUNT)));
			break;
		case CH: 
		cout << (*(static_cast <unsigned char*> (ob.COUNT)));
			break;
		case B: 
		cout << (*(static_cast <bool*> (ob.COUNT)));
			break;
	}
	return s;
}
//----------------------------------------------------


	//-------------------------------------------------
	//-------------------------------------------------
	//-------------------------------------------------
	
	int main()

{
 MAINARRAY arr[55] = {'T','H','I','S','\t','P','R','O','G','R','A','M','\t','W','A','S','\t','M','A','D','E','\t','B','Y','\t','M','A','K','S','I','M','\t','S','H','P','A','G','I','N','\t','I','N','\t',2022,'.','0',6,'.',19,'\0'};
 int i = 0;
 for (int i = 0; i < 49; i++)
 cout << arr[i];
 cout << endl << "pacmen, потому что схавает всё";
 return 0;
}
