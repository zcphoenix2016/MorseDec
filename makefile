UTLIB = googletest/build/googlemock/libgmock_main.a\
        googletest/build/googlemock/libgmock.a\
        googletest/build/googlemock/gtest/libgtest.a

UTINC = -isystem googletest/googlemock/include\
       -isystem googletest/googletest/include\

UTFLAG = -g -pthread -DUNIT_TEST -Wno-write-strings

all:
	g++ -std=c++14 Sources/*.cpp -o MorseDec.exe -g

ut:
	g++ -std=c++14 ${UTFLAG} ${UTINC} ${UTLIB} Sources/*.cpp TestCases/*.cpp -o ut_MorseDec.exe

clean:
	rm -rf *.o
	rm -rf TestCases/*.o
	rm -rf MorseDec.exe
	rm -rf ut_MorseDec.exe
