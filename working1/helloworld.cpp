/*
 * helloworld.cpp
 *
 *  Created on: 27.12.2013
 *      Author: declan
 */

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

enum class SignalingUnitType {
    	SUW,
    	SUA_FULL,
		SUA_HALF
    };
    enum class SignalingUnitFading {
    	None,
    	SIF1,
		SIF2
    };
    enum class LogicalResourceSetup {
    	OneSISOOneTX,
		OneSIMO1x2,
		OneMISO1x2,
		OneMIMO2x2,
		OneMIMO4x2,
		MIMO1x4,
		MIMO2x4,
		OneMIMO4x4
    };
    enum class StackType {
    	RealLteStack,
    	RealLteStackSua,
		RealLteStackSua_Deployment_2,
		RealLteStackSua_Deployment_2_S,
		RealLteStackSua_Deployment_E,
		RealLteStackSua_Deployment_Y,
		RealLteStackSua_Deployment_Z
    };
 /*   enum class StackCombination {
        	LteSisoCell,
			LteSimoCell,
			LteMimoCell,
			LteMimo4x2Fading,
			LteMimo4x4,
			LteCellDeployment2,
			LteCellDeployment2_S,
			LteCellDeploymentE,
			LteCellDeploymentY,
			LteCellDeploymentZ
    };*/


int maxAt(std::vector<int>& vector_name) {
    int max = INT_MIN;
    for (auto val : vector_name) {
         if (max < val) max = val;
    }
    return max;
}

void bar() {
    auto f = []{printf("Hello, Lambdas\n"); };
    f();
 }

// Declaration of StackCombination class
class StackCombination {

public:
	StackCombination(string, int, int, int, int, string, string);
	void print();

private:
	string id;
	int numCores;
	int maxCells;
	int maxLayers;  // calculated over all cells
	int maxDataRateMbps;
	string stackType;
	string sigUnitType;
};

// StackCombination constructor function definition
StackCombination::StackCombination(string name,
		                           int cores,
								   int cells,
								   int layers,
								   int datarate,
								   string st,
								   string sut)
{
	id = name;
	numCores = cores;
	maxCells = cells;
	maxLayers = layers;
	maxDataRateMbps = datarate; // assumes DAU2 and optimized DAU/SUA interface
	stackType = st;
	sigUnitType = sut;
}

void StackCombination::print()
{
	cout << "ID: " << id <<
			", #Cores: " << numCores <<
			", MaxCells: " << maxCells <<
			", DataRate: " << maxDataRateMbps <<
			", StackType: " << stackType <<
			", SignalingUnitType: " << sigUnitType << endl;
}



int main(int argc, char ** argv)
{
	// GNU C compiler check
	puts("C99 version: ");
	for (int i = 0; argv[i]; i++)
	{
		printf("%d: %s\n", i, argv[i]);
	}

	stringstream version;
	version << "GCC version: "
			<< __GNUC__
			<< "."
			<< __GNUC_MINOR__
			<< "."
			<< __GNUC_PATCHLEVEL__
			<< "\nVersion string: "
			<< __VERSION__;

    cout << version.str() << endl;

    // c++11 compiler test
    vector<string> v = {"one", "two", "three"}; // initializer list

    for (string s : v)
    {
    	cout << s << endl;
    }

    bar();

    auto func = [] () { cout << "Hello world (as lambda)" << endl; };
    func(); // now call the function

    // vector of carriers
    std::vector< std::vector<int> > vec2d(2, std::vector<int>(10,0));
    cout << "vector size: " << vec2d.size() << endl;
    for (int i = 0; i < vec2d.size(); ++i)
    {
    	for (int j = 0; j < vec2d.at(i).size(); ++j)
    	{
    		cout << "carrier:" << i << ", Subframe" << j << "=" << vec2d.at(i).at(j) << endl;

    	}
    }
    std::vector<int> vInt { 1,2,3,4,-7,999,5,6 };
    const int maxVal = maxAt(vInt);
    cout << "maxVal : " << maxVal << endl;

    // Single carrier, no fading or fading required
    //StackCombination sc = StackCombination::LteSimoCell;
    StackType st1 = StackType::RealLteStackSua_Deployment_2;
    StackType st2 = StackType::RealLteStackSua_Deployment_2_S;
    LogicalResourceSetup lrs = LogicalResourceSetup::OneSIMO1x2;
    SignalingUnitType suTypeSt1 = SignalingUnitType::SUA_HALF;
    SignalingUnitType suTypeSt2 = SignalingUnitType::SUA_HALF;
    SignalingUnitFading suf = SignalingUnitFading::SIF2;

    cout << "Single carrier suf:" << static_cast<int>(suf) << endl;

    // Single carrier, no fading
    // Single carrier, fading
    // 2DL CA, no fading
    // 2DL CA, fading
    // 3DL CA, no fading
    // 3DL CA, fading
    // 4DL CA, no fading
    // 4DL CA, fading
    // 5DL CA, no fading
    // 5DL CA, fading

    //	id = name;
    //	numCores = cores;
    //	maxCells = cells;
    //	maxLayers = layers;
    //	maxDataRateMbps = datarate; // assumes DAU2 and optimized DAU/SUA interface
    //	stackType = st;
    //	sigUnitType = sut;


    StackCombination Eee("LTE Cell Deployment E", 2, 1, 2, 250, "RealLteStackSua_Deployment_E", "SUA_HALF");
    Eee.print();
    StackCombination Two("LTE Cell Deployment 2", 4, 4, 8, 500, "RealLteStackSua_Deployment_2", "SUA_HALF");
    Two.print();
    StackCombination Y("LTE Cell Deployment Y", 6, 6, 10, 1000, "RealLteStackSua_Deployment_Y", "SUA_FULL");
    Y.print();
    StackCombination Z("LTE Cell Deployment Z", 8, 8, 24, 1600, "RealLteStackSua_Deployment_Z", "SUA_FULL");
    Z.print();

    cout << "Single carrier, no fading --> StackCombination E" << endl;
    cout << "Single carrier, fading    --> StackCombination E" << endl;
    cout << "2DL CA, no fading         --> StackCombination 2 + 2 S" << endl;
    cout << "2DL CA, fading            --> StackCombination 2 + 2 S" << endl;
    cout << "2DL CA ULCA               --> StackCombination 2 + 2 S (no UL 64QAM UL)" << endl;
    cout << "3DL CA, no fading         --> StackCombination 2 + 2 S + E" << endl;
    cout << "3DL CA, fading            --> StackCombination 2 + 2 S + E" << endl;
    cout << "4DL CA, no fading         --> StackCombination 2 + 2 S + E + E" << endl;
    cout << "4DL CA, fading            --> StackCombination 2 + 2 S + E + E" << endl;
    cout << "5DL CA, no fading         --> StackCombination 2 + 2 S + E + E + E" << endl;
    cout << "5DL CA, fading            --> StackCombination 2 + 2 S + E + E + E" << endl;


    return 0;
}


