#pragma once

#include "tiro.h"
#include <string>
using std::string;

class threeofthree : public tiro{
	string atino1;
	double dinero2;
  public:
	threeofthree(string, double);
	virtual ~threeofthree();
	virtual string toString()const;
	string Atino()const;
	double DineroGanado()const;

};