#define CATCH_CONFIG_MAIN
//#include "../catch2.hpp"
#include "solution.h"

#include <iostream>
using std::cout;
using std::endl;

using std::string;


int main(){
    Solution s;
	string ret = s.addBinary("11", "1");
	string sol = "100";
    cout<<"final: "<<ret<<endl;
    cout<<(!sol.compare(ret))<<endl;

	ret = s.addBinary("1010", "1011");
	sol = "10101";
    cout<<"final: "<<ret<<endl;
    cout<<(!sol.compare(ret))<<endl;

    ret = s.addBinary("0", "0");
    sol = "0";
    cout<<"final: "<<ret<<endl;
    cout<<(!sol.compare(ret))<<endl;

}
