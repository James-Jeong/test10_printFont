#include <stdio.h>
#include <string.h>

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
//////////////////////////////////////////////////////

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

	fonts['B'][0] = 0x00; // 0000 0000
	fonts['B'][1] = 0x78; // 0111 1000
	fonts['B'][2] = 0x44; // 0100 0100
	fonts['B'][3] = 0x44; // 0100 0100
	fonts['B'][4] = 0x78; // 0111 1000
	fonts['B'][5] = 0x44; // 0100 0100
	fonts['B'][6] = 0x78; // 0111 1000
	fonts['B'][7] = 0x00; // 0000 0000

	fonts['C'][0] = 0x00; // 0000 0000
	fonts['C'][1] = 0x7E; // 0111 1110
	fonts['C'][2] = 0x40; // 0100 0000
	fonts['C'][3] = 0x40; // 0100 0000
	fonts['C'][4] = 0x40; // 0100 0000
	fonts['C'][5] = 0x40; // 0100 0000
	fonts['C'][6] = 0x7E; // 0111 1110
	fonts['C'][7] = 0x00; // 0000 0000

	fonts['D'][0] = 0x00; // 0000 0000
	fonts['D'][1] = 0x7C; // 0111 1100
	fonts['D'][2] = 0x42; // 0100 0010
	fonts['D'][3] = 0x42; // 0100 0010
	fonts['D'][4] = 0x42; // 0100 0010
	fonts['D'][5] = 0x42; // 0100 0010
	fonts['D'][6] = 0x7C; // 0111 1100
	fonts['D'][7] = 0x00; // 0000 0000

	fonts['E'][0] = 0x00; // 0000 0000
	fonts['E'][1] = 0x7E; // 0111 1110
	fonts['E'][2] = 0x40; // 0100 0000
	fonts['E'][3] = 0x40; // 0100 0000
	fonts['E'][4] = 0x7E; // 0111 1110
	fonts['E'][5] = 0x40; // 0100 0000
	fonts['E'][6] = 0x7E; // 0111 1110
	fonts['E'][7] = 0x00; // 0000 0000

	fonts['H'][0] = 0x00; // 0000 0000
	fonts['H'][1] = 0x42; // 0100 0010
	fonts['H'][2] = 0x42; // 0100 0010
	fonts['H'][3] = 0x42; // 0100 0010
	fonts['H'][4] = 0x7E; // 0111 1110
	fonts['H'][5] = 0x42; // 0100 0010
	fonts['H'][6] = 0x42; // 0100 0010
	fonts['H'][7] = 0x00; // 0000 0000

	fonts['J'][0] = 0x00; // 0000 0000
	fonts['J'][1] = 0x7E; // 0111 1110
	fonts['J'][2] = 0x08; // 0000 1000
	fonts['J'][3] = 0x08; // 0000 1000
	fonts['J'][4] = 0x08; // 0000 1000
	fonts['J'][5] = 0x28; // 0010 1000
	fonts['J'][6] = 0x18; // 0001 1000
	fonts['J'][7] = 0x00; // 0000 0000

	fonts['X'][0] = 0x00; // 0000 0000
	fonts['X'][1] = 0x42; // 0100 0010
	fonts['X'][2] = 0x24; // 0010 0100
	fonts['X'][3] = 0x18; // 0001 1000
	fonts['X'][4] = 0x18; // 0001 1000
	fonts['X'][5] = 0x24; // 0010 0100
	fonts['X'][6] = 0x42; // 0100 0010
	fonts['X'][7] = 0x00; // 0000 0000

	fonts['a'][0] = 0x00; // 0000 0000
	fonts['a'][1] = 0x3C; // 0011 1100
	fonts['a'][2] = 0x04; // 0000 0100
	fonts['a'][3] = 0x3C; // 0011 1100
	fonts['a'][4] = 0x44; // 0100 0100
	fonts['a'][5] = 0x44; // 0100 0100
	fonts['a'][6] = 0x7C; // 0111 1100
	fonts['a'][7] = 0x00; // 0000 0000


	// A
	printf("\n[Default]\n");
	PrintFont('A');

	printf("\n[Bold]\n");
	Bold('A');

	printf("\n[Underline]\n");
	Underline('A');

	printf("\n[Invert]\n");
