#pragma once
#ifndef _MATERIAL_ATTRIBUTE_H_
#define _MATERIAL_ATTRIBUTE_H_

#include <string>
#include<memory>

class MaterialAttribute
{
public:
	std::string name;
	int type;
	float FloatValue;
	//std::weak_ptr<Texture> textureValue;
};
#endif // !_MATERIAL_ATTRIBUTE_H_

