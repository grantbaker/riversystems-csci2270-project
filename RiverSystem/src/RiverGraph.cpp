#include "RiverGraph.h"

RiverGraph::RiverGraph(char * filein) {
    RiverGraph::year = 0;
    RiverGraph::week = 1;

    std::ifstream in;
    std::string line;
    std::string word;
    std::string name;
    int i,j,dist;
    bool source;

    in.open(filein);

    if (in.good()) {
        std::getline(in,line);
        std::stringstream ss(line);
        std::getline(ss,word,',');
        while (std::getline(ss,word,',')) {
            RiverGraph::stations.push_back(new FlowStation(word));
        }

        i = 0;
        while (std::getline(in,line)) {
            std::stringstream ss(line);
            std::getline(ss,name,',');
            j = 0;
            source = true;
            while (std::getline(ss,word,',')) {
                dist = RiverGraph::stoi(word);
                if (dist > 0) {
                    RiverGraph::stations[i]->next = RiverGraph::stations[j];
                }
                if (dist < 0) {
                    RiverGraph::stations[i]->prev.push_back(RiverGraph::stations[j]);
                    source = false;
                }
                RiverGraph::stations[i]->isSource = source;
                j++;
            }
            i++;
        }
        RiverGraph::ocean = RiverGraph::stations[0];
        RiverGraph::updateFlow(RiverGraph::ocean);

        for (i=0; i<52; i++) {
            RiverGraph::nextWeek();
        }

    }
}

RiverGraph::~RiverGraph() {

}

int RiverGraph::stoi(std::string s) {
    std::stringstream ss(s);
    int i;
    ss>>i;
    return i;
}


int RiverGraph::getYear() {
    return RiverGraph::year;
}

int RiverGraph::getWeek() {
    return RiverGraph::week;
}

int RiverGraph::getSourceFlow() {
    return std::floor(2500-1500*std::cos((RiverGraph::week+6)*(8*std::atan(1))/52)+200*std::cos((RiverGraph::week+6)*(16*std::atan(1))/52));
}

void RiverGraph::print() {
    int i,j;
    FlowStation* tmp;
    for (i=0; i<RiverGraph::stations.size(); i++) {
        tmp = RiverGraph::stations[i];
        std::cout<<tmp->name<<":"<<std::endl;
        if (tmp->next)
            std::cout<<"- Flows into: "<<tmp->next->name<<std::endl;
        if (!tmp->isSource) {
            std::cout<<"- Sources:";
            for (j=0; j<tmp->prev.size(); j++) {
                std::cout<<" "<<tmp->prev[j]->name;
            }
            std::cout<<std::endl;
        }
    }
}

void RiverGraph::quickPrint() {
    int i,j;
    FlowStation* tmp;
    for (i=0; i<RiverGraph::stations.size(); i++) {
        tmp = RiverGraph::stations[i];
        std::cout<<tmp->name<<": "<<tmp->flow<<std::endl;

    }
}

void RiverGraph::nextWeek() {
    RiverGraph::updateFlow(RiverGraph::ocean);

    RiverGraph::week++;
    if (RiverGraph::week > 52) {
        RiverGraph::week = 1;
        RiverGraph::year++;
    }
}

void RiverGraph::updateFlow(FlowStation* fs) {
    int i;
    if (!fs->isSource) {
        fs->flow = 0;
        for (i=0; i<fs->prev.size(); i++) {
            fs->flow += fs->prev[i]->flow;
            RiverGraph::updateFlow(fs->prev[i]);
        }
    } else {
        fs->flow = RiverGraph::getSourceFlow();
    }
}
