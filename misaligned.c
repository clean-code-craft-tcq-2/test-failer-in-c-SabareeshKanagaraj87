#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
static char PrintString[100] = "";


static char* GetPrintString(int PairNumber, char * majorColor, char * minorColor)
{
    sprintf(PrintString, "%d|%s|%s|\n", PairNumber, majorColor, minorColor);
    return PrintString;
}

int printColorMap() {

    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
			printf("%s",GetPrintString(i * 5 + j, majorColor[i], minorColor[i]));
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    char ResultString = GetPrintString(1,"White","Blue");
    assert(result == 25);
    assert(ResultString == "1|White|Blue");
	
	
    printf("All is well (maybe!)\n");
    return 0;
}
