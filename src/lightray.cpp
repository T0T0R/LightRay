#include "../include/lightray.h"

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
Vector3 LightRay::getPosition() const{
	return position;
}


Vector3 LightRay::getDirection() const{
	return direction;
}


vector<float> LightRay::getRGB() const{
	return RGB;
}



/***** METHODS *****/
int LightRay::update(vector<float> const& newColor, Vector3 const& newDirection){
	nbBumps ++;
	return EXIT_SUCCESS;
}


vector<float> LightRay::newColor(vector<float> const& incidentColor){
	vector<float> answer (3);
	for (int i=0; i<=2; i++){
		if (incidentColor[i] >= RGB[i]){ answer[i] = RGB[i]; }
		else{ answer[i] = incidentColor[i]; }
	}
	return answer;
}


int LightRay::debug() const{
	cout<<"[DEBUG - LIGHTRAY] - color:"<<RGB[0]<<";"<<RGB[1]<<";"<<RGB[2]<<
		" pos:"<<position.x()<<";"<<position.y()<<";"<<position.z()<<
		" dir:"<<direction.x()<<";"<<direction.y()<<";"<<direction.z()<<endl;
		return EXIT_SUCCESS;
}
