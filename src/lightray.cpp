#include "lightray.h"

/**
	std::vector<float>(3)	: used to store color and objects
	Vector3					: used to store 3 coordinates (position, direction...)
*/

using namespace std;

LightRay::LightRay(vector<float> const& colorRGB, vector<float> const& pos, vector<float> const& dir):
	RGB(colorRGB), position(pos), direction(dir)
{
	nbBumps = 0;
}


LightRay::LightRay(vector<float> const& colorRGB, Vector3 const& pos, Vector3 const& dir):
	RGB(colorRGB), position(pos), direction(dir)
{
	nbBumps = 0;
}


LightRay::~LightRay()
{
	//dtor
}




/***** ACCESSORS *****/
Vector3 LightRay::getPosition(){
	return position;
}


Vector3 LightRay::getDirection(){
	return direction;
}


vector<float> LightRay::getRGB(){
	return RGB;
}



/***** METHODS *****/
int LightRay::update(vector<float> const& newColor, Vector3 const& newDirection){
	nbBumps ++;
	return 0;
}


vector<float> LightRay::newColor(vector<float> const& incidentColor){
	vector<float> answer (3);
	for (int i=0; i<=2; i++){
		if (incidentColor[i] >= RGB[i]){ answer[i] = RGB[i]; }
		else{ answer[i] = incidentColor[i]; }
	}
	return answer;
}


int LightRay::debug(){
	cout<<"[DEBUG - LIGHTRAY] - color:"<<RGB[0]<<";"<<RGB[1]<<";"<<RGB[2]<<
		" pos:"<<position.x()<<";"<<position.y()<<";"<<position.z()<<
		" dir:"<<direction.x()<<";"<<direction.y()<<";"<<direction.z()<<endl;
		return 0;
}
