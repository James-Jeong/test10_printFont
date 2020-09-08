#include <stdio.h>
#include <string.h>
#include <sys/time.h>

///////////////////////////////////////////////////////
/// Definition & Macro
///////////////////////////////////////////////////////

// 출력할 폰트 데이터의 바이트 수
#define MAX_FONT_BYTE 8
// 1 바이트 당 비트 수
#define NUM_OF_BIT 8

// 폰트 데이터를 저장할 이중 배열
// 아스키 코드 256 개에 대한 MAX_FONT_BYTE 만큼의 폰트 데이터를 저장
unsigned char fonts[256][MAX_FONT_BYTE] = {{ 0 }};

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
	fonts['A'][0] = 0x00; // 0000 0000
	fonts['A'][1] = 0x10; // 0001 0000
	fonts['A'][2] = 0x28; // 0010 1000
	fonts['A'][3] = 0x44; // 0100 0100
	fonts['A'][4] = 0x7C; // 0111 1100
	fonts['A'][5] = 0x44; // 0100 0100
	fonts['A'][6] = 0x44; // 0100 0100
	fonts['A'][7] = 0x00; // 0000 0000

	printf("\n[Default]\n");
	PrintFont('A');

	printf("\n[Underline]\n");
	Underline('A');

	printf("\n[Invert]\n");
	Invert('A');

	printf("\n[Bold]\n");
	Bold('A');

	printf("\n[Italic]\n");
	Italic('A');

	printf("\n[Outline]\n");
	Outline('A');

	printf("\n");
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

	printf("  | 84218421 |\n");
	printf("-----------------\n");
	for( ; row < MAX_FONT_BYTE; row++)
	{
		mask = 0x80; // 1000 0000
		printf("%d | ", row);
		for( column = 0; column < NUM_OF_BIT; column++)
		{
			printf("%c", ((unsigned long int)(fonts[targetChar][row]) & mask) == 0 ? ' ' : '#');
			mask >>= 1;
		}
		printf(" | %02X", (unsigned int)(fonts[targetChar][row]));
		printf("\n");
	}
}

/**
 * @fn void Underline(unsigned char targetChar)
 * @brief 특정 문자의 폰트 데이터를 underline 스타일로 변경해서 출력하는 함수
 * 문자의 최하단에 밑줄을 그려서 출력한다.
 * @param targetChar 해당 폰트 스타일로 변경 후 출력할 문자(입력)
 * @return 반환값 없음
 */
void Underline(unsigned char targetChar)
{
	fonts[targetChar][MAX_FONT_BYTE - 1] = 0xFF; // 1111 1111
	PrintFont(targetChar);
	fonts[targetChar][MAX_FONT_BYTE - 1] = 0x00; // 0000 0000
}

/**
 * @fn void Invert(unsigned char targetChar)
 * @brief 특정 문자의 폰트 데이터를 invert 스타일로 변경해서 출력하는 함수
 * 문자를 제외한 모든 영역을 출력한다.
 * @param targetChar 해당 폰트 스타일로 변경 후 출력할 문자(입력)
 * @return 반환값 없음
 */
void Invert(unsigned char targetChar)
{
	int bytePos = 0;
	for( ; bytePos < MAX_FONT_BYTE; bytePos++)
	{
		fonts[targetChar][bytePos] = (unsigned char)(~fonts[targetChar][bytePos]);
	}

	PrintFont(targetChar);

	for(bytePos = 0; bytePos < MAX_FONT_BYTE; bytePos++)
	{
		fonts[targetChar][bytePos] = (unsigned char)(~fonts[targetChar][bytePos]);
	}
}

/**
 * @fn void Bold(unsigned char targetChar)
 * @brief 특정 문자의 폰트 데이터를 bold 스타일로 변경해서 출력하는 함수
 * 문자를 짙게 출력한다.
 * @param targetChar 해당 폰트 스타일로 변경 후 출력할 문자(입력)
 * @return 반환값 없음
 */
void Bold(unsigned char targetChar)
{
	int bytePos = 0;
	unsigned char originalFont[1][MAX_FONT_BYTE] = {{ 0 }};
	memcpy(originalFont[0], fonts[targetChar], MAX_FONT_BYTE);

	for( ; bytePos < MAX_FONT_BYTE; bytePos++)
	{
		fonts[targetChar][bytePos] = fonts[targetChar][bytePos] | (fonts[targetChar][bytePos] >> 1);
	}

	PrintFont(targetChar);

	memcpy(fonts[targetChar], originalFont[0], MAX_FONT_BYTE);
}

/**
 * @fn void Italic(unsigned char targetChar)
 * @brief 특정 문자의 폰트 데이터를 italic 스타일로 변경해서 출력하는 함수
 * 문자를 오른쪽으로 기울여서 출력한다.
 * @param targetChar 해당 폰트 스타일로 변경 후 출력할 문자(입력)
 * @return 반환값 없음
 */
void Italic(unsigned char targetChar)
{
	int bytePos = 0;
	int rightShiftCount = MAX_FONT_BYTE - 3;
	unsigned char originalFont[1][MAX_FONT_BYTE] = {{ 0 }};
	memcpy(originalFont[0], fonts[targetChar], MAX_FONT_BYTE);

	for( ; bytePos < (MAX_FONT_BYTE - 3); bytePos++)
	{
		fonts[targetChar][bytePos] = (unsigned char)(fonts[targetChar][bytePos] >> (rightShiftCount / 2));
		rightShiftCount--;
	}
	fonts[targetChar][MAX_FONT_BYTE - 2] = (unsigned char)(fonts[targetChar][MAX_FONT_BYTE - 2] << 1);

	PrintFont(targetChar);

	memcpy(fonts[targetChar], originalFont[0], MAX_FONT_BYTE);
}

/**
 * @fn void Outline(unsigned char targetChar)
 * @brief 특정 문자의 폰트 데이터를 outline 스타일로 변경해서 출력하는 함수
 * 문자의 테두리 영역만 출력한다.
 * @param targetChar 해당 폰트 스타일로 변경 후 출력할 문자(입력)
 * @return 반환값 없음
 */
void Outline(unsigned char targetChar)
{
	int bytePos = 0;
	unsigned char originalFont[1][MAX_FONT_BYTE] = {{ 0 }};
	memcpy(originalFont[0], fonts[targetChar], MAX_FONT_BYTE);

	for( ; bytePos < MAX_FONT_BYTE; bytePos++)
	{
		fonts[targetChar][bytePos] = fonts[targetChar][bytePos] | (unsigned char)(fonts[targetChar][bytePos] >> 1);
		fonts[targetChar][bytePos] = fonts[targetChar][bytePos] | (unsigned char)(fonts[targetChar][bytePos] << 1);
		fonts[targetChar][bytePos] = fonts[targetChar][bytePos] ^ originalFont[0][bytePos];
	}
	fonts[targetChar][0] = 0x38; // 0011 1000
	fonts[targetChar][MAX_FONT_BYTE - 1] = 0xee; // 1110 1110

	PrintFont(targetChar);

	memcpy(fonts[targetChar], originalFont[0], MAX_FONT_BYTE);
}

