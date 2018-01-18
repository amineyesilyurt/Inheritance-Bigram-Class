all: exe

exe:  _mainTester.o Bigram.o BigramMap.o BigramDyn.o BadData.o 
	g++  _mainTester.o Bigram.o BigramMap.o BigramDyn.o BadData.o -std=c++11 -o exe

 _mainTester.o:  _mainTester.cpp
	g++ -std=c++11 -c  _mainTester.cpp

Bigram.o: Bigram.cpp 
	g++ -std=c++11 -c Bigram.cpp 
	
BigramMap.o: BigramMap.cpp 
	g++ -std=c++11 -c BigramMap.cpp  
		
BigramDyn.o: BigramDyn.cpp 
	g++ -std=c++11 -c BigramDyn.cpp  
	
BadData.o: BadData.cpp 
	g++ -std=c++11 -c BadData.cpp  	
	
clean:
	rm *.o exe
