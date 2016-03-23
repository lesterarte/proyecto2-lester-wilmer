#pragma once

#include "tiro.h"
#include <string>
using std::string;

class twoofthree : public tiro{
	string atino1;
	double dinero2;
  public:
	twoofthree(string, double);
	virtual ~twoofthree();
	virtual string toString()const;
	string Atino()const;
	double DineroGanado()const;

};