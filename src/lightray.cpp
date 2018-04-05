#include "lightray.h"

using namespace std;

LightRay::LightRay(vector<float> const& colorRGB, vector<float> const& pos, vector<float> const& dir):
	RGB(colorRGB), position(pos), direction(dir)
{
	nbBumps = 0;
}

LightRay::~LightRay()
{
	//dtor
}

/***** ACCESSORS *****/
vector<float> LightRay::getPosition(){
	return position;
}

vector<float> LightRay::getDirection(){
	return direction;
}

vector<float> LightRay::getRGB(){
	return RGB;
}


/***** METHODS *****/
int LightRay::update(vector<float> const& newColor, vector<float> const& newDirection){
	nbBumps ++;
	return 0;
}

vector<float> LightRay::newColor(vector<float> const& emissionColor){
	vector<float> answer (3);
	for (int i=0; i<=2; i++){
		if (emissionColor[i] >= RGB[i]){ answer[i] = RGB[i]; }
		else{ answer[i] = emissionColor[i]; }
	}
	return answer;
}
