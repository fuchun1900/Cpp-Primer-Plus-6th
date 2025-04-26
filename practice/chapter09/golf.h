const int LEN = 40;
struct golf
{
    char fullname[LEN];
    int handicap;
};

void setgolf(golf & g, const char * name, int hc);

int setgolf(golf & g);
void showgolf(const golf & g);
void handicap(golf & g, int hc);
