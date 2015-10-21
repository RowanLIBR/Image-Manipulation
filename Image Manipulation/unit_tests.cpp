
#include "ImageProcessing.h"
#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
TEST_CASE("lets see if two images are seen as equal" ) {
	HDSROW001::Image img1;
	img1.load("Lenna_standard.pgm");
	HDSROW001::Image img2;
	img2.load("Lenna_standard.pgm");
	
    REQUIRE( img1==img2 );    
}

TEST_CASE( "Operations","[img]" ) 
{
	
	HDSROW001::Image img;
	img.load("Lenna_standard.pgm");
	
	HDSROW001::Image mask;
	mask.load("Lenna_hat_mask.pgm");	
		
	SECTION("invert")
	{
		HDSROW001::Image inverted;
		inverted.load("Lenna_invert.pgm");	
		REQUIRE((!img)==inverted);    
	}
	
	SECTION("add")
	{
		HDSROW001::Img add;
		add.load("Lenna_add.pgm");					
		REQUIRE((img+mask)==add);
	}
	
	SECTION("subtract")
	{
		HDSROW001::Image subtract;
		subtract.load("./data/Lenna_subtract.pgm");
		REQUIRE((img-mask)==subtract);
	}
	
	SECTION("thresh"){
		
		HDSROW001::Image threshold;
		threshold.load("./data/Lenna_threshold.pgm");
		REQUIRE((img*100)==threshold);
	}
	
	SECTION("mask")
	{
		HDSROW001::Image masky;
		white.load("mask_test.pgm");						
		REQUIRE((white/masksy)==masky);
	}
}




