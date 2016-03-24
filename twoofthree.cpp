#include "twoofthree.h"
#include "tiro.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

twoofthree::twoofthree(double atino1, double dinero2):atino1(atino1), dinero2(dinero2){

}
twoofthree::~twoofthree(){

}
string twoofthree::toString()const{
	stringstream ss;
	ss << "Atino:";
	return ss.str();
}
double twoofthree::Atino()const{
	return atino1;
}

double twoofthree::DineroGanado()const{
	return dinero2*atino1;
}