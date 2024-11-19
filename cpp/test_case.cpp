#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    ofstream outfile("./test_case/test_case.txt");
    const int num_vertices = 10000;
    const int num_edges = 500000;
    const int start_vertex = 1;

    outfile << num_vertices << " " << num_edges << " " << start_vertex << endl;

    srand(time(nullptr));
    for (int i = 0; i < num_edges; i++) {
        int u = rand() % num_vertices + 1;
        int v = rand() % num_vertices + 1;
        outfile << u << " " << v << endl;
    }

    outfile.close();
    return 0;
}