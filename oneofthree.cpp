#include "oneofthree.h"
#include "tiro.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

oneofthree::oneofthree(double atino1, double dinero2):atino1(atino1), dinero2(dinero2){

}
oneofthree::~oneofthree(){

}
string oneofthree::toString()const{
	stringstream ss;
	ss << "Atino:";
	return ss.str();
}
double oneofthree::Atino()const{
	return atino1;
}

double oneofthree::DineroGanado()const{
	return dinero2*atino1;
}