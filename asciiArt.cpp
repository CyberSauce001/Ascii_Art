#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

char tux[] = "icecube.ppm";
char color[256];


class Image {
    private:
        int w,h;
        unsigned char *arr;
    public:
        Image() { arr = NULL; }
        ~Image() { if (arr != NULL) delete [] arr; }
        void load(ifstream &fin)
        {
            char line[50];//100
            fin.getline(line, 50);
            fin.getline(line, 50);
            fin.getline(line, 50);
            w = atoi(line);
            char *p = strstr(line, " ");
            h = atoi(p+1);
            cout << w << " " << h << endl;
            arr = new unsigned char[w*h];
            fin.getline(line, 50);
            char rgb[3][5];//10
            for (int i=0; i<(w*h); i++) {
                for (int j=0; j<3; j++)
                    fin.getline(rgb[j], 5);//10
                int avg;
                avg = atoi(rgb[0]);
                avg += atoi(rgb[1]);
                avg += atoi(rgb[2]);
                avg = avg/3;//3
                arr[i] = avg;
            }
        }
        void display() 
        {
            for (int i=0; i<h; i++) {
                for (int j=0; j<w; j++) {
                    //cout << ".";
                    int pix = arr[(i*w)+j];
                    char c = 32 + pix/3; //33-35 is good //divide by 4
                   //cout << c;
                   cout << c;
                }
                cout << endl;
            }   

        }
};

int main()
{
    ifstream fin(tux);
    if (fin.fail()) {
        cout << "\n\nERROR: cannot open **" << tux << "**\n\n" << endl;
        return 0;
    }
    Image img;
    img.load(fin);
    fin.close();
    img.display();



    return 0;
}
