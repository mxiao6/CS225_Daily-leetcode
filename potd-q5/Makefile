EXENAME = q5

CXX = clang++
CXXFLAGS = -std=c++0x -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): q5.cpp 
	$(CXX) $(CXXFLAGS) q5.cpp -o $(EXENAME)

.PHONY: clean
clean:
	rm -f $(EXENAME)

.PHONY: upload
upload:
	@python .pl_upload.py || echo "Can't upload; please upload your code using your browser."
