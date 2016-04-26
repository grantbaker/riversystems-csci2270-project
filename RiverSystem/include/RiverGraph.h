#ifndef RIVERGRAPH_H
#define RIVERGRAPH_H

#include <iostream>


class RiverGraph {
    public:
        RiverGraph();
        virtual ~RiverGraph();

        std::string getMonth();
        int getYear();
    protected:
    private:


        int month;
        int year;
};

#endif // RIVERGRAPH_H
