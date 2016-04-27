#include <iostream>
#include <cstdio>
#include "RiverGraph.h"

using namespace std;

int main(int argc, char** argv) {

    if (argc < 2) {
        cout<<"Please specify a file."<<endl;
        return 0;
    }

    RiverGraph* rivers = new RiverGraph(argv[1]);

    int sel = 0;
    string target, city;
    int flow;
    while (sel != -1) {
        cout << "================================================================" << endl;
        cout << "______ _                  _____           _                     " << endl;
        cout << "| ___ (_)                /  ___|         | |                    " << endl;
        cout << "| |_/ /___   _____ _ __  \\ `--. _   _ ___| |_ ___ _ __ ___  ___ " << endl;
        cout << "|    /| \\ \\ / / _ \\ '__|  `--. \\ | | / __| __/ _ \\ '_ ` _ \\/ __|" << endl;
        cout << "| |\\ \\| |\\ V /  __/ |    /\\__/ / |_| \\__ \\ ||  __/ | | | | \\__ \\" << endl;
        cout << "\\_| \\_|_| \\_/ \\___|_|    \\____/ \\__, |___/\\__\\___|_| |_| |_|___/" << endl;
        cout << "                                 __/ |                          " << endl;
        cout << "                                |___/                           " << endl;
        cout << "Year " << rivers->getYear() << ", Week " << rivers->getWeek() << endl;
        cout << "================================================================" << endl;
        /*rivers->quickPrint();
        cout << "================================================================" << endl;*/
        cout << "Select an option:" << endl;
        cout << "1. Next Week" << endl;
        cout << "2. Next Year" << endl;
        cout << "3. Random Storm" << endl;
        cout << "4. Targeted Storm" << endl;
        cout << "5. Print" << endl;
        cout << "6. Print Full" << endl;
        cout << "7. Adjust Seasonal Scaling" << endl;
        cout << "8. Connect City" << endl;
        cout << "9. Adjust City Consumption" << endl;
        cout << "0. Exit" << endl;
        cin >> sel;
        switch(sel) {
        case 1:
            rivers->nextWeek();
            break;
        case 2:
            rivers->nextYear();
            break;
        case 3:
            rivers->randomStorm();
            break;
        case 4:
            cout<<"Flow Station: ";
            cin>>target;
            cout<<"Flow Increase: ";
            cin>>flow;
            rivers->targetedStorm(target, flow);
            break;
        case 5:
            rivers->quickPrint();
            getchar();
            getchar();
            break;
        case 6:
            rivers->print();
            getchar();
            getchar();
            break;
        case 7:
            cout<<"Flow Station: ";
            cin>>target;
            cout<<"Seasonal Flow Adjustment (%): ";
            cin>>flow;
            rivers->seasonalFlowAdjustment(target, flow);
            break;
        case 8:
            cout<<"City Name: ";
            cin>>city;
            cout<<"Flow Station: ";
            cin>>target;
            cout<<"Flow Consumption: ";
            cin>>flow;
            rivers->connectCity(city, target, flow);
            break;
        case 9:
            cout<<"City Name: ";
            cin>>city;
            cout<<"Current Consumption: "<<rivers->getCityConsumption(city)<<endl;
            cout<<"New Consumption: ";
            cin>>flow;
            rivers->adjustCityConsumption(city, flow);
            break;
        default:
            cout << "Exiting..." << endl;
            sel = -1;
            break;
        }

    }

    return 0;
}
