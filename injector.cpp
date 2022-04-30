#include <Windows.h>
#include <string>
#include <conio.h>
#include <iostream>

std::string chooseDLL()
{
	OPENFILENAME ofn;
	char fileName[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.lpstrFile = fileName;
	ofn.nMaxFile = MAX_PATH;
	if (GetOpenFileName(&ofn))
	{
		return fileName;
	}
}

int main()
{
	SetConsoleTitle("Injector");
	std::cout << "This is Usurper's Among us Injector. Press enter to choose DLL" << std::endl;
	_getch();

	std::string stringpath = chooseDLL();
	const char* dllPath = stringpath.c_str();
	std::cout << "You choose " << dllPath << std::endl;
	Sleep(1000);
	std::cout << "Press Enter to Inject" << std::endl;
	_getch();

	DWORD pID;
	GetWindowThreadProcessId(FindWindowA(NULL, "Among Us"), &pID);

	if (!pID)
	{
		MessageBoxA(NULL, "Couln't Get Process ID. Ckeck Among Us is Open", "Error", NULL);
	}
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, pID);
	if (hProcess == INVALID_HANDLE_VALUE)
	{
		MessageBoxA(NULL, "Couln't Get Handle to Among Us", "Error", NULL);
	}

	void* allocmemory = VirtualAllocEx(hProcess, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	WriteProcessMemory(hProcess, allocmemory, dllPath, MAX_PATH, 0);

	HANDLE hThread = CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, allocmemory, 0, 0);
	if (hThread)
	{
		MessageBoxA(NULL, "Injected Successfully", "Sucess", NULL);
		VirtualFreeEx(hProcess, allocmemory, NULL, MEM_RELEASE);
		CloseHandle(hThread);
		CloseHandle(hProcess);
	}
	return 0;
}
