#pragma once
#include <algorithm>
#include<time.h>
#include<conio.h> 
#include<stdlib.h >
#include<windows.h>
#include<vector>
#include<iostream>
#include<functional>
#include<fstream>
#include<string>
#include <sstream>

using namespace std;
using namespace System;

typedef unsigned int uint;
int setcolor(int color) {
    Console::ForegroundColor = ConsoleColor(color);
    return color;
}
int setfondo(int fondo) {
    Console::BackgroundColor = ConsoleColor(fondo);
    return fondo;
}
void setposition(int x, int y) {
    Console::SetCursorPosition(x, y);
}
