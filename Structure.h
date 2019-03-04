struct Fvertex
{//define data structure and declare global variable for modules' nodes
    double    time;
    double    cost;
    double    storage;
    double    complexity;
    bool    used;
}V[MODNUM_MAX];

struct Fedge
{//define data structure and declare global variable for modules' edges
    int        from;
    int        to;
    double    time;
    double    cost;
    double    size;
    double    BW;
    double    price;
    bool    used;
}E[MODLINK_MAX];

struct VTY
{//define data structure and declare global variable for VM type
    double                CPU;
    double                IO;
    double                storage;
    double                price;
    double                StartUpTime;
    map<int, list<int>>    Group;
}VT[VMTYPE_MAX];

struct PMC
{//define data structure and declare global variable for PM
    double CPU;
    double IO;
    double trans;
    double storage;
}PM[CLOUDNUM][PMNUM];

struct BWT
{//define data structure and declare global variable for BW type
    double value;
    double price;
}BW[CLOUDNUM][BWTYPE];

struct SMPC
{//define data structure and declare global variable for which cloud and which PM each module assigned to
    int cloud;
    int pm;
}MPC[MODNUM_MAX];
