#include <iostream>
#include "RiverGraph.h"

using namespace std;

int main(int argc, char** argv) {

    RiverGraph* rivers = new RiverGraph(argv[1]);

    int sel = 0;
    while (sel != 6) {
        cout << "================================================================" << endl;
        cout << "______ _                  _____           _                     " << endl;
        cout << "| ___ (_)                /  ___|         | |                    " << endl;
        cout << "| |_/ /___   _____ _ __  \\ `--. _   _ ___| |_ ___ _ __ ___  ___ " << endl;
        cout << "|    /| \\ \\ / / _ \\ '__|  `--. \\ | | / __| __/ _ \\ '_ ` _ \\/ __|" << endl;
        cout << "| |\\ \\| |\\ V /  __/ |    /\\__/ / |_| \\__ \\ ||  __/ | | | | \\__ \\" << endl;
        cout << "\\_| \\_|_| \\_/ \\___|_|    \\____/ \\__, |___/\\__\\___|_| |_| |_|___/" << endl;
        cout << "                                 __/ |                          " << endl;
        cout << "                                |___/                           " << endl;
        cout << "Current Month: " << rivers.getMonth() << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;


    }

    return 0;
}
