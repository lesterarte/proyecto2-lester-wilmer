#pragma once

#include "tiro.h"
#include <string>
using std::string;

class twoofthree : public tiro{
	double atino1;
	double dinero2;
  public:
	twoofthree(double, double);
	virtual ~twoofthree();
	virtual string toString()const;
	double Atino()const;
	double DineroGanado()const;

};