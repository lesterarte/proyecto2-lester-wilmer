#pragma once

#include "tiro.h"
#include <string>
using std::string;

class oneofthree : public tiro{
	double atino1;
	double dinero2;
  public:
	oneofthree(double, double);
	virtual ~oneofthree();
	virtual string toString()const;
	double Atino()const;
	double DineroGanado()const;

};