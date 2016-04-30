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

        RiverGraph::nextYear();

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
    int flowOut;
    FlowStation* tmp;
    for (i=0; (unsigned)i<RiverGraph::stations.size(); i++) {
        tmp = RiverGraph::stations[i];
        std::cout<<tmp->name<<":"<<std::endl;
        if (tmp->next)
            std::cout<<"- Flows into: "<<tmp->next->name<<std::endl;
        if (!tmp->isSource) {
            std::cout<<"- Sources:";
            for (j=0; (unsigned)j<tmp->prev.size(); j++) {
                std::cout<<" "<<tmp->prev[j]->name;
            }
            std::cout<<std::endl;
        } else {
            std::cout<<"- Scaling: "<<tmp->flowScaling<<std::endl;
        }
        flowOut=tmp->flow;
        if (tmp->out.size()!=0) {
            std::cout<<"- Connected Cities:";
            for (j=0; (unsigned)j<tmp->out.size(); j++) {
                std::cout<<" "<<tmp->out[j]->name<<" ("<<tmp->out[j]->flow<<")";\
                flowOut-=tmp->out[j]->flow;
            }
            std::cout<<std::endl;
        }
        if (!tmp->isSource) {
            std::cout<<"- Flow in: "<<tmp->flow<<std::endl;
        }
        if (tmp!=RiverGraph::ocean) {
            std::cout<<"- Flow out: "<<flowOut<<std::endl;
        }

    }
}

void RiverGraph::quickPrint() {
    int i;
    FlowStation* tmp;
    for (i=0; (unsigned)i<RiverGraph::stations.size(); i++) {
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

void RiverGraph::nextYear() {
    int i;
    for (i=0; i<52; i++) {
        RiverGraph::nextWeek();
    }
}

void RiverGraph::updateFlow(FlowStation* fs) {
    int i,j,sub;
    if (!fs->isSource) {
        fs->flow = 0;
        for (i=0; (unsigned)i<fs->prev.size(); i++) {
                sub = 0;
            for (j=0; (unsigned)j<fs->prev[i]->out.size(); j++) {
                sub += fs->prev[i]->out[j]->flow;
            }
            fs->flow += fs->prev[i]->flow;
            fs->flow -= sub;
            if (fs->flow < 0) {
                fs->flow = 0;
            }
            RiverGraph::updateFlow(fs->prev[i]);
        }
    } else {
        fs->flow = std::floor((fs->flowScaling/100)*RiverGraph::getSourceFlow());
    }
}

void RiverGraph::randomStorm() {
    int i;
    for (i=0; (unsigned)i<RiverGraph::stations.size(); i++) {
        if ((double) std::rand()/(RAND_MAX) > 0.75) {
            RiverGraph::stations[i]->flow += std::floor((double) 100+ (rand() %(8*RiverGraph::getSourceFlow())));
        }
    }

}

void RiverGraph::targetedStorm(std::string target, int flowIncrease) {
    FlowStation* fs = RiverGraph::findStation(target);
    if (fs) {
        fs->flow += flowIncrease;
    } else {
        std::cout<<"Error: Invalid target."<<std::endl;
    }
}

void RiverGraph::connectCity(std::string cityName, std::string target, int flow) {
    City* newcity = new City(cityName, flow);
    FlowStation* fs = RiverGraph::findStation(target);
    if (fs) {
        fs->out.push_back(newcity);
    } else {
        std::cout<<"Error: Invalid target."<<std::endl;
    }
}

FlowStation* RiverGraph::findStation(std::string target) {
    int i;
    for (i=0; (unsigned)i<RiverGraph::stations.size(); i++) {
        if (target.compare(RiverGraph::stations[i]->name) == 0) {
            return RiverGraph::stations[i];
        }
    }
    return NULL;
}

void RiverGraph::seasonalFlowAdjustment(std::string target, int flowAdj) {
    FlowStation* fs = RiverGraph::findStation(target);
    if (fs->isSource) {
        fs->flowScaling = flowAdj;
    } else {
        std::cout<<"Error: Not a source station."<<std::endl;
    }
}

int RiverGraph::getCityConsumption(std::string city) {
    int i,j;
    for (i=0; (unsigned)i<RiverGraph::stations.size(); i++) {
        for (j=0; (unsigned)j<RiverGraph::stations[i]->out.size(); j++) {
            if (city.compare(RiverGraph::stations[i]->out[j]->name) == 0) {
                return RiverGraph::stations[i]->out[j]->flow;
            }
        }
    }
    return -1;
}

void RiverGraph::adjustCityConsumption(std::string city, int newFlow) {
    int i,j;
    for (i=0; (unsigned)i<RiverGraph::stations.size(); i++) {
        for (j=0; (unsigned)j<RiverGraph::stations[i]->out.size(); j++) {
            if (city.compare(RiverGraph::stations[i]->out[j]->name) == 0) {
                RiverGraph::stations[i]->out[j]->flow = newFlow;
                return;
            }
        }
    }
    std::cout<<"Error: Invalid target."<<std::endl;
}
