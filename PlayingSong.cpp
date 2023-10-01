#include "myhead.h"


void PlayingSong::SetMusic(int id){
	this->id = id;
	char song_result[10240];
	this->playing = 0;
	//Ӧ��Ҫ��https://github.com/Binaryify/NeteaseCloudMusicApi
	//�з���ʹ�ùٷ���api������һ���ٷ��������࣬��Ϊʱ�����⣬�˴�ʹ���������ҵĵ���������ӿ�

	string url = "/song/detail?ids=" + to_string(this->id);
	net_GET(url,song_result);
	//cout<<song_result;
	
	yyjson_doc *doc = yyjson_read(song_result, strlen(song_result), 0);
	yyjson_val *root = yyjson_doc_get_root(doc);
	yyjson_val *temp = yyjson_obj_get(root, "songs");
	temp = yyjson_arr_get(temp,0);
	
	this->name = Utf8ToGbk(yyjson_get_str(yyjson_obj_get(temp, "name")));
	
	temp = yyjson_obj_get(temp,"ar");
	temp = yyjson_arr_get(temp,0);
	
	this->artist = Utf8ToGbk(yyjson_get_str(yyjson_obj_get(temp, "name")));
	//�Ƚ�����������Ҫ�ģ�ʣ�µĵȻ��Ϲٷ���api�ٽ���
	
	yyjson_doc_free(doc);
	
	
	cout<<this->id<<endl;
	if(this->name.length()){
		//��������־���ֹͣ����
		mciSendString("close now_mp3", 0, 0, 0);
	}
	string path = "https://music.163.com/song/media/outer/url?id="+to_string(this->id)+".mp3";
    string command = "open \"" + path + "\" type mpegvideo alias now_mp3";
    mciSendString(command.c_str(), NULL, 0, NULL);
    
	this->getTotalTime_str();
	this->getPosition_str();
    player.newVolume=player.getVolume();
    //�ػ�ײ����½ǵĸ�����Ϣ
    InvalidateRect(HWNDM[H_PlayingInfo_m], NULL, TRUE);
    //�ػ�����������Ϣ
	InvalidateRect(HWNDM[H_PlayingControl], NULL, TRUE);
	//�ػ����½ǰ�ť
	InvalidateRect(HWNDM[H_PlayingSet_m], NULL, TRUE);
}
void PlayingSong::getTotalTime_str(){
	char sLength[100];
	long lLength;
	mciSendString("status now_mp3 length", sLength, 100, 0);
	lLength = strtol(sLength, NULL, 10);
	this->totalTime=lLength;
	//�����������
	int mm = 0;
	int ss;
	lLength = lLength/1000;
	while(lLength>59){
		lLength-=60;
		mm++;
	}
	ss=lLength;
	//����format����������Ϊ��������֧��c++ 20
	this->totalTime_str = (mm<10?"0":"") + to_string(mm)+":" + (ss<10?"0":"") + to_string(ss);
}
void PlayingSong::getPosition_str(){
	char sPosition[100];
	long lPosition;
	mciSendString("status now_mp3 position", sPosition, 100, 0);
	lPosition = strtol(sPosition, NULL, 10);
	this->position = lPosition;
	//cout<<lPosition<<endl;
	//���㵱ǰ���ŵĳ���
	int mm = 0;
	int ss;
	lPosition = lPosition/1000;
	while(lPosition>59){
		lPosition-=60;
		mm++;
	}
	ss=lPosition;
	this->position_str = (mm<10?"0":"") + to_string(mm)+":" + (ss<10?"0":"") + to_string(ss);
}

void PlayingSong::Play(){
	mciSendString("play now_mp3", NULL, 0, NULL);
	if(this->playing == 0){
		this->playing = 1;
		SetTimer(HWNDM[H_PlayingControl],163,1000,NULL);
	}
}
void PlayingSong::Pause(){
	mciSendString("Pause now_mp3", NULL, 0, NULL);
	this->playing = 0;
	KillTimer(HWNDM[H_PlayingControl],163);
}

void PlayingSong::ProgressLoop(){
	if(!this->playing){
		KillTimer(HWNDM[H_PlayingControl],163);
	}
	this->getPosition_str();
	InvalidateRect(HWNDM[H_PlayingControl], NULL, TRUE);
	//cout<<"1"<<endl;
}
void PlayingSong::PlayFromPosition(long position){
	string command = "play now_mp3 from "+to_string(position)+" to "+to_string(this->totalTime);
	mciSendString(command.c_str(), NULL, 0, NULL);
	if(this->playing == 0){
		this->playing = 1;
		SetTimer(HWNDM[H_PlayingControl],163,1000,NULL);
	}
}
int PlayingSong::getVolume(){
	char volume[100]; 
	mciSendString("status now_mp3 volume", volume, sizeof(volume), 0);
	return atoi(volume);
}
void PlayingSong::setVolume(int Vnum){
	string command = "setaudio now_mp3 volume to "+to_string(Vnum);
	mciSendString(command.c_str(), 0, 0, 0);
}
