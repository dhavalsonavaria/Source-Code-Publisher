///////////////////////////////////////////////////////////////////////
// Process.cpp - class used to start process                         //
// ver 1.0                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2018         //
///////////////////////////////////////////////////////////////////////
#include "Process.h"
#include"Processor.h"
#include <iostream>
//#include <windows.h>
#include <conio.h>
void Processor::startProcess(std::string name)
{
  std::cout << "chrome --new-instance";
  
  Process p;
  p.title("test application");
  std::string appPath =  "c:/Program Files (x86)/Google/Chrome/Application/chrome.exe";  // path to application to start
  p.application(appPath);
  std::string cmdLine = "/A " + name;  // asking notepad to display Process.h
  p.commandLine(cmdLine);
  
  std::cout << "\n  You need to kill each window (upper right button) to continue.";
  std::cout << "\n  Press key to start";
  _getche();
  
    std::cout << "\n  starting process: \"" << appPath << "\"";
    std::cout << "\n  with this cmdlne: \"" << cmdLine << "\"";
    p.create();
    CBP callback = []() { std::cout << "\n  --- child process exited with this message ---"; };
    p.setCallBackProcessing(callback);
    p.registerCallback();
    WaitForSingleObject(p.getProcessHandle(), INFINITE);  // wait for created process to terminate
  std::cout << "\n  after OnExit";
  std::cout.flush();
  char ch;
  std::cin.read(&ch,1);
}
#ifdef TEST_PROCESS1
void main()
{
	std::string start = "start";Process p;
		p.startProcess("test.h");}
#endif 