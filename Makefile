CXX=g++
CXXFLAGS= -Wextra -g 

BINS= sparse_test sparse_generator sparse_converter

COMMON_SOURCES= mystring.cpp\
			    rational_number.cpp\
				vector.cpp\
				matrix.cpp\
				my_exeptions.cpp\
				matrix_coord.cpp

COMMON_OBJS= $(patsubst %.cpp, %.o, $(COMMON_SOURCES))


all: $(BINS)

matrix_coord.cpp: matrix_coord_row_column.h
my_exeptions.cpp: matrix_ex.h vector_ex.h rational_number_ex.h


sparse_test: main_test.o $(COMMON_OBJS) 
	$(CXX) -o $@ $(CXXFLAGS) $^

sparse_generator: main_generator.o $(COMMON_OBJS) 
	$(CXX) -o $@ $(CXXFLAGS) $^

sparse_converter: main_converter.o $(COMMON_OBJS) 
	$(CXX) -o $@ $(CXXFLAGS) $^

%.o: %.cpp %.h
	$(CXX) -c $(CXXFLAGS) $<


clean:
	rm -f $(COMMON_OBJS) $(BINS) main_test.o main_generator.o main_converter.o
