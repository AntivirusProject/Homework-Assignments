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


	int flag1 = 0;
	int flag2 = 0;
	char buffer1[30], buffer2[30];
	float x1, y1, z1, x2, y2, z2;
	float baseline1, baseline2;
	float diff1, diff2;
	float s1[300], s2[300];
	HANDLE file1,file2;
	COMMTIMEOUTS timeouts;
	DWORD read1, written1, read2, written2;
	DCB port1, port2;
	HANDLE keyboard = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	
	DWORD mode;
	//char port_name[128] = "\\\\.\\COM3";
	LPCWSTR port_name1 = L"\\\\.\\COM4";
	LPCWSTR port_name2 = L"\\\\.\\COM5";
	char init1[] = ""; // e.g., "ATZ" to completely reset a modem.
	char init2[] = "";

	if (argc > 2){
		swprintf_s((wchar_t *)&port_name1, 128, L"\\\\.\\COM%c", argv[1][0]);
		swprintf_s((wchar_t *)&port_name2, 128, L"\\\\.\\COM%c", argv[1][0]);
		//sprintf(port_name, "\\\\.\\COM%c", argv[1][0]);
	}

	file1 = CreateFile(port_name1,GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);

	if (INVALID_HANDLE_VALUE == file1) {
		system_error("opening file 1");
		return 1;
	}
	
	file2 = CreateFile(port_name2, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

	if (INVALID_HANDLE_VALUE == file2) {
		system_error("opening file 2");
		return 1;
	}


	memset(&port1, 0, sizeof(port1));
	port1.DCBlength = sizeof(port1);
	if (!GetCommState(file1, &port1))
		system_error("getting comm state");
	//if (!BuildCommDCB("baud=19200 parity=n data=8 stop=1", &port))
	if (!BuildCommDCB(L"baud=9600 parity=n data=8 stop=1", &port1))
		system_error("building comm DCB");
	if (!SetCommState(file1, &port1))
		system_error("adjusting port settings");

	memset(&port2, 0, sizeof(port2));
	port2.DCBlength = sizeof(port2);
	if (!GetCommState(file2, &port2))
		system_error("getting comm state");
	//if (!BuildCommDCB("baud=19200 parity=n data=8 stop=1", &port))
	if (!BuildCommDCB(L"baud=9600 parity=n data=8 stop=1", &port2))
		system_error("building comm DCB");
	if (!SetCommState(file2, &port2))
		system_error("adjusting port settings");


	timeouts.ReadIntervalTimeout = 1;
	timeouts.ReadTotalTimeoutMultiplier = 1;
	timeouts.ReadTotalTimeoutConstant = 1;
	timeouts.WriteTotalTimeoutMultiplier = 1;
	timeouts.WriteTotalTimeoutConstant = 1;
	if (!SetCommTimeouts(file1, &timeouts))
		system_error("setting port1 time-outs.");

	if (!SetCommTimeouts(file2, &timeouts))
		system_error("setting port2 time-outs.");


	if (!GetConsoleMode(keyboard, &mode))
		system_error("getting keyboard mode 1");
	
	mode &= ~ENABLE_PROCESSED_INPUT;
	if (!SetConsoleMode(keyboard, mode))
		system_error("setting keyboard mode 1");
	

	if (!EscapeCommFunction(file1, CLRDTR))
		system_error("clearing DTR");

	if (!EscapeCommFunction(file2, CLRDTR))
		system_error("clearing DTR");

	Sleep(200);
	if (!EscapeCommFunction(file1, SETDTR))
		system_error("setting DTR");

	if (!EscapeCommFunction(file2, SETDTR))
		system_error("setting DTR");

	if (!WriteFile(file1, init1, sizeof(init1), &written1, NULL))
		system_error("writing data to port1");

	if (!WriteFile(file2, init2, sizeof(init2), &written2, NULL))
		system_error("writing data to port2");

	if (written1 != sizeof(init1))
		system_error("not all data written to port 1");

	if (written2 != sizeof(init2))
		system_error("not all data written to port 2");
	
	
	int t = 0;

	do {

		ReadFile(file1, buffer1, sizeof(buffer1), &read1, NULL);
		ReadFile(file2, buffer2, sizeof(buffer2), &read2, NULL);
		if (read1 && read2){
			//WriteFile(screen, buffer1, read1, &written1, NULL);
			//WriteFile(screen, buffer2, read2, &written2, NULL);
			sscanf_s(buffer1, "%f %f %f", &x1, &y1, &z1);
			sscanf_s(buffer2, "%f %f %f", &x2, &y2, &z2);
			s1[t] = sqrt(x1*x1 + y1*y1 + z1*z1);
			
			s2[t] = sqrt(x2*x2 + y2*y2 + z2*z2);
			t = t + 1;
		}
	} while (t < 4);

	baseline1 = s1[t];
	baseline2 = s2[t];
	int count = 0;
	bool car_enter = 0;
	bool car_depart = 0;
	float threshold = 7.0;
	float time1, time2, time3, time_to_cross_sen2,total_time, length, speed;
	float distance = 30;
	do {

		ReadFile(file1, buffer1, sizeof(buffer1), &read1, NULL);
		ReadFile(file2, buffer2, sizeof(buffer2), &read2, NULL);
		if (read1 && read2){
			//WriteFile(screen, buffer1, read1, &written1, NULL);
			//WriteFile(screen, buffer2, read2, &written2, NULL);
			sscanf_s(buffer1, "%f %f %f", &x1, &y1, &z1);
			sscanf_s(buffer2, "%f %f %f", &x2, &y2, &z2);
			s1[t] = sqrt(x1*x1 + y1*y1 + z1*z1);
			diff1 = s1[t] - s1[t - 1];
			s2[t] = sqrt(x2*x2 + y2*y2 + z2*z2);
			diff2 = s2[t] - s2[t - 1];
			printf("\n\n%f \t %f", diff1, diff2);
			if ((diff1 > threshold || diff1 < -threshold) && flag1 == 0 && (s1[t] > baseline1 + 5 || s1[t] < baseline1 - 5)){
				//printf("\n Detected");
				flag1 = 1;
				time1 = t;
				car_enter = true;
				
			}

			if ((diff1 < threshold && diff1 > -threshold) && flag1 == 1){
				flag1 = 0;
				//printf("\n The Car has left");

			}

			if ((diff2 > threshold || diff2 < -threshold) && flag2 == 0 && (s2[t] > baseline2 + 5 || s2[t] < baseline2 - 5)){
				//printf("\n Detected");
				flag2 = 1;
				time2 = t;
				
			}

			if ((diff2 < threshold && diff2 > -threshold) && flag2 == 1){
				flag2 = 0;
				time3 = t;
				car_depart = true;
				//printf("\n The Car has left");
				

			}

			if (car_enter == true && car_depart == true){
				car_enter = false;
				car_depart = false;
				total_time = (time2 - time1) * 100 / 1000;
				speed = distance / total_time;
				time_to_cross_sen2 = (time3 - time2) * 100 / 1000;
				length = time_to_cross_sen2 * speed;
				count = count + 1;
				printf("\n Count: %d", count);
				printf("\n Speed: %f cm/s", speed);
				printf("\n Length: %f cm", length);
			}

			
			t = t + 1;
			
		}

		

	} while (t < 300);

	printf("End");
	CloseHandle(keyboard);
	CloseHandle(file1);
	CloseHandle(file2);
	_getch();
	return 0;
}