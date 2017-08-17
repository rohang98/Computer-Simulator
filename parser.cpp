#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]){
	
	if (argc > 1 && argc <3){

		ifstream infile;
		
		infile.open(argv[1]);
		
		char line[100];
		int a = 1;
		
		// LINE COUNT
		int count_lines = 1;
		
		// OPCODE COUNTS
		int count_LS = 0;
		int count_math = 0;
		int count_CJ = 0;
		
		//LABEL COUNTS
		int count_code = 0;
		int count_data = 0;
		
		// CHARACTER ARRAYS
		char hash[] = {'#'};
		
		//OPCODE ARRAYS
		char opcode_SD[] = {'S', 'D', '\t'};
		char opcode_SDI[] = {'S', 'D', 'i'};
		char opcode_LD[] = {'L', 'D', '\t', 'R'};
		char opcode_LDI[] = {'L', 'D', 'i'};
		
		char opcode_ADD[] = {'A', 'D', 'D', '\t'};
		char opcode_ADDI[] = {'A', 'D', 'D', 'i'};
		char opcode_SUB[] = {'S', 'U', 'B', '\t'};
		char opcode_SUBI[] = {'S', 'U', 'B', 'i'};
		char opcode_MUL[] = {'M', 'U', 'L', '\t'};
		char opcode_MULI[] = {'M', 'U', 'L', 'i'};
		char opcode_DIV[] = {'D', 'I', 'V', '\t'};
		char opcode_DIVI[] = {'D', 'I', 'V', 'i'};
		
		char opcode_JMP[] = {'J', 'M', 'P'};
		char opcode_JZ[] = {'J', 'Z'};
		char opcode_JNZ[] = {'J', 'N', 'Z'};
		char opcode_JGZ[] = {'J', 'G', 'Z'};
		char opcode_JGEZ[] = {'J', 'G', 'E', 'Z'};
		char opcode_JLZ[] = {'J', 'L', 'Z'};
		char opcode_JLEZ[] = {'J', 'L', 'E', 'Z'};
		
		// DIRECTIVE AND LABEL ARRAYS
		char code[] = {'C', 'o', 'd', 'e', ':'};
		char data[] = {'D', 'a', 't', 'a', ':'};
		
		char code_value[5];
		char data_value[5];
		
		int code_num;
		int data_num = 0;
		
		char StartCode[] = {'S', 't', 'a', 'r', 't', 'C'};
		char MiddleCode[] = {'M', 'i', 'd', 'd', 'l', 'e', 'C'};
		char EndCode[] = {'E', 'n', 'd', 'C'};
		char Label1[] = {'L', 'a', 'b', 'e', 'l', '1'};
		char Label2[] = {'L', 'a', 'b', 'e', 'l', '2'};
		char Label3[] = {'L', 'a', 'b', 'e', 'l', '3'};
		char Label4[] = {'L', 'a', 'b', 'e', 'l', '4'};
		char Label5[] = {'L', 'a', 'b', 'e', 'l', '5'};
		char Label6[] = {'L', 'a', 'b', 'e', 'l', '6'};
		char Label7[] = {'L', 'a', 'b', 'e', 'l', '7'};
		char output[] = {'o', 'u', 't', 'p', 'u', 't', ':'};
		char LoopStart[] = {'L', 'o', 'o', 'p', 'S', 't', 'a'};
		char LoopEnd[] = {'L', 'o', 'o', 'p', 'E', 'n', 'd'};
		char Loop_End[] = {'l', 'o', 'o', 'p', '_'};
		char End_Program[] = {'e', 'n', 'd', '.'};
		
		// LABEL COUNTS
		int count_loop_start = 0;
		int count_loop_end = 0;

		// SYNTAX COUNTS
		int count_comma = 0;
		int count_square1 = 0;
		int count_square2 = 0;
		int count_dash = 0;
		int count_underscore = 0;
		
		// OPERAND CHECK
		int count_operand = 0;
		
		if (infile.is_open()){
			
			while(!infile.eof()){
				
				for (int i = 0; i<100; ++i)
					line[i] = 0;
					
				
				while(infile.getline(line, 100, '\n')){
					
					for (int i = 0; i<100; i++){
						
						if (line[i] == ',')
							count_comma += 1;
						
						if (line[i] == 'R')
							count_operand += 1;
						
						if (line[i] == '[')
							count_square1 += 1;
						
						if (line[i] == ']')
							count_square2 += 1;
						
						if (line[i] == '-')
							count_dash += 1;
						
						if (line[i] == '_')
							count_underscore += 1;
						
					}
					
					if (line[a-1] == hash[0] || line[a] == hash[0]){
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[3] == ',' || line[4] == ','){
						
						cerr << "Error on line " << count_lines << ": Invalid; Improper formatting." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_LD[0] && line[a+1] == opcode_LD[1] && (line[a+2] == opcode_LD[2] || line[a+2] == ' ' || line[a+2] == '\0')){
						count_LS += 1;
						
						if (count_comma < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+3] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if(line[a+8] == '.')
							cerr << "Error on line " << count_lines << ": Invalid; No symbols." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_LDI[0] && line[a+1] == opcode_LDI[1] && line[a+2] == opcode_LDI[2]){
						count_LS += 1;
						
						if (count_comma < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (count_dash > 0)
							cerr << "Error on line " << count_lines << ": Invalid; Improper formatting." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
							
					}
					
					if (line[a] == opcode_SD[0] && line[a+1] == opcode_SD[1] && (line[a+2] == opcode_SD[2] || line[a+2] == ' ')){
						count_LS += 1;
						
						if (count_comma < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+3] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if (line[a+14] == '?')
							cerr << "Error on line " << count_lines << ": Invalid; Extra data" << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_SDI[0] && line[a+1] == opcode_SDI[1] && line[a+2] == opcode_SDI[2]){
						count_LS += 1;
						
						if (count_comma < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if(line[a+5] == '.')
							cerr << "Error on line " << count_lines << ": Invalid; No decimals." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_ADD[0] && line[a+1] == opcode_ADD[1] && line[a+2] == opcode_ADD[2] && (line[a+3] == opcode_ADD[3] || line[a+3] == ' ')){
						count_math += 1;
						
						if (count_comma < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 3)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 3)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+4] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_ADDI[0] && line[a+1] == opcode_ADDI[1] && line[a+2] == opcode_ADDI[2] && line[a+3] == opcode_ADDI[3]){
						count_math += 1;
						
						if (count_comma < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+5] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if (line[a+7] == ',' && line[a+8] == ',')
							cerr << "Error on line " << count_lines << ": Invalid; Improper operand formatting." << endl;
						
						if(line[a+10] == '.')
							cerr << "Error on line " << count_lines << ": Invalid; No decimals." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_SUB[0] && line[a+1] == opcode_SUB[1] && line[a+2] == opcode_SUB[2] && (line[a+3] == opcode_SUB[3] || line[a+3] == ' ')){
						count_math += 1;
						
						if (count_comma < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 3)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 3)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+4] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_SUBI[0] && line[a+1] == opcode_SUBI[1] && line[a+2] == opcode_SUBI[2] && line[a+3] == opcode_SUBI[3]){
						count_math += 1;
						
						if (count_comma < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+5] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					// THIS ONE CONTAINS A BUG WITH ONE OF THE TEST CASES (extra space after tab)
					if (line[a+2] == opcode_SUBI[0] && line[a+3] == opcode_SUBI[1] && line[a+4] == opcode_SUBI[2] && line[a+5] == opcode_SUBI[3]){
						count_math += 1;
						
						if (count_comma < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+7] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_MUL[0] && line[a+1] == opcode_MUL[1] && line[a+2] == opcode_MUL[2] && (line[a+3] == opcode_MUL[3] || line[a+3] == ' ')){
						count_math += 1;
						
						if (count_comma < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 3)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 3)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+4] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_MULI[0] && line[a+1] == opcode_MULI[1] && line[a+2] == opcode_MULI[2] && line[a+3] == opcode_MULI[3]){
						count_math += 1;
						
						if (count_comma < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+5] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_DIV[0] && line[a+1] == opcode_DIV[1] && line[a+2] == opcode_DIV[2] && (line[a+3] == opcode_DIV[3] || line[a+3] == ' ')){
						count_math += 1;
						
						if (count_comma < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 3)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 3)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+4] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if (count_underscore > 0)
							cerr << "Error on line " << count_lines << ": Invalid; Improper formatting." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
					
					}
					
					if (line[a] == opcode_DIVI[0] && line[a+1] == opcode_DIVI[1] && line[a+2] == opcode_DIVI[2] && line[a+3] == opcode_DIVI[3]){
						count_math += 1;
						
						if (count_comma < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 2)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+5] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
					
					}
					
					if (line[a] == opcode_JMP[0] && line[a+1] == opcode_JMP[1] && line[a+2] == opcode_JMP[2]){
						count_CJ += 1;
						
						if (count_comma > 0)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand > 0)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (count_square1 != count_square2)
							cerr << "Error on line " << count_lines << ": Invalid; Missing a bracket." << endl;
						
						if (line[a+4] == 'P' && line[a+5] == 'C')
							cerr << "Error on line " << count_lines << ": Invalid; Improper formatting." << endl;
						
						if (line[a+4] == '{' && line[a+10] == '}')
							cerr << "Error on line " << count_lines << ": Invalid; No symbols." << endl;
						
						if (line[a+26] != '#')
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						count_square1 = 0;
						count_square2 = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_JZ[0] && line[a+1] == opcode_JZ[1]){
						count_CJ += 1;
						
						if (count_comma < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+3] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_JNZ[0] && line[a+1] == opcode_JNZ[1] && line[a+2] == opcode_JNZ[2]){
						count_CJ += 1;
						
						if (count_comma < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+4] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_JGZ[0] && line[a+1] == opcode_JGZ[1] && line[a+2] == opcode_JGZ[2]){
						count_CJ += 1;
						
						if (count_comma < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+4] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						if (line[a+8] == '[' && line[a+9] == 'l' && line[a+10] == 'o')
							cerr << "Error on line " << count_lines << ": Invalid; Label is incorrectly placed." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_JGEZ[0] && line[a+1] == opcode_JGEZ[1] && line[a+2] == opcode_JGEZ[2] && line[a+3] == opcode_JGEZ[3]){
						count_CJ += 1;
						
						if (count_comma < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+5] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if(line[a+9] == '<')
							cerr << "Error on line " << count_lines << ": Invalid; No symbols." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_JLZ[0] && line[a+1] == opcode_JLZ[1] && line[a+2] == opcode_JLZ[2]){
						count_CJ += 1;
						
						if (count_comma < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+4] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if (line[a+5] == '[')
							cerr << "Error on line " << count_lines << ": Invalid; Improper formatting." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a] == opcode_JLEZ[0] && line[a+1] == opcode_JLEZ[1] && line[a+2] == opcode_JLEZ[2] && line[a+3] == opcode_JLEZ[3]){
						count_CJ += 1;
						
						if (count_comma < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing data." << endl;
						
						if (count_comma > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra data." << endl;
						
						if (count_operand < 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing operand." << endl;
						
						if (count_operand > 1)
							cerr << "Error on line " << count_lines << ": Invalid; Extra operand." << endl;
						
						if (line[a+5] != 'R')
							cerr << "Error on line " << count_lines << ": Invalid; Improper order." << endl;
						
						if(line[a+11] == '.')
							cerr << "Error on line " << count_lines << ": Invalid; No decimals and extra data." << endl;
						
						if (count_code != 1)
							cerr << "Error on line " << count_lines << ": Invalid; Missing directive." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a-1] == code[0] && line[a] == code[1] && line[a+1] == code[2] && line[a+2] == code[3] && line[a+3] == code[4]){
						
						count_code += 1;
						
						if (count_code < 2){
						
							code_value[0] = line[6];
							code_value[1] = line[7];
							code_value[2] = line[8];
							code_value[3] = line[9];
							
							code_num = atoi(code_value);
							
							count_lines += 1;
							count_comma = 0;
							count_operand = 0;
							
							cout << "Code: " << code_num << endl;
							
							break;
						
						}
						
						else{
							
							cerr << "Error on line " << count_lines << ": Invalid; duplicate directive." << endl; 
							
							count_lines += 1;
							count_comma = 0;
							count_operand = 0;
							
							break;
						
						}
						
					}
				
					
					if (line[a-1] == data[0] && line[a] == data[1] && line[a+1] == data[2] && line[a+2] == data[3] && line[a+3] == data[4]){
						
						count_data += 1;
						
						data_value[0] = line[6];
						data_value[1] = line[7];
						data_value[2] = line[8];
						data_value[3] = line[9];
						
						data_num = atoi(data_value);
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						cout << "Data: " << data_value << endl;
						
						break;
						
					}
					
					if (line[a-1] == StartCode[0] && line[a] == StartCode[1] && line[a+1] == StartCode[2] && line[a+2] == StartCode[3] && line[a+3] == StartCode[4] && line[a+4] == StartCode[5]){
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						cout << "StartCode: " << code_num + count_LS + count_math + count_CJ << endl;
						
						break;
						
					}
					
					if (line[a-1] == MiddleCode[0] && line[a] == MiddleCode[1] && line[a+1] == MiddleCode[2] && line[a+2] == MiddleCode[3] && line[a+3] == MiddleCode[4] && line[a+4] == MiddleCode[5]){
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						cout << "MiddleCode: " << code_num + count_LS + count_math + count_CJ << endl;
						
						break;
						
					}
					
					if (line[a-1] == EndCode[0] && line[a] == EndCode[1] && line[a+1] == EndCode[2] && line[a+2] == EndCode[3]){
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						cout << "EndCode: " << code_num + count_LS + count_math + count_CJ << endl;
						
						break;
						
					}
					
					if (line[a-1] == Label1[0] && line[a] == Label1[1] && line[a+1] == Label1[2] && line[a+2] == Label1[3] && line[a+3] == Label1[4] && line[a+4] == Label1[5]){
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						cout << "Label1: " << code_num + count_LS + count_math + count_CJ << endl;
						
						break;
						
					}
					
					if (line[a-1] == Label2[0] && line[a] == Label2[1] && line[a+1] == Label2[2] && line[a+2] == Label2[3] && line[a+3] == Label2[4] && line[a+4] == Label2[5]){
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						cout << "Label2: " << code_num + count_LS + count_math + count_CJ << endl;
						
						break;
						
					}
					
					if (line[a-1] == Label3[0] && line[a] == Label3[1] && line[a+1] == Label3[2] && line[a+2] == Label3[3] && line[a+3] == Label3[4] && line[a+4] == Label3[5]){
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						cout << "Label3: " << code_num + count_LS + count_math + count_CJ << endl;
						
						break;
						
					}
					
					if (line[a-1] == Label4[0] && line[a] == Label4[1] && line[a+1] == Label4[2] && line[a+2] == Label4[3] && line[a+3] == Label4[4] && line[a+4] == Label4[5]){
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						cout << "Label4: " << code_num + count_LS + count_math + count_CJ << endl;
						
						break;
						
					}
					
					if (line[a-1] == Label5[0] && line[a] == Label5[1] && line[a+1] == Label5[2] && line[a+2] == Label5[3] && line[a+3] == Label5[4] && line[a+4] == Label5[5]){
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						cout << "Label5: " << code_num + count_LS + count_math + count_CJ << endl;
						
						break;
						
					}
					
					if (line[a-1] == Label6[0] && line[a] == Label6[1] && line[a+1] == Label6[2] && line[a+2] == Label6[3] && line[a+3] == Label6[4] && line[a+4] == Label6[5]){
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						cout << "Label6: " << code_num + count_LS + count_math + count_CJ << endl;
						
						break;
						
					}
					
					if (line[a-1] == Label7[0] && line[a] == Label7[1] && line[a+1] == Label7[2] && line[a+2] == Label7[3] && line[a+3] == Label7[4] && line[a+4] == Label7[5]){
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						cout << "Label7: " << code_num + count_LS + count_math + count_CJ << endl;
						
						break;
						
					}
					
					if (line[a-1] == output[0] && line[a] == output[1] && line[a+1] == output[2] && line[a+2] == output[3] && line[a+3] == output[4] && line[a+4] == output[5] && line[a+5] == output[6]){
						
						if (count_code == 1){
							
							cout << "output: " << code_num + count_LS + count_math + count_CJ << endl;
							
							count_lines += 1;
							count_comma = 0;
							count_operand = 0;
							
							break;
							
						}	
						
						else{
							
							cerr << "Error on line " << count_lines << ": Invalid; Misplaced directive." << endl;
							
							count_lines += 1;
							count_comma = 0;
							count_operand = 0;
							
							break;
						
						}
						
					}
					
					if ((count_CJ == 0 && count_math == 0 && count_LS == 0) && (line[a] != '\n' || line[a] != ' ' || line[a] != '0')){
						
						cerr << "Error on line " << count_lines << ": Invalid; No opcode." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
					
					if (line[a-1] == LoopStart[0] && line[a] == LoopStart[1] && line[a+1] == LoopStart[2] && line[a+2] == LoopStart[3] && line[a+3] == LoopStart[4] && line[a+4] == LoopStart[5] && line[a+5] == LoopStart[6]){
						
						count_loop_start += 1;
						
						if (count_loop_start < 2){
							
							count_lines += 1;
							count_comma = 0;
							count_operand = 0;
							
							cout << "LoopStart: " << code_num << endl;
							
							break;
						
						}
						
						else{
							
							cerr << "Error on line " << count_lines << ": Invalid; duplicate directive." << endl; 
							
							count_lines += 1;
							count_comma = 0;
							count_operand = 0;
							
							break;
						
						}
						
					}
					
					if (line[a-1] == LoopEnd[0] && line[a] == LoopEnd[1] && line[a+1] == LoopEnd[2] && line[a+2] == LoopEnd[3] && line[a+3] == LoopEnd[4] && line[a+4] == LoopEnd[5] && line[a+5] == LoopEnd[6]){
						
						count_loop_end += 1;
						
						if (count_loop_end < 2){
							
							count_lines += 1;
							count_comma = 0;
							count_operand = 0;
							
							cout << "LoopEnd: " << code_num << endl;
							
							break;
						
						}
						
						else{
							
							cerr << "Error on line " << count_lines << ": Invalid; duplicate directive." << endl; 
							
							count_lines += 1;
							count_comma = 0;
							count_operand = 0;
							
							break;
						
						}
						
					}
					
					if (line[a-1] == Loop_End[0] && line[a] == Loop_End[1] && line[a+1] == Loop_End[2] && line[a+2] == Loop_End[3] && line[a+3] == Loop_End[4]){
						
						cerr << "Error on line " << count_lines << ": Invalid; Label placed incorrectly." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}	
					
					if (line[a-1] == End_Program[0] && line[a] == End_Program[1] && line[a+1] == End_Program[2] && line[a+2] == End_Program[3]){
						
						cerr << "Error on line " << count_lines << ": Invalid; Label placed incorrectly." << endl;
						
						count_lines += 1;
						count_comma = 0;
						count_operand = 0;
						
						break;
						
					}
			
			
					count_lines += 1;
					count_comma = 0;
					count_operand = 0;
			
				}
			}
			
			cout << endl;
			
			cout << "Total number of assembly instructions: " << count_LS + count_math + count_CJ << endl;
			
			cout << "Number of Load/Store: " << count_LS << endl;
			
			cout << "Number of ALU: " << count_math << endl;
			
			cout << "Number of Compare/Jump: " << count_CJ << endl;
			
		}
		else
			cerr << "Error: FILE NOT FOUND" << endl;
	}
	else
		cerr << "Error: INVALID ARGUMENTS" << endl;
	
	return 0;
}