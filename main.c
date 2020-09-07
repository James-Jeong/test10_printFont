#include <stdio.h>

///////////////////////////////////////////////////////
/// Definition & Macro
///////////////////////////////////////////////////////

unsigned char fonts[256][8];

///////////////////////////////////////////////////////
/// Predefinition of Local Functions
///////////////////////////////////////////////////////

void PrintFont(unsigned char c);
void Underline(unsigned char c);
void Invert(unsigned char c);
void Bold(unsigned char c);
void Italic(unsigned char c);
void Outline(unsigned char c);

///////////////////////////////////////////////////////
/// Main Function
///////////////////////////////////////////////////////

int main()
{
	fonts['A'][0] = 0x00;
	fonts['A'][1] = 0x10;
	fonts['A'][2] = 0x28;
	fonts['A'][3] = 0x44;
	fonts['A'][4] = 0x7C;
	fonts['A'][5] = 0x44;
	fonts['A'][6] = 0x44;
	fonts['A'][7] = 0x00;

	PrintFont('A');
	Underline('A');
	Invert('A');
	Bold('A');
	Italic('A');
	Outline('A');

	return 1;
}

///////////////////////////////////////////////////////
/// Local Functions
///////////////////////////////////////////////////////

void PrintFont(unsigned char c)
{
	unsigned long int mask = 0;
	int row = 0;
	int column = 0;

	printf("\n[Default]\n");
	for( ; row < 8; row++)
	{
		mask = 0x1000000000000000;
		printf("%02X |", (unsigned int)(fonts[c][row]));
		for( column = 0; column < 128; column++)
		{
			if(column > 52 && column < 60) printf("%c", ((unsigned long int)(fonts[c][row]) & mask) == 0 ? ' ' : '#');
			mask >>= 1;
		}
		printf("\n");
	}
	printf("\n");
}

void Underline(unsigned char c)
{
	unsigned long int mask = 0;
	int row = 0;
	int column = 0;

	printf("\n[Underline]\n");
	fonts[c][7] = 0xFF;
	for( ; row < 8; row++)
	{
		mask = 0x1000000000000000;
		printf("%02X |", (unsigned int)(fonts[c][row]));
		for( column = 0; column < 128; column++)
		{
			if(column > 52 && column < 60) printf("%c", ((unsigned long int)(fonts[c][row]) & mask) == 0 ? ' ' : '#');
			mask >>= 1;
		}
		printf("\n");
	}
	fonts[c][7] = 0x00;
	printf("\n");
}

void Invert(unsigned char c)
{
	unsigned long int mask = 0;
	int row = 0;
	int column = 0;
	int bytePos = 0;

	for( ; bytePos < 8; bytePos++)
	{
		fonts[c][bytePos] = ~fonts[c][bytePos];
	}

	printf("\n[Invert]\n");
	for( ; row < 8; row++)
	{
		mask = 0x1000000000000000;
		printf("%02X |", (unsigned int)(fonts[c][row]));
		for( column = 0; column < 128; column++)
		{
			if(column > 52 && column < 60) printf("%c", ((unsigned long int)(fonts[c][row]) & mask) == 0 ? ' ' : '#');
			mask >>= 1;
		}
		printf("\n");
	}
	printf("\n");

	for(bytePos = 0; bytePos < 8; bytePos++)
	{
		fonts[c][bytePos] = ~fonts[c][bytePos];
	}
}

void Bold(unsigned char c)
{
	unsigned long int mask = 0;
	int row = 0;
	int column = 0;
	int bytePos = 0;

	unsigned char backUpFont[1][8];

	for( ; bytePos < 8; bytePos++)
	{
		backUpFont[0][bytePos] = fonts[c][bytePos];
		fonts[c][bytePos] = fonts[c][bytePos] | (fonts[c][bytePos] >> 1);
	}

	printf("\n[Bold]\n");
	for( ; row < 8; row++)
	{
		mask = 0x1000000000000000;
		printf("%02X |", (unsigned int)(fonts[c][row]));
		for( column = 0; column < 128; column++)
		{
			if(column > 52 && column < 60) printf("%c", ((unsigned long int)(fonts[c][row]) & mask) == 0 ? ' ' : '#');
			mask >>= 1;
		}
		printf("\n");
	}
	printf("\n");

	for(bytePos = 0; bytePos < 8; bytePos++)
	{
		fonts[c][bytePos] = backUpFont[0][bytePos];
	}
}

void Italic(unsigned char c)
{
	unsigned long int mask = 0;
	int row = 0;
	int column = 0;
	int bytePos = 0;
	int italicCount = 5;

	for( ; bytePos < 5; bytePos++)
	{
		fonts[c][bytePos] >>= italicCount / 2;
		italicCount--;
	}
	fonts[c][6] <<= 1; 

	printf("\n[Italic]\n");
	for( ; row < 8; row++)
	{
		mask = 0x1000000000000000;
		printf("%02X |", (unsigned int)(fonts[c][row]));
		for( column = 0; column < 128; column++)
		{
			if(column > 52 && column < 60) printf("%c", ((unsigned long int)(fonts[c][row]) & mask) == 0 ? ' ' : '#');
			mask >>= 1;
		}
		printf("\n");
	}
	
	italicCount = 5;
	for(bytePos = 0; bytePos < 5; bytePos++)
	{
		fonts[c][bytePos] <<= italicCount / 2;
		italicCount--;
	}
	fonts[c][6] >>= 1;

	printf("\n");
}

void Outline(unsigned char c)
{
	unsigned long int mask = 0;
	int row = 0;
	int column = 0;
	int bytePos = 0;
	unsigned char backUpFont[1][8];

	for( ; bytePos < 8; bytePos++)
	{
		backUpFont[0][bytePos] = fonts[c][bytePos];
		fonts[c][bytePos] = fonts[c][bytePos] | (fonts[c][bytePos] >> 1);
		fonts[c][bytePos] = fonts[c][bytePos] | (fonts[c][bytePos] << 1);
		fonts[c][bytePos] = fonts[c][bytePos] ^ backUpFont[0][bytePos];
	}
	fonts[c][0] = 0x38;
	fonts[c][7] = 0xee;

	printf("\n[Outline]\n");
	for( ; row < 8; row++)
	{
		mask = 0x1000000000000000;
		printf("%02X |", (unsigned int)(fonts[c][row]));
		for( column = 0; column < 128; column++)
		{
			if(column > 52 && column < 60) printf("%c", ((unsigned long int)(fonts[c][row]) & mask) == 0 ? ' ' : '#');
			mask >>= 1;
		}
		printf("\n");
	}
	printf("\n");

	for(bytePos = 0; bytePos < 8; bytePos++)
	{
		fonts[c][bytePos] = backUpFont[0][bytePos];
	}
}

