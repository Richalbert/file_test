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


class Bme280 {

	private:

		struct bme280_data m_bme;
   		time_t m_now;


	public: 

		//on contruit l objet avec les donnees du capteurs
		Bme280() {
			std::cout << "Constructor1" << std::endl;
			m_now = time(0);
			std::cout << "Number of sec since 1 January 1970 : " << m_now << std::endl;
		}

//TODO ne marche pas!
		//Bme280(double pressure, double temperature, double humidity):
		//m_bme.pressure(pressure),
		//m_bme.tempertature(temperature),
		//m_bme.humidity(humidity)
	      	//{
		//	std::cout << "Constructor2" << std::endl;
		//	Bme280();
		//}

		Bme280(double pressure, double temperature, double humidity){
			std::cout << "Constructor2" << std::endl;
			m_now = time(0);
			m_bme.pressure = pressure;
			m_bme.temperature = temperature;
			m_bme.humidity = humidity;
		}

		void display() const {
			struct tm *ltm = localtime(&m_now);

			int year = 1900 + ltm->tm_year;
			int month = 1 + ltm->tm_mon;
			int day = ltm->tm_mday;
			int hour = ltm->tm_hour;
			int min = ltm->tm_min;
			int sec = ltm->tm_sec;

			std::cout<<year<<"-"<<month<<"-"<<day<<"-"<<hour<<"-"<<min<<"-"<<sec<<" "<<std::endl;

	//		std::cout<<m_bme.pressure<<" "<<m_bme.temperature<<" "<<m_bme.humidity<<" "<<std::endl;  

		}

		// on le sauve dans le fichier

};



using namespace std;  

int main () {  

	Bme280 bme280;
	bme280.display();

	Bme280 bme280_2(1024,25,30);
	bme280_2.display();




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
