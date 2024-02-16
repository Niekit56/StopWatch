#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h> 

#define TRUE 1

//function for outputting digits
void drawDigit(int digit, char buffer[][100]) {
    switch(digit) {
        case 0:
            sprintf(buffer[0], "  #####  ");
            sprintf(buffer[1], " #     # ");
            sprintf(buffer[2], "#       #");
            sprintf(buffer[3], "#       #");
            sprintf(buffer[4], "#       #");
            sprintf(buffer[5], " #     # ");
            sprintf(buffer[6], "  #####  ");
            break;
        case 1:
            sprintf(buffer[0], "    #    ");
            sprintf(buffer[1], "   ##    ");
            sprintf(buffer[2], "  # #    ");
            sprintf(buffer[3], "    #    ");
            sprintf(buffer[4], "    #    ");
            sprintf(buffer[5], "    #    ");
            sprintf(buffer[6], "  #####  ");
            break;
        case 2:
            sprintf(buffer[0], "  #####  ");
            sprintf(buffer[1], " #     # ");
            sprintf(buffer[2], "       # ");
            sprintf(buffer[3], "  #####  ");
            sprintf(buffer[4], " #       ");
            sprintf(buffer[5], "#        ");
            sprintf(buffer[6], "#########");
            break;
        case 3:
            sprintf(buffer[0], "  #####  ");
            sprintf(buffer[1], " #     # ");
            sprintf(buffer[2], "       # ");
            sprintf(buffer[3], "  #####  ");
            sprintf(buffer[4], "       # ");
            sprintf(buffer[5], " #     # ");
            sprintf(buffer[6], "  #####  ");
            break;
        case 4:
            sprintf(buffer[0], "#       #");
            sprintf(buffer[1], "#       #");
            sprintf(buffer[2], "#       #");
            sprintf(buffer[3], "#########");
            sprintf(buffer[4], "       # ");
            sprintf(buffer[5], "       # ");
            sprintf(buffer[6], "       # ");
            break;
        case 5:
            sprintf(buffer[0], "#########");
            sprintf(buffer[1], "#        ");
            sprintf(buffer[2], "#        ");
            sprintf(buffer[3], "######## ");
            sprintf(buffer[4], "       # ");
            sprintf(buffer[5], "#      # ");
            sprintf(buffer[6], " ######  ");
            break;
        case 6:
            sprintf(buffer[0], " ######  ");
            sprintf(buffer[1], "#        ");
            sprintf(buffer[2], "#        ");
            sprintf(buffer[3], "#######  ");
            sprintf(buffer[4], "#      # ");
            sprintf(buffer[5], "#      # ");
            sprintf(buffer[6], " ######  ");
            break;
        case 7:
            sprintf(buffer[0], "#########");
            sprintf(buffer[1], "#     #  ");
            sprintf(buffer[2], "     #   ");
            sprintf(buffer[3], "    #    ");
            sprintf(buffer[4], "   #     ");
            sprintf(buffer[5], "  #      ");
            sprintf(buffer[6], "  #      ");
            break;
        case 8:
            sprintf(buffer[0], " ######  ");
            sprintf(buffer[1], "#      # ");
            sprintf(buffer[2], "#      # ");
            sprintf(buffer[3], " ######  ");
            sprintf(buffer[4], "#      # ");
            sprintf(buffer[5], "#      # ");
            sprintf(buffer[6], " ######  ");
            break;
        case 9:
            sprintf(buffer[0], " ######  ");
            sprintf(buffer[1], "#      # ");
            sprintf(buffer[2], "#      # ");
            sprintf(buffer[3], " ####### ");
            sprintf(buffer[4], "       # ");
            sprintf(buffer[5], "       # ");
            sprintf(buffer[6], " ######  ");
            break;
    }
}

int main() {

    int minutes = 0;
    int seconds = 0;

    char digitBuffers[5][7][100]; // Buffers to store each digit
    while(TRUE) {
        // Draw first digit of minutes
        drawDigit(minutes / 10, digitBuffers[0]);
        // Draw second digit of minutes
        drawDigit(minutes % 10, digitBuffers[1]);
        // Draw colon
        sprintf(digitBuffers[2][0], " : ");
        // Draw first digit of seconds
        drawDigit(seconds / 10, digitBuffers[3]);
        // Draw second digit of seconds
        drawDigit(seconds % 10, digitBuffers[4]);

        // Use ANSI control characters to change the text color
        printf("\033[0;32m"); // \033 - escape sequence, [0;32m - code for green color       

        // Print the buffer
        for (int i = 0; i < 7; i++) {
            printf("%s  %s  %s  %s  %s\n", digitBuffers[0][i], digitBuffers[1][i], digitBuffers[2][0], digitBuffers[3][i], digitBuffers[4][i]);
        }

        fflush(stdout);
        usleep(1000000); // 1000000 microseconds = 1 second
        system("clear");

        //simple logic for changing symbols
        seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
            if (minutes == 100) {
                minutes = 0;
            }
        }
    }
    return 0;
}
