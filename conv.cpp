#include <iostream>
#include <string>
#include <math.h>


using namespace std;

class Program
{
public:
	Program(const int argc, const char **argv)
	{
		if (!(this->analizeCountArg(argc, argv)))//Запускаем анализ аргументов
		{
			cout << helpInf << endl;
			exit(1);
		}
		if (!(this->analizeConvertNumber()))//Запускаем проверку числа
		{
			cout << helpInf << endl;
			cout << nonCorrect << endl;
			exit(2);
		}
	}

	unsigned char getMode()
	{
		return mode;
	}

	double getNumber() // Считываем число
	{
		short int counterPointAndNulls = 0;
		int argLength = arguments[1].length() - 1;
		double number = 0.0;
		char nowNumber = 0;
		for (register int i = argLength; i>=0; i--)
		{
			nowNumber = ((int)arguments[1][i] - 48);
			if((int)nowNumber <= 0)
			{
				counterPointAndNulls++;
				continue;
			}
			if(argLength == i)
			{
				number = number + (int)nowNumber;
				continue;
			}
			if(counterPointAndNulls == 0)
			{
				number = number + (int)nowNumber * pow(10,argLength - i);
			}
			else
			{
				number = number + (int)nowNumber * pow(10,argLength - i - 1);
				counterPointAndNulls++;
			}
		}
		if(counterPointAndNulls > 0)
		{
			number = number * pow(10,(-(argLength-(--counterPointAndNulls))));
		}
		return number;
	}


	~Program()
	{
		delete[] arguments;
	}

private:
	unsigned char mode = 0;
	const string helpInf = "convmltokm [argument] <convertible number>\n -ml - convert number to killomiters\n -km - convert number to mile";
	const string nonCorrect = "You entered an invalid value.";

	string* arguments;

	bool analizeCountArg(const int count,const char **argArr) // Первичная проверка
	{
		switch (count)
		{
		case 3:
			arguments = new string[2];
			arguments[0] = string(argArr[1]);
			arguments[1] = string(argArr[2]);			
			if (arguments[0] == "-ml")
			{
				mode = 1;
				break;
			}
			if (arguments[0] == "-km")
			{
				mode = 2;
				break;
			}
		default:
			return false;
			break;
		}
		return true;
	}

	bool analizeConvertNumber() // Проверка введённого числа
	{
		int countSimbol = arguments[1].length();
		if (countSimbol == 1)
		{
			if(arguments[1][0] >= '0' && arguments[1][0] <= '9')
			{
				return true;
			}
		}else{
			if(arguments[1][0] == '-')
			{
				arguments[1].erase(0,1);
				countSimbol--;
			}
			if(arguments[1][0] == '.')
			{
				return false;
			}
			for(register int i = 0;i < countSimbol;i++)
			{
				if((int)arguments[1][i] >= 48 && (int)arguments[1][i] <= 57)
				{
					continue;
				}else if(arguments[1][i] == '.')
				{
					continue;
				}else
				{
					return false;
				}
			}
		}
		return true;
	}
};

inline double mlToKm(double ml);
inline double kmToMl(double km);

int main(const int argc, const char ** argv)
{
	Program This(argc, argv);
	double convNumber = This.getNumber();
	switch (This.getMode())
	{
	case 1:
		cout << mlToKm(convNumber) << endl;
		break;
	case 2:
		cout << kmToMl(convNumber) << endl;
		break;
	}
	return 0;
}

inline double mlToKm(double ml)
{
	return (ml * 1.609343);
}

inline double kmToMl(double km)
{
	return (km / 1.609343);
}
