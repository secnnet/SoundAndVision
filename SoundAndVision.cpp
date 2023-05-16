#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main()
{
    int w = 40;  // width of the pattern
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Get a handle to the console for changing text color
    int color = 1;  // Initialize color value
    int shape = 0;  // Initialize shape value

    while (1) {  // Infinite loop
        if (_kbhit()) {  // If a key has been pressed
            char ch = _getch();  // Get the pressed key
            if (ch == '+') {
                w++;  // Increase the width of the pattern
            }
            else if (ch == '-' && w > 1) {
                w--;  // Decrease the width of the pattern
            }
            else if (ch == 's') {
                shape = (shape + 1) % 3;  // Change the shape of the pattern
            }
        }

        for (int i = 1; i <= w * (w + 1); i++) {  // Iterate over each position in the pattern
            if (i % (w + 1) == 0) {  // If at the end of a line
                printf("\n");  // Print a newline character
            }
            else if (
                shape == 0 && (i % (w) == 0 || i % (w + 2) == 1) ||
                shape == 1 && i % (w + 1) / 2 == i % (w) ||
                shape == 2 && (i % (w) == 0 || i % (w + 2) == 1) && i % (w + 1) / 2 != i % (w)
                ) {
                SetConsoleTextAttribute(hConsole, color);  // Set the color of the text
                printf("*");  // Print a star
                Beep(400 + i / w * 100, 100);  // Play a sound
                color = color % 15 + 1;  // Cycle through colors
            }
            else {
                SetConsoleTextAttribute(hConsole, 15);  // Set color to white
                printf(" ");  // Print a space
            }
        }
        Sleep(100);  // Delay for 100 milliseconds
        system("CLS");  // Clear the screen
    }
}
