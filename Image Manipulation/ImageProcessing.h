#ifndef IMAGE_PROCESSING
#define IMAGE_PROCESSING
#include <memory>
#include <stdio.h>	
namespace HDSROW001
{
	class Image
	{
	private:
		int width,height,array_size;
		std::unique_ptr<unsigned char[]> data; // pointer opject that contains a raw pointer to an opject (image data)
		unsigned char *memblock;
		unsigned char *memblock2;
		std::string output;
		std::string operation;
	public:

		void load(std::string filename,unsigned char* mem);
		void save(std::string filename);
		void mask(Image& img);
		Image(std::string filename);
		void copy(Image& img);
	
		
		void operator+ (Image& img); //overide 
		void operator- (Image& img);
		void operator! (void);
		void operator/ (Image& img);
		void operator* (int f);
		bool operator== (Image& img);

			
		
		class Iterator
		{
			private:
				int pos;
				unsigned char *poitner;
				friend class Image;
				Iterator(unsigned char *p) : poitner(p) {
					pos = 0;
				}


     		public:
        
       			Iterator(const Iterator & rhs) : poitner(rhs.poitner){}
       			
      

       			Iterator operator++ (void)
       			{
       				poitner++;
       				return *this;
       			}
       			Iterator operator-- (void)
       			{
       				poitner--;
       				return *this;
       			}
       			unsigned char & operator* (void)
       			{
       				return *poitner;
       			}
       			bool operator==(Iterator& itr)
       			{
       				if(poitner == itr.poitner)
       				{
       					return true;
       				}
       				else
       					return false;
       			}
       
        
        }; 
   
        Iterator begin()
    	{
    		 return Iterator(data.get());
    	}
        Iterator end()
        {
        	return Iterator(&(data.get()[array_size+1]));
        }

        void add(Image& i2);
        void subtract(Image& i2);
        void invert();
        void thresh(int f);
        bool sameSize(Image& other);


 };

}
#endif