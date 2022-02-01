#include <stdio.h>
#include <assert.h>
#include <string.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
static char PrintString[100] = "";


static char* GetPrintString(int PairNumber, const char * majorColor, const char * minorColor)
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
    assert(result == 25);
    assert(strcmp(GetPrintString(1, "White", "Blue"), "1|White|Blue\n") == 0);
	
	
	
    printf("All is well (maybe!)\n");
    return 0;
}
