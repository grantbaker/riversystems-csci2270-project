#ifndef RIVERGRAPH_H
#define RIVERGRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>


class RiverGraph {
    public:
        RiverGraph(char * filein);
        virtual ~RiverGraph();

        std::string getMonth();
        int getYear();
    protected:
    private:
        int getDefaultFlow();

        int month;
        int year;
};

#endif // RIVERGRAPH_H
