#ifndef RIVERGRAPH_H
#define RIVERGRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <cstdlib>

struct City;

struct FlowStation {
    std::string name;
    FlowStation* next;
    std::vector<FlowStation*> prev;
    std::vector<City*> out;
    bool isSource = false;
    int flowScaling = 100;
    int flow = 100;

    FlowStation(){};
    FlowStation(std::string in_name) {
        name = in_name;
    };
};

struct City {
    std::string name;
    FlowStation* source;
    int flow;
    City(){};
    City(std::string in_name, int in_flow) {
        name = in_name;
        flow = in_flow;
    };
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
        void nextYear();
        void connectCity(std::string city, std::string target, int flow);
        void randomStorm();
        void targetedStorm(std::string target, int flowIncrease);
        void seasonalFlowAdjustment(std::string target, int flowAdj);
        int getCityConsumption(std::string city);
        void adjustCityConsumption(std::string city, int newFlow);
    protected:
    private:
        int getSourceFlow();
        int stoi(std::string in);
        void updateFlow(FlowStation* fs);
        FlowStation* findStation(std::string target);

        FlowStation* ocean;
        std::vector<FlowStation*> stations;
        int week;
        int year;
};

#endif // RIVERGRAPH_H
