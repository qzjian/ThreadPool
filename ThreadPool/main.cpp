#include "thread_pool.h"
#include <time.h>
class YourClass {
public:
	int cmd; // cmd = 1是上线程停止计算，正常退出。
	void work(){printf("I am working\n"); cmd=1;}
};


void threadfunc(void *p)
{
	YourClass* yourObject = (YourClass*)p;
	 while (true) {
		yourObject->work();
		if (yourObject->cmd==1)	break;
	 }
}

int main()
{
	unsigned int st=time(NULL);
	ThreadPool tp;
	for(int i=0; i<2000; i++)
	{
		Sleep(30);
		YourClass* yo=new YourClass();
		tp.Call(threadfunc,yo);
	}
	printf("----------ts=%ld\n",time(NULL)-st);
	Sleep(1000000000);
	return 0;
}