#include <iostream>
#include <string>
#include <cstring>

using namespace std;

inline double kmToMile(char *millis);
inline double mlToKillometers(char *killomiters);
int coutingSimbol(char **arguments);

int main(const int argc,const char** argv)
{
	string entA = " [argum] number";
	string help = "-ml	convert mile to killometers.\n-km	convert killometers mile.";
	string* firstArgument = new string[4];
	switch(argc)
		{
			case 3:
				*firstArgument = string(argv[1]);
				
				int countOfSimbol  = coutingSimbol(&*argv);
				char* secondArgument = new char [countOfSimbol];
				cout << "*firstArgument = " << *firstArgument << endl;
				if(*firstArgument == "-ml")
				{
					cout << argv[2]<< "ml" << " = " << mlToKillometers(secondArgument) << "km" << endl;
				}else if(*firstArgument == "-km"){
					cout << argv[2]<< "km" << " = " << kmToMile(secondArgument) << "ml" << endl;
				}else{
					cout << argv[0] << entA << endl;
					cout << help << endl;
					cout << "Argument not recognized." << endl;
				}
				delete [] secondArgument;
				break;
			default:
				cout << argv[0] << entA << endl;
				cout << help << endl;
			break;
		}
	delete [] firstArgument;
	return 0;
}

int coutingSimbol(char **arguments)
{
	register unsigned int i = 0;
	while(true)
	{
		if(arguments[2][i] != '\0')
		{
			break;
		}
		i++;
	}
	return i;
}

inline double kmToMile(char *millis)
{	
	double ml = stod(millis); 
	return (ml*1.609);
}

inline double mlToKillometers(char *killomiters)
{
	double km = stod(killomiters);
	return (km/1.609);
}
