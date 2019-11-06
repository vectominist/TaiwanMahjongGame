#ifndef MJPLAYER 
#define MJPLAYER 
#include <iostream>
#include <vector>
#include "MJhand.h"
using namespace std;
class MJplayer:public MJhand{
	friend class MJstage;
public:
	MJplayer();
	MJplayer(int , int/*, MJtile*, int*/);
	~MJplayer();
	int Get_Pos() const;
	int Get_Mon() const;
	void Print_Hand();
	void Set_Pos(int);
	//void Reset_Hand(MJtile*, int);
	virtual void strategy(int position, MJtile t, int &actiontype, int &actionparameter);
	virtual void getinfo(int position, vector<MJtile> ts, int tiles_num);
	//type: nothing=0 eat=1 pong=2 minggone=3 angone=4 bugone=5 applique=6 hu=7 8=play

	/*
	int P_total_len() const;
	int P_faceup_len() const;
	void P_set_faceup_len(int f);
	bool P_stage() const;
	void P_set_stage(bool s);
	void P_set_last(const MJtile&); // debug code
	MJtile P_get_last()const;
	MJtile P_get_tile(int)const;
	int P_get_tile_suit(int)const;
    int P_get_tile_rank(int)const;
    int P_get_tile_suit_z(int)const; // count from 0
    int P_get_tile_rank_z(int)const; // count from 0
	
	int P_caneat(const MJtile&);
	bool P_canpong(const MJtile&);
	bool P_canminggone(const MJtile&);
	bool P_canangone(const MJtile&);
	bool P_canbugone(const MJtile&);
	bool P_canhu(const MJtile&);
	
	void P_arrange();
	void P_draw(MJcollection&);
	MJtile P_play(int);
	void P_faceup(int);
	void P_applique(int, MJcollection&);
	void P_initial(MJcollection&);
	
	void P_eat(const MJtile&, int);
	void P_pong(const MJtile&);
	void P_minggone(const MJtile&, MJcollection&);
	void P_angone(int, MJcollection&);
	void P_bugone(int, MJcollection&);
	void P_huother(const MJtile&);
	void P_huown();

	void P_showhandtoothers();
	*/

protected:
	//MJhand _hand;
	void set_hand(MJtile*);
	int _position;//east = 1 ,south = 2 , west = 3 , north = 4 
	// -> 0 , 1 , 2 , 3 (because it's easier to use for comparing (..%4))
	int _money;

};
#endif