Invert('A');

	printf("\n[Italic]\n");
	Italic('A');

	printf("\n[Outline]\n");
	Outline('A');

	// B
	printf("\n[Default]\n");
	PrintFont('B');

	printf("\n[Bold]\n");
	Bold('B');

	printf("\n[Underline]\n");
	Underline('B');

	printf("\n[Invert]\n");
	Invert('B');

	printf("\n[Italic]\n");
	Italic('B');

	printf("\n[Outline]\n");
	Outline('B');

	// C
	printf("\n[Default]\n");
	PrintFont('C');

	printf("\n[Bold]\n");
	Bold('C');

	printf("\n[Underline]\n");
	Underline('C');

	printf("\n[Invert]\n");
	Invert('C');

	printf("\n[Italic]\n");
	Italic('C');

	printf("\n[Outline]\n");
	Outline('C');

	// D
	printf("\n[Default]\n");
	PrintFont('D');

	printf("\n[Bold]\n");
	Bold('D');

	printf("\n[Underline]\n");
	Underline('D');

	printf("\n[Invert]\n");
	Invert('D');

	printf("\n[Italic]\n");
	Italic('D');

	printf("\n[Outline]\n");
	Outline('D');

	// E
	printf("\n[Default]\n");
	PrintFont('E');

	printf("\n[Bold]\n");
	Bold('E');

	printf("\n[Underline]\n");
	Underline('E');

	printf("\n[Invert]\n");
	Invert('E');

	printf("\n[Italic]\n");
	Italic('E');

	printf("\n[Outline]\n");
	Outline('E');

	// H
	printf("\n[Default]\n");
	PrintFont('H');

	printf("\n[Bold]\n");
	Bold('H');

	printf("\n[Underline]\n");
	Underline('H');

	printf("\n[Invert]\n");
	Invert('H');

	printf("\n[Italic]\n");
	Italic('H');

	printf("\n[Outline]\n");
	Outline('H');

	// J
	printf("\n[Default]\n");
	PrintFont('J');

	printf("\n[Bold]\n");
	Bold('J');

	printf("\n[Underline]\n");
	Underline('J');

	printf("\n[Invert]\n");
	Invert('J');

	printf("\n[Italic]\n");
	Italic('J');

	printf("\n[Outline]\n");
	Outline('J');

	// X
	printf("\n[Default]\n");
	PrintFont('X');

	printf("\n[Bold]\n");
	Bold('X');

	printf("\n[Underline]\n");
	Underline('X');

	printf("\n[Invert]\n");
	Invert('X');

	printf("\n[Italic]\n");
	Italic('X');

	printf("\n[Outline]\n");
	Outline('X');

	// a
	printf("\n[Default]\n");
	PrintFont('a');

	printf("\n[Bold]\n");
	Bold('a');

	printf("\n[Underline]\n");
	Underline('a');

	printf("\n[Invert]\n");
	Invert('a');

	printf("\n[Italic]\n");
	Italic('a');

	printf("\n[Outline]\n");
	Outline('a');

	printf("\n");
	return 1;
}

///////////////////////////////////////////////////////
/// Local Functions
///////////////////////////////////////////////////////

/**
 * @fn void PrintFont(unsigned char targetChar)
 * @brief 특정 문자에 대한 폰트 데이터를 화면에 출력하는 함수
 * 문자를 기본 폰트 스타일로 출력한다.
 * @param targetChar 화면에 출력할 문자(입력)
 * @return 반환값 없음
 */
void PrintFont(unsigned char targetChar)
{
	int row = 0;
	int column = 0;
	unsigned char mask = 0;

	printf("  | 84218421 |\n");
	printf("-----------------\n");
	for( ; row < MAX_FONT_BYTE; row++)
	{
		mask = 0x80; // 1000 0000
		printf("%d | ", row);
		for( column = 0; column < NUM_OF_BIT; column++)
		{
			printf("%c", (unsigned char)((fonts[targetChar][row]) & mask) == 0 ? ' ' : '#');
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
 * 문자 영역을 출력하지 않고, 문자를 제외한 모든 영역을 출력한다.
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
	unsigned char originalFont[MAX_FONT_BYTE] = { 0 };
	memcpy(originalFont, fonts[targetChar], MAX_FONT_BYTE);

	for( ; bytePos < MAX_FONT_BYTE; bytePos++)
	{
		fonts[targetChar][bytePos] = fonts[targetChar][bytePos] | (fonts[targetChar][bytePos] >> 1);
	}

	PrintFont(targetChar);

	memcpy(fonts[targetChar], originalFont, MAX_FONT_BYTE);
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
	int bytePos = 1;
	int rightShiftCount = MAX_FONT_BYTE - 3;
	unsigned char originalFont[MAX_FONT_BYTE] = { 0 };
	memcpy(originalFont, fonts[targetChar], MAX_FONT_BYTE);

	for( ; bytePos < (MAX_FONT_BYTE - 3); bytePos++)
	{
		fonts[targetChar][bytePos] = (unsigned char)(fonts[targetChar][bytePos] >> (rightShiftCount / 3));
		rightShiftCount--;
	}
	fonts[targetChar][MAX_FONT_BYTE - 2] = (unsigned char)(fonts[targetChar][MAX_FONT_BYTE - 2] << 1);

	PrintFont(targetChar);

	memcpy(fonts[targetChar], originalFont, MAX_FONT_BYTE);
}

/**
 * @fn void Outline(unsigned char targetChar)
 * @brief 특정 문자의 폰트 데이터를 outline 스타일로 변경해서 출력하는 함수
 * 문자 영역을 출력하지 않고, 문자의 테두리 영역만 출력한다.
 * @param targetChar 해당 폰트 스타일로 변경 후 출력할 문자(입력)
 * @return 반환값 없음
 */
void Outline(unsigned char targetChar)
{
	int bytePos = 0;
	unsigned char originalFont[MAX_FONT_BYTE] = { 0 };
	memcpy(originalFont, fonts[targetChar], MAX_FONT_BYTE);

	fonts[targetChar][0] = fonts[targetChar][0] | (unsigned char)(fonts[targetChar][1]);
	fonts[targetChar][MAX_FONT_BYTE - 1] = fonts[targetChar][MAX_FONT_BYTE - 1] | (unsigned char)(fonts[targetChar][MAX_FONT_BYTE - 2]);

	for( ; bytePos < MAX_FONT_BYTE; bytePos++)
	{
		fonts[targetChar][bytePos] = fonts[targetChar][bytePos] | (unsigned char)(fonts[targetChar][bytePos] >> 1);
		fonts[targetChar][bytePos] = fonts[targetChar][bytePos] | (unsigned char)(fonts[targetChar][bytePos] << 1);
		fonts[targetChar][bytePos] = fonts[targetChar][bytePos] ^ originalFont[bytePos];
	}

	PrintFont(targetChar);

	memcpy(fonts[targetChar], originalFont, MAX_FONT_BYTE);
}

