EXENAME = q38

OBJS = main.o func.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	    $(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: main.cpp func.h
	    $(CXX) $(CXXFLAGS) main.cpp

func.o: func.cpp func.h
	    $(CXX) $(CXXFLAGS) func.cpp

clean:
	rm *.o

.PHONY: upload
upload:
	@python .pl_upload.py || echo "Can't upload; if it is still before the deadline, run 'make noupload' (ONCE ONLY) and follow the instructions to turn in your submission."

.PHONY: noupload
noupload:
	tar czf noupload.tar.gz Makefile .pl_upload.cfg *.cpp
	@echo Email the file "'noupload.tar.gz'" to mattox@illinois.edu to turn in your assignment.
	@echo Please do NOT email to resubmit your problem.  This question is graded on the basis of partipation.
	@echo If you have submitted it already, assuming it is really code, you already have credit.
