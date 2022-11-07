#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[]) {
	if (argc == 1 || argc > 2) {
		//fprintf(stderr, "%s", "Liczba argumentow wieksza niz 1 lub brak argumentow\n");
		return 1;
	}

	char* ptr;
	long int retStr = strtol(argv[1], &ptr, 10);
	if (retStr == 0) {
		//fprintf(stderr, "%s", "Argument nie jest liczba naturalna\n");
		return 2;
	}
	if (retStr < 1 || retStr>13) {
		//fprintf(stderr, "%s", "Liczba poza zakresem 1-13\n");
		return 3;
	}
	if (retStr == 1 || retStr == 2) {
		//fprintf(stderr, "%s", "Argument wysnosi 1 lub 2\n");
		return 1;
	}

	STARTUPINFO si;
	PROCESS_INFORMATION pi[2];
	char argLine[50];
	int argNumbers[2] = {retStr - 1, retStr - 2};
	memset(&si, 0, sizeof(si));
	memset(&pi, 0, sizeof(pi));
	si.cb = sizeof(si);

	for (int i = 0; i < 2; i++) {
		sprintf(argLine, "lab6.exe %d", argNumbers[i]);
		if (!CreateProcessA(NULL, argLine, NULL, NULL, 0, 0, NULL, NULL, &si, &pi[i])) {
			printf("CreateProcess #%d failed (%d).\n", i + 1, GetLastError());
			return 2;
		}
		printf("Process #%d created: handle=%p, identifier=%d\n", i + 1, pi[i].hProcess, pi[i].dwProcessId);
	}

	HANDLE cHandle[2] = { pi[0].hProcess, pi[1].hProcess };
	int cExitCode[2];

	WaitForMultipleObjects(2, cHandle, 1, INFINITE);

	for (int i = 0; i < 2; i++) {
		GetExitCodeProcess(pi[i].hProcess, &cExitCode[i]);
		printf("%d\t%d\t%s\t%d\n", (int)GetCurrentProcessId(), pi[i].dwProcessId, argNumbers[i], cExitCode[i]);
		CloseHandle(pi[i].hProcess);
		CloseHandle(pi[i].hThread);
	}

	printf("%d\t%d\n\n", (int)GetCurrentProcessId(), cExitCode[0] + cExitCode[1]);
	
	return 0;
}