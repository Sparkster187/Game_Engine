#pragma once

#ifndef _KEYBOARD_H_
#define _KEyBOARD_H_

#include <memory>
#include <vector>

class Keyboard
{
public:
	bool getKey(int keyCode);
	bool getKeyDown(int keyCode);
	bool getkeyUp(int keyCode);
private:
	std::vector<int>keycodes;
};
#endif