#citation: https://oregonstate.instructure.com/courses/1719543/pages/lecture-makefiles?module_item_id=18712398

CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGs += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -w

LDFLAGS = 

SOURCES = *.cpp

HEADERS = *.hpp

OBJS = main.o 
DOCUMENTS = *.pdf *.txt

FINAL: ${SOURCES} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${SOURCES} -o FINAL 

${OBJS}: ${SOURCES}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm FINAL 
	rm -R FINAL.dSYM
zip:
	zip finalProject_Chris_Nelson.zip ${SOURCES} ${HEADERS} ${DOCUMENTS} makefile

unzip:
	unzip finalProject_Chris_Nelson.zip 
