PYTHONINCLUDEPATH=/usr/include/python2.7
PYTHONLIBRARYPATH=/usr/lib/python2.7/config

test.out: test_parser.cpp
	g++ test_parser.cpp `cppunit-config --cflags --libs` -g -I $(PYTHONINCLUDEPATH) -L $(PYTHONLIBRARYPATH) -o test.out

parser.o: parser.cpp
	g++ parser.cpp -I $(PYTHONINCLUDEPATH) -L $(PYTHONLIBRARYPATH) -lpython2.7 -g -c -o parser.o
	
