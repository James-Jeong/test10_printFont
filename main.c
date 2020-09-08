#include <stdio.h>
#include <string.h>
#include <sys/time.h>

///////////////////////////////////////////////////////
/// Definition & Macro
///////////////////////////////////////////////////////

// 출력할 폰트 데이터의 바이트 수
#define NUM_OF_BYTE 8

// 폰트 데이터를 저장할 이중 배열
// 아스키 코드 256 개에 대한 8 바이트의 폰트 데이터를 저장
// 256 X 8 = 2,048 바이트
unsigned char fonts[256][NUM_OF_BYTE];

///////////////////////////////////////////////////////
/// Predefinition of Local Functions
///////////////////////////////////////////////////////

void PrintFont(unsigned char targetChar);
void Underline(unsigned char targetChar);
void Invert(unsigned char targetChar);
void Bold(unsigned char targetChar);
void Italic(unsigned char targetChar);
void Outline(unsigned char targetChar);

///////////////////////////////////////////////////////
/// Main Function
///////////////////////////////////////////////////////

/**
 * @fn int main()
 * @brief 문자 폰트 출력 프로그램
 * @return 1 반환
 */
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

//	long int result = 0;
//	struct timeval start, end;

	printf("\n[Default]\n");
	PrintFont('A');

	printf("\n[Underline]\n");
	Underline('A');

	printf("\n[Invert]\n");
//	gettimeofday(&start, NULL);
	Invert('A');
//	gettimeofday(&end, NULL);
//	result = (long int)(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
//	printf("%ld(micro)\n", result);

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

/**
 * @fn void PrintFont(unsigned char targetChar)
 * @brief 특정 문자에 대한 폰트 데이터를 화면에 출력하는 함수
 * @param targetChar 화면에 출력할 문자(입력)
 * @return 반환값 없음
 */
void PrintFont(unsigned char targetChar)
{
	int row = 0;
	int column = 0;
	unsigned long int mask = 0;

	printf("   |84218421\n");
	printf("------------\n");
	for( ; row < NUM_OF_BYTE; row++)
	{
		mask = 0x1000000000000000;
		printf("%02X |", (unsigned int)(fonts[targetChar][row]));
		for( column = 0; column < 128; column++)
		{
			if(column > 52 && column < 61) printf("%c", ((unsigned long int)(fonts[targetChar][row]) & mask) == 0 ? ' ' : '#');
			mask >>= 1;
		}
		printf("\n");
	}
}

/**
 * @fn void Underline(unsigned char targetChar)
 * @brief 특정 문자의 폰트 데이터를 underline 스타일로 변경해서 출력하는 함수
 * @param targetChar 해당 폰트 스타일로 변경 후 출력할 문자(입력)
 * @return 반환값 없음
 */
void Underline(unsigned char targetChar)
{
	fonts[targetChar][7] = 0xFF;
	PrintFont(targetChar);
	fonts[targetChar][7] = 0x00;
}

/**
 * @fn void Invert(unsigned char targetChar)
 * @brief 특정 문자의 폰트 데이터를 invert 스타일로 변경해서 출력하는 함수
 * @param targetChar 해당 폰트 스타일로 변경 후 출력할 문자(입력)
 * @return 반환값 없음
 */
void Invert(unsigned char targetChar)
{
	int bitPos = 0;
	for( ; bitPos < NUM_OF_BYTE; bitPos++)
	{
		fonts[targetChar][bitPos] = (unsigned char)(~fonts[targetChar][bitPos]);
	}

	PrintFont(targetChar);

	for(bitPos = 0; bitPos < NUM_OF_BYTE; bitPos++)
	{
		fonts[targetChar][bitPos] = (unsigned char)(~fonts[targetChar][bitPos]);
	}
}

/**
 * @fn void Bold(unsigned char targetChar)
 * @brief 특정 문자의 폰트 데이터를 bold 스타일로 변경해서 출력하는 함수
 * @param targetChar 해당 폰트 스타일로 변경 후 출력할 문자(입력)
 * @return 반환값 없음
 */
void Bold(unsigned char targetChar)
{
	int bitPos = 0;
	unsigned char tempFont[1][NUM_OF_BYTE];
	memcpy(tempFont[0], fonts[targetChar], NUM_OF_BYTE);

	for( ; bitPos < NUM_OF_BYTE; bitPos++)
	{
		fonts[targetChar][bitPos] = fonts[targetChar][bitPos] | (fonts[targetChar][bitPos] >> 1);
	}

	PrintFont(targetChar);

	memcpy(fonts[targetChar], tempFont[0], NUM_OF_BYTE);
}

/**
 * @fn void Italic(unsigned char targetChar)
 * @brief 특정 문자의 폰트 데이터를 italic 스타일로 변경해서 출력하는 함수
 * @param targetChar 해당 폰트 스타일로 변경 후 출력할 문자(입력)
 * @return 반환값 없음
 */
void Italic(unsigned char targetChar)
{
	int bitPos = 0;
	int italicCount = 5;
	unsigned char tempFont[1][NUM_OF_BYTE];
	memcpy(tempFont[0], fonts[targetChar], NUM_OF_BYTE);

	for( ; bitPos < 5; bitPos++)
	{
		fonts[targetChar][bitPos] = (unsigned char)(fonts[targetChar][bitPos] >> italicCount / 2);
		italicCount--;
	}
	fonts[targetChar][6] = (unsigned char)(fonts[targetChar][6] << 1);

	PrintFont(targetChar);

	memcpy(fonts[targetChar], tempFont[0], NUM_OF_BYTE);
}

/**
 * @fn void Outline(unsigned char targetChar)
 * @brief 특정 문자의 폰트 데이터를 outline 스타일로 변경해서 출력하는 함수
 * @param targetChar 해당 폰트 스타일로 변경 후 출력할 문자(입력)
 * @return 반환값 없음
 */
void Outline(unsigned char targetChar)
{
	int bitPos = 0;
	unsigned char tempFont[1][NUM_OF_BYTE];
	memcpy(tempFont[0], fonts[targetChar], NUM_OF_BYTE);

	for( ; bitPos < NUM_OF_BYTE; bitPos++)
	{
		fonts[targetChar][bitPos] = fonts[targetChar][bitPos] | (unsigned char)(fonts[targetChar][bitPos] >> 1);
		fonts[targetChar][bitPos] = fonts[targetChar][bitPos] | (unsigned char)(fonts[targetChar][bitPos] << 1);
		fonts[targetChar][bitPos] = fonts[targetChar][bitPos] ^ tempFont[0][bitPos];
	}
	fonts[targetChar][0] = 0x38;
	fonts[targetChar][7] = 0xee;

	PrintFont(targetChar);

	memcpy(fonts[targetChar], tempFont[0], NUM_OF_BYTE);
}

