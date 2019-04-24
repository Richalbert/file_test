//writing to a file
//
//https://www.javatpoint.com/cpp-files-and-streams

#include <iostream>  
#include <fstream>  

using namespace std;  

int main () {  

	//ofstream 	
	//It is used to create files and write information to the files.
    	ofstream filestream("testout.txt");  

    	if (filestream.is_open())  
    	{  
        	filestream << "Welcome to javaTpoint.\n";  
        	filestream << "C++ Tutorial.\n";  
        	filestream.close();  
    	}  
    	else 
		cout <<"File opening is fail.";  
    
	return 0;  
}  
