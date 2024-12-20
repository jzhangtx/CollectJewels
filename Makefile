CollectJewels: CollectJewels.o
	g++ -g -o CollectJewels.exe CollectJewels.o -pthread    

CollectJewels.o: CollectJewels/CollectJewels.cpp
	g++ -g  -c -pthread CollectJewels/CollectJewels.cpp
