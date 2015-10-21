#include "ImageProcessing.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <memory>
#include <sstream>


namespace HDSROW001
{
     Image::Image(std::string fielmane)
    {
        
    	load(fielmane, memblock);
    }

    //  Image::Image(std::string fielmane,std::string fielmane2,std::string operation1, std::string output1)
    // {
    // 	operation = operation1;
    // 	output = output1;
    // 	load(fielmane,memblock);
    // 	load(fielmane2,memblock2);
    // }

	void Image::load(std::string fielmane,unsigned char* mem)
	{
		 std::string width1;
    	 std::string height1;
		 std::string ignored;
		 std::string intensity;
		 std::ifstream dat_fiel(fielmane, std::ios::in|std::ios::binary); // open the binary file
		 std::getline(dat_fiel,ignored);
         dat_fiel >> std::ws;
          std::cout<<"line: "<<ignored<<std::endl;
		  std::getline(dat_fiel,ignored);
		  dat_fiel >> std::ws;
		std::cout<<ignored<<std::endl;
		 while(ignored[0] == '#')
		 {
		 	 std::getline(dat_fiel,ignored);
		 	 std::cout<<ignored<<std::endl;
		 	 dat_fiel >> std::ws;
		 }
		// std::getline(dat_fiel,ignored);
		// dat_fiel >> std::ws;
		std::istringstream ss(ignored);
		ss >> width1 >> std::ws;
		ss >> height1 >> std::ws;
		width = atoi(width1.c_str());
				std::cout <<"width "<< width1 <<std::endl;
		height = atoi(height1.c_str());
				std::cout <<"height "<< height1 <<std::endl;
		array_size = width*height;
		std::cout <<"Array size "<< array_size <<std::endl;
    	std::getline(dat_fiel,intensity);
    	mem = new unsigned char[array_size];
    	dat_fiel.read((char *)mem, array_size);
        dat_fiel.close();
        data.reset((unsigned char*)mem);
	}

	void Image::copy(Image& img)
	{
		   Image::Iterator    beg = this->begin(), end = this->end();
   			Image::Iterator    inStart = img.begin(), inEnd  = img.end();
   			while (*beg  !=  '\0') { *beg = *inStart;   ++beg; ++inStart; } 

	}


		bool Image::operator== (Image& other){
	if(!sameSize(other))
	{
		return false;
    }
    
     Image::Iterator beg = this->begin();
	 Image::Iterator beg2 = other.begin();
	 while(*beg != '\0')
	 {
		 if(*beg != *beg2)
		 {
			 return false;
		 }
	 }
	 
	 return true;    
}
	bool Image::sameSize(Image& other)
	{
		if(height == other.height)
		{
			if(width == other.width)
			{			
			return true;}
			else{return false;}
		}
		else
		{
			return false;
		}
	}


	void Image::save(std::string filename)
	{
		std::ofstream output1(filename);
		output1 <<"P5\n";
		output1 <<width<<" "<<height<<"\n";
		output1 <<"255\n";
		output1.close();
		 std::ofstream output(filename, std::ios::out|std::ios::binary|std::ios::app);
		 output.write((char *)data.get(),array_size);
		 
		 output.close();
	}

	void Image::operator+ (Image& img)
	{
		Image::Iterator beg = this->begin(), end = this->end();
		Image::Iterator beg2 = img.begin(), end2 = img.end();
		while(!(beg == end)) // checks if the iterator is at the end of the list
		{
			if(*beg + *beg2 > 255)
			{
				*beg = (unsigned char)(255);
			}
			else{
 					*beg = (unsigned char)(*beg + *beg2);
 		        }
 			++beg;
 			++beg2;
 			
 			
		}
	}

	void Image::operator- (Image& img)
	{
		Image::Iterator beg = this->begin(), end = this->end();
		Image::Iterator beg2 = img.begin(), end2 = img.end();
		while(!(beg == end))
		{
			if(*beg - *beg2 < 0)
			{
				*beg = (unsigned char)(1);
			}
			else{
 			*beg = (unsigned char)(*beg - *beg2);}
 			++beg;
 			++beg2;
 			
		}
	}

	void Image::operator! (void)
	{
		Image::Iterator beg = this->begin(), end = this->end();
		
		while(!(beg == end))
		{
			*beg = (unsigned char)(255 - *beg);
			
			++beg;
			
		
		}
	}

	void Image::operator/ (Image& img)
	{

	Image::Iterator beg = this->begin(), end = this->end();
		Image::Iterator beg2 = img.begin(), end2 = img.end();
		while(!(beg == end))
		{
			if(*beg2 == (unsigned char)(255))
			{
				
			}
			else
			{
				*beg = 1;

			}
			++beg;
			++beg2;
			
			
		}
	}

	void Image::operator* (int f)
	{
		Image::Iterator beg = this->begin(),end = this->end();
		while(!(beg == end))
		{
			if(((int)(*beg))>f)
			{
				*beg = (unsigned char)(255);
			}
			else
			{
				*beg = (unsigned char)(1);
			}
			++beg;
			
	}
}

 	void Image::add(Image& i2)
 	{

 		*this+i2;
 	}

 	void Image::subtract(Image& i2)
 	{
 		*this-i2;
 	}

 	void Image::invert()
 	{
 		!(*this);
 	}

 	void Image::mask(Image& i2)
 	{
 		*this/i2;
 	}

 	void Image::thresh(int f)
 	{
 		(*this)*f;
 	}
}