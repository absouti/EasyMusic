
#ifndef MYHEAD_H
#define MYHEAD_H
#include <iostream>

#include<string>
#include<assert.h>
#include<fstream>

#include <format>
#include "yyjson/yyjson.h"

#include <windows.h>
#include <windowsx.h>
#include <map>
#include <winuser.h>
#include <string>
#include <windef.h>
#include <unistd.h>


#include "FreeImage.h"
#pragma comment(lib, "FreeImage.lib")

#include <dwmapi.h>
#pragma comment(lib, "Dwmapi.lib")

#include <mmsystem.h>
#pragma comment(lib, "WinMM.lib")

//#include <gdiplus.h>
//#pragma comment (lib,"gdiplus.lib")

#include <wininet.h>
#pragma comment(lib, "wininet.lib")

//using namespace Gdiplus;

using namespace std;

//�������¼�
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//head���¼�
LRESULT CALLBACK mytitleProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//���Ͻǲ�����ť���¼�
LRESULT CALLBACK myOP_BtnProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//�رհ�ť�¼�
LRESULT CALLBACK closeProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//������¼�
LRESULT CALLBACK Edit_out_Proc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//foot���¼�
LRESULT CALLBACK myfootProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);

//��󻯻�ԭ��ť
LRESULT CALLBACK tofullSProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//��С����ť
LRESULT CALLBACK tosmallSProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//miniģʽ��ť
LRESULT CALLBACK tominiProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//����������ͼ��
LRESULT CALLBACK searchProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//logo����
LRESULT CALLBACK logoProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//��߲˵��¼�
LRESULT CALLBACK L_menuProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//�����ܲ˵�
LRESULT CALLBACK L_MainIndexProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//�����ܲ˵���ť
LRESULT CALLBACK L_MainIndex_btnProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//�ҵ����ֹ��ܲ˵�
LRESULT CALLBACK MyMusicIndexProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//���ܲ˵�С����
LRESULT CALLBACK IndexTitleProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//�ҵ����ֲ˵���ť
LRESULT CALLBACK L_Mymusic_btnProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//���Դ��ڱ�Ǿ���
LRESULT CALLBACK testWinProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//�ײ���ಥ���еĸ�����Ϣ
LRESULT CALLBACK footLProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//�ײ����ư�ť��
LRESULT CALLBACK PlayingControlProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//�ײ��Ҳ�Ĳ�������
LRESULT CALLBACK PlayingSetProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//�����������
LRESULT CALLBACK VolumePanelProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//�������¼�
LRESULT CALLBACK searchEditProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//�������ҳ
LRESULT CALLBACK SearchResultPageProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
//�������������Ŀ
LRESULT CALLBACK SearchItemInfoProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);



//����head��
int Loadhead(HINSTANCE hInstance,HWND hwnd);
//����foot��
int Loadfoot(HINSTANCE hInstance,HWND hwnd);
//��ʼ��������
int init_wc_Class(HINSTANCE hInstance);
//��ⴰ���Ƿ񴴽��ɹ�
int cheackWin(HWND hwnd);
//��ⴰ�����Ƿ�ע��ɹ�
int cheackClass(WNDCLASSEX wc);
//������ߵĲ˵�
int LoadLmenu(HINSTANCE hInstance,HWND hwnd);
//��ȡ��Ļ���ű���
double GetScreenScale();
//dpiת����ֵ
int DPI(int num);
int DDPI(double num);
int DPIW(double num);
double DPIP(double num);

//tooltip����
int tooltip_tooltip(HINSTANCE hInstance);
int tooltip_show(std::string str,int x, int y);
int tooltip_hide();


//��ʼ����ͼ�豸
int init_gdiDevice();

//�ַ���ת��
string Utf8ToGbk(const char *src_str);
string GbkToUtf8(const char *src_str);
//url�������
std::string UrlEncode(const std::string& str);
std::string UrlDecode(const std::string& str);
//http get����
int net_GET(string url,char *result);

//������������ʾ������
void VolumePanel_show();
void VolumePanel_hide();

//��ȫ�л���ͼ�豸
int safeSwitchColor(HDC hdc,int type,int w,int r,int g,int b);

struct MainIndexBTN{
	HWND hwnd;
	int id;
	int mouseHover = 0;
	int checked = 0;
	string text = "";
	HENHMETAFILE emf;
};



struct MenuItem{
	HWND hwnd;
	int height;
	map<int,MainIndexBTN> childItem; 
};


//���ڲ�����
class PlayingSong{
	public:
		int id;
		string name;
		string artist;
		string album;
		string url;
		string cover;
		string lrc;
		string totalTime_str;
		string position_str;
		long totalTime;
		long position;
		int time;
		int playing;
		int newVolume;
		int theVolumeBeforeMute;
		void SetMusic(int id);
		void Play();
		void Pause();
		void getTotalTime_str();
		void getPosition_str();
		void ProgressLoop();
		void PlayFromPosition(long position);
		void setVolume(int Vnum);
		int getVolume();
};

struct SearchResultPage_struct{
	string keyword;
	int PlayALL = 0;
	int DownloadALL = 0;
	int itemNum = 0;
};
struct SearchItemWidth_struct{
	int empty = DPI(40);
	int index = DPI(40);
	int love = DPI(40);
	int downlaod = DPI(40);
	int title;
	int artist;
	int album;
	int length = DPI(80);
	int heat = DPI(130);
};

struct SearchItemInfo__struct{
	HWND hwnd;
	long long id;
	int songId;
	int mouseHover = 0;
	int checked = 0;
	int isLove = 0;
	int isDownload = 0;
	string title;
	string artist;
	string album;
	string length;
	int heat;
	RECT itemRect;
};


//������ȫ�ֱ���
extern map<int,HWND> HWNDM;
extern map<int,HBITMAP> BITM;
extern double constDPI;
extern char appName[];
extern map<int,MainIndexBTN> MainIndexList;
extern map<string,HPEN> myPEN;
extern map<string,HBRUSH> myBRUSH;
extern map<int,MenuItem> MenuItemList;
extern map<int,MainIndexBTN> MyMusicItemList;
extern string domainName;
extern PlayingSong player;
extern SearchResultPage_struct SearchResultPage;
extern SearchItemWidth_struct SearchItemWidth;
extern map<int,SearchItemInfo__struct> SearchItemInfo;

//���崰�ڹ�����
#define H_MAIN_WIN  	1
#define H_MYHEAD		2
#define H_OPBTN			3
#define H_MYFOOT		4
#define H_LMENU			5
#define H_tooltip		6
#define H_PlayingInfo_m	7
#define H_PlayingSet_m	8
#define H_PlayingControl 9
#define H_VolumePanel	10
#define H_SearchResultPage 11

//����λͼ����
#define BIT_CLOSE		1



#endif
