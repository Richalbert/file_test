//writing to a file
//
//https://www.javatpoint.com/cpp-files-and-streams
//https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
//man locatime
//

#include <iostream>  
#include <fstream>  

#include <ctime>

struct bme280_data {
        /*! Compensated pressure */
        double pressure;
        /*! Compensated temperature */
        double temperature;
        /*! Compensated humidity */
        double humidity;
};

//struct tm *localtime(const time_t *time);
//This returns a pointer to the tm structure representing local time.
/*struct tm {
   int tm_sec;   // seconds of minutes from 0 to 61
   int tm_min;   // minutes of hour from 0 to 59
   int tm_hour;  // hours of day from 0 to 24
   int tm_mday;  // day of month from 1 to 31
   int tm_mon;   // month of year from 0 to 11
   int tm_year;  // year since 1900
   int tm_wday;  // days since sunday
   int tm_yday;  // days since January 1st
   int tm_isdst; // hours of daylight savings time
   }
*/

class Bme280 {

	private:

		struct bme280_data bme;

   		time_t now;


	public: 

		//on contruit l objet avec les donnees du capteurs
		Bme280() {
			std::cout << "Constructor" << std::endl;
			now = time(0);
			std::cout << "Number of sec since January 1,1970:" << now << std::endl;
		}

		//Bme280()

		void display() const {
			struct tm *ltm = localtime(&now);

			int year = 1900 + ltm->tm_year;
			int month = 1 + ltm->tm_mon;
			int day = ltm->tm_mday;
			int hour = ltm->tm_hour;
			int min = ltm->tm_min;
			int sec = ltm->tm_sec;

			std::cout<<year<<"-"<<month<<"-"<<day<<"-"<<hour<<"-"<<min<<"-"<<sec<<" "<<std::endl;


		}

		// on le sauve dans le fichier

};



using namespace std;  

int main () {  

	Bme280 bme280;
	bme280.display();

	//ofstream 	
	//It is used to create files and write information to the files.
    	ofstream filestreamOut("testout.txt");  


	struct bme280_data bme = { 1020.6 , 27.7 , 45.3 }; 
	
	//current date/time based on current system
   	time_t now = time(0);
	cout << "\nNumber of sec since January 1,1970:" << now << endl;

   	tm *ltm = localtime(&now);

   	// print various components of tm structure.
   	//cout << "Year" << 1970 + ltm->tm_year<<endl;
   	//cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   	//cout << "Day: "<<  ltm->tm_mday << endl;
   	//cout << "Time: "<< 1 + ltm->tm_hour << ":";
   	//cout << 1 + ltm->tm_min << ":";
   	//cout << 1 + ltm->tm_sec << endl;

	int year = 1900 + ltm->tm_year;
	int month = 1 + ltm->tm_mon;
	int day = ltm->tm_mday;
	int hour = ltm->tm_hour;
	int min = ltm->tm_min;
	int sec = ltm->tm_sec;


    	if (filestreamOut.is_open())  
    	{  
        	filestreamOut << "Welcome to javaTpoint.\n";  
        	filestreamOut << "C++ Tutorial.\n";  
        	filestreamOut << year << "-" << month << "-" << day << "-" << hour << "-" << min << "-" << sec << " "
			      << bme.pressure << " " 
		              << bme.temperature << " "  
			      << bme.humidity << " " << endl;  

        	filestreamOut.close();  
    	}  
    	else 
		cout <<"File opening is fail.";  
    


	//ifstream 	
	//It is used to read information from files.
	string str;  

	ifstream filestreamIn("testout.txt");  
  	if (filestreamIn.is_open())  
  	{  
    		while ( getline (filestreamIn,str) )  
    		{  
      			cout << str <<endl;  
    		}  

    		filestreamIn.close();  

  	}	  
  	else {  
      		cout << "File opening is fail."<<endl;   
    	}  





	return 0;  
}  
