#include "tiro.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

tiro::tiro(){

}
tiro::~tiro(){

}
string tiro::toString()const{
	stringstream ss;
	ss << "Tiro @ " << this;
	return ss.str();
}
