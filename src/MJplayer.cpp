#include <iostream>
#include "MJhand.h"
#include "MJplayer.h"
using namespace std;

MJplayer::MJplayer(){
	// empty
}
MJplayer::MJplayer(int _init_pos, int _init_money/*, 
	MJtile* _init_tiles, int _init_tiles_len*/){
	_total_len=_faceup_len=_stage=0;
    for (int i=0; i<30; i++) {
        _tiles[i]=MJtile();
        noreveal[i]=0;
    }
	_position=_init_pos;
	_money=_init_money;
	//_hand=MJhand(/*_init_tiles,_init_tiles_len*/);
	// remember to change MJhand.cpp -> setfromId

}
MJplayer::~MJplayer(){
	// empty
}
int MJplayer::Get_Pos() const{
	return _position;
}
int MJplayer::Get_Mon() const{
	return _money;
}
void MJplayer::Set_Pos(int _pos){
	_position=_pos;
}
void MJplayer::Print_Hand(){
	cout<<*(this);
}
void MJplayer::set_hand(MJtile* _init_tiles){
	_faceup_len=0;
    _total_len=16;
    _stage=0;
	for(int i=0;i<16;++i){
		_tiles[i].setfromId(_init_tiles[i].getTileId());
	}
	for(int i=0;i<30;++i){
		noreveal[i]=0;
	}
}
void MJplayer::strategy(int position, MJtile t, 
	int &actiontype, int &actionparameter){
	// do nothing -> brainless AI
	// type: nothing=0 eat=1 pong=2 minggone=3 angone=4 bugone=5 applique=6 hu=7 play=8
	// actionparmeter: 
	if(canhu(t) && position==_position){ // huown
		actiontype=7;
		return;
	}
	if(actiontype==8){ // play
		actiontype=8;
		actionparameter=total_len()-faceup_len()+stage();
		return;
	}
	else {
		actiontype=0; // do nothing
		return;
	}
}
void MJplayer::getinfo(int position, vector<MJtile> ts, int tiles_num){
	// tiles_num = how many tiles are involved in this action

}


// Hand Functions
/*
int MJplayer::P_total_len() const             {return _hand.total_len();}
int MJplayer::P_faceup_len() const            {return _hand.faceup_len();}
void MJplayer::P_set_faceup_len(int f)        {_hand.set_faceup_len(f);}
bool MJplayer::P_stage() const                {return _hand.stage();}
void MJplayer::P_set_stage(bool s)            {_hand.set_stage(s);}
void MJplayer::P_set_last(const MJtile& _t)   {_hand.set_last(_t);}
MJtile MJplayer::P_get_last()const            {return _hand.get_last();}
MJtile MJplayer::P_get_tile(int _ID)const     {return _hand.get_tile(_ID);}
int MJplayer::P_get_tile_suit(int _ID)const   {return _hand.get_tile_suit(_ID);}
int MJplayer::P_get_tile_rank(int _ID)const   {return _hand.get_tile_rank(_ID);}
int MJplayer::P_get_tile_suit_z(int _ID)const {return _hand.get_tile_suit_z(_ID);}
int MJplayer::P_get_tile_rank_z(int _ID)const {return _hand.get_tile_suit_z(_ID);}
	
int MJplayer::P_caneat(const MJtile& _t)      {return _hand.caneat(_t);}
bool MJplayer::P_canpong(const MJtile& _t)    {return _hand.canpong(_t);}
bool MJplayer::P_canminggone(const MJtile& _t){return _hand.canminggone(_t);}
bool MJplayer::P_canangone(const MJtile& _t)  {return _hand.canangone(_t);}
bool MJplayer::P_canbugone(const MJtile& _t)  {return _hand.canbugone(_t);}
bool MJplayer::P_canhu(const MJtile& _t)      {return _hand.canhu(_t);}
	
void MJplayer::P_arrange()                    {_hand.arrange();}
void MJplayer::P_draw(MJcollection& _MJ_COL)  {_hand.draw(_MJ_COL);}
MJtile MJplayer::P_play(int _PL_ID)           {return _hand.play(_PL_ID);}
void MJplayer::P_faceup(int _FU_ID)           {_hand.faceup(_FU_ID);}
void MJplayer::P_applique(int _APP_ID, MJcollection& _MJ_COL)
{_hand.applique(_APP_ID,_MJ_COL);}
void MJplayer::P_initial(MJcollection& _MJ_COL){_hand.initial(_MJ_COL);}
	
void MJplayer::P_eat(const MJtile& _t, int _ID){_hand.eat(_t,_ID);}
void MJplayer::P_pong(const MJtile& _t)        {_hand.pong(_t);}
void MJplayer::P_minggone(const MJtile& _t, MJcollection& _MJ_COL)
{_hand.minggone(_t,_MJ_COL);}
void MJplayer::P_angone(int _ID, MJcollection& _MJ_COL)
{_hand.angone(_ID,_MJ_COL);}
void MJplayer::P_bugone(int _ID, MJcollection& _MJ_COL)
{_hand.bugone(_ID,_MJ_COL);}
void MJplayer::P_huother(const MJtile& _t)     {_hand.huother(_t);}
void MJplayer::P_huown()                       {_hand.huown();}

void MJplayer::P_showhandtoothers()            {_hand.showhandtoothers();}
*/