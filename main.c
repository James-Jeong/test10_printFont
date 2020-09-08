#include <stdio.h>
#include <sys/time.h>

///////////////////////////////////////////////////////
/// Definition & Macro
///////////////////////////////////////////////////////

unsigned char fonts[256][8];

///////////////////////////////////////////////////////
/// Predefinition of Static Function
///////////////////////////////////////////////////////

static void CopyFont(unsigned char *dstFont, unsigned char *srcFont);

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

	long int result = 0;
	struct timeval start, end;

	printf("\n[Default]\n");
	PrintFont('A');

	printf("\n[Underline]\n");
	Underline('A');

	printf("\n[Invert]\n");
	gettimeofday(&start, NULL);
	Invert('A');
	gettimeofday(&end, NULL);
	result = (long int)(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	printf("%ld(micro)\n", result);

	printf("\n[Invert2]\n");
	gettimeofday(&start, NULL);
	Invert2('A');
	gettimeofday(&end, NULL);
	result = (long int)(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	printf("%ld(micro)\n", result);

	printf("\n[Bold]\n");
	Bold('A');

	printf("\n[Italic]\n");
	Italic('A');

	printf("\n[Outline]\n");
	Outline('A');

	return 1;
}

///////////////////////////////////////////////////////
/// Local Functions
///////////////////////////////////////////////////////

void PrintFont(unsigned char c)
{
	int row = 0;
	int column = 0;
	unsigned long int mask = 0;

	printf("   |84218421\n");
	printf("------------\n");
	for( ; row < 8; row++)
	{
		mask = 0x1000000000000000;
		printf("%02X |", (unsigned int)(fonts[c][row]));
		for( column = 0; column < 128; column++)
		{
			if(column > 52 && column < 61) printf("%c", ((unsigned long int)(fonts[c][row]) & mask) == 0 ? ' ' : '#');
			mask >>= 1;
		}
		printf("\n");
	}
}

void Underline(unsigned char c)
{
	fonts[c][7] = 0xFF;
	PrintFont(c);
	fonts[c][7] = 0x00;
}

void Invert(unsigned char c)
{
	int bitPos = 0;
	for( ; bitPos < 8; bitPos++)
	{
		fonts[c][bitPos] = (unsigned char)(~fonts[c][bitPos]);
	}

	PrintFont(c);

	for(bitPos = 0; bitPos < 8; bitPos++)
	{
		fonts[c][bitPos] = (unsigned char)(~fonts[c][bitPos]);
	}
}

void Bold(unsigned char c)
{
	int bitPos = 0;
	unsigned char tempFont[1][8];

	CopyFont(tempFont[0], fonts[c]);

	for( ; bitPos < 8; bitPos++)
	{
		fonts[c][bitPos] = fonts[c][bitPos] | (fonts[c][bitPos] >> 1);
	}

	PrintFont(c);

	CopyFont(fonts[c], tempFont[0]);
}

void Italic(unsigned char c)
{
	int bitPos = 0;
	int italicCount = 5;
	unsigned char tempFont[1][8];

	CopyFont(tempFont[0], fonts[c]);

	for( ; bitPos < 5; bitPos++)
	{
		fonts[c][bitPos] = (unsigned char)(fonts[c][bitPos] >> italicCount / 2);
		italicCount--;
	}
	fonts[c][6] = (unsigned char)(fonts[c][6] << 1);

	PrintFont(c);

	CopyFont(fonts[c], tempFont[0]);
}

void Outline(unsigned char c)
{
	int bitPos = 0;
	unsigned char tempFont[1][8];

	CopyFont(tempFont[0], fonts[c]);

	for( ; bitPos < 8; bitPos++)
	{
		fonts[c][bitPos] = fonts[c][bitPos] | (unsigned char)(fonts[c][bitPos] >> 1);
		fonts[c][bitPos] = fonts[c][bitPos] | (unsigned char)(fonts[c][bitPos] << 1);
		fonts[c][bitPos] = fonts[c][bitPos] ^ tempFont[0][bitPos];
	}
	fonts[c][0] = 0x38;
	fonts[c][7] = 0xee;

	PrintFont(c);

	CopyFont(fonts[c], tempFont[0]);
}

///////////////////////////////////////////////////////
/// Static Function
///////////////////////////////////////////////////////

static void CopyFont(unsigned char *dstFont, unsigned char *srcFont)
{
	int bitPos = 0;
	for( ; bitPos < 8; bitPos++)
	{
		dstFont[bitPos] = srcFont[bitPos];
	}
}

