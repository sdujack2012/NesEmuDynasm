/* 
 * File:   main.cpp
 * Author: 凯
 *
 * Created on 2015年7月31日, 下午11:29
 */



#include "CPU6502OpTranslator.h"
#include <iostream>
#include <fstream>
#include <map>
#include <SFML/Graphics.hpp>

int main(){
	 int length;
	 uint8_t* buffer;
	 uint8_t* memory = new uint8_t[0x10000];
	  for(int i=0;i<0x10000;i++){
		memory[i]=0;
	 }
	 ifstream is;
	 is.open ("super.nes", ios::binary );
	 uint8_t inform[16];
	 is.read ((char*)inform,16);
	 cout<<inform[0]<<endl;
	 cout<<inform[1]<<endl;
	 cout<<inform[2]<<endl;
	 for(int i=3;i<16;i++){
		 cout<<(int)inform[i]<<endl;
	 }
	 
	 buffer = memory + 0x8000;
	 // read data as a block:
	 
	 is.read ((char*)buffer,1024*16*2);
	 cout<<hex<<(int)memory[0xfffc]<<(int)memory[0xfffd]<<endl;
	 cout<<hex<<is.tellg();
	 cin>>length;
	 // get length of file:
	//is.seekg (0, ios::end);
	 //length = is.tellg();
	 //is.seekg (0, ios::beg);
	
	 
	 
	
	 
	
	
	 
	 
	  
	
	 is.close();

	 map<int,functionBlock> tranlatedBlocks;
	
	uint16_t pc=*((uint16_t*)(memory+0xFFFC));
	CPU6502OpTranslator c;
	
	
	while(true){
		
		
			
			
		cout<<"***********************************"<<endl;
		
		cout<<"PC: "<<"0x"<<hex<<pc<<":"<<(int)memory[pc]<<endl;
		
		cout<<"A: "<<"0x"<<hex<<(int)c.A_backup<<endl;
		cout<<"X: "<<"0x"<<hex<<(int)c.X_backup<<endl;
		cout<<"Y: "<<"0x"<<hex<<(int)c.Y_backup<<endl;
		cout<<"S: "<<"0x"<<hex<<(int)c.S_backup<<endl;
		cout<<"***********************************"<<endl;
		c.setUp();
		if(tranlatedBlocks[pc]==0){
			tranlatedBlocks[pc] = (functionBlock)c.translate(pc,memory);
		}
		c.clear();
		pc=tranlatedBlocks[pc]();
	}
	
	return 0;
}

/*
sf::Texture* compileCHR(uint8_t* partern){
	
	sf::Texture *CHR = new sf::Texture[512];
	for(int i=0;i<512;i++){
		CHR[i].create(8, 8);
		sf::Uint8* pixels = new sf::Uint8[8 * 8 * 4];
		for(int j=0;j<8;j++){
				for(int k=0;k<8;k++){
					uint8_t l = 1;
					l = (partern[i*16+j]>>(7-k))&l;
					pixels[j*8*4+k*4] = l*100;
					pixels[j*8*4+k*4+1] = l*100;
					pixels[j*8*4+k*4+2] = l*100;
					pixels[j*8*4+k*4+3] = 255;
				}	
		}
		CHR[i].update(pixels);
	}
	
	return CHR;
}
int main()
{
	
	sf::Transform t;
	 uint8_t* buffer;
	 uint8_t* memory = new uint8_t[0x10000];
	 uint8_t* partern = new uint8_t[8*1024];
	  for(int i=0;i<0x10000;i++){
		memory[i]=0;
	 }
	 ifstream is;
	 is.open ("super.nes", ios::binary );
	 uint8_t inform[16];
	 is.read ((char*)inform,16);
	
	 buffer = memory + 0x8000;
	 // read data as a block:
	 
	 is.read ((char*)buffer,1024*16);
	  
	 is.read ((char*)partern,1024*8);
	  
	 is.close();
	
	sf::Texture* CHR = compileCHR(partern);
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
		for(int i=0;i<512;i++){
			
			sf::RectangleShape rectangle(sf::Vector2f(8,8));
			rectangle.setTexture(&CHR[i]);
			
			rectangle.setPosition(i%16*8, i/16*8);
			
			window.draw(rectangle);
		}
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}
*/


