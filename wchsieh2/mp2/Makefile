EXE = testimage
OBJS = testimage.o png.o rgbapixel.o image.o

COMPILER = g++ 
COMPILER_OPTS = -c -g -O0 -Wall -Werror 
LINKER = g++ 
LINKER_OPTS = -lpng 

all: $(EXE)

$(EXE) : $(OBJS)
	$(LINKER) $(OBJS) $(LINKER_OPTS) -o $(EXE)
 
testimage.o : testimage.cpp image.h
	$(COMPILER) $(COMPILER_OPTS) testimage.cpp 
png.o : png.cpp png.h 
	$(COMPILER) $(COMPILER_OPTS) png.cpp 
rgbapixel.o : rgbapixel.cpp rgbapixel.h 
	$(COMPILER) $(COMPILER_OPTS) rgbapixel.cpp 
image.o : image.cpp image.h 
	$(COMPILER) $(COMPILER_OPTS) image.cpp

clean: 
	-rm -f *.o $(EXE)

