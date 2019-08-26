#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, string> combinacion;

int brown[3];
int green[3];
int clear[3];
map<int, string> combinaciones;
bool leerDatos(){
    if(scanf("%u %u %u %u %u %u %u %u %u ",
            &brown[0],&green[0],&clear[0],
             &brown[1],&green[1],&clear[1],
             &brown[2],&green[2],&clear[2])==9)
        return true;
    return false;
}


void minMovimientos(){
    combinaciones.insert(combinacion(brown[1]+brown[2]+ green[0] + green[1] + clear[0] + clear[2],"BCG"));
    combinaciones.insert(combinacion(brown[1]+brown[2]+ green[0] + green[2] + clear[0] + clear[1],"BGC"));
    combinaciones.insert(combinacion(brown[0]+brown[2]+ green[0] + green[1] + clear[1] + clear[2],"CBG"));
    combinaciones.insert(combinacion(brown[0]+brown[1]+ green[0] + green[2] + clear[1] + clear[2],"CGB"));
    combinaciones.insert(combinacion(brown[0]+brown[2]+ green[1] + green[2] + clear[0] + clear[1],"GBC"));
    combinaciones.insert(combinacion(brown[0]+brown[1]+ green[1] + green[2] + clear[0] + clear[2],"GCB"));

    auto it = combinaciones.begin();
    cout<<it->second<<" "<<it->first<<endl;
    combinaciones.clear();
}

int main() {

    while(leerDatos()){
        minMovimientos();
    }

}
