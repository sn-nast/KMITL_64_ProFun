#include "main.h"
#include "Move.h"
#include "Buffer.h"
#include "Control.h"
HANDLE wHnd;
HANDLE rHnd;
DWORD fdwMode;

CHAR_INFO consoleBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];
COORD bufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
COORD characterPos = { 0, 0 };
SMALL_RECT windowSize = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

bool playStatus = true;
DWORD numEvents = 0;
DWORD numEventsRead = 0;

Player playerMe, * P_playerMe;

int main() {
	srand(time_t(NULL));
	setConsole(SCREEN_WIDTH, SCREEN_HEIGHT);
	setCursor(0);
	strcpy_s(playerMe.format, "[O]");

	playerMe.position = { 5, 5 };
	playerMe.attribute = 7;
	playerMe.lenght = strlen(playerMe.format);

	setMode();
	while (playStatus) {
		// Input Keyboard & Mouse events
		moveControl(&playerMe);
		clearBuffer();
		playerMove(playerMe);
		displayBuffer();
		Sleep(100);
	}
	return 0;
}
