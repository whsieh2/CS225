EXE = testimage testscene
OBJS = testimage.o png.o rgbapixel.o image.o

COMPILER = g++ 
COMPILER_OPTS = -c -g -O0 -Wall -Werror 
LINKER = g++ 
LINKER_OPTS = -lpng 

all: $(EXE)

$(EXE) : $(OBJS)
	$(LINKER) $(OBJS) $(LINKER_OPTS) -o $(EXE)

testscene: testscene.o scene.o png.o rgbapixel.o image.o
	$(LINKER) testscene.o scene.o png.o rgbapixel.o image.o -lpng -o testscene
testscene.o: testscene.cpp scene.h png.h rgbapixel.h image.h
	$(COMPILER) $(COMPILER_OPTS) testscene.cpp
scene.o: scene.h image.h png.h
	$(COMPILER) $(COMPILER_OPTS) scene.cpp 
	
testimage: testimage.o png.o rgbapixel.o image.o
	$(LINKER) testimage.o png.o rgbapixel.o image.o -lpng -o testimage
testimage.o : testimage.cpp image.h png.h rgbapixel.h
	$(COMPILER) $(COMPILER_OPTS) testimage.cpp 
png.o : png.h 
	$(COMPILER) $(COMPILER_OPTS) png.cpp 
rgbapixel.o : rgbapixel.h png.h
	$(COMPILER) $(COMPILER_OPTS) rgbapixel.cpp 
image.o : image.h png.h
	$(COMPILER) $(COMPILER_OPTS) image.cpp

clean: 
	-rm -f *.o $(EXE);

