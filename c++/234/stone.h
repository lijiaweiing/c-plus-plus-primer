#ifndef STONE_H_INCLUDED
#define STONE_H_INCLUDED
class Stonewe
{
private:
        enum{Lbs_per_stn=14};
        int stone;
        double pds_left;
        double pounds;
public:
        Stonewe(double lbs);
        Stonewe(int stn,double lbs);
        Stonewe();
        ~Stonewe();
        void show_lbs()const;
        void show_stn()const;

};


#endif // STONE_H_INCLUDED
