#pragma once

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <memory>
#include <vector>

class Keyboard
{
public:
	bool getKey(int keyCode); ///< function for getting the key that has been pressed on the keyboard
	bool getKeyDown(int keyCode); ///< function for getting the key that been pressed once it has been pushed down
	bool getkeyUp(int keyCode); ///< function for getting the key that has been pressed once it has been released
private:
	std::vector<int>keycodes; 
};
#endif