/*********************************************************************
 * Created by Mercury Interactive Windows Sockets Recorder
 *
 * Created on: Thu Dec 19 14:51:59
 *********************************************************************/
#include "lrs.h"
void CreatSendSocket(){//������������
	lrs_create_socket("socket1","TCP","RemoteHost=10.0.101.139:80",LrsLastArg);
}

void CloseSendSocket(){//�رշ�������
	lrs_disable_socket("socket1",DISABLE_SEND_RECV);
	lrs_close_socket("socket1");
}
int Logon(){//��½
	lrs_send("socket1","buf0",LrsLastArg);
	timeOut();
	lrs_receive("socket1","buf1",LrsLastArg);
}
void reg0(){//��ȡSessionID
	lrs_save_searched_string("socket1", NULL,"param0","LB/BIN={","RB/BIN=}",1,-1,-1);
}
void timeOut(){
	lrs_set_recv_timeout(1, 1);
    lrs_set_recv_timeout2(1,1);
}
vuser_init()
{
	/*
	CreatSendSocket();
	Logon();//��½����ȡ�豸�б�
	reg0();
	CloseSendSocket();
	lrs_startup(257);
	*/

	return 0;
}

