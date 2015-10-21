#include "ImageProcessing.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <memory>
#include <sstream>


using namespace HDSROW001;
using namespace std;

int main(int argc, char* argv[])
{
	if(argc == 4)
	{
       string image = argv[2];
       string operation = argv[1];
       string output = argv[3];
       Image I(image);
       if(operation.compare("-i") == 0){
       //	std::cout << "here" << std::endl;
       I.invert();
   }

       I.save(output);

	}
	if(argc == 5)
	{
		string operation = argv[1];
		if(operation.compare("-t") == 0)
		{
			string image = argv[3];
			int f = stoi(argv[2]);
			std::cout<<f<<std::endl;
			string output = argv[4];
			Image I(image);
			I.thresh(f);
			I.save(output);
		}
		else{
			string image = argv[2];
			cout<<"4"<<endl;
			string image2 = argv[3];
			
			string output = argv [4];
			Image I(image);
			Image I2(image2);
			if(I.sameSize(I2)){ // first checks to see if images are same size
			if(operation.compare("-l")==0)
			{
				I.mask(I2);
			}
			if(operation.compare("-a") == 0)
			{
				I.add(I2);
			}
			if(operation.compare("-s")==0)
			{
				I.subtract(I2);	
			}
			
		I.save(output);
		}
		else
		{
			cout<<"Images not compatable"<<std::endl;
		}
	}
	}
}