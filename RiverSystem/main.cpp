#include <iostream>
#include "RiverGraph.h"

using namespace std;

int main(int argc, char** argv) {

    RiverGraph* rivers = new RiverGraph(argv[1]);

    int sel = 0;
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
        cout << "2. Random Storm" << endl;
        cout << "3. Targeted Storm" << endl;
        cout << "4. Print" << endl;
        cout << "5. Print Full" << endl;
        cin >> sel;
        switch(sel) {
        case 1:
            rivers->nextWeek();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            rivers->quickPrint();
            break;
        case 5:
            rivers->print();
            break;
        default:
            cout << "Exiting..." << endl;
            sel = -1;
            break;
        }

    }

    return 0;
}
