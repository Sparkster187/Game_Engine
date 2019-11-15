#pragma once
#ifndef _SCREEN_H_
#define _SCREEN_H_

class Screen
{
public:
	unsigned int getWidth();
	unsigned int getHeight();

private:
	unsigned int width;
	unsigned int height;
};
#endif // !_SCREEN_H_

