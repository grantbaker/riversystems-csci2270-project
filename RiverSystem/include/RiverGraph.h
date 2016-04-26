#ifndef RIVERGRAPH_H
#define RIVERGRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>

struct City;

struct FlowStation {
    std::string name;
    FlowStation* next;
    std::vector<FlowStation*> prev;
    std::vector<City*> out;
    bool isSource = false;
    double flowScaling;
    int flow = 100;

    FlowStation(){};
    FlowStation(std::string in_name) {
        name = in_name;
    };
};

struct City {
    FlowStation* source;
    int flow;
};

class RiverGraph {
    public:
        RiverGraph(char * filein);
        virtual ~RiverGraph();

        int getWeek();
        int getYear();
        void quickPrint();
        void print();
        void nextWeek();
    protected:
    private:
        int getSourceFlow();
        int stoi(std::string in);
        void updateFlow(FlowStation* fs);

        FlowStation* ocean;
        std::vector<FlowStation*> stations;
        int week;
        int year;
};

#endif // RIVERGRAPH_H
