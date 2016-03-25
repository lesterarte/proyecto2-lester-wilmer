#pragma once

#include "tiro.h"
#include <string>
using std::string;

class threeofthree : public tiro{
	double atino1;
	double dinero2;
  public:
	threeofthree(double, double);
	virtual ~threeofthree();
	virtual string toString()const;
	double Atino()const;
	double DineroGanado()const;

};