#include <stdio.h>
#include <stdlib.h>

bool running = true;

#define NUM_REGISTERS 4

//Registers
int registers[NUM_REGISTERS];

//Instructions
int program_instructions[] = 
{
	0x1064, 0x11C8,
	0x2201, 0x0000
};


int program_counter = 0;

int fetch()
{
	return program_instructions[program_counter++];
}


int instruction_number = 0;
int reg1 = 0;
int reg2 = 0;
int reg3 = 0;
int imm  = 0;

void decode(int instruction)
{
	instruction_number = (instruction & 0xF000) >> 12;
	reg1 = (instruction & 0xF00) >> 8;
	reg2 = (instruction & 0xF0) >> 4;
	reg3 = (instruction & 0xF);
	imm = (instruction & 0xFF);
}


void evaluate()
{
	switch(instruction_number)
	{
		case 0:
		//halt
		printf("halt\n");
		running = false;
		break;
		case 1:
		//loadi
		printf("loadi r%d #%d\n", reg1, imm);
		registers[reg1] = imm;
		break;
		case 2:
		//Add
		printf("add r%d r%d r%d\n", reg1, reg2, reg3);
		registers[reg1] = registers[reg2] + registers[reg3];
		break;
	}
}

void showRegs()
{
	  int i;
	    printf( "regs = " );
		  for( i=0; i<NUM_REGISTERS; i++ )
			      printf( "%04X ", registers[ i ] );
				    printf( "\n" );
}


void run()
{
	while(running)
	{
		showRegs();
		int instruction = fetch();
		decode(instruction);
		evaluate();
	}
	showRegs();
}

int main(int argc, char* argv[])
{
	run();

	return 0;
}
