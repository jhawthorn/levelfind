CXXFLAGS?=-O2

all: levelfind

levelfind:
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o levelfind levelfind.cc

clean:
	rm -f levelfind

.PHONY: all clean
