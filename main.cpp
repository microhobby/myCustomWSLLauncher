//
//    Copyright (C) Matheus Castello  All rights reserved.
// Licensed under the terms described in the LICENSE file in the root of this project.
//

#include <iostream>
#include "stdafx.h"

int main(int argc, char* argv[])
{
    DWORD err;
    const std::wstring Name = L"Debian";
    WslApiLoader* wslApi;

    if (argc > 1)
        wslApi = new WslApiLoader(s2ws(argv[1]).c_str());
    else
        wslApi = new WslApiLoader(Name); 
    
    std::cout << "My Custom WSL Launcher b0.1\n";

    // the unique difference from my launcher is that we do not use the current directory
    wslApi->WslLaunchInteractive(
        L"",        // command (empty will call the default shell)
        FALSE,      // dot not execute the command on the current directory
        &err        // get the exit code
    );
    
    std::cout << "Exit code " << err << "\n";
    delete wslApi;

    return err;
}

std::wstring s2ws(const std::string& str)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}
