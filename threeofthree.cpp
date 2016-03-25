#include "threeofthree.h"
#include "tiro.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

threeofthree::threeofthree(double atino1, double dinero2):atino1(atino1), dinero2(dinero2){

}
threeofthree::~threeofthree(){

}
string threeofthree::toString()const{
	stringstream ss;
	ss << "Atino:";
	return ss.str();
}
double threeofthree::Atino()const{
	return atino1;
}

double threeofthree::DineroGanado()const{
	return dinero2*atino1;
}