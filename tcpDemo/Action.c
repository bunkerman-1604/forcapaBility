#include "lrs.h"
//实时心电
void getResourceList(){//获取按条件查找设备
	lrs_send("socket1","buf2",LrsLastArg);
	lrs_receive("socket1","buf3",LrsLastArg);
}
void getPatientList(){//获取用户列表
	lrs_send("socket1","buf4",LrsLastArg);
	lrs_receive("socket1","buf5",LrsLastArg);
}
void getUserList(){//获取按条件查找的用户
	lrs_send("socket1","buf6",LrsLastArg);
	timeOut();
	lrs_receive("socket1","buf7",LrsLastArg);
}
void allotResource(){//发放操作
	lrs_send("socket1","buf8",LrsLastArg);
	timeOut();
	lrs_receive("socket1","buf9",LrsLastArg);
}
void PrintParam(char* tar){//打印变量；
	char tmp[1000];
	lr_convert_string_encoding(tar,
							   LR_ENC_UTF8,
							   "GB2312",
							   "GOAL");
	strcpy(tmp,lr_eval_string("<GOAL>"));
	lr_save_string(tmp,"GOAL");
	lr_output_message("返回值：%s",lr_eval_string("<GOAL>"));		
}
void reg1(){//获取getPatientList返回值
	lrs_save_searched_string("socket1", NULL,"param1","LB/BIN=<body>\r\n","RB/BIN=</body>",1,-1,-1);
}
void reg2(){//获取发放操作返回值
	lrs_save_searched_string("socket1", NULL,"param2","LB/BIN=userNo\":\"","RB/BIN=\"",1,-1,-1);
}
void reg3(){//获取发放操作返回值
	lrs_save_searched_string("socket1", NULL,"param3","LB/BIN={","RB/BIN=}",1,-1,-1);
}
void api7(){
	lrs_send("socket1","buf10",LrsLastArg);
//	timeOut();
//  lrs_set_socket_options("socket1",LRS_NO_DELAY,TRUE);
//	lrs_set_receive_option(EndMarker, EndMarker_None ) // 读取直到缓冲结束.
//	lrs_set_receive_option(EndMarker, StringTerminator , "\r\n") //读取直到"\r\n"符号出现 .
//	lrs_set_receive_option(EndMarker, BinaryStringTerminator , "\X00") 读取直到二进制符号"\\X00"出现
	lrs_receive("socket1","buf12",LrsLastArg);
	//lrs_receive_ex("socket1","buf12"," NumberOfBytesToRecv=10", LrsLastArg);
}
void reg7(){//获取发放操作返回值
	lrs_save_searched_string("socket1", NULL,"param7","LB/BIN={","RB/BIN=}",1,-1,-1);
}
Action()//xintiao
{

	int startTime = 0,endTime = 0,time_e = 0;
/*	lr_output_message("deviceMacs=%s,deviceID=%s,PatientID=%s.",lr_eval_string("1312001&queryTitle"),lr_eval_string("defcae35-e222-47b9-ba2b-858486c7c8a0"),lr_eval_string("1417572258885"));

	CreatSendSocket();
	getResourceList();//查找指定设备号；
	//reg1();
	//PrintParam(lr_eval_string("<param1>"));
	CloseSendSocket();

	CreatSendSocket();
	getPatientList();//进入设备发放页面(获取用户列表界面)；
	//reg1();
	//PrintParam(lr_eval_string("<param1>"));
	CloseSendSocket();
	
    
	lr_start_transaction("CheckPat");

	CreatSendSocket();
	getUserList();//按照客户ID查找用户
	reg2();
	CloseSendSocket();
    
	lr_end_transaction("CheckPat", LR_AUTO);
    
	lr_start_transaction("Allot");

	CreatSendSocket();
	allotResource();//对指定的客户(ID)、设备(ID)进行发放请求；
	reg3();
	PrintParam(lr_eval_string("<param3>"));
	CloseSendSocket();

	lr_end_transaction("Allot", LR_AUTO);
*/

	startTime = clock();

	CreatSendSocket();

	lr_rendezvous("API7");

	lr_start_transaction("SendAPI7");

	api7();

	lr_end_transaction("SendAPI7",LR_AUTO);

	reg7();

	PrintParam(lr_eval_string("<param7>"));

	CloseSendSocket();

	lr_output_message("已完成%s次。",lr_eval_string("<round>"));

	endTime = clock();

	time_e=(int)(endTime-startTime);

	if(time_e < 5000){

		lr_think_time((float)((5000-time_e))/1000);

	}
	

    return 0;
}

