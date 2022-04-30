#include <iostream>
#include <windows.h>


int main()
{
    int newValue = 2000;
    int readTest = 0;


    HWND hwnd = FindWindowA(NULL, "Plants vs. Zombies");
    if (hwnd == NULL)
    {
        std::cout << "Cannot Find Plants vs. Zombies" << std::endl;
        Sleep(3000);
        exit(-1);
    }
    else
    {
        DWORD procID;
        GetWindowThreadProcessId(hwnd, &procID);
        HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
        if (procID == NULL)
        {
            std::cout << "Cannot obtain process" << std::endl;
            Sleep(3000);
            exit(-1);
        }
        else
        {
            
            WriteProcessMemory(handle, (PBYTE*)/*hexvalue*/, &newValue, sizeof(newValue), 0);
            ReadProcessMemory(handle, (PBYTE*)/*hexvalue*/, &readTest, sizeof(int), 0);
            std::cout << readTest << std::endl;
            Sleep(10000);
            
        
        }

    }
    
    return 0;


}
