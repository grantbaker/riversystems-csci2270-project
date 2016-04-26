#include "RiverGraph.h"

RiverGraph::RiverGraph(char * filein) {
    RiverGraph::year = 1;
    RiverGraph::month = 1;
}

RiverGraph::~RiverGraph() {

}

int RiverGraph::getYear() {
    return RiverGraph::year;
}

std::string RiverGraph::getMonth() {
    char* months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    return months[RiverGraph::month-1];
}

int RiverGraph::getDefaultFlow() {
    int* flowrates = {300,400,600,900,900,1000,1000,800,600,500,400,300};
    return flowrates[RiverGraph::month-1];
}
