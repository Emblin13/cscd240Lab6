#include "lab6.h"

int main()
{
    int * array = NULL;
    int length, choice, value;

//Code provided by Timbre to let scanf compile properly in Visual Studio
    char string[255];
#if WIN32
    scanf_s(stdin, "%s", string);
#else
    scanf(stdin, "%s", string);
#endif
////////////////////////////////////////////////////////////////////////

    length = readInitialLength();
    array = createAndFill(length);

    do
    {
        choice = menu();

        switch(choice)
        {
            case 1: printSortedArray(array, length);
                    break;

            case 2: array = addItem(&length, array);
                    break;

            case 3: value = readValue();
                    printIfFound(value, array, length);
        }
    }while(choice != 4);

    cleanUp(array);
    array = NULL;

    return 0;
}
