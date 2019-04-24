//writing to a file
//
//https://www.javatpoint.com/cpp-files-and-streams

#include <iostream>  
#include <fstream>  

struct bme280_data {
        /*! Compensated pressure */
        double pressure;
        /*! Compensated temperature */
        double temperature;
        /*! Compensated humidity */
        double humidity;
};



using namespace std;  

int main () {  

	//ofstream 	
	//It is used to create files and write information to the files.
    	ofstream filestreamOut("testout.txt");  


	struct bme280_data bme = { 1020.6 , 27.7 , 45.3 }; 

    	if (filestreamOut.is_open())  
    	{  
        	filestreamOut << "Welcome to javaTpoint.\n";  
        	filestreamOut << "C++ Tutorial.\n";  
        	filestreamOut << bme.pressure << " " 
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
