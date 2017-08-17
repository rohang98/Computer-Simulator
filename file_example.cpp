// write a program that reads a series
// of words from a file and counts the number
// of (non-whitespace) characters in each line

// needed library
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char input_string[50];
	
	// declare the file object
	ifstream infile;
	ofstream outfile;
	
	// open the file
	infile.open("file_input.txt");
	outfile.open("file_output.txt");
	
	// read from file
	while(infile >> input_string)
	{
		int count_chars = 0;
		
		while (input_string[count_chars] != 0 && count_chars < 50)
			count_chars++;
		
		// output to a file		
		outfile << count_chars << endl;
	}
	
	// close the file
	infile.close();
	outfile.close();
	
	return 0;
}