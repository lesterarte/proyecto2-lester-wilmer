#pragma once

#include "tiro.h"
#include <string>
using std::string;

class oneofthree : public tiro{
	string atino1;
	double dinero2;
  public:
	oneofthree(string, double);
	virtual ~oneofthree();
	virtual string toString()const;
	string Atino()const;
	double DineroGanado()const;

};