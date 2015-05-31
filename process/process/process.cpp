#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>

#define STRICT
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

void system_error(char *name) {
	//char *ptr = NULL;
	WCHAR ptr[1024];
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM,
		0,
		GetLastError(),
		0,
		//(char *)&ptr,
		ptr,
		1024,
		NULL);

	//fprintf(stderr, "\nError %s: %s\n", name, ptr);
	fprintf(stderr, "\nError %s: %s\n", name, &ptr);
	LocalFree(ptr);
}


int _tmain(int argc, _TCHAR* argv[])
{


	int flag = 0;
	char buffer[30];
	float x, y, z;
	int t = 0;
	float diff;
	float s[300];
	HANDLE file;
	COMMTIMEOUTS timeouts;
	DWORD read, written;
	DCB port;
	HANDLE keyboard = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode;
	//char port_name[128] = "\\\\.\\COM3";
	LPCWSTR port_name = L"\\\\.\\COM4";
	char init[] = ""; // e.g., "ATZ" to completely reset a modem.

	if (argc > 2)
		swprintf_s((wchar_t *)&port_name, 128, L"\\\\.\\COM%c", argv[1][0]);
	//sprintf(port_name, "\\\\.\\COM%c", argv[1][0]);


	file = CreateFile(port_name,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);

	if (INVALID_HANDLE_VALUE == file) {
		system_error("opening file");
		return 1;
	}


	memset(&port, 0, sizeof(port));
	port.DCBlength = sizeof(port);
	if (!GetCommState(file, &port))
		system_error("getting comm state");
	//if (!BuildCommDCB("baud=19200 parity=n data=8 stop=1", &port))
	if (!BuildCommDCB(L"baud=9600 parity=n data=8 stop=1", &port))
		system_error("building comm DCB");
	if (!SetCommState(file, &port))
		system_error("adjusting port settings");


	timeouts.ReadIntervalTimeout = 1;
	timeouts.ReadTotalTimeoutMultiplier = 1;
	timeouts.ReadTotalTimeoutConstant = 1;
	timeouts.WriteTotalTimeoutMultiplier = 1;
	timeouts.WriteTotalTimeoutConstant = 1;
	if (!SetCommTimeouts(file, &timeouts))
		system_error("setting port time-outs.");


	if (!GetConsoleMode(keyboard, &mode))
		system_error("getting keyboard mode");
	mode &= ~ENABLE_PROCESSED_INPUT;
	if (!SetConsoleMode(keyboard, mode))
		system_error("setting keyboard mode");

	if (!EscapeCommFunction(file, CLRDTR))
		system_error("clearing DTR");
	Sleep(200);
	if (!EscapeCommFunction(file, SETDTR))
		system_error("setting DTR");

	if (!WriteFile(file, init, sizeof(init), &written, NULL))
		system_error("writing data to port");

	if (written != sizeof(init))
		system_error("not all data written to port");


	do {

		ReadFile(file, buffer, sizeof(buffer), &read, NULL);
		//if (read){
		//WriteFile(screen, buffer, read, &written, NULL);
		sscanf_s(buffer, "%f %f %f", &x, &y, &z);
		printf("\n%f %f %f\n", x, y, z);
		t = t + 1;
		//}

	} while (t < 300);

	printf("End");
	CloseHandle(keyboard);
	CloseHandle(file);
	_getch();
	return 0;
}